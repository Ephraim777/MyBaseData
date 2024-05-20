#include <string>
#include "myString.h"
using namespace std;



MyString::MyString(const char* str)  {


        size_t size = strlen(str);
        m_pStr = new char[size + 1];
        for (int i = 0; i < size; i++) {
            m_pStr[i] = str[i];

        }
        m_pStr[size] = '\0';

}
MyString::MyString(const MyString& otr) {
    size_t size = strlen(otr.m_pStr);
    m_pStr = new char[size + 1];
    for (int i = 0; i < size; i++) {
        m_pStr[i] = otr.m_pStr[i];

    }
    m_pStr[size] = '\0';

}


MyString::~MyString() {
    delete [] m_pStr;
    m_pStr = nullptr;
}

 const char* MyString::GetString() const {
    return  this->m_pStr;
}
 const char* MyString::SetNewString(const char* str) {


     size_t size = strlen(str);
     char* newstr = new char[size + 1];
     for (int i = 0; i < size; i++) {
         newstr[i] = str[i];
     }
     newstr[size] = '\0';
     delete[] m_pStr;
     m_pStr = newstr;
     newstr = nullptr;

     return this->m_pStr;
 }
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }


    if (m_pStr) {
        delete[] m_pStr;
    }

    if (other.m_pStr) {
        size_t size = std::strlen(other.m_pStr);


        m_pStr = new char[size + 1];


        std::strcpy(m_pStr, other.m_pStr);
    } else {

        m_pStr = nullptr;
    }

    return *this;
}
MyString& MyString::operator =( const char * other){
   if (other == nullptr){
       delete [] this->m_pStr;
       m_pStr = nullptr;
       return *this;
   }
   if (m_pStr != nullptr && std::strcmp(m_pStr,other) == 0){
       return *this;
   }
   delete [] m_pStr;
    this->m_pStr = new char[std::strlen(other)+1];
    std::strcpy(this->m_pStr,other);
    return *this;
}
MyString& MyString::operator =( MyString&& other){
    if (this != &other) {
        char* ptr1 = m_pStr;
        m_pStr = other.m_pStr;
        other.m_pStr = ptr1;

    }
    return *this;

}

 
  MyString MyString::operator +(MyString& first) {
      if (!m_pStr && !first.m_pStr) {
          return MyString();
     }else if (!m_pStr){
         return MyString(first.m_pStr);
     }
     else if (!first.m_pStr) {
          return MyString(m_pStr);
     }
      size_t len1 = strlen(m_pStr);
      size_t len2 = strlen(first.m_pStr);
      size_t totallen = len1 + len2;
      char* newstr = new char[totallen + 1];
      for (size_t i = 0; i < len1; i++) {
          newstr[i] = m_pStr[i];
      }
      for (size_t i = 0; i < len2; i++) {
          newstr[len1 + i] = first.m_pStr[i];
      }
      newstr[totallen] = '\0';
      MyString d(newstr);
      delete [] newstr;
      return d;

          
          


    

    

   }
  MyString& MyString::operator +=(MyString& oth) {
      size_t num1 = strlen(this->m_pStr);
      size_t num2 = strlen(oth.m_pStr);
      size_t num3 = num1 + num2;
      char* ptr = new char[num3 + 1];
      for (int i = 0; i < num1; i++) {
          ptr[i] = this->m_pStr[i];
      }
      for (int i = 0; i < num2; i++) {
          ptr[num1 + i] = oth.m_pStr[i];
      }
      ptr[num3] = '\0';
      delete[] this->m_pStr;
      this->m_pStr = ptr;
      ptr = nullptr;
      return *this;
      

  }
  bool MyString::operator ==(MyString& oth) {
      if (*this == oth.m_pStr) {
          return true;
      }
      return false;
  }
  bool MyString::operator ==(const char * oth) {
      size_t num = strlen(oth);
      size_t num1 = strlen(this->m_pStr);
      if (num != num1) {
          return false;
      }
      for (int i = 0; i < num; i++) {
          if (oth[i] != this->m_pStr[i]) {
              return false;
          }
      }
      return true;
  }

std::ostream& operator<<(std::ostream& examp,const MyString& str) {
    examp  << str.GetString();
    return examp;

}