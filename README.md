## BUILDING

To get started, enter\
`cmake --list-presets all`\
choose \<build preset\> and paste to this template\
`cmake --build --preset <build preset>`

For example you can choose release build type\
`cmake --build --preset <os>-release`\
Or debug build with test's and run it\
`cmake --build --preset <os>-debug`\
`ctest --preset <os>-[debug|release|benchmark]`

### Build shared or static
Select a build template from the ones above and add `-DYSLIBS_BUILD_SHARED=ON`, by default yslibs is built statically

## FEATURES
list of all sublibraries and main project tasks
| lib | progress |
| ---- | --- |
| core | ![](https://geps.dev/progress/20?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| macro | ![](https://geps.dev/progress/90?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| algorithm | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| collection | ![](https://geps.dev/progress/35?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| util | ![](https://geps.dev/progress/70?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| filesystem | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| | |
| build system | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| tests | ![](https://geps.dev/progress/20?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| documentation| ![](https://geps.dev/progress/70?dangerColor=800000&warningColor=ff9900&successColor=006600) |

### ***core*** module feature list
| submodule | description | progress |
| --- | --- | --- |
| core | main header with all project settings | ![](https://geps.dev/progress/40?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| debug | useful tools for debuging the project | ![](https://geps.dev/progress/50?dangerColor=800000&warningColor=ff9900&successColor=006600) |

### ***macro*** module feature list
| submodule | description | progress |
| --- | --- | --- |
| core | most useful macro expressions | ![](https://geps.dev/progress/90?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| variadic | VA lists arg count macro | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| inc \| dec | predefined arithmetic icrement and decrement | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| sequence | things, that can generate sequence and place it | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| arg | macro, that can take head, tail, first, last, count of arg list | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| exec | execute function-like macro with predefined arg list | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| logic | boolean operations with macro | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| reverse | reverse arg list | ![](https://geps.dev/progress/100?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| runtime | some runtime macro, such as min, max, offsetof, etc. | ![](https://geps.dev/progress/90?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| foreach | deprecated [moved to collections] | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
