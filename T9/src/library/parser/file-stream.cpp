#include "file-stream.h"
//-------------------------------------------------------------------------//
#include <sstream>
#include <cstring>
#include <stdexcept>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace parser
    {
//-------------------------------------------------------------------------//
        file_stream::file_stream(const std::string & fname) : fileName(fname), stream(fname.c_str())
        {
            if (this->stream.is_open() != true)
            {
                std::ostringstream buffer;

                buffer << "Error [" << strerror(errno) << " opening the file [" << fname << "].";
                throw (std::invalid_argument(buffer.str()));
            }
        }

        file_stream::~file_stream() noexcept
        {
            if (this->stream.is_open() != false) { this->stream.close(); }
        }

        void file_stream::parse(const fn_onread & onread)
        {
            if (this->stream.is_open() != true) { throw (std::invalid_argument("The stream is not opening correctly.")); }

            std::string line;
            unsigned int lineNo = 0U;

            while (stream.eof() != true)
            {
                // Reading a case as a line.
                std::getline(stream, line);
                // Informing about reading data.
                if (onread(lineNo++, line) != true) { return; }
            }
        }
//-------------------------------------------------------------------------//
    }; // namespace parser
}; // namespace exam
