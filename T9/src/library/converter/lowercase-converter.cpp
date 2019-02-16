#include "lowercase-converter.h"
//-------------------------------------------------------------------------//
#include <sstream>
//-------------------------------------------------------------------------//
namespace exam
{
    namespace converter
    {
//-------------------------------------------------------------------------//
        namespace
        {
            auto to_symbol_count(unsigned char number, unsigned char count) -> std::string
            {
                std::ostringstream buffer;

                for (char i = 0; i < count; ++i) { buffer << std::to_string(number); }
                return buffer.str();
            }
        }; // namespace
//-------------------------------------------------------------------------//
        auto lowercase_converter::encode(const std::string & text) const -> std::string
        {
            unsigned char prev_key = -1;
            std::ostringstream buffer;

            for (const auto & symbol : text)
            {
                common::symbols_t::const_iterator citer = this->symbols.find(symbol);

                if (citer == this->symbols.end()) { throw (std::invalid_argument(std::string("Unsupported symbol [") + symbol + "].")); }
                //
                if (prev_key == (*citer).second.keypad) { buffer << ' '; }
                buffer << to_symbol_count((*citer).second.keypad, (*citer).second.count);
                // Saving key pad.
                prev_key = (*citer).second.keypad;
            }
            return buffer.str();
        }

        auto lowercase_converter::decode(const std::string & numbers) const -> std::string
        {
            return "";
        }
//-------------------------------------------------------------------------//
        lowercase_converter::lowercase_converter()
        {
            this->symbols.insert(common::symbols_t::value_type('a', {2, 1}));
            this->symbols.insert(common::symbols_t::value_type('b', {2, 2}));
            this->symbols.insert(common::symbols_t::value_type('c', {2, 3}));
            this->symbols.insert(common::symbols_t::value_type('d', {3, 1}));
            this->symbols.insert(common::symbols_t::value_type('e', {3, 2}));
            this->symbols.insert(common::symbols_t::value_type('f', {3, 3}));
            this->symbols.insert(common::symbols_t::value_type('g', {4, 1}));
            this->symbols.insert(common::symbols_t::value_type('h', {4, 2}));
            this->symbols.insert(common::symbols_t::value_type('i', {4, 3}));
            this->symbols.insert(common::symbols_t::value_type('j', {5, 1}));
            this->symbols.insert(common::symbols_t::value_type('k', {5, 2}));
            this->symbols.insert(common::symbols_t::value_type('l', {5, 3}));
            this->symbols.insert(common::symbols_t::value_type('m', {6, 1}));
            this->symbols.insert(common::symbols_t::value_type('n', {6, 2}));
            this->symbols.insert(common::symbols_t::value_type('o', {6, 3}));
            this->symbols.insert(common::symbols_t::value_type('p', {7, 1}));
            this->symbols.insert(common::symbols_t::value_type('q', {7, 2}));
            this->symbols.insert(common::symbols_t::value_type('r', {7, 3}));
            this->symbols.insert(common::symbols_t::value_type('s', {7, 4}));
            this->symbols.insert(common::symbols_t::value_type('t', {8, 1}));
            this->symbols.insert(common::symbols_t::value_type('u', {8, 2}));
            this->symbols.insert(common::symbols_t::value_type('v', {8, 3}));
            this->symbols.insert(common::symbols_t::value_type('w', {9, 1}));
            this->symbols.insert(common::symbols_t::value_type('x', {9, 2}));
            this->symbols.insert(common::symbols_t::value_type('y', {9, 3}));
            this->symbols.insert(common::symbols_t::value_type('z', {9, 4}));
            this->symbols.insert(common::symbols_t::value_type(' ', {0, 1}));
        }
//-------------------------------------------------------------------------//
    }; // namespace converter
}; // namespace exam
