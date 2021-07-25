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
    string newUpdate = "testing";
    updateData(data, 12, "ic", newUpdate);

    // REGISTRATION FOR NEW USERS
    // registerNew(data, {
    //                       "66",
    //                       "TEST1",
    //                       "TEST2",
    //                       "TEST3",
    //                       "TEST4",
    //                   });

    // REMOVE USER
    // deleteFromDatabase(data, 66, "TEST4");

    // SIMPLE CHECK FOR UPDATE
    // cout << checkInfo(data, 12, "ic", newUpdate) << endl;
    // cout << checkInfo(data, 66, "ic", "TEST4") << endl;

    // UPDATE THE DATABASE AT THE END OF MAIN LOOP
    // OR
    // UPDATE AT THE END OF UPDATE
    updateUserDatabase(data, "database.txt");
    return 0;
}