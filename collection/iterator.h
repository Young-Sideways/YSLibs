/*******************************************************************************
 *  @file      iterator.h
 *  @brief     universal collection iterators
 *  @author    Young Sideways
 *  @date      15.02.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once

#pragma region --- INCLUDES ---

#include "general.h"

#pragma endregion

#pragma region --- MACROS ---
#pragma endregion

#pragma region --- TYPEDEFS ---
/**
 *  @enum  it_direction_t
 *  @brief Defines iterator bypass type
 */
typedef enum {
	IT_REVERSE = -1,
	IT_UNDEFINED = 0,
	IT_FORWARD = 1,
} it_direction_t;

/**
 *  @struct iterator_t
 *  @brief  Defines iterator structure
 */
typedef struct {
	struct collection_header* collection;
	byte* data;
	int stage;
	it_direction_t direction;
} iterator_t;

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - forward iterator to begining element
 */
iterator_t it_begin(_IN void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - forward iterator to memory block after last container element
 */
iterator_t it_end(_IN void* collection);

/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - reverse iterator to last element
 */
iterator_t it_rbegin(_IN void* collection);
/**
 *  @brief  reverse iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - reverse iterator to memory block before first container element
 */
iterator_t it_rend(_IN void* collection);

/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - forward iterator to first element
 */
iterator_t it_first(_IN void* collection);
/**
 *  @brief  forward iterator constructor
 *  @param[in] collection - collection, including valid base collection header
 *  @retval			      - forward iterator to last element
 */
iterator_t it_last(_IN void* collection);

/**
 *  @brief iterator destructor
 *  @param[in] iterator - valid iterator pointer
 */
void it_delete(_IN iterator_t* iterator);

#pragma endregion

#pragma region --- FUNCIONS ---

/**
 *  @brief     pointer to data block
 *  @param[in] iterator - valid iterator pointer
 *  @retval             - returns valid data pointer, otherwise @code{.c} NULL @endcode
 */
void* it_get(_IN iterator_t* iterator);
/**
 *  @brief shifts iterator to next data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_next(_IN iterator_t* iterator);
/**
 *  @brief shifts iterator to previous data block of container
 *  @param[in] iterator - valid iterator pointer
 */
void it_prev(_IN iterator_t* iterator);

/**
 *  @brief  compares @code lhs @endcode and @code rhs @endcode iterators
 *  @param[in]  lhs  - valid left iterator pointer
 *  @param[in]  rhs  - valid right iterator pointer
 *  @param[in]  size - unused
 *  @retval offset between lhs and rhs, othewise @code CONTAINER_INVALID_INDEX @endcode
 */
comparator_t it_comp;

#pragma endregion

#endif // !_ITERATOR_H_
