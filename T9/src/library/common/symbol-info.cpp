#include "symbol-info.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace common
    {
//-------------------------------------------------------------------------//
        symbol_info_t::symbol_info_t(unsigned char key, unsigned char lcount) : keypad(key), count(lcount)
        {
        }
//-------------------------------------------------------------------------//
        std::ostream & operator<<(std::ostream & stream, const symbol_info_t & symbol)
        {
            return stream;
        }

        std::ostream & operator<<(std::ostream & stream, const symbols_t & symbols)
        {
            return stream;
        }
//-------------------------------------------------------------------------//
    }; // namespace common
}; // namespace exam
