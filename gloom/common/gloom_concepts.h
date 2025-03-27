#ifndef GLOOM_CONCEPTS_H
#define GLOOM_CONCEPTS_H

#include <concepts>
#include <utility>

namespace Gloom {

template <typename T>
concept StandardLayout = std::is_standard_layout_v<T>;

template <typename T>
concept ScopedEnum = std::is_scoped_enum_v<T>;

template <ScopedEnum T> struct is_allowed_enum : std::false_type {};

template <typename T>
concept AllowedBitmaskEnum = ScopedEnum<T> && is_allowed_enum<T>::value;

template <AllowedBitmaskEnum Enum> constexpr Enum operator|(Enum LHS, Enum RHS) {
  return static_cast<Enum>(std::to_underlying(LHS) | std::to_underlying(RHS));
}

template <AllowedBitmaskEnum Enum> constexpr Enum operator&(Enum LHS, Enum RHS) {
  return static_cast<Enum>(std::to_underlying(LHS) & std::to_underlying(RHS));
}

template <AllowedBitmaskEnum Enum> constexpr bool HasBits(Enum LHS, Enum RHS) {
  return (LHS & RHS) == RHS;
}

#define ALLOW_BITMASK_ENUM(EnumType)                                                                                                       \
  template <> struct is_allowed_enum<EnumType> : std::true_type {};

} // namespace Gloom

#endif // GLOOM_CONCEPTS_H