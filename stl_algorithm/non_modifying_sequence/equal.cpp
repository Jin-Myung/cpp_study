#include <string>
#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string &s) {
    return equal(s.cbegin(), s.cbegin()+s.length()/2, s.crbegin());
}

void test(const std::string& s) {
    std::cout << s << " "
        << (is_palindrome(s) ? "is" : "is not")
        << " a palindrome\n";
}
 
int main() {
    test("anna");
    test("nexus");
}
