$ErrorActionPreference = "Stop"

# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$workingdirectory = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $workingdirectory

Write-Output "------------------"
Write-Output "Building x86 Debug"
Write-Output "------------------"

# build the solution
& "MSBuild.exe" /t:Build /p:Platform=x86 /p:Configuration=Debug "foolsgoldsource.sln"

# copy across vgui.dll files so that foolsgoldsource_test.dll will load 
Copy-Item "C:\Program Files (x86)\Steam\steamapps\common\Half-Life\vgui.dll" -Destination "Debug"

Write-Output "-----------------"
Write-Output "Testing x86 Debug"
Write-Output "-----------------"

# run the tests
& "vstest.console.exe" Debug\foolsgoldsource_test.dll --logger:"console;verbosity=Normal"

# could test x64 but VGUI is 32 bit only

Pop-Location