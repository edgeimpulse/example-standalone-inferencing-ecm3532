$device = $args[0]
$path = $args[1]
Write-Output "Eta Compute: Starting GDBServer process for $device at $args[1]..."

$device = "-device $device"
$interface = "-if swd"
$speed = "-speed 1000"
#Start-Job –Name "JLinkGDBServer.exe" –Scriptblock { )} -ArgumentList $message1,$message2
Start-Job { JLinkGDBServer.exe -device ECM3532 -if swd -speed 1000 } -Name "JLinkGDBServer.exe"
Start-Sleep -s 2

Write-Output "Starting GDB with tui..."
$timer =  New-Object System.Timers.Timer
$gdb = "arm-none-eabi-gdb -q -iex 'set auto-load safe-path $path' -tui"
Invoke-Expression $gdb

if ($timer.Elapsed.TotalSeconds -lt 1) {
    Write-Output "...tui not supported."
    Write-Output "Starting GDB without tui..."
    $gdb = "arm-none-eabi-gdb -q -iex 'set auto-load safe-path $path'"
    Invoke-Expression $gdb
}

Write-Output "...GDB Finished."
Write-Output "...Stopping JLinkGDBServer"
Get-Process | Where-Object { $_.Name -eq "JLinkGDBServer" } | Select-Object -First 1 | Stop-Process -Force
Get-Process | Where-Object { $_.Name -eq "JLinkGUIServer" } | Select-Object -First 1 | Stop-Process -Force
$timer.Close()
Write-Output "...Exiting!"
