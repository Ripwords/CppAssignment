#include <iostream>
#include <fstream>
#include <string>
#include "functions/dataProcessor.h"

using namespace std;

int main()
{
    // LOAD THE DATA
    auto data = readFile("database.txt");

    // UPDATE THE DATA
    string newUpdate = "011226140991";
    updateData(data, 12, "ic", newUpdate);

    // SIMPLE CHECK FOR UPDATE
    cout << data[12][0][dictionary["ic"]] << endl;
    cout << checkInfo(data, 12, "ic", newUpdate) << endl;

    // UPDATE THE DATABASE AT THE END OF MAIN LOOP
    // OR
    // UPDATE AT THE END OF UPDATE
    updateDatabase(data, "database.txt");
    return 0;
}