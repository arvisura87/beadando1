//Author:    Jakab Tamás
//Date:      2020.03.30.
//Title:     I./6., Set of integers

#include "integers.h"

//Task: 	representing
//Activity: printing the elements of the set
void Integers::representing()
{
    if (p_vector == NULL || p_vector -> empty())
    {
        cout << "Error, the set is empty! Please fill it with integers." << endl;
    } else
    {
        cout << "Representing the Set of Integers: " << endl;

        for(int number : *p_vector) {
        cout << number << '\n';
        }
    }
}

//Task: 	representing
//Activity: printing the elements of the set
void Integers::isEmpty()
{
    if (p_vector == NULL || p_vector -> empty())
    {
        cout << "The set is empty!" << endl;
    } else
    {
        cout << "The set is not empty!" << endl;
    }
}

//Task: 	adding
//Activity: adds the element to the vector if the element is not already in it
void Integers::adding()
{
    int number;
    bool contain = false;

    while (!(cin >> number))
    {
        cout << "Please give a valid integer number!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }

    if (p_vector == NULL) {
        p_vector = new vector<int>;
        p_vector -> push_back(number);
        cout << "Done! :)" << endl;
    } else {
        for (int num : *p_vector)
        {
            if (num == number)
            {
                contain = true;
                cout << number << " is already exist in the set! Give another integer!" << endl;
            }
        }
        if (!contain)
        {
            p_vector -> push_back(number);
            if (number % 2 == 0)
                evenCounter++;
        }
    }
}

//Task: 	removing
//Activity: removing the element from the vector if the element exist in it
void Integers::removing()
{
    int number;
    bool deleted = false;

    if (p_vector == NULL) {
        cout << "Can not remove, the set is empty, so your number is surely does not exist in it! :)" << endl;
    } else
    {
        while (!(cin >> number))
        {
            cout << "Please give a valid integer number!" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }

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
void Integers::checkExistence()
{
    int number;
    bool isIn = false;

    if (p_vector == NULL) {
        cout << "The set is empty, so your number is surely does not exist in it! :)" << endl;
    } else
    {
        while (!(cin >> number))
        {
            cout << "Please give a valid integer number!" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }

        for (int num : *p_vector)
        {
            if (num == number)
                isIn = true;
        }
        if (isIn)
        {
            cout << "The set is contains the given number: " << number << endl;
        } else
        {
            cout << "The set is NOT contains the given number: " << number << endl;
        }
    }
}

//Task: 	even count
//Activity: giving the number of the even numbers in the set
void Integers::evenCount()
{
    cout << "There is/are " << evenCounter << " even number(s) in the set." << endl;
}
