// stackdump <pid>: print native call stacks of all threads (module+offset, export names via dbghelp).
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <dbghelp.h>
#include <cstdio>
#include <cstdlib>
#pragma comment(lib, "dbghelp.lib")

int main(int argc, char** argv) {
    DWORD pid = (DWORD)atoi(argv[1]);
    HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!proc) { printf("OpenProcess failed %lu\n", GetLastError()); return 1; }
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
    SymInitialize(proc, nullptr, TRUE);
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 te{}; te.dwSize = sizeof(te);
    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
        if (te.th32OwnerProcessID != pid) continue;
        HANDLE th = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);
        if (!th) continue;
        SuspendThread(th);
        CONTEXT c{}; c.ContextFlags = CONTEXT_FULL;
        if (GetThreadContext(th, &c)) {
            wchar_t* desc = nullptr; char name[256] = "";
            if (SUCCEEDED(GetThreadDescription(th, &desc)) && desc) { WideCharToMultiByte(CP_UTF8, 0, desc, -1, name, 255, 0, 0); LocalFree(desc); }
            printf("--- tid %lu \"%s\"\n", te.th32ThreadID, name);
            STACKFRAME64 sf{};
            sf.AddrPC.Offset = c.Rip; sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = c.Rsp; sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = c.Rbp; sf.AddrFrame.Mode = AddrModeFlat;
            for (int i = 0; i < 40; i++) {
                if (!StackWalk64(IMAGE_FILE_MACHINE_AMD64, proc, th, &sf, &c, nullptr, SymFunctionTableAccess64, SymGetModuleBase64, nullptr)) break;
                DWORD64 pc = sf.AddrPC.Offset; if (!pc) break;
                DWORD64 mb = SymGetModuleBase64(proc, pc);
                IMAGEHLP_MODULE64 mi{}; mi.SizeOfStruct = sizeof(mi);
                SymGetModuleInfo64(proc, pc, &mi);
                char buf[sizeof(SYMBOL_INFO) + 256]; SYMBOL_INFO* si = (SYMBOL_INFO*)buf; si->SizeOfStruct = sizeof(SYMBOL_INFO); si->MaxNameLen = 255;
                DWORD64 disp = 0;
                bool sym = SymFromAddr(proc, pc, &disp, si);
                printf("  %s+%llX %s+%llX\n", mi.ModuleName, (unsigned long long)(pc - mb), sym ? si->Name : "?", (unsigned long long)disp);
            }
        }
        ResumeThread(th);
        CloseHandle(th);
    }
    return 0;
}
