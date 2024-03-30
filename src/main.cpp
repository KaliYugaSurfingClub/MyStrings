#include "../includes/String.h"

#include <iostream>

const String &get_shorter(const String &s1, const String &s2) {
    return (s1.get_size() > s2.get_size()) ? s1 : s2;
}

int main() {
    String s1("123");
    String s("1");
    s = std::move(s1);
    String s2("1");
    s2 = "12";

    return 0;
}
