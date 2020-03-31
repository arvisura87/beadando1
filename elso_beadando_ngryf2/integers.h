//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Class of set of integers
//Methods: representing, isEmpty, adding, removing, checkExistence, evenCount
class Integers {
public:
    enum Errors {NOT_AN_INTEGER, ALREADY_EXIST, EMPTY};

    Integers(){ p_vector = NULL; evenCounter = 0; }
    ~Integers() { delete[] p_vector; }

    void representing();
    void isEmpty();
    void adding();
    void removing();
    void checkExistence();
    void evenCount();

private:
    vector<int>* p_vector;
    int evenCounter;
};
