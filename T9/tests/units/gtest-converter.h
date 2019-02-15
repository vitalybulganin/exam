/*!==========================================================================
* \file
* - Program:       gtest-t9
* - File:          gtest-converter.h
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
#ifndef __GTEST_CONVERTER_H_A3CFE15C_F664_4134_991E_27844C1A9BC4__
#define __GTEST_CONVERTER_H_A3CFE15C_F664_4134_991E_27844C1A9BC4__
//-------------------------------------------------------------------------//
#include <fstream>
#include <stdexcept>
//-------------------------------------------------------------------------//
#include <gtest/gtest.h>
//-------------------------------------------------------------------------//
#include <mtc/wcsstr.h>
//-------------------------------------------------------------------------//
#include "../../src/library/converter/converter-factory.h"
//-------------------------------------------------------------------------//
TEST(TestT9, lowercaseConverter)
{
    exam::common::converter_ptr_t converter = exam::converter::converter_factory::getConverter(exam::converter::converter_factory::converter_type::lowercase);

    EXPECT_TRUE(converter != nullptr);
    EXPECT_TRUE(converter->encode("hi") == "44 444");
    EXPECT_TRUE(converter->encode("yes") == "999337777");
    EXPECT_TRUE(converter->encode("hello world") == "4433555 555666096667775553");
}
//-------------------------------------------------------------------------//
#endif // __GTEST_CONVERTER_H_A3CFE15C_F664_4134_991E_27844C1A9BC4__
