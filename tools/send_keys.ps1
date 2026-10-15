# Sends REAL keyboard events (SendInput, scan codes) to the JFGRecompiled window at given times, for testing the
# actual keyboard bindings (the JFG_INPUT_SCRIPT path bypasses them). Brings the window to the foreground first.
# Times are seconds since this script started (start it right after the game, e.g. as a job next to
# run_to_goldwood.ps1 which launches the game ~2 s after it starts).
# Usage: powershell -File tools\send_keys.ps1 -Keys "112.0:SPACE:300,115:W:2000"   (names: SPACE W A S D Q E R
#        LSHIFT ENTER UP DOWN LEFT RIGHT, or a hex scan code like 0x39)
param([string]$Keys)
Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class KeyIn {
    [StructLayout(LayoutKind.Sequential)] public struct KEYBDINPUT { public ushort wVk, wScan; public uint dwFlags, time; public IntPtr extra; }
    [StructLayout(LayoutKind.Explicit, Size = 40)] public struct INPUT { [FieldOffset(0)] public uint type; [FieldOffset(8)] public KEYBDINPUT ki; }
    [DllImport("user32.dll")] public static extern uint SendInput(uint n, INPUT[] inputs, int size);
    [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int cmd);
    [DllImport("user32.dll")] public static extern void keybd_event(byte vk, byte scan, uint flags, IntPtr extra);
    public static void Key(ushort scan, bool up, bool ext) {
        INPUT[] i = new INPUT[1];
        i[0].type = 1; i[0].ki.wScan = scan;
        i[0].ki.dwFlags = 0x0008u | (up ? 0x0002u : 0u) | (ext ? 0x0001u : 0u);
        SendInput(1, i, Marshal.SizeOf(typeof(INPUT)));
    }
}
"@
$names = @{ SPACE = 0x39; W = 0x11; A = 0x1E; S = 0x1F; D = 0x20; Q = 0x10; E = 0x12; R = 0x13; LSHIFT = 0x2A; ENTER = 0x1C;
            UP = 0xE048; DOWN = 0xE050; LEFT = 0xE04B; RIGHT = 0xE04D }
$t0 = Get-Date
foreach ($item in ($Keys -split "," | Where-Object { $_ })) {
    $at, $key, $hold = $item -split ":"
    if (-not $hold) { $hold = 200 }
    $code = if ($names.ContainsKey($key)) { $names[$key] } else { [Convert]::ToInt32($key, 16) }
    $wait = [double]$at - ((Get-Date) - $t0).TotalSeconds
    if ($wait -gt 0) { Start-Sleep -Milliseconds ([int]($wait * 1000)) }
    $p = Get-Process JFGRecompiled -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Select-Object -First 1
    if (-not $p) { "no game window"; exit 1 }
    [KeyIn]::keybd_event(0x12, 0, 0, [IntPtr]::Zero); [KeyIn]::keybd_event(0x12, 0, 2, [IntPtr]::Zero) # ALT tap: allows SetForegroundWindow
    [KeyIn]::ShowWindow($p.MainWindowHandle, 9) | Out-Null
    [KeyIn]::SetForegroundWindow($p.MainWindowHandle) | Out-Null
    Start-Sleep -Milliseconds 150
    $ext = ($code -band 0xE000) -eq 0xE000
    [KeyIn]::Key([uint16]($code -band 0xFF), $false, $ext)
    Start-Sleep -Milliseconds ([int]$hold)
    [KeyIn]::Key([uint16]($code -band 0xFF), $true, $ext)
    "sent $key at $([int](((Get-Date) - $t0).TotalMilliseconds)) ms"
}
