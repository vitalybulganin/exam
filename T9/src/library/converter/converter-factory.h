/*!==========================================================================
* \file
* - Program:       T9
* - File:          converter-factory.h
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
#ifndef __CONVERTER_FACTORY_H_2FDF9D2B_E118_418A_B17D_74D419EBEBDA__
#define __CONVERTER_FACTORY_H_2FDF9D2B_E118_418A_B17D_74D419EBEBDA__
//-------------------------------------------------------------------------//
#include "../common/convertable.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace converter
    {
//-------------------------------------------------------------------------//
        class converter_factory final
        {
        public:
            //!< Supported type of converters.
            enum class converter_type {lowercase = 1};

            /**
             * Gets the instance of converter by its type.
             * @param type
             * @return
             */
            static auto getConverter(const converter_type & type) -> common::converter_ptr_t;
        };
//-------------------------------------------------------------------------//
    }; // namespace converter
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __CONVERTER_FACTORY_H_2FDF9D2B_E118_418A_B17D_74D419EBEBDA__
