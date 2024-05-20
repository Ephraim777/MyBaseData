#pragma once
#include "myString.h"
class MyData {
public:
	enum Sex { UNDEF, MALE, FEMALE };
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData();
	MyData(Sex s, size_t age, const char* job, float sal);
	~MyData() = default;
	MyData(const MyData& d);
	MyData& operator =(const MyData& d);
	MyData(MyData&& d);
	MyData& operator =(MyData&& d);
	friend std::ostream& operator << (std::ostream &os, const MyData& d);
	friend class Pair;
    std::string Return_Sex();
    size_t Return_m_age ();
    MyString Return_m_job();
    float Return_m_salary();

};
