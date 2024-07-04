/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#include "macro/sequence.h"

// #define M_CHECK_N(x, n, ...) n
// #define M_CHECK(...) M_CHECK_N(__VA_ARGS__, 0, )
// #define M_PROBE(x) x, 1,
// 
// #define M_NOT(x) M_CHECK(M_CAT(M_NOT_, x))
// #define M_NOT_0 M_PROBE(~)
// 
// #define M_COMPL(x) M_CAT(M_COMPL_, x)
// #define M_COMPL_0 1
// #define M_COMPL_1 0
// 
// #define M_BOOL(x) M_COMPL(M_NOT(x))
// 
// #define M_IIF(cnd) M_CAT(M_IIF_, cnd)
// #define M_IIF_0(t, ...) __VA_ARGS__
// #define M_IIF_1(t, ...) t
// #define M_IF(c) M_IIF(M_BOOL(c))
// 
// 
// #define M_WHEN(cnd) M_IF(cnd)(M_EXPAND, M_EMPTY)
// 
// #define M_REPEAT(count, macro, ...) \
//     M_WHEN(count) \
//     ( \
//         M_OBSTRUCT(M_REPEAT_INDIRECT) () \
//         ( \
//             M_DEC(count), macro, __VA_ARGS__ \
//         ) \
//         M_OBSTRUCT(macro) \
//         ( \
//             M_DEC(count), __VA_ARGS__ \
//         ) \
//     )
// #define M_REPEAT_INDIRECT() M_REPEAT
// 
// //An example of using this macro
// #define M(i, _) i

int main(int argc, char** argv) {

    char arr[] = { M_SEQ_GEN(12, (;), 'a') };

    return 0;
}
