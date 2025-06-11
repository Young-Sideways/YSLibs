# KROT - Young Sideways RPC system
# KROT syntax format standart - version 1.0

## reserved keywords
|-----------------------------|---------------------------------------------------------|
|          keyword            |                       description                       |
|-----------------------------|---------------------------------------------------------|
| import <path to .rpc file>  | imports all statements from another <file>              |
| include <path to file>      | put #include directive to generated C code file         |
type, struct, union, as, typeof
func

## Type system: registered types (translates as system features list while RPC's connects)
### All type-keywords are reserved keywords
### System types
|------|------|-----------------|--------------|--------------------------------------------------------|
| type | size |    C analog     | requirements |                         detail                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                        Fixed width integer formats                                    |
|------|------|-----------------|--------------|--------------------------------------------------------|
| i8   |  1   |     int8_t      |   required   |                                                        |
| i16  |  2   |     int16_t     |   required   |                                                        |
| i32  |  4   |     int32_t     |   required   |                                                        |
| i64  |  8   |     int64_t     |   required   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|
| u8   |  1   |     uint8_t     |   required   |                                                        |
| u16  |  2   |     uint16_t    |   required   |                                                        |
| u32  |  4   |     uint32_t    |   required   |                                                        |
| u64  |  8   |     uint64_t    |   required   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                      IEEE-754 floating-point formats                                  |
|------|------|-----------------|--------------|--------------------------------------------------------|
|  fs  |  4   |      float      |   required   | single precision floating-point format                 |
|  fd  |  8   |      double     |   required   | double precision floating-point format                 |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                               Boolean formats                                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
| bool |  1   |     _Bool*1     |   required   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                                String formats                                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
| cstr |  4+  |      char*      |   required   | standart ascii 8-bit C-string with '\0' at the end     |
| ustr |  4+  |     wchar_t*    |   required   | utf-8 with L'\0' at the end that converts to MB        |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                                 time formats                                          |
|------|------|-----------------|--------------|--------------------------------------------------------|
| time |  4-8 |     time_t      |   required   | POSIX time representation in seconds since 1 jan 1970  |
| date |  36  |    struct tm    |   required   | date representation                                    |
| spec |  8   | struct timespec |   required   | time stamp with seconds and nanoseconds                |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                               Special formats                                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
| void |  0   |      void       |   required   | specifies a type, thats represent nothing              |
|------|------|-----------------|--------------|--------------------------------------------------------|




### Optional system types
|------|------|-----------------|--------------|--------------------------------------------------------|
| type | size |    C analog     | requirements |                         detail                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                        Fixed width integer formats                                    |
|------|------|-----------------|--------------|--------------------------------------------------------|
| i128 |  16  |   __int128_t    |   optional   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|
| u128 |  16  |   __uint128_t   |   optional   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                      Variable width integer formats                                   |
|------|------|-----------------|--------------|--------------------------------------------------------|
|  bi  |  1+  |   _BitTnt(x)    |   optional   | bit-precise integer format                             |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                      IEEE-754 floating-point formats                                  |
|------|------|-----------------|--------------|--------------------------------------------------------|
|  fq  | 16*3 |  long double*3  |   optional   |  quadruple precision floating-point format             |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                          IEEE-754 decimal formats                                     |
|------|------|-----------------|--------------|--------------------------------------------------------|
| d32  |  4   |  _Decimal32*4   |   optional   |  decimal32 floating-point format                       |
| d64  |  8   |  _Decimal64*4   |   optional   |  decimal64 floating-point format                       |
| d128 |  16  |  _Decimal128*4  |   optional   | decimal128 floating-point format                       |
|------|------|-----------------|--------------|--------------------------------------------------------|

*1 - '_Bool' literal before C23 satndart (+ #include <stdbool.h>). Since C23 <stdbool.h> and '_Bool' are deprecated.
*2 - '_BitInt(x)' translates as byte array with alignment of 1 byte
*3 - size of 'long double can be different, and depends on platform, e.g. 8, 10 or 16 bytes'
*4 - If the implementation predefines the macro constant __STDC_IEC_60559_DFP__, the following decimal floating-point types are also supported. Otherwise, these decimal floating-point types are not supported.

### Setting for optional system types
If system does not support some data format by default, RPCC generates a code, thats contain predefined macro
    i128, u128     - RPC_NOOPT_TYPE_BIG_INT
    bi             - RPC_NOOPT_TYPE_BIT_INT
    fq             - RPC_NOOPT_TYPE_QUADFLOAT
    d32, d64, d128 - RPC_NOOPT_TYPE_DECIMAL
but this optional types can be disabled by config attributes
    i128, u128     - DISABLE_TYPE_BIG_INT
    bi             - DISABLE_TYPE_BIT_INT
    fq             - DISABLE_TYPE_QUADFLOAT
    d32, d64, d128 - DISABLE_TYPE_DECIMAL

### Extened YSLib types
KROT has adapters for YSLibs collection data types

|------|------|-----------------|--------------|--------------------------------------------------------|
| type | size |    C analog     | requirements |                         detail                         |
|------|------|-----------------|--------------|--------------------------------------------------------|
|                                     YSLibs collection data types                                      |
|------|------|-----------------|--------------|--------------------------------------------------------|
| tpl  | ...  |    tuple_t      |   extended   |                                                        |
| pair | ...  |    pair_t       |   extended   |                                                        |
| var  | ...  |    variant_t    |   extended   |                                                        |
| arr  | ...  |    array_t      |   extended   |                                                        |
| mat  | ...  |    matrix_t     |   extended   |                                                        |
| vec  | ...  |    vector_t     |   extended   |                                                        |
| deq  | ...  |    deque_t      |   extended   |                                                        |
| que  | ...  |    queue_t      |   extended   |                                                        |
| stk  | ...  |    stack_t      |   extended   |                                                        |
| str  | ...  |    string_t     |   extended   |                                                        |
| set  | ...  |    set_t        |   extended   |                                                        |
| map  | ...  |    map_t        |   extended   |                                                        |
| cset | ...  |    cset_t       |   extended   |                                                        |
| cmap | ...  |    cmap_t       |   extended   |                                                        |
| b3   | ...  |    btree_t      |   extended   |                                                        |
| rb3  | ...  |    rbtree_t     |   extended   |                                                        |
|------|------|-----------------|--------------|--------------------------------------------------------|


config
    name: 
    port:
    attributes: EXTEND_YSLIBS_DATA_TYPES
