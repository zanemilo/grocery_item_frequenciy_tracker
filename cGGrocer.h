/* File: cGGrocer.h
Purpose: This program is designed to track item frequencies for the Corner Grocer.

Author: Zane Deso
Date: 02/23/2024
*/

#ifndef CGGROCER_H
#define CGGROCER_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class cGGrocer {
private: // Declare Private Vars for cGGrocer Class

public: // Declare Public vars for cGGrocer Class
    cGGrocer(); // Declare Constructor method
    void loadItemsFromFile(vector<string>& items, const string& filename); 
    void calculateFrequenciesAndWriteToFile(const vector<string>& items, const string& filename); 
    void printHistogram(const vector<string>& items); 
    void printAllItemFrequencies(const vector<string>& items); 
    int findItemFrequency(const vector<string>& itemList, const string& item);
    void showMenu();
    
}; // cGGrocer Class

#endif // CGGROCER_H
