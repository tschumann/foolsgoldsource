Fool's GoldSource
=================

Mock GoldSource engine for unit testing Half-Life mods and plugins.

The implementation is in `foolsgoldsource.cpp` with `foolsgoldsource/hlsdk` containing the required definitions from the Half-Life SDK (with minimal changes to avoid having to recreate the whole directory structure).


How to use
----------

Import foolsgoldsource as a subproject and include `foolsgoldsource.cpp` and `foolsgoldsource.h` as part of the project.

Include `foolsgoldsource.h` in your test files and if you don't have a separate unit test project you can include `vscu_test.h` as well.


Testing
-------

```
powershell ./test.ps1
```


License
-------

The code in `foolsgoldsource/hlsdk` is from https://github.com/ValveSoftware/halflife and is covered by the license at https://github.com/ValveSoftware/halflife/blob/master/LICENSE
