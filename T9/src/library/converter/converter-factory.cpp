#include "converter-factory.h"
//-------------------------------------------------------------------------//
#include <stdexcept>
//-------------------------------------------------------------------------//
#include "lowercase-converter.h"
//-------------------------------------------------------------------------//
namespace exam
{
    namespace converter
    {
//-------------------------------------------------------------------------//
        auto converter_factory::getConverter(const converter_type & type) -> common::converter_ptr_t
        {
            switch (type)
            {
                case converter_type::lowercase: { return common::converter_ptr_t(reinterpret_cast<common::convertable *>(new lowercase_converter())); }

                default: { throw (std::invalid_argument("Unknown type of converter.")); }
            }
        }
//-------------------------------------------------------------------------//
    }; // namespace converter
}; // namespace exam
