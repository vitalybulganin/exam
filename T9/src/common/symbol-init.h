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
#ifndef T9_SPELLING_SYMBOL_INIT_H
#define T9_SPELLING_SYMBOL_INIT_H
//-------------------------------------------------------------------------//
#include "symbol-info.h"
//-------------------------------------------------------------------------//
namespace exam
{
//-------------------------------------------------------------------------//
    class symbol_init final
    {
        //!< Keeps a map of symbols.
        symbols_t symbols;

    public:
        /**
         * Constructor.
         */
        symbol_init();

        /**
         *
         * @return
         */
        auto getSymbols() const noexcept -> const symbols_t &;
    };
//-------------------------------------------------------------------------//
}; // namespace exam
//-------------------------------------------------------------------------//
#endif //T9_SPELLING_SYMBOL_INIT_H
