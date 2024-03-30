#include "../includes/String.h"

#include <cstring>
#include <algorithm>
#include <locale>

const char *String::get() const {
    return c_str;
}

size_t String::get_size() const {
    return size;
}

String::String(const char *char_ptr) {
    size_t len = strlen(char_ptr);
    c_str = new char[len + 1];
    size = len;

    strcpy(c_str, char_ptr);
}

String::String(const char c) : size(1) {
    c_str = new char[2];
    c_str[0] = c;
    c_str[1] = '\0';
}

String::~String() {
    delete [] c_str;
}


String &String::operator=(String &&other) noexcept {
    swap(*this, other);
    return *this;
}

String &String::operator=(const char *char_ptr) {
    *this = String(char_ptr);
    return *this;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete c_str;
        *this = String(other);
    }

    return *this;
}

String String::operator+(const char *char_ptr) const {
    size_t res_len = strlen(c_str) + strlen(char_ptr);

    char *res_c_str = new char[res_len + 1];
    res_c_str[0] = '\0';
    strcat(res_c_str, c_str);
    strcat(res_c_str, char_ptr);

    return String(res_c_str);
}

String String::operator+(const String &operand) const {
    return *this + operand.c_str;
}

String String::operator+(const std::string &operand) const {
    return *this + operand.c_str();
}

String String::operator+(const char c) const {
    size_t res_len = strlen(c_str) + 2;

    char *res_c_str = new char[res_len];
    strcpy(res_c_str, c_str);
    res_c_str[res_len - 2] = c;
    res_c_str[res_len - 1] = '\0';

    return String(res_c_str);
}

String String::operator*(size_t n) const {
    String res;
    for (size_t i = 0; i < n; ++i) {
        res = *this + res;
    }

    return res;
}

//возвращает функцию которая проверяет содержиться ли C в строке operand
auto get_find_pred(const String &operand) {
    return [operand](char c) -> bool {
        auto end = operand.get() + operand.get_size();
        return std::find(operand.get(), end, c) == end;
    };
}

String String::operator-(const String &operand) const {
    char *res_c_str = new char[1 + std::count_if(c_str, c_str + size, get_find_pred(operand))];

    size_t curr_index = 0;
    size_t i = 0;
    for (; i < size; ++i) {
        if (get_find_pred(operand)(c_str[i])) {
            res_c_str[curr_index++] = c_str[i];
        }
    }
    res_c_str[curr_index] = '\0';

    return String(res_c_str);
}

bool String::operator==(const String &operand) const {
    if (size != operand.size) {
        return false;
    }

    return std::equal(c_str, c_str + size, operand.c_str);
}

bool String::operator!=(const String &operand) const {
    return !(*this == operand);
}

bool String::operator<(const String &operand) const {
    for (size_t i = 0; i < size && i < operand.size; ++i) {
        if (c_str[i] < operand.c_str[i]) {
            return true;
        }
    }

    return size < operand.size;
}

bool String::operator<=(const String &operand) const {
    return *this == operand || *this < operand;
}

bool String::operator>(const String &operand) const {
    return !(*this < operand);
}

bool String::operator>=(const String &operand) const {
    return *this == operand || *this > operand;
}

String String::operator!() const {
    String res(c_str);
    for (size_t i = 0; i < size; ++i) {
        res.c_str[i] = isupper(c_str[i]) ? tolower(c_str[i], std::locale()) : toupper(c_str[i], std::locale());
    }

    return res;
}

char &String::operator[](size_t index) {
    return c_str[index];
}

const char &String::operator[](size_t index) const {
    return c_str[index];
}

char *String::operator()(const char *substring) const {
    char *res = strstr(c_str, substring);
    return res ? res : nullptr;
}

void swap(String &left, String &right) {
    std::swap(left.c_str, right.c_str);
    std::swap(left.size, right.size);
}

String::String(String &&other) noexcept {
    swap(*this, other);
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    std::cout << str.get();
    return os;
}

std::istream &operator>>(std::istream &is, String &str) {
    std::cin >> std::noskipws ;
    for (char c = '\0'; std::cin >> c && !isspace(c); str = str + c);
    is.clear();
    return is;
}











