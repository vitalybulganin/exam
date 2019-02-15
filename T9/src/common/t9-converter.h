//
// Created by bulganin-va on 14.02.19.
//

#ifndef T9_SPELLING_T9_CONVERTER_H
#define T9_SPELLING_T9_CONVERTER_H
#include "convertable.h"
namespace exam
{
    namespace common
    {
        class t9converter : public conertable
        {
        public:
            t9converter() = default;
            virtual ~t9converter() noexcept;

            // Override methods.
        public:
            /**
             * Encodes a text into keypad numbers.
             * @param text [in] - A text.
             * @return A sequence of numbers which represents a text.
             */
            virtual auto encode(const std::string & text) const -> std::string override;

            /**
             * Decodes a sequence of numbers into a text.
             * @param numbers [in] - A sequence of numbers.
             * @return A text, which represents a sequence of numbers.
             */
            virtual auto decode(const std::string & numbers) const -> std::string override;
        };
    }; // namespace common
}; // namespace exam
#endif //T9_SPELLING_T9_CONVERTER_H
