## BUILDING

To get started, enter\
`cmake --list-presets all`\
choose \<build preset\> and paste to this template\
`cmake --build --preset <build preset>`

For example you can choose release build type\
`cmake --build --preset <os>-release`\
Or debug build with test's and run it\
`cmake --build --preset <os>-debug`\
`ctest --preset linux-debug`
