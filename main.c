/*******************************************************************************
 *  @file      main.c
 *  @brief     main file of project
 *  @author    Young Sideways
 *  @date      23.05.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

// #include "macro/sequence.h"
#define M_DEC_0 0
#define M_DEC_1 0
#define M_DEC_2 1
#define M_DEC_3 2
#define M_DEC_4 3
#define M_DEC_5 4
#define M_DEC_6 5
#define M_DEC_7 6
#define M_DEC_8 7
#define M_DEC_9 8
#define M_DEC_10 9
#define M_DEC_11 10
#define M_DEC_12 11
#define M_DEC_13 12
#define M_DEC_14 13
#define M_DEC_15 14
#define M_DEC_16 15
#define M_DEC_17 16
#define M_DEC_18 17
#define M_DEC_19 18

#define M_DEC(i) M_CAT(M_DEC_, i)

#define M_CAT(a, b) a##b
#define VA_CAT(var, ...) var##__VA_ARGS__

#define M_EVAL(...)  M_EVAL1(M_EVAL1(M_EVAL1(M_EVAL1(__VA_ARGS__))))
#define M_EVAL1(...) M_EVAL2(M_EVAL2(M_EVAL2(M_EVAL2(__VA_ARGS__))))
#define M_EVAL2(...) M_EVAL3(M_EVAL3(M_EVAL3(M_EVAL3(__VA_ARGS__))))
#define M_EVAL3(...) M_EVAL4(M_EVAL4(M_EVAL4(M_EVAL4(__VA_ARGS__))))
#define M_EVAL4(...) __VA_ARGS__

#define M_COMMA() ,

#define M_EMPTY(...)
#define M_DEFER(var) var M_EMPTY()
#define M_OBSTRUCT(var) var M_DEFER(M_EMPTY)()
#define M_EXPAND(var) var
#define VA_DEFER(...) __VA_ARGS__ M_EMPTY()
#define VA_OBSTRUCT(...) __VA_ARGS__ M_DEFER(M_EMPTY)()
#define VA_EXPAND(...) __VA_ARGS__

#define M_CHECK_N(x, n, ...) n
#define M_CHECK(...) M_CHECK_N(__VA_ARGS__, 0, )
#define M_PROBE(x) x, 1,

#define M_NOT(x) M_CHECK(M_CAT(M_NOT_, x))
#define M_NOT_0 M_PROBE(~)

#define M_COMPL(x) M_CAT(M_COMPL_, x)
#define M_COMPL_0 1
#define M_COMPL_1 0

#define M_BOOL(x) M_COMPL(M_NOT(x))

#define M_IIF(cnd) M_CAT(M_IIF_, cnd)
#define M_IIF_0(t, ...) __VA_ARGS__
#define M_IIF_1(t, ...) t
#define M_IF(c) M_IIF(M_BOOL(c))

#define M_PARENS() ()

#define M_WHEN(cnd) M_IF(cnd)(VA_EXPAND, M_EMPTY)
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


#define M_SEQ_GEN_HELPER1() M_SEQ_GEN_HELPER
#define M_SEQ_GEN_HELPER(n, var) M_WHEN(n)(var M_IF(M_DEC(n))(M_COMMA()) M_OBSTRUCT(M_SEQ_GEN_HELPER1)()(M_DEC(n), var))
#define M_SEQ_GEN(n, var) M_EVAL(M_SEQ_GEN_HELPER(n, var))

int main(int argc, char** argv) {

    int a1[] = { M_SEQ_GEN(16, 1) };

    return 0;
}
