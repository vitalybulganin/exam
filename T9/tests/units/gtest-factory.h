/*!==========================================================================
* \file
* - Program:       gtest-t9
* - File:          gtest-factory.h
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
#ifndef __GTEST_FACTORY_H_105019C6_FE2F_40B3_B7E8_0537308C1EFD__
#define __GTEST_FACTORY_H_105019C6_FE2F_40B3_B7E8_0537308C1EFD__
//-------------------------------------------------------------------------//
#include <fstream>
#include <stdexcept>
//-------------------------------------------------------------------------//
#include <gtest/gtest.h>
//-------------------------------------------------------------------------//
#include "../../src/library/converter/converter-factory.h"
//-------------------------------------------------------------------------//
TEST(TestT9, factoryBuild)
{
    EXPECT_NO_THROW(exam::converter::converter_factory::getConverter(exam::converter::converter_factory::converter_type::lowercase));
    EXPECT_TRUE(exam::converter::converter_factory::getConverter(exam::converter::converter_factory::converter_type::lowercase) != nullptr);
}
//-------------------------------------------------------------------------//
#endif // __GTEST_FACTORY_H_105019C6_FE2F_40B3_B7E8_0537308C1EFD__
