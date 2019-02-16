#include "validator-factory.h"

#include "small-validator.h"
#include "large-validator.h"

namespace exam
{
    namespace validator
    {
        auto validator_factory::getValidator(const validator_factory::type & type) -> common::validator_ptr_t
        {
            if (type == validator_factory::type::small) { return common::validator_ptr_t(reinterpret_cast<common::validatable *>(new small_validator())); }
            else if (type == validator_factory::type::large) { return common::validator_ptr_t(reinterpret_cast<common::validatable *>(new large_validator())); }

            throw (std::invalid_argument("Unsupported type of validator [" + std::to_string(int(type)) + "]."));
        }
    }; // namespace validator
}; // namespace exam
