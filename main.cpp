
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int SIZE = 30;

int main()
{
    // PART 1: STD::ARRAY
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

    // Demonstrate basic std::array member functions
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

    // Calculate customer statistics
    cout << "\nCustomer Statistics" << endl;

    cout << "Maximum customers: "
         << *max_element(customers.begin(), customers.end())
         << endl;

    cout << "Minimum customers: "
         << *min_element(customers.begin(), customers.end())
         << endl;

    cout << "Total customers: "
         << accumulate(customers.begin(), customers.end(), 0)
         << endl;

    // Make a copy to preserve the original customer data
    array<int, SIZE> sortedCustomers = customers;

    // Sort in ascending order
    sort(sortedCustomers.begin(), sortedCustomers.end());

    cout << "\nCustomers sorted in ascending order:" << endl;

    for (int value : sortedCustomers)
    {
        cout << value << " ";
    }
    cout << endl;

    // Sort in descending order
    sort(sortedCustomers.rbegin(), sortedCustomers.rend());

    cout << "\nCustomers sorted in descending order:" << endl;

    for (int value : sortedCustomers)
    {
        cout << value << " ";
    }
    cout << endl;

    // Search for a customer count
    int target = 85;

    array<int, SIZE>::iterator it;

    it = find(customers.begin(), customers.end(), target);

    cout << "\nSearching for " << target << " customers:" << endl;

    if (it != customers.end())
    {
        cout << "Found on day "
             << it - customers.begin() + 1 << endl;
    }
    else
    {
        cout << "Customer count not found." << endl;
    }

    // Demonstrate fill() and swap()
    cout << "\nArray Fill and Swap Demonstration" << endl;

    // Create copies to preserve the original customer data
    array<int, SIZE> closedDays = customers;
    array<int, SIZE> backupCustomers = customers;

    // Simulate zero customers during a closure
    closedDays.fill(0);

    cout << "Customers during closure: "
         << closedDays.front() << endl;

    // Restore the customer data from the backup
    closedDays.swap(backupCustomers);

    cout << "Customers after restoring backup: "
         << closedDays.front() << endl;

    cout << "Total customers after restoration: "
         << accumulate(closedDays.begin(), closedDays.end(), 0)
         << endl;

    // PART 2: STD::VECTOR
    vector<int> vectorCustomers;

    // Open the same external data file again
    ifstream vectorFile("customers.txt");

    if (!vectorFile)
    {
        cout << "Error opening customers.txt for vector." << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        int count;

        if (!(vectorFile >> count))
        {
            cout << "Error reading vector customer data." << endl;
            return 1;
        }

        vectorCustomers.push_back(count);
    }

    vectorFile.close();

    cout << "\nVector Customer Tracker" << endl;
    cout << "Customer data for 30 days:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Day " << i + 1 << ": "
             << vectorCustomers.at(i) << " customers" << endl;
    }

    // Demonstrate basic std::vector member functions
    cout << "\nVector Information" << endl;

    cout << "Vector size: " << vectorCustomers.size() << endl;
    cout << "First day: " << vectorCustomers.front() << endl;
    cout << "Last day: " << vectorCustomers.back() << endl;
    cout << "Day 3: " << vectorCustomers.at(2) << endl;

    cout << "Is vector empty? ";
    if (vectorCustomers.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Vector data address: "
         << vectorCustomers.data() << endl;

    // Calculate vector customer statistics
    cout << "\nVector Customer Statistics" << endl;

    cout << "Maximum customers: "
         << *max_element(vectorCustomers.begin(),
                         vectorCustomers.end())
         << endl;

    cout << "Minimum customers: "
         << *min_element(vectorCustomers.begin(),
                         vectorCustomers.end())
         << endl;

    cout << "Total customers: "
         << accumulate(vectorCustomers.begin(),
                       vectorCustomers.end(), 0)
         << endl;

    // Make a copy to preserve the original vector data
    vector<int> sortedVector = vectorCustomers;

    // Sort vector in ascending order
    sort(sortedVector.begin(), sortedVector.end());

    cout << "\nVector sorted in ascending order:" << endl;

    for (int value : sortedVector)
    {
        cout << value << " ";
    }
    cout << endl;

    // Sort vector in descending order
    sort(sortedVector.rbegin(), sortedVector.rend());

    cout << "\nVector sorted in descending order:" << endl;

    for (int value : sortedVector)
    {
        cout << value << " ";
    }
    cout << endl;

    // Search the original vector for a customer count
    vector<int>::iterator vectorIt;

    vectorIt = find(vectorCustomers.begin(),
                    vectorCustomers.end(), target);

    cout << "\nVector searching for "
         << target << " customers:" << endl;

    if (vectorIt != vectorCustomers.end())
    {
        cout << "Found on day "
             << vectorIt - vectorCustomers.begin() + 1
             << endl;
    }
    else
    {
        cout << "Customer count not found." << endl;
    }

    return 0;
}