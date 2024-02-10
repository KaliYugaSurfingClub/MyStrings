#include "../includes/My_string.h"

#include <iostream>

const My_string &get_shorter(const My_string &s1, const My_string &s2) {
    return (s1.get_size() < s2.get_size()) ? s1 : s2;
}

int main() {
    My_string s("123");
    const My_string sc("const");
    cout << s << ' ' << sc << endl;

    My_string s1 = sc * 2 + "123" + '1';
    cout << s1 << endl;

    My_string s2 = s1 - My_string('1');
    cout << s2 << endl;

    My_string s3;
    cin >> s3;
    cout << s3 << endl;

    cout << (s1 > s2 ? My_string("true") : My_string("false")) << endl;

    cout << get_shorter(s1, s2) << endl;

    vector<My_string> vec(10);

    for (size_t i = 0; i < vec.size(); ++i) {
        My_string prev = i >= 1 ? vec[i - 1] : My_string('\0');
        vec[i] = prev + My_string('0' + i);
    }

    for (const auto &str : vec) {
        cout << str << endl;
    }

    return 0;
}
