/*!==========================================================================
* \file
* - Program:       T9
* - File:          small-validator.h
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
#ifndef __SMALL_VALIDATOR_H_C050130C_E2FB_43EB_ACEC_5B03D490D6AD__
#define __SMALL_VALIDATOR_H_C050130C_E2FB_43EB_ACEC_5B03D490D6AD__
//-------------------------------------------------------------------------//
#include "abstract-validator.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace validator
    {
//-------------------------------------------------------------------------//
        class small_validator : public abstract_validator
        {
            using base_class = abstract_validator;
            friend class validator_factory;

        public:
            /**
             * Destructor.
             * @throw None.
             */
            virtual ~small_validator() noexcept = default;

            /**
             * Validates a text.
             * @param lineNo [in] - A line number.
             * @param text [in] - A text.
             * @throw std::invalid_argument - A text is invalid.
             */
            virtual auto validate(unsigned lineNo, const std::string & text) -> void override;

        protected:
            //!< Constructor.
            small_validator() = default;
        };
//-------------------------------------------------------------------------//
    }; // namespace validator
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __SMALL_VALIDATOR_H_C050130C_E2FB_43EB_ACEC_5B03D490D6AD__
