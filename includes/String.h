#pragma once

#include <vector>
#include <string>
#include <iostream>


class String {
    friend void swap(String &left, String &right);

private:
    char *c_str = nullptr;
    mutable size_t size = 0;

public:
    explicit String(const char *char_ptr);
    explicit String(char c);
    explicit String(const std::string &str) : String(str.c_str()) {}
    String(const String &other) : String(other.get()) {}
    String(String &&other) noexcept;
    String() : String('\0') {}

    ~String();

    String &operator=(const String &other);
    String &operator=(String &&other) noexcept;
    String &operator=(const char *char_ptr);

    String operator+(const char *char_ptr) const;
    String operator+(char c) const;
    String operator+(const String &operand) const;
    String operator+(const std::string &operand) const;

    bool operator==(const String &operand) const;
    bool operator!=(const String &operand) const;
    bool operator<(const String &operand) const;
    bool operator<=(const String &operand) const;
    bool operator>(const String &operand) const;
    bool operator>=(const String &operand) const;

    String operator*(size_t n) const;
    String operator!() const;
    String operator-(const String &operand) const;

    char *operator()(const char *substring) const;

    char &operator[](size_t index);
    const char &operator[](size_t index) const;

    const char *get() const;
    size_t get_size() const;
};

std::ostream &operator<<(std::ostream &os, const String &str);
std::istream &operator>>(std::istream &is, String &str);
