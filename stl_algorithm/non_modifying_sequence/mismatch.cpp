#include <string>
#include <algorithm>
#include <iostream>

std::string mirror_ends(std::string str) {
    return std::string(
            str.cbegin(),
            std::mismatch(str.cbegin(), str.cend(), str.crbegin()).first
            );
}

int main() {
    std::cout << mirror_ends("ab1234ba") << '\n'
              << mirror_ends("1231") << '\n'
              << mirror_ends("12321") << '\n';
}
