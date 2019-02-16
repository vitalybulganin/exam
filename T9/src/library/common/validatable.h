/*!==========================================================================
* \file
* - Program:       T9
* - File:          validatable.h
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
#ifndef __VALIDATABLE_H_D41A3969_CEF1_47A7_9038_28631081EBFA__
#define __VALIDATABLE_H_D41A3969_CEF1_47A7_9038_28631081EBFA__
//-------------------------------------------------------------------------//
#include <string>
#include <memory>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace common
    {
//-------------------------------------------------------------------------//
        struct validatable
        {
            /**
             * Validates a text.
             * @param lineNo [in] - A line number.
             * @param text [in] - A text.
             * @throw std::invalid_argument - A text is invalid.
             */
            virtual auto validate(unsigned lineNo, const std::string & text) -> void = 0;
        };
        //!<
        using validator_ptr_t = std::shared_ptr<validatable>;
//-------------------------------------------------------------------------//
    }; // namespace common
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __VALIDATABLE_H_D41A3969_CEF1_47A7_9038_28631081EBFA__
