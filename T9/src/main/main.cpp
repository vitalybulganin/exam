/*!==========================================================================
 * \file
 *   Program:       t9-spelling
 *   File:          main.cpp
 *   Created:       02/12/2019
 *   Author:        Vitaly Bulganin
 *   Description:
 *   Comments:
 *
-----------------------------------------------------------------------------
 *
 * History:
 *
===========================================================================*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdexcept>
#include <vector>
//-------------------------------------------------------------------------//
#include "../library/converter/converter-factory.h"
#include "../library/validator/validator-factory.h"
//-------------------------------------------------------------------------//
#include "../library/parser/file-stream.h"
//-------------------------------------------------------------------------//
namespace
{
//-------------------------------------------------------------------------//
    using namespace exam::converter;
    using namespace exam::validator;
    //!< Prints usage.
    auto usage() -> void
    {
        std::cout << "Usage: t9-spelling <file name> <type>" << std::endl;
        std::cout << "\t<file name> - A file, which keeps a set of cases." << std::endl;
        std::cout << "\t<type> - A type of case, which must be one of the following value: small or large." << std::endl;
    }
//-------------------------------------------------------------------------//
}; // namespace
//-------------------------------------------------------------------------//
int main(int argc, char * argv[])
{
    try
    {
        if (argc < 3) { throw (std::invalid_argument("Too less input arguments.")); }
        if (strcmp(argv[2], "small") != 0 && strcmp(argv[2], "large") != 0) { throw (std::invalid_argument(std::string("Unsupported type of validator [") + argv[2] + "].")); }

        unsigned caseNo = 0;
        exam::parser::file_stream fstream(argv[1]);
        // Getting the instance of validator.
        auto validator = validator_factory::getValidator((strcmp(argv[2], "small") == 0) ? validator_factory::type::small : validator_factory::type::large);
        // Getting a converter.
        exam::common::converter_ptr_t converter = converter_factory::getConverter(converter_factory::converter_type::lowercase);
        // Parsing the file.
        fstream.parse([&converter, &validator](unsigned int lineNo, const std::string & line) -> bool {

            try
            {
                // Validating params.
                validator->validate(lineNo, line);

                if (lineNo > 1)
                {
                    // Encoding a text into a sequence number.
                    std::cout << "Case #" << lineNo - 1 << ": " << converter->encode(line) << std::endl;
                }
                return true;
            }
            catch (const std::exception & exc)
            {
                std::cerr << "[ERROR] " << exc.what() << std::endl;
            }
            return false;
        });
        return 0;
    }
    catch (const std::exception & exc)
    {
        std::cerr << "[ERROR] " << exc.what() << std::endl;
        // Printing usage.
        usage();
    }
    return 1;
}