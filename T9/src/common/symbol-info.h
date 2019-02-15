/*!==========================================================================
 * \file
 *   Program:       t9-spelling
 *   File:          symbol-info.h
 *   Created:       02/12/2019
 *   Author:        Vitaly Bulganin
 *   Description:
 *   Comments:
 *
-----------------------------------------------------------------------------
 *
 * History:
 *
===========================================================================*/
#pragma once
//-------------------------------------------------------------------------//
#ifndef __SYMBOL_INFO_H_AAC69A9B_D5AC_4681_8D18_B9BFC91A7DD7__
#define __SYMBOL_INFO_H_AAC69A9B_D5AC_4681_8D18_B9BFC91A7DD7__
//-------------------------------------------------------------------------//
#include <map>
#include <ostream>
//-------------------------------------------------------------------------//
namespace exam
{
//-------------------------------------------------------------------------//
    //!<
    struct symbol_info_t
    {
        //!< Keeps a keypad number.
        unsigned char keypad = 0;
        //!< Keeps a count of number.
        unsigned char count = 0;
    };
    //!< Keeps a map of symbol and symbol info.
    using symbols_t = std::map<char, symbol_info_t>;
//-------------------------------------------------------------------------//
    std::ostream & operator<<(std::ostream & stream, stream, const symbol_info_t & symbol);
    std::ostream & operator<<(std::ostream & stream, stream, const symbols_t & symbols);
//-------------------------------------------------------------------------//
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __SYMBOL_INFO_H_AAC69A9B_D5AC_4681_8D18_B9BFC91A7DD7__
