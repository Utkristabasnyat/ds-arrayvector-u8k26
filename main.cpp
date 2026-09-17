
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

    // Demonstrating std::array member functions
    cout << "\nArray Information" << endl;

    cout << "Array size: " << customers.size() << endl;

    cout << "First day: " << customers.front() << endl;

    cout << "Last day: " << customers.back() << endl;

    cout << "Day 3: " << customers.at(2) << endl;

    cout << "Is array empty? ";
    if (customers.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Array data address: "
         << customers.data() << endl;

    return 0;
}