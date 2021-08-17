#include "functions/functions.h"

using namespace std;

int main()
{
    auto data = readFile("database.txt");
    auto parcelData = readParcelData("parcelData.txt");

    while (true)
    {
        draw_WELCOME();
        draw_TO();
        draw_PARCEL_SYSTEM();
        cout << "\t\t\n\t Press ENTER to continue >> ";
        string choice;
        display_selection(choice);
        if (choice == "M" || choice == "m")
        {
            managementLogIn(data, parcelData);
        }
        else if (choice == "R" || choice == "r")
        {
            residentLogIn(data, parcelData);
        }
        else if (choice == "E" || choice == "e")
        {
            break;
        }
        else
        {
            display_invalid_input();
            continue;
        }
    }

    updateUserDatabase(data, "database.txt");
    updateParcelDatabase(parcelData, "parcelData.txt");
    return 0;
}