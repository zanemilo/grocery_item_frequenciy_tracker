/* File: altMain.cpp
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
    cGGrocer(); // Declare Constructor method
    void loadItemsFromFile(vector<string>& items, const string& filename); // Opens and reads file contents from "CS210_Project_Three_Input_File.txt" and add the file contents to a vector
    void calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename); // Calculate the frequencies of each word from "CS210_Project_Three_Input_File.txt" and save the outcomes to given file name
    void printHistogram(const vector<string>& items); // Count and print a 'bar graph' with '*' to show the frequency of each word in the given vector
    void printAllItemFrequencies(const vector<string>& items); // Count and print every items frequency in the given vector
    int findItemFrequency(const vector<string>& itemList, const string& item); // Search a vector for the frequency of the input string
    void showMenu();
    
}; // cGGrocer Class

#endif // CGGROCER_H
// HEADER END


// CPP START
cGGrocer::cGGrocer() { // Constructor used to initialize class
    
} // cGGrocer()

void cGGrocer::loadItemsFromFile(vector<string>& items, const string& filename) { // Opens and reads file contents from "CS210_Project_Three_Input_File.txt" and add the file contents to a vector
    ifstream file(filename); // Open the file
    if (!file.is_open()) { // if file cannot be opened
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return;
    } // if

    string item; // Declare local string variable
    while (file >> item) { // Read each word (item) from the file
        items.push_back(item);
    } // if

    file.close(); // Close the file
} // loadItemsFromFile(vector<string>& items, const string& filename)

void cGGrocer::calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename) { // Calculate the frequencies of each word from "CS210_Project_Three_Input_File.txt" and save the outcomes to given file name
    map<string, int> frequencyMap; // Use a map to count the frequency of each item
    for (size_t i = 0; i < items.size(); ++i) { // Increment the frequency count for each item
        frequencyMap[items[i]]++;
    } // for

    ofstream outFile(filename); // Open the file for writing
    if (!outFile.is_open()) {
        cerr << "Could not open the file for writing - '" << filename << "'" << endl;
        return;
    } // if

    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { // Iterate over the map and write each item and its frequency to the file
        outFile << it->first << " " << it->second << "\n";
    } // for

    outFile.close(); // Close the file
} // calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename)

void cGGrocer::printHistogram(const vector<string>& items) { // Count and print a 'bar graph' with '*' to show the frequency of each word in the given vector
    map<string, int> frequencyMap; // Use a map to count the frequency of each item
    for (size_t i = 0; i < items.size(); ++i) {
        frequencyMap[items[i]]++;
    } // for
    
    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { // Iterate over the map and print each item and its frequency as a histogram
        cout << it->first << " ";

        for (int j = 0; j < it->second; ++j) { // Print asterisks equal to the frequency of the item
            cout << "*";
        } // for
        cout << endl;
    } // for
} // printHistogram(const vector<string>& items)

void cGGrocer::printAllItemFrequencies(const vector<string>& items) { // Count and print every items frequency in the given vector
    map<string, int> frequencyMap; // Use a map to count the frequency of each item
    for (size_t i = 0; i < items.size(); ++i) {
        // Increment the frequency count for each item
        frequencyMap[items[i]]++;
    } // for
    
    for (map<string, int>::const_iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { // Iterate over the map and print each item and its frequency
        cout << it->first << " " << it->second << endl;
    } // for
} // printAllItemFrequencies(const vector<string>& items)

int cGGrocer::findItemFrequency(const vector<string>& itemList, const string& item) { // Function to find and return the frequency of an item in the list
    int count = 0;
    for (size_t i = 0; i < itemList.size(); ++i) {
        if (itemList[i] == item) {
            ++count;
        } // if
    } // for
    return count;
} // findItemFrequency(const vector<string>& itemList, const string& item)

void cGGrocer::showMenu() { // Print Menu Options
    cout << "\n==== Corner Grocer Item Tracker ====\n";
    cout << "1. Search for an item frequency\n";
    cout << "2. Display frequency of all items\n";
    cout << "3. Show histogram of item frequencies\n";
    cout << "4. Exit\n";
    cout << "Please select an option: ";
} // showMenu()
// CPP END


// MAIN START
int main() {
    vector<string> items; // declare items vector to hold data from file
    int choice; // declare int variable to handle storing user input for menu option choice
    string searchItem; // declare string variable to handle user input for item to search for in case 1
    cGGrocer grocer; // Create instance of Grocer Class

    
    grocer.loadItemsFromFile(items, "CS210_Project_Three_Input_File.txt"); // Load items from file and add them to items vector
    grocer.calculateFrequenciesAndWriteToFile(items, "frequency.dat"); // Create and write to the data file immediately after loading items

    do {
        grocer.showMenu(); // display menu options to user
        cin >> choice; // get users input for choice

        switch (choice) { // switch case to handle and validate users choice
            case 1: { // "1. Search for an item frequency\n";
                cout << "Enter the item you wish to look for: ";
                cin >> searchItem; // Get item to search for from user
                int frequency = grocer.findItemFrequency(items, searchItem); // get item frequency from items vector
                cout << "Frequency of '" << searchItem << "': " << frequency << endl; // output frequency of item searched for
                break;
            }
            case 2: // "2. Display frequency of all items\n";
                grocer.printAllItemFrequencies(items); // get and display all item frequency from items vector
                break;
            case 3: // "3. Show histogram of item frequencies\n";
                grocer.printHistogram(items); // Call the function to print the histogram of item frequencies from items vector
                break;
            case 4: // "4. Exit\n";
                cout << "Exiting program. Thank you for using the Corner Grocer Item Tracker.\n";
                break;
            default: // If choice not in above cases, then default to this outcome
                cout << "Invalid option selected. Please try again.\n";
        } // Switch
    } while (choice != 4); // do while

    return 0;
} // main
// MAIN END