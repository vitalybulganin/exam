/*!==========================================================================
* \file
* - Program:       T9
* - File:          convertable.h
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
#ifndef __CONVERTABLE_H_D5133431_8119_4308_9667_67BA23A41C58__
#define __CONVERTABLE_H_D5133431_8119_4308_9667_67BA23A41C58__
//-------------------------------------------------------------------------//
#include <string>
#include <memory>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace common
    {
//-------------------------------------------------------------------------//
        struct convertable
        {
            /**
             * Encodes a text into keypad numbers.
             * @param text [in] - A text.
             * @return A sequence of numbers which represents a text.
             */
            virtual auto encode(const std::string & text) const -> std::string = 0;

            /**
             * Decodes a sequence of numbers into a text.
             * @param numbers [in] - A sequence of numbers.
             * @return A text, which represents a sequence of numbers.
             */
            virtual auto decode(const std::string & numbers) const -> std::string = 0;
        };
//-------------------------------------------------------------------------//
        //!<
        using converter_ptr_t = std::shared_ptr<convertable>;
//-------------------------------------------------------------------------//
    }; // namespace common
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __CONVERTABLE_H_D5133431_8119_4308_9667_67BA23A41C58__
