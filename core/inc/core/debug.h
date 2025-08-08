/*******************************************************************************
 *  @file      debug.h
 *  @brief     debug module helps debug your code
 *  @author    Young Sideways
 *  @date      18.04.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef DEBUG_H_
#define DEBUG_H_


#include <assert.h>


#ifdef NDEBUG
    #define explain_assert(expression, msg) ((void)0)
    #define explain_error(msg) ((void)0)
#else
    #define explain_assert(expression, msg) assert((expression) && msg)
    #define explain_error(msg) explain_assert(0, msg)
#endif 


#endif // !DEBUG_H_
