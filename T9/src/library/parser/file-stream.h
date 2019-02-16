/*!==========================================================================
* \file
* - Program:       T9
* - File:          file-stream.h
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
#ifndef __FILE_STREAM_H_47805041_45E0_4825_9DB1_804E9D2FEF03__
#define __FILE_STREAM_H_47805041_45E0_4825_9DB1_804E9D2FEF03__
//-------------------------------------------------------------------------//
#include <string>
#include <fstream>
#include <functional>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace parser
    {
//-------------------------------------------------------------------------//
        using fn_onread = std::function<bool(unsigned lineNo, const std::string & unit)>;
//-------------------------------------------------------------------------//
        class file_stream
        {
            //!< Keeps a name of file.
            const std::string fileName;
            //!< Keeps a stream.
            std::ifstream stream;

        public:
            file_stream(const file_stream &) = delete;
            file_stream(const file_stream &&) = delete;
            file_stream & operator=(const file_stream &) = delete;

        public:
            /**
             * Constructor.
             * @param fname [in] - A name of file.
             */
            file_stream(const std::string & fname);

            /**
             * Destructor.
             * @throw None.
             */
            virtual ~file_stream() noexcept;

            /**
             * Parses a file.
             * @param onread [in] - A callback function on success.
             */
            void parse(const fn_onread & onread);
        };
//-------------------------------------------------------------------------//
    }; // namespace parser
}; // namespace exam
//-------------------------------------------------------------------------//
#endif // __FILE_STREAM_H_47805041_45E0_4825_9DB1_804E9D2FEF03__
