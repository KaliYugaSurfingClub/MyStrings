#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class My_string {
private:
    char *c_str = nullptr;
    mutable size_t size = 0;

public:
    explicit My_string(const char *char_ptr);
    explicit My_string(char c);
    explicit My_string(const string &str) : My_string(str.c_str()) {}
    My_string(const My_string &other) : My_string(other.get()) {}
    My_string() : My_string('\0') {}

    ~My_string();

    My_string &operator=(My_string &&other) noexcept;
    My_string &operator=(const char *char_ptr) noexcept;

    My_string operator+(const char *char_ptr) const;
    My_string operator+(char c) const;
    My_string operator+(const My_string &operand) const;
    My_string operator+(const string &operand) const;

    bool operator==(const My_string &operand) const;
    bool operator!=(const My_string &operand) const;
    bool operator<(const My_string &operand) const;
    bool operator<=(const My_string &operand) const;
    bool operator>(const My_string &operand) const;
    bool operator>=(const My_string &operand) const;

    My_string operator*(size_t n) const;
    My_string operator!() const;
    My_string operator-(const My_string &operand) const;

    char *operator()(const char *substring) const;

    char &operator[](size_t index);
    const char &operator[](size_t index) const;

    const char *get() const;
    size_t get_size() const;

    void dev_print() const {
        cout << c_str << endl;
    }
};

ostream &operator<<(ostream &os, const My_string &str);
istream &operator>>(istream &is, My_string &str);
