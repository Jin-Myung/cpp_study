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
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}
