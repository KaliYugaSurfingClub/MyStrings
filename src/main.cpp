#include "../includes/My_string.h"

#include <iostream>

const My_string &get_shorter(const My_string &s1, const My_string &s2) {
    return (s1.get_size() < s2.get_size()) ? s1 : s2;
}

int main() {
    My_string s("123");
    My_string s1("123");
    s = s1;

    cout << s << endl;


    return 0;
}
