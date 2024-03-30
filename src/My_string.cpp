#include "../includes/My_string.h"

#include <cstring>
#include <algorithm>
#include <locale>

const char *My_string::get() const {
    return c_str;
}

size_t My_string::get_size() const {
    return size;
}

My_string::My_string(const char *char_ptr) {
    size_t len = strlen(char_ptr);
    c_str = new char[len + 1];
    size = len;

    strcpy(c_str, char_ptr);
}

My_string::My_string(const char c) : size(1) {
    c_str = new char[2];
    c_str[0] = c;
    c_str[1] = '\0';
}

My_string::~My_string() {
    delete [] c_str;
}


My_string &My_string::operator=(My_string &&other) noexcept {
    swap(*this, other);
    return *this;
}

My_string &My_string::operator=(const char *char_ptr) {
    *this = My_string(char_ptr);
    return *this;
}

My_string &My_string::operator=(const My_string &other) {
    if (this != &other) {
        delete c_str;
        *this = My_string(other);
    }

    return *this;
}

My_string My_string::operator+(const char *char_ptr) const {
    size_t res_len = strlen(c_str) + strlen(char_ptr);

    char *res_c_str = new char[res_len + 1];
    res_c_str[0] = '\0';
    strcat(res_c_str, c_str);
    strcat(res_c_str, char_ptr);

    return My_string(res_c_str);
}

My_string My_string::operator+(const My_string &operand) const {
    return *this + operand.c_str;
}

My_string My_string::operator+(const string &operand) const {
    return *this + operand.c_str();
}

My_string My_string::operator+(const char c) const {
    size_t res_len = strlen(c_str) + 2;

    char *res_c_str = new char[res_len];
    strcpy(res_c_str, c_str);
    res_c_str[res_len - 2] = c;
    res_c_str[res_len - 1] = '\0';

    return My_string(res_c_str);
}

My_string My_string::operator*(size_t n) const {
    My_string res;
    for (size_t i = 0; i < n; ++i) {
        res = *this + res;
    }

    return res;
}

//возвращает функцию которая проверяет содержиться ли C в строке operand
auto get_find_pred(const My_string &operand) {
    return [operand](char c) -> bool {
        auto end = operand.get() + operand.get_size();
        return find(operand.get(), end, c) == end;
    };
}

My_string My_string::operator-(const My_string &operand) const {
    char *res_c_str = new char[1 + count_if(c_str, c_str + size, get_find_pred(operand))];

    size_t curr_index = 0;
    size_t i = 0;
    for (; i < size; ++i) {
        if (get_find_pred(operand)(c_str[i])) {
            res_c_str[curr_index++] = c_str[i];
        }
    }
    res_c_str[curr_index] = '\0';

    return My_string(res_c_str);
}

bool My_string::operator==(const My_string &operand) const {
    if (size != operand.size) {
        return false;
    }

    return equal(c_str, c_str + size, operand.c_str);
}

bool My_string::operator!=(const My_string &operand) const {
    return !(*this == operand);
}

bool My_string::operator<(const My_string &operand) const {
    for (size_t i = 0; i < size && i < operand.size; ++i) {
        if (c_str[i] < operand.c_str[i]) {
            return true;
        }
    }

    return size < operand.size;
}

bool My_string::operator<=(const My_string &operand) const {
    return *this == operand || *this < operand;
}

bool My_string::operator>(const My_string &operand) const {
    return !(*this < operand);
}

bool My_string::operator>=(const My_string &operand) const {
    return *this == operand || *this > operand;
}

My_string My_string::operator!() const {
    My_string res(c_str);
    for (size_t i = 0; i < size; ++i) {
        res.c_str[i] = isupper(c_str[i]) ? tolower(c_str[i], locale()) : toupper(c_str[i], locale());
    }

    return res;
}

char &My_string::operator[](size_t index) {
    return c_str[index];
}

const char &My_string::operator[](size_t index) const {
    return c_str[index];
}

char *My_string::operator()(const char *substring) const {
    char *res = strstr(c_str, substring);
    return res ? res : nullptr;
}

void swap(My_string &left, My_string &right) {
    swap(left.c_str, right.c_str);
    swap(left.size, right.size);
}

My_string::My_string(My_string &&other) noexcept {
    swap(*this, other);
}

ostream &operator<<(ostream &os, const My_string &str) {
    cout << str.get();
    return os;
}

istream &operator>>(istream &is, My_string &str) {
    cin >> noskipws ;
    for (char c = '\0'; cin >> c && !isspace(c); str = str + c);
    is.clear();
    return is;
}











