#include "MyString.h"

MyString::MyString()
 : text(create("")){}

MyString::MyString(const char* str)
 : text(create(str)){}

MyString::MyString(const MyString &str)
 : length(str.getLength()), text(createCopy(str.text, getLength())) {}

MyString::~MyString()
{
    delete[] text;
    text = NULL;//dtor
}

char* MyString::create(const char* str = NULL)
{
    length = strlen(str);
    text = new char[getLength()+1];
    strcpy(text, str);
    text[getLength()] = 0;
    return text;
}

char* MyString::createCopy(char* const str, size_t leng)
{
    char* temp = new char[leng];
    std::copy(str, str + leng, temp);
    return temp;
}

MyString& MyString::operator=(const char* str)
{
    delete[] text;
    text = create(str);
    return* this;
}

MyString& MyString::operator=(const MyString &str)
{
    return operator=(str.text);
}

bool MyString::operator==(const char* str)
{
    if(this->getLength()!=strlen(str)) return false;
    for(int i = 0; i<this->getLength(); i++){
        if(text[i] != str[i]) return false;
    }
    return true;
}

bool MyString::operator==(const MyString &str)
{
    if(this->getLength()!=str.getLength()) return false;
    for(int i = 0; i<this->getLength(); i++){
        if(text[i] != str.text[i]) return false;
    }
    return true;
}

MyString& MyString::operator+=(const MyString &str)
{
    length += str.getLength();
    char* temp = new char[getLength()+1];
    strcpy(temp, text);
    strcat(temp, str.text);
    delete[] text;
    text = temp;
    return* this;
}

MyString MyString::operator+(const MyString &str)
{
    return MyString(*this) += str;
}

MyString MyString::operator+(const char* str)
{
    return MyString(this->text) += str;
}

size_t MyString::getLength() const
{
    return length;
}

MyString operator+(const MyString &str1, const char* str2)
{
    return MyString(str1) += str2;
}

MyString operator+(const char* str1, const MyString &str2)
{
    return MyString(str1) += str2.text;
}

ostream & operator<<(ostream &out, const MyString &str)
{
    out<<str.text;
    return out;
}
