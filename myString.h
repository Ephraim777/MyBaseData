#pragma once

#include <cstring>
#include <iostream>
class MyString
{
    char* m_pStr;
public:
    MyString() :m_pStr(nullptr) {

    }
    MyString(const char* str);
    const char* GetString() const;
    const char* SetNewString(const char* str);
    MyString(const MyString& otr);
    MyString& operator =(const MyString& other);
    MyString& operator =( const char * other);
    MyString& operator =( MyString&& other);
    friend std::ostream& operator<<(std::ostream& examp, const MyString& str);
    MyString operator +(MyString& first);
    MyString& operator +=(MyString& oth);
    bool operator ==(MyString& oth);
    ~MyString();
    bool operator ==(const char* oth);
friend class Pair;
    friend class Base;

};