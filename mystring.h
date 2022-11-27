/*
Avani Goyal
Project 21.1
CS 2B
Dave Harden
11/24/22

This class creates a string that is more convinient to use than a c-string.
Operators are overloaded to make constructing, reading, printing, and accessing
characters easier.

Member functions ----------

MyString();
- The default constructor of the class which creates an empty string
- PRECONDITIONS: none
- POSTCONDITIONS: an empty string of type MyString is created

MyString(const char *inString);
- Constructor that takes a c-string in as a parameter
- PRECONDITIONS: the parameter must be a c-string
- POSTCONDITIONS: a MyString object is created and stores the provided string

int length() const;
- returns the length of the string
- PRECONDITIONS: none
- POSTCONDITIONS: the length of the string is returned

friend std::ostream& operator<<(ostream& out, const MyString &inString);
- prints the string
- PRECONDITIONS: the left hand side object is of type ostream and the right hand
    side is of type MyString
- POSTCONDITIONS: the string MyString contains is inserted into the ostream

char operator[](int index) const;
- allows indexing of the string
- PRECONDITIONS: the index provided is within the range for the string
- POSTCONDITIONS: the character at the index is returned

char& operator[](int index);
- allows assignment thorugh indexing
- PRECONDITIONS: the index provided is within the range for the string
- POSTCONDITIONS: a pointer to the character at the index is returned

friend bool operator<(const MyString lhs, const MyString rhs);
- overloading the less than operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs < rhs is returned

friend bool operator==(const MyString lhs, const MyString rhs);
- overloading the equal to operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs == rhs is returned

friend bool operator!=(const MyString lhs, const MyString rhs);
- overloading the not equal to operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs != rhs is returned

friend bool operator>(const MyString lhs, const MyString rhs);
- overloading the greater than operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs > rhs is returned

friend bool operator<=(const MyString lhs, const MyString rhs);
- overloading the less than or equal operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs <= rhs is returned

friend bool operator>=(const MyString lhs, const MyString rhs);
- overloading the greater than or equal operator
- PRECONDITIONS: both sides should be of type MyString or should be c-strings
- POSTCONDITIONS: the boolean result of lhs >= rhs is returned

~MyString();
- destructor for MyString type
- PRECONDITIONS: none
- POSTCONDITIONS: all compnents of the MyString object are deallocated from the
    memory

MyString(const MyString &obj);
- copy constructor for the MyString class
- PRECONDITIONS: the parameter should be of type MyString
- POSTCONDITIONS: another MyString object is created with the same value as the
    parameter

MyString operator=(const MyString &obj);
- overloading the assignemnt operator for MyString types
- PRECONDITIONS: the right hand side should be a MyString object or a c-string
    and the left hand side should be of type MyString
- POSTCONDITIONS: the left hand side is assigned to a deep copy of the right
    hand side and a pointer to the left hand side object is returned

friend istream& operator>>(istream& in, MyString& instr);
- overloads the insersion operator for an object of type MyString
- PRECONDITIONS: the left hand side must be an input stream and the right hand
    side must be an object of type MyString
- POSTCONDITIONS: all the characters in the stream up until the first whitespace
    are read into the MyString object

void read(istream& in, char delimiter);
- reads characters from a stream until the delimiter is reached and sets the
    MyString object to the input
- PRECONDITIONS: none
- POSTCONDITIONS: the input is stored in the MyString object

friend MyString operator+(const MyString lhs, const MyString rhs);
- concatenates two MyString objects
- PRECONDITIONS: the left and right hand side are either MyString objects or
    c-strings
- POSTCONDITIONS: a new MyString object with the two inputs concatenated is
    returned

friend MyString operator+=(MyString &lhs, const MyString rhs);
- concatenates two strings and assigns the new value to the first object
- PRECONDITIONS: the left hand side is a MyString object and the right hand side
    is either a MyString object or a c-string

*/

#include <iostream>

using namespace std;

namespace cs_mystring {
    class MyString {
        public:
            static const int MAX_CHARACTERS = 127;
            MyString();
            MyString(const char *inString);
            int length() const;
            friend std::ostream& operator<<(ostream& out, const MyString &inString);
            char operator[](int index) const;
            char& operator[](int index);
            friend bool operator<(const MyString lhs, const MyString rhs);
            friend bool operator==(const MyString lhs, const MyString rhs);
            friend bool operator!=(const MyString lhs, const MyString rhs);
            friend bool operator>(const MyString lhs, const MyString rhs);
            friend bool operator<=(const MyString lhs, const MyString rhs);
            friend bool operator>=(const MyString lhs, const MyString rhs);
            ~MyString();
            MyString(const MyString &obj);
            MyString operator=(const MyString &obj);
            friend istream& operator>>(istream& in, MyString& instr);
            void read(istream& in, char delimiter);
            friend MyString operator+(const MyString lhs, const MyString rhs);
            friend MyString operator+=(MyString &lhs, const MyString rhs);
        private:
            char *str;
    };
}