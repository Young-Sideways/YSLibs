#include <stdbool.h>
#include <stdint.h>

static bool char_map[] = {
    ['a'] = true, ['A'] = true,
    ['b'] = true, ['B'] = true,
    ['c'] = true, ['C'] = true,
    ['d'] = true, ['D'] = true,
    ['e'] = true, ['E'] = true,
    ['f'] = true, ['F'] = true,
    ['g'] = true, ['G'] = true,
    ['h'] = true, ['H'] = true,
    ['i'] = true, ['I'] = true,
    ['j'] = true, ['J'] = true,
    ['k'] = true, ['K'] = true,
    ['l'] = true, ['L'] = true,
    ['m'] = true, ['M'] = true,
    ['n'] = true, ['N'] = true,
    ['o'] = true, ['O'] = true,
    ['p'] = true, ['P'] = true,
    ['q'] = true, ['Q'] = true,
    ['r'] = true, ['R'] = true,
    ['s'] = true, ['S'] = true,
    ['t'] = true, ['T'] = true,
    ['u'] = true, ['U'] = true,
    ['v'] = true, ['V'] = true,
    ['w'] = true, ['W'] = true,
    ['x'] = true, ['X'] = true,
    ['y'] = true, ['Y'] = true,
    ['z'] = true, ['Z'] = true,
    ['.'] = true,
    [','] = true,
    ['"'] = true,
    ['\''] = true,
    ['\\'] = true,
    ['\t'] = true,
    ['\n'] = true,
    ['\r'] = true,
    ['{'] = true,
    ['}'] = true,
    ['['] = true,
    [']'] = true,
    ['('] = true,
    [')'] = true,
    ['_'] = true,
    ['+'] = true,
    ['-'] = true,
    ['='] = true,
    ['*'] = true,
    ['!'] = true,
    ['@'] = true,
    ['$'] = true,
    ['%'] = true,
    ['^'] = true,
    ['&'] = true,
    ['|'] = true,
    ['~'] = true,
    ['/'] = true,
    [':'] = true,
    [';'] = true,
    ['`'] = true
};

typedef enum JSON_obj_type {
    JSON_UNDEFINED = -1, // invalid JSON object 

    JSON_NULL      =  0, // empty type
    JSON_OBJECT    =  1, // object type
    JSON_ARRAY     =  2, // array type

    JSON_BOOL      =  3, // bool
    JSON_INT       =  4, // int64_t
    JSON_DOUBLE    =  5, // double
    JSON_STRING    =  6, // char*
    JSON_RAW       =  7, // char*
} JSON_obj_type;

typedef struct JSON_obj {
    char* name;
    struct JSON_obj* next;

    union {
        int64_t value_int   ;
        double  value_double;
        char*   value_string;
        struct {
            struct JSON_obj* child_array     ;
            size_t           child_array_size;
        } value_array;
        struct {
            struct JSON_obj* child_first   ;
            struct JSON_obj* child_map     ;
            size_t           child_map_size;
        } value_object;
    };
    JSON_obj_type type;
} *JSON_obj;

#define JSON_obj_to(JSON_obj, type, default_value)                                        \
    _Generic( ((type)0)                                                                 , \
        bool              :               (bool)JSON_obj_to_int(JSON_obj, default_value), \
        signed char       :        (signed char)JSON_obj_to_int(JSON_obj, default_value), \
        signed short      :       (signed short)JSON_obj_to_int(JSON_obj, default_value), \
        signed int        :         (signed int)JSON_obj_to_int(JSON_obj, default_value), \
        signed long       :        (signed long)JSON_obj_to_int(JSON_obj, default_value), \
        signed long long  :                     JSON_obj_to_int(JSON_obj, default_value), \
        unsigned char     :      (unsigned char)JSON_obj_to_int(JSON_obj, default_value), \
        unsigned short    :     (unsigned short)JSON_obj_to_int(JSON_obj, default_value), \
        unsigned int      :       (unsigned int)JSON_obj_to_int(JSON_obj, default_value), \
        unsigned long     :      (unsigned long)JSON_obj_to_int(JSON_obj, default_value), \
        unsigned long long: (unsigned long long)JSON_obj_to_int(JSON_obj, default_value), \
        float             :           (float)JSON_obj_to_double(JSON_obj, default_value), \
        double            :                  JSON_obj_to_double(JSON_obj, default_value), \
        long double       :     (long double)JSON_obj_to_double(JSON_obj, default_value), \
        char*             :           (char*)JSON_obj_to_string(JSON_obj, default_value), \
        default:          : fprintf(stderr, "invalid JSON object type cast")              \
    )

JSON_obj* JSON_parse(char* src);