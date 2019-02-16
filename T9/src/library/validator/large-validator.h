/*!==========================================================================
* \file
* - Program:       T9
* - File:          large-validator.h
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
#ifndef __LARGE_VALIDATOR_H_A3FCCDA3_B537_4264_B6EF_9F972AEF798C__
#define __LARGE_VALIDATOR_H_A3FCCDA3_B537_4264_B6EF_9F972AEF798C__
//-------------------------------------------------------------------------//
#include "abstract-validator.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace validator
    {
//-------------------------------------------------------------------------//
        class large_validator : public abstract_validator
        {
            using base_class = abstract_validator;
            friend class validator_factory;

        public:
            /**
             * Destructor.
             * @throw None.
             */
            virtual ~large_validator() noexcept = default;

            /**
             * Validates a text.
             * @param lineNo [in] - A line number.
             * @param text [in] - A text.
             * @throw std::invalid_argument - A text is invalid.
             */
            virtual auto validate(unsigned lineNo, const std::string & text) -> void override;

        protected:
            //!< Constructor.
            large_validator() = default;
        };
//-------------------------------------------------------------------------//
    }; // namespace validator
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __LARGE_VALIDATOR_H_A3FCCDA3_B537_4264_B6EF_9F972AEF798C__
