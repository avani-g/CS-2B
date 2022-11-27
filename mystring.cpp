#include "mystring.h"
#include <cstring>
#include <cassert>

namespace cs_mystring {
    
    
    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }






    MyString::MyString(const char *inString) {
        str = new char[strlen(inString) + 1];
        strcpy(str, inString);
    }






    int MyString::length() const {
        return strlen(str);
    }






    ostream& operator<<(ostream& out, const MyString &inString) {
        out << inString.str;
        return out;
    }






    char MyString::operator[](int index) const{
        assert(index >= 0 && index < (int) strlen(str));
        return str[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < (int) strlen(str));
        return str[index];
    }






    bool operator<(const MyString lhs, const MyString rhs) {
        return (strcmp(lhs.str, rhs.str) < 0);
    }






    bool operator==(const MyString lhs, const MyString rhs) {
        return (strcmp(lhs.str, rhs.str) == 0);
    }






    bool operator!=(const MyString lhs, const MyString rhs) {
        return !(lhs == rhs);
    }






    bool operator>(const MyString lhs, const MyString rhs) {
        return !(lhs == rhs) && !(lhs < rhs);
    }






    bool operator<=(const MyString lhs, const MyString rhs) {
        return lhs < rhs || lhs == rhs;
    }






    bool operator>=(const MyString lhs, const MyString rhs) {
        return lhs > rhs || lhs == rhs;
    }






    MyString::~MyString() {
        delete[] str;
    }






    MyString::MyString(const MyString &obj) {
        str = new char[strlen(obj.str) + 1];
        strcpy(str, obj.str);
    }






    MyString MyString::operator=(const MyString &obj) {
        if(this != &obj) {
            delete str;
            str = new char[strlen(obj.str) + 1];
            strcpy(str, obj.str);
        }
        return *this;
    }






    istream& operator>>(istream& in, MyString& instr) {
        char temp[MyString::MAX_CHARACTERS + 1];
        in >> temp;
        delete[] instr.str;
        instr.str = new char[strlen(temp) + 1];
        strcpy(instr.str, temp);

        return in;
    }






    void MyString::read(istream& in, char delimiter) {
        char temp[MyString::MAX_CHARACTERS + 1];
        in.getline(temp, MyString::MAX_CHARACTERS, delimiter);
        delete[] str;
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }






    MyString operator+(const MyString lhs, const MyString rhs) {
        char temp[MyString::MAX_CHARACTERS * 2 + 1];
        strcpy(temp, lhs.str);
        strcat(temp, rhs.str);
        MyString result = MyString(temp);
        return result;
    }






    MyString operator+=(MyString &lhs, const MyString rhs) {
        lhs = lhs + rhs;
        return lhs;
    }
}