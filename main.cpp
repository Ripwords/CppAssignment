#include "functions.h"

using namespace std;

int main()
{
    // READ THE DATABASE AND STORE THEM IN VARIABLES
    auto data = readFile("database.txt");
    auto parcelData = readParcelData("parcelData.txt");

    // MAIN PROGRAM
    while (true)
    {
        draw_WELCOME();
        draw_TO();
        draw_PARCEL_SYSTEM();
        cout << "\t\t\n\t Press ENTER to continue >> ";
        cin.get();
        system("cls");
        string choice;
        draw_PARCEL_SYSTEM2();
        display_selection(choice);
        if (choice == "M" || choice == "m")
        {
            system("cls");
            managementLogIn(data, parcelData);
            updateUserDatabase(data, "database.txt");
            updateParcelDatabase(parcelData, "parcelData.txt");
            cin.clear();
            cin.ignore(512, '\n');
            continue;
        }
        else if (choice == "R" || choice == "r")
        {
            system("cls");
            residentLogIn(data, parcelData);
            updateUserDatabase(data, "database.txt");
            updateParcelDatabase(parcelData, "parcelData.txt");
            cin.clear();
            cin.ignore(512, '\n');
            continue;
        }
        else if (choice == "E" || choice == "e")
        {
            break;
        }
        else
        {
            display_invalid_input();
            system("cls");
            continue;
        }
    }
    return 0;
}