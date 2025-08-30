Fool's GoldSource
=================
Fake GoldSource engine for unit testing Half-Life mods and plugins.

The implementation is in `foolsgoldsource.cpp` with `foolsgoldsource/hlsdk` containing the required headers definitions from the Half-Life SDK (with minimal changes to avoid having to recreate the whole directory structure).

The CLIENT_DLL guard is so that the server code can build without needing to know about the client code.


How to use
----------
Import foolsgoldsource as a git submodule:
```
git submodule add https://github.com/tschumann/foolsgoldsource
```

Then include `foolsgoldsource.cpp` and `foolsgoldsource.h` as part of the project.

Include `foolsgoldsource.h` in your test files, and if you don't have a separate unit test project and are using Visual Studio C++ Unit tests you can include `vscu_test.h` as well to allow the tests to be run without breaking the .dll file. Call `foolsgoldsource::gEngine.Initialise()` to set the fake engine to a clean state that is ready for use.


How it works
------------
`foolsgoldsource.cpp` instantiates a global variable whose constructor populates `gEngfuncs`, `IEngineStudio`, `g_engfuncs` and `gpGlobals` so that these SDK globals resolve in tests.


Testing
-------
Open "Developer Powershell for VS" (first line may not be needed)
```
Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process
./test.ps1
```


License
-------
The code in `foolsgoldsource/hlsdk` is from https://github.com/ValveSoftware/halflife and is covered by the license at https://github.com/ValveSoftware/halflife/blob/master/LICENSE

The files comes from `common/`, `engine/`, `public/` and `utils/vgui/include/`
