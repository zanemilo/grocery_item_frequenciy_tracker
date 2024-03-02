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
#include "cGGrocer.h"

using namespace std;


int main() {
    vector<string> items;
    int choice;
    string searchItem;
    cGGrocer grocer; // Create instance of Grocer Class

    
    grocer.loadItemsFromFile(items, "CS210_Project_Three_Input_File.txt"); // Load items from file
    grocer.calculateFrequenciesAndWriteToFile(items, "frequency.dat"); // Create and write to the data file immediately after loading items

    do {
        
        
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
