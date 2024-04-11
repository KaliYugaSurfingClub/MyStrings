#include "../includes/String.h"

#include <iostream>

const String &get_shorter(const String &s1, const String &s2) {
    return (s1.get_size() > s2.get_size()) ? s1 : s2;
}

int main() {


    return 0;
}
