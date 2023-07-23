@echo off

set CommonCompilerFlags= -O2 /EHsc /fp:fast -Gm- -GR- -EHa- -Oi -WX -W4 -nologo
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib

cl %CommonCompilerFlags% clicker.cpp /link %CommonLinkerFlags% -incremental:no -opt:ref
