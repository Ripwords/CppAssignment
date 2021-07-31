#include "functions/functions.h"

using namespace std;

int main()
{
    // VARIABLES
    string choice;
    string managementID;
    auto data = readFile("database.txt");
    auto parcelData = readParcelData("parcelData.txt");

    draw_WELCOME();
    draw_TO();
    draw_PARCEL_SYSTEM();
    cout << "\n\t Please press ENTER to continue >>";
    cin.get();
    system("cls");
    draw_PARCEL_SYSTEM2();
    display_selection(choice);
    system("cls");
    
    // Specify if the user is a resident or a management based on his choice (choice) || The inputs are 'R' for users and 'M' for management.
    if (choice == "R" || choice == "r")
    
    {
        residentLogIn(data);
        userOptions();
    }
    else if (choice == "M" || choice == "m")
    {
        managementLogIn();
        managementOptions(data, parcelData);
    }
    else
    {
        cerr << "EERRRROORRRR" /*Write an error message*/ "" << endl;
    }

    return 0;
}