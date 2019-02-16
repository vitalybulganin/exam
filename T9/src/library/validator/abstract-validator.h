/*!==========================================================================
* \file
* - Program:       T9
* - File:          abstract-validator.h
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
#ifndef T9_SPELLING_ABSTRACT_VALIDATOR_H
#define T9_SPELLING_ABSTRACT_VALIDATOR_H
//-------------------------------------------------------------------------//
#include <src/library/common/validatable.h>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace validator
    {
//-------------------------------------------------------------------------//
        class abstract_validator : public common::validatable
        {
        public:
            /**
             * Validates a text.
             * @param lineNo [in] - A line number.
             * @param text [in] - A text.
             * @throw std::invalid_argument - A text is invalid.
             */
            virtual auto validate(unsigned lineNo, const std::string & text) -> void override;
        };
//-------------------------------------------------------------------------//
    }; // namespace validator
}; // namespace exam
//-------------------------------------------------------------------------//
#endif //T9_SPELLING_ABSTRACT_VALIDATOR_H
