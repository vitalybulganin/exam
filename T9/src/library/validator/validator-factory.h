/*!==========================================================================
* \file
* - Program:       T9
* - File:          validator-factory.h
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
#ifndef __VALIDATOR_FACTORY_H_40A384AC_0AD4_4104_8929_7DF0AA618FDB__
#define __VALIDATOR_FACTORY_H_40A384AC_0AD4_4104_8929_7DF0AA618FDB__
//-------------------------------------------------------------------------//
#include "../common/validatable.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace validator
    {
//-------------------------------------------------------------------------//
        class validator_factory final
        {
        public:
            //!< Supported type of validator.
            enum class type {small = 1, large = 2};

        public:
            /**
             * Gets the instance of validator by its type.
             * @param type [in] - A type of validator.
             * @return The instance of validator.
             */
            static auto getValidator(const validator_factory::type & type) -> common::validator_ptr_t;
        };
//-------------------------------------------------------------------------//
    }; // namespace validator
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __VALIDATOR_FACTORY_H_40A384AC_0AD4_4104_8929_7DF0AA618FDB__
