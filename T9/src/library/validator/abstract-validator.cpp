#include "abstract-validator.h"
namespace exam
{
    namespace validator
    {
//-------------------------------------------------------------------------//
        namespace
        {
            //!< Keeps a max size of cases.
            const long g_max_size = 100L;
            //!< Keeps a min size of cases.
            const long g_min_size = 1L;
            //!<
            auto is_number_valid(const std::string & number) -> bool
            {
                for (const auto & symbol : number)
                {
                    if (symbol == '-' || symbol == '+') { continue; }
                    if (isdigit(symbol) > 0) { return false; }
                }
                return true;
            }
        }; // namespace
//-------------------------------------------------------------------------//
        auto abstract_validator::validate(unsigned lineNo, const std::string & text) -> void
        {
            if (text.empty() != false) { throw (std::invalid_argument("No case found.")); }

            if (lineNo == 0)
            {
                if (is_number_valid(text) != true) { throw (std::invalid_argument("The number of cases value is invalid. It must be integer.")); }
                // Getting a count of cases.
                const auto size = atol(text.c_str());

                if (size < g_min_size) { throw (std::invalid_argument("The number of cases value is invalid. It must be positive.")); }
                if (size > g_max_size)
                {
                    throw (std::invalid_argument("The number of cases value is too large [" +
                                                 std::to_string(size) + "]. It must be in [" +
                                                 std::to_string(g_min_size) + ", " +
                                                 std::to_string(g_max_size) + "]."));
                }
            }
        }
//-------------------------------------------------------------------------//
    }; // namespace validator
}; // namespace exam
