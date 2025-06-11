/*******************************************************************************
 * @file      method.h
 * @author    Young Sideways
 * @brief     Commmon RPC method definition
 * @date      07.05.2025
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef RPC_METHOD_H_
#define RPC_METHOD_H_

#pragma once

#pragma region --- INCLUDE ---

#pragma endregion

#pragma region --- MACRO ---

#pragma endregion

#pragma region --- TYPEDEF ---

typedef const struct RPC_method {
    const char* name;
} RPC_method_t;

#define RPC_DECLARE_METHOD(foo, ret, ... /* params */) \
    const struct { \
        const char* name; \
        RPC_param_t retval; \
        RPC_param_t params[VA_NARG(__VA_ARGS__)]; \
    } RPC_method_##foo##_ = { \
        #foo, \
        RPC_UNIFORM_PARAM ret, \
        { VA_EXEC(RPC_TRANSLATE_PARAMS(__VA_ARGS__)) }; \
    };

#pragma endregion

#pragma region --- CONSTRUCTOR/DESTRUCTOR ---

#pragma endregion

#pragma region --- FUNCTION ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#pragma region ---  ---

#pragma endregion

#endif // !RPC_METHOD_H_
