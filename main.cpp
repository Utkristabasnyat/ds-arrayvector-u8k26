
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int SIZE = 30;

int main()
{
    array<int, SIZE> customers;

    ifstream inputFile("customers.txt");

    if (!inputFile)
    {
        cout << "Error opening customers.txt" << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (!(inputFile >> customers.at(i)))
        {
            cout << "Error reading customer data." << endl;
            return 1;
        }
    }

    inputFile.close();

    cout << "Restaurant Customer Tracker" << endl;
    cout << "Customer data for 30 days:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Day " << i + 1 << ": "
             << customers.at(i) << " customers" << endl;
    }

    return 0;
}