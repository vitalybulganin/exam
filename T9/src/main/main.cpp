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
//-------------------------------------------------------------------------//
namespace
{
//-------------------------------------------------------------------------//
    using namespace exam::converter;
    //!<
    enum class dataset_type {small = 1, large = 2};
    //!<
    using case_infos_t = std::vector<std::string>;
    //!<
    auto is_number_valid(const std::string & number) -> bool
    {
        for (const auto & symbol : number)
        {
            if (symbol == '-' || symbol == '+') { continue; }
            if (isdigit(symbol) != 1) { return false; }
        }
        return true;
    }
    //!< Parses a file.
    //@return A collection of test cases.
    auto parse(const std::string & fname, const dataset_type & type) -> case_infos_t
    {
        long size = 0L;
        std::string line;
        case_infos_t cases;
        std::ifstream stream(fname.c_str());

        if (stream.is_open() != true)
        {
            std::ostringstream buffer;

            buffer << "Error [" << strerror(errno) << "] opening the following file [" << fname << "].";
            throw (std::invalid_argument(buffer.str()));
        }
        // Reading a number of cases.
        std::getline(stream, line);

        if (line.empty() != false) { throw (std::invalid_argument("No a number of cases found in the file [" + fname + "].")); }
        if (is_number_valid(line) != true) { throw (std::invalid_argument("The number of cases value is invalid. It must be integer.")); }
        // Getting a count of cases.
        size = atol(line.c_str());

        if (size < 0) { throw (std::invalid_argument("The number of cases value is invalid. It must be positive.")); }
        if (size > 0 && size > 100) { throw (std::invalid_argument("The number of cases value is too large [" + std::to_string(size) + "]. It must be in [1, 100].")); }

        while (size > 0 && stream.eof() != true)
        {
            // Reading a case as a line.
            std::getline(stream, line);

            if (line.empty() != false) { throw (std::invalid_argument("Invalid format structure in the file [" + fname + "]. The line is empty.")); }
            if (type == dataset_type::small && line.length() > 15) { throw (std::invalid_argument("The length of message is too large [" + std::to_string(line.length()) + "], but must be in [1, 15].")); }
            if (type == dataset_type::large && line.length() > 1000) { throw (std::invalid_argument("The length of message is too large [" + std::to_string(line.length()) + "], but must be in [1, 1000].")); }
            // Adding a case into collection.
            cases.push_back(line);
        }
        // Closing the handle.
        stream.close(); //<TODO> Adding closing the file handle including exception raised.

        if (cases.size() != size) { throw std::invalid_argument("A count of cases is too large [" + std::to_string(cases.size()) + "], but expected only [" + std::to_string(size) + "]."); }

        return std::move(cases);
    }
//-------------------------------------------------------------------------//
}; // namespace
//-------------------------------------------------------------------------//
int main(int argc, char * argv[])
{
    try
    {
        unsigned caseNo = 0;
        // Getting input file.
        std::string fname = argv[1];
        // Parsing the file.
        auto cases = parse(argv[1], dataset_type::small);
        // Getting a converter.
        exam::common::converter_ptr_t converter = converter_factory::getConverter(converter_factory::converter_type::lowercase);

        for (const auto & cs : cases)
        {
            // Encoding a text into a sequence number.
            std::cout << "Case #" << ++caseNo << ": " << converter->encode(cs) << std::endl;
        }
        return 0;
    }
    catch (const std::exception & exc)
    {
        std::cerr << "[ERROR] " << exc.what() << std::endl;
    }
    return 1;
}