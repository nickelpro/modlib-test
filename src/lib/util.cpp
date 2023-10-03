module;
#include <concepts>
#include <iostream>
#include <string_view>

export module lib:util;

export namespace lib {

void print(std::string_view s) {
  std::cout << s << "\n";
}

template <std::integral T> T add(T a, T b) {
  return a + b;
}

} // namespace lib
