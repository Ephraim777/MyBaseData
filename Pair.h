#pragma once
#include "myString.h"
#include "MyData.h"
#include <iostream>
class Pair {

	MyString key;
	MyData dat;
	Pair()=default;
    ~Pair() =default;
	Pair(const char* k, const MyData & d);
	Pair& operator = (const Pair& other);
	Pair(Pair&& other);
	Pair& operator = (Pair&& other);
	bool operator==(const char* key) ;
	friend class Base;
    friend class Menu;
public:
    MyString & ReturnKey();
    MyData & Returndat();

};