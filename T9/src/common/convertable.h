//
// Created by bulganin-va on 14.02.19.
//

#ifndef T9_SPELLING_CONVERTABLE_H
#define T9_SPELLING_CONVERTABLE_H
#include <string>
namespace exam
{
    namespace common
    {
        struct conertable
        {
            /**
             * Encodes a text into keypad numbers.
             * @param text [in] - A text.
             * @return A sequence of numbers which represents a text.
             */
            virtual auto encode(const std::string & text) const -> std::string = 0;

            /**
             * Decodes a sequence of numbers into a text.
             * @param numbers [in] - A sequence of numbers.
             * @return A text, which represents a sequence of numbers.
             */
            virtual auto decode(const std::string & numbers) const -> std::string = 0;
        };
    }
}
#endif //T9_SPELLING_CONVERTABLE_H
