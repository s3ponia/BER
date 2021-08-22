//
// Created by vyacheslav on 8/21/21.
//

#ifndef KAURI_UTIL_H
#define KAURI_UTIL_H

#include "Constants.h"
#include <cstdint>
#include <type_traits>

namespace KauriTask {
    template<std::size_t S, class T = std::uintmax_t, typename = std::enable_if_t<S < CHAR_BIT * sizeof(T)>>
    constexpr T pow_2 = ((T)1) << S;

    template<std::size_t S, class ValueType>
    struct Bits {
        static_assert(S < CHAR_BIT * sizeof(ValueType));
        using value_type = ValueType;

        Bits(const Bits&) = default;
        constexpr Bits(ValueType value) : value(value) {};
        ValueType value;

        constexpr operator ValueType() noexcept {
            return value & (pow_2<S> - 1);
        }

        constexpr Bits operator~() const noexcept {
            return ~value;
        }
    };
}

#endif //KAURI_UTIL_H
