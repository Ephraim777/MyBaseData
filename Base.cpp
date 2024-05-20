#include "Base.h"
#include <string.h>
Base::Base() {
	this->capacity = 1;
	this->count = 0;
	this->pBase = new  Pair[this->capacity];




}
Base::~Base() {

		delete[] this->pBase;

	this->pBase = nullptr;
}
Base::Base(const Base& bd) {
this->pBase = new Pair[bd.capacity];
this->count = bd.count;
this->capacity = bd.capacity;
for ( size_t i = 0; i <this->count; i++){
    this->pBase[i]= bd.pBase[i];
}

}
Base::Base(Base&& bd){
    count = bd.count;
    pBase = bd.pBase;
    capacity = bd.capacity;
    bd.pBase = nullptr;
}
Base& Base::operator=(Base&& bd){
    if (this == &bd){
        return *this;
    }

    Pair* tmp = pBase;
    count = bd.count;
    capacity = bd.capacity;
    pBase = bd.pBase;
    bd.pBase = tmp;
    bd.pBase = nullptr;
    return *this;
}
Base& Base::operator =(const Base& bd) {
	this->capacity = bd.capacity;
	this->count = bd.count;
	for (int i = 0; i < bd.count; i++) {
		this->pBase[i] = bd.pBase[i];
}

	return *this;

}
MyData& Base::operator[](const char* key) {
	for (int i = 0; i < this->count; i++) {
		if (strcmp(pBase[i].key.GetString() , key) == 0) {
			return pBase[i].dat;
		}
	}
	if (this->count >= this->capacity) {
		this->capacity *= 3;
		Pair* newar = new Pair[this->capacity];
		for (int i = 0; i < this->count; i++) {
			newar[i] = pBase[i];
		}
		delete[] pBase;
		pBase = newar;
		newar = nullptr;
	}


    pBase[count].key = key;

	count++;
	return pBase[count-1].dat;
}


 std::ostream& operator<< (std::ostream& examp,  Base& bd) {
    if (bd.count == 0){
        std::cout << "Ваша база данных пустая!!!\n";


    }

    for (int i =0; i<bd.count; i++) {

               examp << "№ " << i+1 << std::endl;
        examp << "Full Name: ";
        examp << bd.pBase[i].ReturnKey() << std::endl;
        examp << "Gender: ";
        examp << bd.pBase[i].Returndat().Return_Sex() << std::endl;
        examp << "Age: ";
        examp << bd.pBase[i].Returndat().Return_m_age() << std::endl;
        examp << "Job: ";
        examp << bd.pBase[i].Returndat().Return_m_job().GetString() << std::endl;
        examp << "Salary: ";
        examp << bd.pBase[i].Returndat().Return_m_salary() << std::endl << std::endl;
    }
	 return examp;
}


int Base::deletePair(const char* key){

    bool k_Key = false;
for ( int i =0; i <this->count; i++){
    if(strcmp(pBase[i].key.m_pStr, key) == 0){
        k_Key = true;
        return i;
    }
}
if ( k_Key == false){

    return -2;
}
return 0;
}

bool Base::Checkname(const char * ptr){
    for (size_t i=0; i<count; i++ ){
        if (strcmp(pBase[i].key.m_pStr,ptr) == 0){
            return true;
        }
    }
    return false;
}
