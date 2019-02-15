/*!==========================================================================
* \file
* - Program:       T9
* - File:          lowercase-converter.h
* - Created:       02/15/2019
* - Author:        Vitaly Bulganin
* - Description:
* - Comments:
*
-----------------------------------------------------------------------------
*
* - History:
*
===========================================================================*/
#pragma once
//-------------------------------------------------------------------------//
#ifndef __LOWAERCASE_CONVERTER_H_B8EFC63A_AA80_49E1_B186_901FA5344970__
#define __LOWAERCASE_CONVERTER_H_B8EFC63A_AA80_49E1_B186_901FA5344970__
//-------------------------------------------------------------------------//
#include "../common/convertable.h"
#include "../common/symbol-info.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace converter
    {
//-------------------------------------------------------------------------//
        class lowercase_converter : public common::convertable
        {
            friend class converter_factory;
            //!< Keeps a map of symbols.
            common::symbols_t symbols;
            //!< Constructor.
            lowercase_converter();

        public:
            /**
             * Destructor.
             * @throw None.
             */
            virtual ~lowercase_converter() noexcept = default;

            // Override methods.
        public:
            /**
             * Encodes a text into keypad numbers.
             * @param text [in] - A text.
             * @return A sequence of numbers which represents a text.
             */
            virtual auto encode(const std::string & text) const -> std::string override;

            /**
             * Decodes a sequence of numbers into a text.
             * @param numbers [in] - A sequence of numbers.
             * @return A text, which represents a sequence of numbers.
             */
            virtual auto decode(const std::string & numbers) const -> std::string override;
        };
//-------------------------------------------------------------------------//
    }; // namespace converter
}; // namespace exam
//-------------------------------------------------------------------------//
#endif //__LOWAERCASE_CONVERTER_H_B8EFC63A_AA80_49E1_B186_901FA5344970__
