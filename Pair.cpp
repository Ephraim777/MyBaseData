#include "Pair.h"

Pair::Pair(const char* k, const MyData& d) {
    size_t num = strlen(k);
	this->key.m_pStr = new char[num+1];
    for ( size_t i =0; i < num; i++){
        this->key.m_pStr[i] =k[i];
    }
    this->key.m_pStr[num] = '\0';

	this->dat.sex = d.sex;
	this->dat.m_age = d.m_age;
	this->dat.m_job = d.m_job;
	this->dat.m_salary = d.m_salary;
	
}
Pair::Pair(Pair&& other){
    this->dat = std::move(other.dat);
    this->key = std::move(other.key);

}
Pair& Pair::operator = (Pair&& other){
    this->key = std::move(other.key);
    this->dat.sex = other.dat.sex;
    this->dat.m_salary = other.dat.m_salary;
    this->dat.m_job = std::move(other.dat.m_job);
    this->dat.m_age = other.dat.m_age;
    return *this;
}
Pair& Pair::operator = (const Pair& other) {
	this->key = other.key;
	this->dat.sex = other.dat.sex;
	this->dat.m_salary = other.dat.m_salary;
	this->dat.m_job = other.dat.m_job;
	this->dat.m_age = other.dat.m_age;
	return *this;
}
bool Pair::operator==(const char* key)  {

	if (this->key == key) {
		return true;
	}
	return false;
}
MyData& Pair::Returndat(){
    return dat;
}
MyString & Pair::ReturnKey(){
    return key;
}
