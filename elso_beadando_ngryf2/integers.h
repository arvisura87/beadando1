//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Class of set of integers
//Methods: representing, isEmpty, adding, removing, checkExistence, evenCount
class Integers {
public:
    enum Errors {NOT_AN_INTEGER, ALREADY_EXIST, EMPTY};

    Integers(){ p_vector = new vector<int>; evenCounter = 0; }
    ~Integers() { delete[] p_vector; }

    void print();
    bool isEmpty();
    void add(int number);
    void removes(int number);
    bool contains(int number);
    int evenCount();

private:
    vector<int>* p_vector;
    int evenCounter;
};
