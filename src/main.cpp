#include "../includes/My_string.h"

#include <iostream>

const My_string &get_shorter(const My_string &s1, const My_string &s2) {
    return (s1.get_size() > s2.get_size()) ? s1 : s2;
}


int main() {
    My_string s1("123");
    My_string s("1");
    s = std::move(s1);
    My_string s2("1");
    s2 = "12";

    return 0;
}
