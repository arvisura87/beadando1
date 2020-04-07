//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#include "integers.h"

//Task: 	representing
//Activity: printing the elements of the set
void Integers::print()
{
    if (isEmpty())
    {
        cout << "Error, the set is empty! Please fill it with integers.\n" << endl;;
    } else
    {
        cout << "Representing the Set of Integers: " << endl;

        for(auto const& value: *p_vector) {
            cout << value << endl;
        }
    }
}

//Task: 	representing
//Activity: printing the elements of the set
bool Integers::isEmpty()
{
    return p_vector -> empty();
}

//Task: 	adding
//Activity: adds the element to the vector if the element is not already in it
void Integers::add(int number)
{
    bool contain = false;

    if (isEmpty()) {
        p_vector -> push_back(number);
        cout << "Done! :)" << endl;
    } else
    {
        for(auto const& value: *p_vector)
        {
            if (value == number)
            {
                contain = true;
                cout << "Already exist in the set! Give another integer!" << endl;
            }
        }

        if (!contain)
        {
            p_vector -> push_back(number);
        }
    }
    if (number % 2 == 0) evenCounter++;
}

//Task: 	removing
//Activity: removing the element from the vector if the element exist in it
void Integers::removes(int number)
{
    bool deleted = false;

    if (isEmpty()) {
        cout << "Can not remove, the set is empty, so your number is surely does not exist in it! :)" << endl;
    } else
    {
        int counter = -1;
        for (int num : *p_vector)
        {
            counter++;
            if (num == number)
            {
                p_vector -> erase(p_vector -> begin() + counter);
                deleted = true;
                cout << number << " has been removed!" << endl;
                if (number % 2 == 0)
                    evenCounter--;
            }
        }
        if (!deleted)
            cout << number << " is not exist in the set, so it cant be removed!" << endl;
    }
}

//Task: 	check existence
//Activity: checking the given number is exist in the set or not
bool Integers::contains(int number)
{
    for (int num : *p_vector)
    {
        if (num == number)
        {
            return true;
        }
    }
    return false;
}

//Task: 	even count
//Activity: giving the number of the even numbers in the set
int Integers::evenCount()
{
    return evenCounter;
}
