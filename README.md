## REQUIREMENTS

YSLibs build system supports multiple AMD64 platform, such as `windows` `linux` and `mac` and depends olny `cmake >= 3.25` and `clang >= 17`, because it uses last, at this point, C Language standard - 23.\
In my future plans rewrite part of lib, to make it more portable and add support for other architectures, such as `RISC`, `arm` and `aarch64`

## BUILDING

To get started, choose any \<build preset\>
`cmake --list-presets all`\
and paste to this template\
`cmake --build --preset <build preset>`

For example you can take release build type\
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
| filesystem | moved to `util` due 0.0.5 |
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
| expect | static expectation maxro | ![](https://geps.dev/progress/30?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| foreach | deprecated [moved to collections] | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |

### ***collection*** module feature list
| submodule | description | progress |
| --- | --- | --- |
| tuple | struct like serializable enumerable set of values | ![](https://geps.dev/progress/30?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| pair | key-value pair | ![](https://geps.dev/progress/29?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| variant | safer union like object representation | ![](https://geps.dev/progress/50?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| array | C-array compatible representation of static array, supports alhorithms and enumerations | ![](https://geps.dev/progress/80?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| matrix | multidimensional array | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| vector | C-array compatible representation of dynamic array | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| deque | dynamic double-ended FIFO implementation | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| queue | dynamic FIFO implementation | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| stack | dynamic LIFO implementation | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| string | C-string compatible representation of dynamic strings | ![](https://geps.dev/progress/10?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| set | associative container of unique values | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| map | associative container of unique key-value pairs | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| count set | associative container of non-unique values | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| count map | associative container of non-unique key-value pairs | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| binary tree | linked sh*t! | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| red-black tree | another linked sh*t! | ![](https://geps.dev/progress/0?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| | |
| iterator | object for unifying access to enumerable containers | ![](https://geps.dev/progress/70?dangerColor=800000&warningColor=ff9900&successColor=006600) |
| foreach | set of macro's to orchestrate iterators | ![](https://geps.dev/progress/20?dangerColor=800000&warningColor=ff9900&successColor=006600) |
