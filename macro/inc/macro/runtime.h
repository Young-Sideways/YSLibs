/*******************************************************************************
 *  @file      runtime.h
 *  @brief     MACRO runtime lib
 *  @author    Young Sideways
 *  @date      04.07.2024
 *  @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef M_RUNTIME_H_
#define M_RUNTIME_H_

#pragma once

#pragma region --- MACRO ---

#define M_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define M_MIN(x, y) (((x) < (y)) ? (x) : (y))

#define M_OFFSETOF(container_type, field) &(((container_type*)NULL)->field)

#define M_TERNAR(predicate, if_true, if_false) ((predicate) ? (if_true) : (if_false))
#define M_ISNULL(value, other) ((value) ? (value) : (other))

#pragma endregion

#endif // !M_RUNTIME_H_
