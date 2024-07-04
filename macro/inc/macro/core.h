/*******************************************************************************
 *  @file      core.h
 *  @brief     MACRO core lib
 *  @author    Young Sideways
 *  @date      29.03.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_CORE_H_
#define M_CORE_H_

#pragma once

#pragma region --- MACRO ---

#define M_STR(var)   #var
#define VA_STR(...) #__VA_ARGS__

#define M_CAT(a, b) a##b
#define VA_CAT(var, ...) var##__VA_ARGS__

#define M_COMMA() ,
#define M_SEMI()  ;
#define M_COLON() :
#define M_DOT()   .

#define M_LPAREN()    (
#define M_RPAREN()    )
#define M_PAREN(...) (__VA_ARGS__)

#define M_LBRACK()   [
#define M_RBRACK()   ]
#define M_BRACK(...) [__VA_ARGS__]

#define M_LBRACE()    {
#define M_RBRACE()    }
#define M_BRACE(...)  {__VA_ARGS__}

#define M_EVAL(...)  M_EVAL1(M_EVAL1(M_EVAL1(M_EVAL1(__VA_ARGS__))))
#define M_EVAL1(...) M_EVAL2(M_EVAL2(M_EVAL2(M_EVAL2(__VA_ARGS__))))
#define M_EVAL2(...) M_EVAL3(M_EVAL3(M_EVAL3(M_EVAL3(__VA_ARGS__))))
#define M_EVAL3(...) M_EVAL4(M_EVAL4(M_EVAL4(M_EVAL4(__VA_ARGS__))))
#define M_EVAL4(...) __VA_ARGS__

#define M_EMPTY(...)
#define M_DEFER(...)    __VA_ARGS__ M_EMPTY()
#define M_OBSTRUCT(...) __VA_ARGS__ M_DEFER(M_EMPTY)()
#define M_EXPAND(...)   __VA_ARGS__

#endif // !M_CORE_H_
