/*******************************************************************************
 *  @file      core.h
 *  @brief     General types, macros, functions etc.
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef CORE_H_
#define CORE_H_

#pragma once

#pragma region --- INCLUDE ---

#pragma endregion

#pragma region --- MACRO ---

/**
 *  @def   UNUSED
 *  @brief mark parameter as unused
 *  @param variable - parameter
 */
#define UNUSED(variable) ((void)variable)

#pragma endregion

#pragma region --- TYPEDEF ---

typedef signed char   byte;
typedef unsigned char ubyte;

#pragma endregion

#pragma region --- MACRO ---

#ifdef __cplusplus
#define YSL_BEGIN_DECLS extern "C" {
#define YSL_END_DECLS }
#else
#define YSL_BEGIN_DECLS
#define YSL_END_DECLS
#endif

#if defined(_WIN32) || defined(_WIN64)
#   define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#   define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#if defined(_MSC_VER)
#define __FUNC__ __FUNCSIG__
#else
#define __FUNC__ __func__
#endif

#if defined(__GNUC__)
#   define YSL_LIKELY(x) __builtin_expect (!!(x), 1)
#   define YSL_UNLIKELY(x) __builtin_expect (!!(x), 0)
#else
#   define YSL_LIKELY(v) v
#   define YSL_UNLIKELY(v) v
#endif

#ifdef _MSC_VER
/* Microsoft Visual C */
#   ifdef YSL_STATIC
#       define YSL_API
#   elif defined(YSL_COMPILATION)
#       define YSL_API __declspec (dllexport)
#   else
#       define YSL_API __declspec (dllimport)
#   endif
#   define YSL_CALL __cdecl
#elif defined(__GNUC__) /* GCC */
#   ifdef YSL_STATIC
#       define YSL_API
#   elif defined(YSL_COMPILATION)
#       define YSL_API __attribute__ ((visibility ("default")))
#   else
#       define YSL_API
#   endif
#   define YSL_CALL
#else /* Other compilers */
#   define YSL_API
#   define YSL_CALL
#endif

#if defined(_MSC_VER)
#   define YSL_INLINE __inline
#else
#   define YSL_INLINE __inline__
#endif

#ifdef _MSC_VER
#   define YSL_TYPEOF(x) __typeof__(x)
#   define YSL_TYPEOF_UNQUAL(x) decltype
#else
#   define YSL_TYPEOF(x) typeof(x)
#   define YSL_TYPEOF_UNQUAL(x) typeof_unqual(x)
#endif

#if defined(__GNUC__)
#   define YSL_PURE __attribute__ ((pure))
#else
#   define YSL_PURE
#endif

#pragma endregion

#endif // !CORE_H_
