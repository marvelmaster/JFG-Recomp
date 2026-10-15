# Saves a screenshot of the JFGRecompiled window (also when it is covered) via PrintWindow(PW_RENDERFULLCONTENT).
# Usage: powershell -ExecutionPolicy Bypass -File tools\shot_window.ps1 out.png
param([string]$Out)
Add-Type -AssemblyName System.Drawing
Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class Win {
    [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L, T, R, B; }
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr hdc, uint flags);
    [DllImport("user32.dll")] public static extern bool SetProcessDPIAware();
}
"@
$p = Get-Process JFGRecompiled -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Select-Object -First 1
if (-not $p) { "no JFGRecompiled window"; exit 1 }
# Without DPI awareness, at >100% display scaling the rect is in logical pixels and only the
# top-left part of the (physical-size) window content is captured, which looks like a zoomed picture.
[Win]::SetProcessDPIAware() | Out-Null
$r = New-Object Win+RECT
[Win]::GetWindowRect($p.MainWindowHandle, [ref]$r) | Out-Null
$w = $r.R - $r.L; $h = $r.B - $r.T
$bmp = New-Object System.Drawing.Bitmap $w, $h
$g = [System.Drawing.Graphics]::FromImage($bmp)
$hdc = $g.GetHdc()
$ok = [Win]::PrintWindow($p.MainWindowHandle, $hdc, 2)
$g.ReleaseHdc($hdc); $g.Dispose()
$bmp.Save($Out); $bmp.Dispose()
"saved ${w}x${h} printwindow=$ok"
