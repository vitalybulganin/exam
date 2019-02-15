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

#include "../common/t9-converter.h"

namespace
{
    //!<
    using case_infos_t = std::vector<std::string>;
    //!< Parses a file.
    //@return A collection of test cases.
    auto parse(const std::string & fname) -> case_infos_t
    {
        size_t size = 0;
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
        std::getline(stream, line); //<TODO> Added validation value.
        // Getting a count of cases.
        size = atol(line.c_str());

        while (stream.eof() != true)
        {
            // Reading a case as a line.
            std::getline(stream, line); //<TODO> Added validation value.
            // Adding a case into collection.
            cases.push_back(line);
        }
        // Closing the handle.
        stream.close();

        if (cases.size() != size)
        {

        }
        return std::move(cases);
    }
}; // namespace

int main(int argc, char * argv[])
{
    try
    {
        unsigned caseNo = 0;
        exam::common::t9converter converter;
        // Getting input file.
        std::string fname = argv[1];
        // Parsing the file.
        auto cases = parse(argv[1]);

        for (const auto & cs : cases)
        {
            // Encoding a text into a sequence number.
            std::cout << "Case #" << ++caseNo << ": " << converter.encode(cs) << std::endl;
        }
        return 0;
    }
    catch (const std::exception & exc)
    {
        std::cerr << "[ERROR] " << exc.what() << std::endl;
    }
    return 1;
}