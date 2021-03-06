#include "large-validator.h"

namespace exam
{
    namespace validator
    {
        auto large_validator::validate(unsigned lineNo, const std::string & text) -> void
        {
            base_class::validate(lineNo, text);

            if (lineNo > 0)
            {
                if (text.empty() != false) { throw (std::invalid_argument("Invalid format structure. The line is empty.")); }
                if (text.length() > 1000) { throw (std::invalid_argument("The length of message is too large [" + std::to_string(text.length()) + "] in the case [" + std::to_string(lineNo) + "], but must be in [1, 1000].")); }
            }
        }
    }; // namespace validator
}; // namespace exam
