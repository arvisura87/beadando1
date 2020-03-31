//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Class of diagonal matrices
//Methods: add, multiply, write, read, refer to an element
//Representation: only the elements of the diagonal
class Integers {
public:
    enum Exceptions{NOT_AN_INTEGER, ALREADY_EXIST, EMPTY};

    Integers(){ p_vector = NULL; p_biggest = NULL; }
    ~Integers() { delete[] p_vector; }

    vector<int> getting();

private:
    vector<int> *p_vector;
    int *p_biggest;
};
