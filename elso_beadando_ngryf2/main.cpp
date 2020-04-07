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
    cout << p_integers -> evenCount();
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

TEST_CASE("Testing isEmpty with empty set", "") {

    Integers *p_integers = new Integers();
    CHECK(p_integers -> isEmpty() == true);
}

TEST_CASE("Testing contains method with non existing number", "") {

    Integers *p_integers = new Integers();
    CHECK(p_integers -> contains(5) == false);
}

TEST_CASE("Testing add method with a new number in the set", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(1);

    CHECK(p_integers -> contains(1) == true);
}

TEST_CASE("Testing isEmpty with non empty set", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(4);
    CHECK(p_integers -> isEmpty() == false);
}

TEST_CASE("Testing contains method with existing number", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(2);
    CHECK(p_integers -> contains(2) == true);
}

TEST_CASE("Testing remove method with existing number", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(3);
    p_integers -> removes(3);

    CHECK(p_integers -> contains(3) == false);
}

TEST_CASE("Testing evenCount method with evens", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(6);
    p_integers -> add(7);
    p_integers -> add(8);

    CHECK(p_integers -> evenCount() == 2);
}

TEST_CASE("Testing evenCount method without evens", "") {

    Integers *p_integers = new Integers();
    p_integers -> add(7);

    CHECK(p_integers -> evenCount() == 0);
}

#endif
