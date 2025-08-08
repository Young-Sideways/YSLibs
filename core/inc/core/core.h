/*******************************************************************************
 *  @file      core.h
 *  @brief     General types, macros, functions etc.
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef CORE_H_
#define CORE_H_


/**
 *  @def   YSL_UNUSED
 *  @brief mark parameter as unused
 *  @param variable - parameter
 */
#define YSL_UNUSED(variable) ((void)variable)


#ifdef __cplusplus
#   define YSL_BEGIN_DECLS extern "C" {
#   define YSL_END_DECLS }
#   define YSL_AUTO auto
#else
#   define YSL_BEGIN_DECLS
#   define YSL_END_DECLS
#   define YSL_AUTO __auto_type
#endif


#if defined(_MSC_VER) /* Microsoft Visual C */
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

#if defined(_MSC_VER) /* Microsoft Visual C */

#   define __FUNC__ __FUNCSIG__

#   define YSL_INLINE __inline
#   define YSL_ALWAYS_INLINE __forceinline

#   define YSL_LIKELY(v) v
#   define YSL_UNLIKELY(v) v

#   define YSL_TYPEOF(x) __typeof__(x)
#   define YSL_TYPEOF_UNQUAL(x) __typeof_unqual__(x)

#   define YSL_PURE __declspec( naked )

#elif defined(__GNUC__) /* GCC / Clang */

#   define __FUNC__ __func__

#   define YSL_INLINE __inline__
#   define YSL_ALWAYS_INLINE __attribute__((always_inline)) YSL_INLINE

#   define YSL_LIKELY(x) __builtin_expect (!!(x), 1)
#   define YSL_UNLIKELY(x) __builtin_expect (!!(x), 0)

#   define YSL_TYPEOF(x) typeof(x)
#   define YSL_TYPEOF_UNQUAL(x) typeof_unqual(x)

#   define YSL_PURE __attribute__ ((pure))

#else /* Other compilers */

#   define __FUNC__ __func__

#   define YSL_INLINE inline
#   define YSL_ALWAYS_INLINE YSL_INLINE

#   define YSL_LIKELY(v) v
#   define YSL_UNLIKELY(v) v

#   define YSL_TYPEOF(x) typeof(x)
#   define YSL_TYPEOF_UNQUAL(x) typeof_unqual(x)

#   define YSL_PURE

#endif

#if defined(YSL_CORE_SELFIMPL)

    static char* __ysl_strrchr_impl(const char* string, int symbol) {
        char* last = NULL;

        if ( YSL_LIKELY(string != NULL) )
            for (; *string != '\0'; string++)
                if (*string == symbol)
                    last = (char*)string;
        
        return (char*)last;
    }

#   if defined(_WIN32) || defined(_WIN64)
#       define __FILENAME__ (__ysl_strrchr_impl(__FILE__, '\\') ? (__ysl_strrchr_impl(__FILE__, '\\') + 1) : __FILE__)
#   else
#       define __FILENAME__ (__ysl_strrchr_impl(__FILE__, '/') ? (__ysl_strrchr_impl(__FILE__, '/') + 1) : __FILE__)
#   endif

#else

#   include <string.h>

#   if defined(_WIN32) || defined(_WIN64)
#       define __FILENAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1) : __FILE__)
#   else
#       define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1) : __FILE__)
#   endif

#endif

#endif // !CORE_H_
