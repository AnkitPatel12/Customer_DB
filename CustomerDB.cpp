// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Ankit Patel
// ap56764
// Slip days used: 1
// Summer 2022
/*
 * Copy the contents of header.txt (filled out) and paste here
 */
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    for(int i = 0; i < length; i++){
        if(name == data[i].name) {
            return data[i];
        }
    }
    //amortized doubling
    if(length == capacity){
        capacity*=2;
        Customer* ptr = new Customer[capacity];
        for(int i = 0; i < length ; i++){
            ptr[i] = data[i];
        }
        delete [] data;
        data = ptr;
    }
    Customer add(name);
    data[length] = add;
    length+=1;
    return data[length-1];
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    for(int i = 0; i < length; i++){
        if(name == data[i].name) {
            return true;
        }
    }
    return false;
}
