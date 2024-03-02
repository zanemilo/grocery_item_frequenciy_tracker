/* File: main.cpp
Purpose: This program is designed to track item frequencies for the Corner Grocer.

Author: Zane Deso
Date: 02/23/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// HEADER START
#ifndef CGGROCER_H
#define CGGROCER_H

#include <vector>
#include <string>
#include <map>

class cGGrocer {
private: // Declare Private Vars for cGGrocer Class

public: // Declare Public vars for cGGrocer Class

    void loadItemsFromFile(vector<string>& items, const string& filename); 
    void calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename); // Method to calculate the balance with out monthly deposits for each year
    void printHistogram(const vector<string>& items); // Method to calculate the balance with monthly deposits for each year
    void printAllItemFrequencies(const vector<string>& items); // Method to update balances after each calculation
    int findItemFrequency(const vector<string>& itemList, const string& item);
    void showMenu();
    
}; // cGGrocer Class

#endif // CGGROCER_H
// HEADER END



































// CPP START
cGGrocer::cGGrocer() {
    // Constructor can be used to initialize any resources if needed
}

void cGGrocer::loadItemsFromFile(vector<string>& items, const string& filename) {
    ifstream file(filename); // Open the file
    if (!file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return;
    }

    string item;
    while (file >> item) { // Read each word (item) from the file
        items.push_back(item);
    }

    file.close(); // Close the file
}


void cGGrocer::calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename) {
    // Use a map to count the frequency of each item
    map<string, int> frequencyMap;
    for (size_t i = 0; i < items.size(); ++i) {
        // Increment the frequency count for each item
        frequencyMap[items[i]]++;
    }

    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Could not open the file for writing - '" << filename << "'" << endl;
        return;
    }

    // Iterate over the map and write each item and its frequency to the file
    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        outFile << it->first << " " << it->second << "\n";
    }

    // Close the file
    outFile.close();
}

void cGGrocer::printHistogram(const vector<string>& items) {
    // Use a map to count the frequency of each item
    map<string, int> frequencyMap;
    for (size_t i = 0; i < items.size(); ++i) {
        frequencyMap[items[i]]++;
    }
    
    // Iterate over the map and print each item and its frequency as a histogram
    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        cout << it->first << " ";
        // Print asterisks equal to the frequency of the item
        for (int j = 0; j < it->second; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void cGGrocer::printAllItemFrequencies(const vector<string>& items) {
    // Use a map to count the frequency of each item
    map<string, int> frequencyMap;
    for (size_t i = 0; i < items.size(); ++i) {
        // Increment the frequency count for each item
        frequencyMap[items[i]]++;
    }
    
    // Iterate over the map and print each item and its frequency
    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}


int cGGrocer::findItemFrequency(const vector<string>& itemList, const string& item) { // Function to find and return the frequency of an item in the list
    int count = 0;
    for (size_t i = 0; i < itemList.size(); ++i) {
        if (itemList[i] == item) {
            ++count;
        }
    }
    return count;
}

void cGGrocer::showMenu() {
    cout << "\n==== Corner Grocer Item Tracker ====\n";
    cout << "1. Search for an item frequency\n";
    cout << "2. Display frequency of all items\n";
    cout << "3. Show histogram of item frequencies\n";
    cout << "4. Exit\n";
    cout << "Please select an option: ";
}
// CPP END





























// MAIN START
int main() {
    vector<string> items;
    int choice;
    string searchItem;
    // cGGrocer grocer; // Create instance of Grocer Class

    
    // grocer.loadItemsFromFile(items, "CS210_Project_Three_Input_File.txt"); // Load items from file
    // grocer.calculateFrequenciesAndWriteToFile(items, "frequency.dat"); // Create and write to the data file immediately after loading items

    do {
        cGGrocer grocer; // Create instance of Grocer Class

    
        grocer.loadItemsFromFile(items, "CS210_Project_Three_Input_File.txt"); // Load items from file
        grocer.calculateFrequenciesAndWriteToFile(items, "frequency.dat"); // Create and write to the data file immediately after loading items
        
        grocer.showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the item you wish to look for: ";
                cin >> searchItem;
                int frequency = grocer.findItemFrequency(items, searchItem);
                cout << "Frequency of '" << searchItem << "': " << frequency << endl;
                break;
            }
            case 2:
                grocer.printAllItemFrequencies(items);
                break;
            case 3:
                grocer.printHistogram(items); // Call the function to print the histogram of item frequencies
                break;
            case 4:
                cout << "Exiting program. Thank you for using the Corner Grocer Item Tracker.\n";
                break;
            default:
                cout << "Invalid option selected. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
} // main
// MAIN END