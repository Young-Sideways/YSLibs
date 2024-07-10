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

### Building shared or static
Select a build template from the ones above and add `-DYSLIBS_BUILD_SHARED=ON`, by default yslibs is built statically

## FEATURES
| lib | progress |
|-|-|
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
