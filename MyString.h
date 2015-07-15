#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <algorithm>
#include <iostream>


typedef std::basic_ostream<char> ostream;
class MyString
{
    public:
        MyString();
        MyString(const char* str);
        MyString(const MyString &str);
        ~MyString();
        MyString& operator=(const char* str);
        MyString& operator=(const MyString &str);
        bool operator==(const char* str);
        bool operator==(const MyString &str);
        MyString& operator+=(const MyString &str);
        MyString operator+(const MyString &str);
        MyString operator+(const char* str);
        size_t getLength() const;
        friend MyString operator+(const MyString &str1, const char* str2);
        friend MyString operator+(const char* str1, const MyString &str2);
        friend ostream & operator<<(ostream &out, const MyString &str);
    protected:
    private:
        size_t length;
        char* text;
        char* create(const char* str);
        char* createCopy(char* const str, size_t leng);
};

#endif // MYSTRING_H
