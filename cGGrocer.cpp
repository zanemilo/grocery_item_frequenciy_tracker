/* File: cGGrocer.cpp
Purpose: This program is designed to track item frequencies for the Corner Grocer.

Author: Zane Deso
Date: 02/23/2024
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "cGGrocer.h"

using namespace std;

cGGrocer::cGGrocer() {}

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



