/*******************************************************************************
 *  @file      private.h
 *  @brief     collections private members definition
 *  @note      only for internal use
 *  @author    Young Sideways
 *  @date      10.04.2024
 *  @copyright © Young Sideways, 2024. All right reserved.
 ******************************************************************************/

#ifndef _COLLECTION_PRIVATE_H_
#define _COLLECTION_PRIVATE_H_

#pragma once

#pragma region --- INCLUDES ---
#pragma endregion

#pragma region --- MACROS ---

#ifdef _COMPARATOR_H_
#define PRIVATE_COMPARATOR(collection) (comparator_pt)(collection->_comp)
#endif // !_COMPARATOR_H_

#ifdef _SEARCH_H_
#define PRIVATE_SEARCH(collection) (comparator_pt)(collection->_search)
#endif // !_SEARCH_H_

#ifdef _SWAP_H_
#define PRIVATE_SWAP(collection) (comparator_pt)(collection->_swap)
#endif // !_SWAP_H_

#ifdef _SORT_H_
#define PRIVATE_SORT(collection) (comparator_pt)(collection->_sort)
#endif // !_SORT_H_

#pragma endregion

#endif // !_COLLECTION_PRIVATE_H_
