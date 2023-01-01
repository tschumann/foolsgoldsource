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
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=x86 /p:Configuration=Debug "foolsgoldsource.sln"

Write-Output "-----------------"
Write-Output "Testing x86 Debug"
Write-Output "-----------------"

# run the tests
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" Debug\foolsgoldsource_test.dll --logger:"console;verbosity=Normal"

Write-Output "------------------"
Write-Output "Building x64 Debug"
Write-Output "------------------"

# build the solution
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=x64 /p:Configuration=Debug "foolsgoldsource.sln"

Write-Output "-----------------"
Write-Output "Testing x64 Debug"
Write-Output "-----------------"

# run the tests
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" x64\Debug\foolsgoldsource_test.dll --logger:"console;verbosity=Normal"

Pop-Location