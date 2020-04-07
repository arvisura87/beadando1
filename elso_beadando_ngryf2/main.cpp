//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#include "integers.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

//class of menu for the set of integers
class Menu{
  public:
    Menu() { p_integers = new Integers(); }
    ~Menu() { delete[] p_integers; }
    void run();

  private:
    Integers *p_integers;

    void menuWrite();
    void print();
    void isEmpty();
    void add();
    void removes();
    void contains();
    void evenCount();
    int readInput();
};

int main()
{
//set locale(LC_ALL,"Hun");
    Menu m;
    m.run();
}

void Menu::run()
{
    int n = 0;
    do{
        menuWrite();
        cout << endl << ">>>>" ; cin >> n;
        switch(n){
            case 1: print();
                    break;
            case 2: isEmpty();
                    break;
            case 3: add();
                    break;
            case 4: removes();
                    break;
            case 5: contains();
                    break;
            case 6: evenCount();
                    break;
        }
    }while(n!=0);
}

void Menu::menuWrite()
{
     cout << endl << endl;
     cout << " 0. - Quit" << endl;
     cout << " 1. - Represent the Set of Integers" << endl;
     cout << " 2. - Check the Set is empty or not" << endl;
     cout << " 3. - Add an integer if not already exist in the set" << endl;
     cout << " 4. - Remove an integer if it is in the set" << endl;
     cout << " 5. - Check if a given number exist in the set" << endl;
     cout << " 6. - Get how many even numbers are in the set" << endl;
}


void Menu::print()
{
    p_integers -> print();
}

void Menu::isEmpty()
{
    bool isEmpty = p_integers -> isEmpty();
    if (isEmpty)
    {
        cout << "The set is empty!";
    } else
    {
        cout << "The set is NOT empty!";
    }
}

void Menu::add()
{
    int input = readInput();
    p_integers -> add(input);
}

void Menu::removes()
{
    int input = readInput();
    p_integers -> removes(input);
}

void Menu::contains()
{
    int input = readInput();
    if (p_integers -> contains(input))
    {
        cout << "Contains.";
    } else
    {
        cout << "Not containing.";
    }
}


void Menu::evenCount()
{
    p_integers -> evenCount();
}

int Menu::readInput()
{
    int input;
    while (!(cin >> input))
    {
        cout << "Please give a valid integer number!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return input;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("create", "inp.txt") {
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail()){
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag c(3);
    in >> c;
    CHECK(c(0,0)==3);
    CHECK(c(1,1)==2);
    CHECK(c(2,2)==1);

    Diag b(2);
    in >> b;
    CHECK(b(0,0)==2);
    CHECK(b(1,1)==1);

    Diag a(1);
    in >> a;
    CHECK(a(0,0)==1);
}

TEST_CASE("getting and changing an element of the matrix", "") {

    Diag a(3);
    a(0,0) = 0;
    CHECK(a(0,0)==0);
}

TEST_CASE("copy constructor", "inp.txt") {
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail()){
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a(3);
    in >> a;

    Diag b = a;

    CHECK(a(0,0)==b(0,0));
    CHECK(a(1,1)==b(1,1));
    CHECK(a(2,2)==b(2,2));
}

TEST_CASE("assignment operator", "inp.txt") {
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail()){
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a(3), b(3);
    in >> a;

    b = a;
    CHECK(a(0,0)==b(0,0));
    CHECK(a(1,1)==b(1,1));
    CHECK(a(2,2)==b(2,2));

    Diag c(3);
    c = b = a;
    CHECK(a(0,0)==c(0,0));
    CHECK(a(1,1)==c(1,1));
    CHECK(a(2,2)==c(2,2));

    a = a;
    CHECK(a(0,0)==3);
    CHECK(a(1,1)==2);
    CHECK(a(2,2)==1);
}

TEST_CASE("add", "inp2.txt") {
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail()){
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a(3), b(3), c(3), d(3), f(3), e(3), z(3);
    in >> a >> b >> z >> e;

    c = a + b;
    CHECK(c(0,0)==4);
    CHECK(c(1,1)==5);
    CHECK(c(2,2)==6);

    d = b + a;
    CHECK(c(0,0)==d(0,0));
    CHECK(c(1,1)==d(1,1));
    CHECK(c(2,2)==d(2,2));

    d = (a + b) + c;
    f = a + (b + c);
    CHECK(d(0,0)==f(0,0));
    CHECK(d(1,1)==f(1,1));
    CHECK(d(2,2)==f(2,2));

    c = a + z;
    CHECK(c(0,0)==a(0,0));
    CHECK(c(1,1)==a(1,1));
    CHECK(c(2,2)==a(2,2));
}

TEST_CASE("multiply", "inp2.txt") {
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail()){
        cout << "File name error!" << endl;
        exit(1);
    }

    Diag a(3), b(3), c(3), d(3), f(3), e(3), z(3);
    in >> a >> b >> z >> e;

    c = a * b;
    CHECK(c(0,0)==3);
    CHECK(c(1,1)==6);
    CHECK(c(2,2)==9);

    d = b * a;
    CHECK(c(0,0)==d(0,0));
    CHECK(c(1,1)==d(1,1));
    CHECK(c(2,2)==d(2,2));

    d = (a * b) * c;
    f = a * (b * c);
    CHECK(d(0,0)==f(0,0));
    CHECK(d(1,1)==f(1,1));
    CHECK(d(2,2)==f(2,2));

    c = a * e;
    CHECK(c(0,0)==a(0,0));
    CHECK(c(1,1)==a(1,1));
    CHECK(c(2,2)==a(2,2));
}

TEST_CASE("ecxeptions", "") {

    Diag a(3);

    try{
        a(3,3) = 4;
    } catch(Diag::Exceptions ex){
        if(Diag::OVERINDEXED) ;
    }

    try{
        a(-1,4) = 4;
    } catch(Diag::Exceptions ex){
        if(Diag::OVERINDEXED) ;
    }

    Diag b(2); Diag c(3);

    try{
        a = b;
    } catch(Diag::Exceptions ex){
        if(Diag::DIFFERENT) ;
    }

    try{
        c = a + b;
    } catch(Diag::Exceptions ex){
        if(Diag::DIFFERENT) ;
    }

    try{
        c = a * b;
    } catch(Diag::Exceptions ex){
        if(Diag::DIFFERENT) ;
    }


    try{
        a(1,0) = 4;
    } catch(Diag::Exceptions ex){
        if(Diag::NULLPART) ;
    }

    try{
        int  k = a(1,0);
    } catch(Diag::Exceptions ex){
        if(Diag::NULLPART) ;
    }
}

#endif
