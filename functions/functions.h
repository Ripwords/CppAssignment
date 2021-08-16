#include "dataProcessor.h"
#include "parcelDataProcessor.h"
#include "../prettyStrings/pretty.h"
#include <cctype>

void searchForResident(map<int, vector<vector<string>>> &data)
{
    int unitNumber;
    while (true)
    {
        draw_PARCEL_SYSTEM2();
        cout << "\n\t\t\tPlease enter the Unit Number: ";
        cin >> unitNumber;
        if (!checkRegistration(data, unitNumber))
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Invalid Unit Number, (Y) to try again, (N) to leave" << endl;
            string YorN;
            cin >> YorN;
            if (YorN == "y" || YorN == "Y")
            {
                system("cls");
                continue;
            }
            else if (YorN == "n" || YorN == "N")
            {
                return;
            }
            else
            {
                cout << "Invalid input, the program will now leave this menu" << endl;
                return;
            }
        }
        break;
    }
    searchData(data, unitNumber);
    cin.clear();
    cin.ignore(512, '\n');
    cout << "Press enter to continue";
    cin.get();

    system("cls");
}

void userRegistration(map<int, vector<vector<string>>> &data)
{
    int unit;
    string name;
    string phone;
    string email;
    string ic;
    while (true)
    {
        display_registration();
        cout << "\n\t\t\t\t\t   Unit Number     : ";
        cin >> unit;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            display_invalid_input();
            system("cls");
            display_registration();
            cout << "\n\t\t\t\t\t   Unit Number     : ";
            cin >> unit;
        }

        cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t\t   Full Name       : ";
        cin >> name;
        cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t\t   Phone Number    : ";
        cin >> phone;
        cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t\t   Email Adress    : ";
        cin >> email;
        cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t\t   IC Number       : ";
        cin >> ic;
        system("cls");
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Unit Number  | " << setw(25) << unit << "| ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Full Name    | " << setw(25) << name << "| ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Phone Number | " << setw(25) << phone << "|";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Email Adress | " << setw(25) << email << "|";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| IC Number    | " << setw(25) << ic << "|   ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n___________________________________________________________________________________________________________________\n";
        string YorN;
        cout << "Please confirm the entered information YES (Y) or NO (N) >> ";
        cin >> YorN;
        if (YorN == "y" || YorN == "Y")
        {
            break;
        }
        else if (YorN == "n" || YorN == "N")
        {
            cout << "Do you want to re-input your information? Y or N" << endl;
            string YorN_2;
            cin >> YorN_2;
            if (YorN_2 == "Y" || YorN_2 == "y")
            {
                system("cls");
                continue;
            }
            else if (YorN_2 == "N" || YorN_2 == "n")
            {
                return;
            }
        }
        else
        {
            cout << "Invalid input, the program will now leave this menu" << endl;
            return;
        }
    }
    vector<string> registration = {to_string(unit), name, phone, email, ic};
    registerNew(data, registration);
}

void updateUserData(map<int, vector<vector<string>>> &data)
{
    int unit;
    string dataCode;
    string update;
    string currentInfo;
    string option;

    while (true)
    {
        while (true)
        {
            display_title("User Update");
            cout << "\n\t\t\t\t\t                      			";
            cout << "\n\t\t\t\t\t  Please key in the Unit Number   : ";
            cin >> unit;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
                display_invalid_input();
                system("cls");
                string YorN;
                cout << "Do you want to continue? Yes (Y) or NO (N) : " << endl;
                cin >> YorN;
                if (YorN == "Y" || YorN == "y")
                {
                    system("cls");
                    continue;
                }
                else if (YorN == "N" || YorN == "n")
                {
                    return;
                }
                else
                {
                    cout << "Invalid input, the program will now leave this menu" << endl;
                    return;
                }
                continue;
            }
            else
            {
                if (!checkRegistration(data, unit))
                {
                    cout << "\nUnit is not registered in the database, please refer to management\nPress enter to continue" << endl;
                    cin.clear();
                    cin.ignore(512, '\n');
                    cin.get();
                    return;
                }
            }
            break;
        }

        while (true)
        {
            updateUserDataPrintOut();
            cin >> option;
            system("cls");
            if (option != "1" && option != "2")
            {
                cin.clear();
                cin.ignore(512, '\n');
                display_invalid_input();
                system("cls");
                string YorN;
                cout << "Do you want to continue? Yes (Y) or NO (N) : " << endl;
                cin >> YorN;
                if (YorN == "Y" || YorN == "y")
                {
                    system("cls");
                    continue;
                }
                else if (YorN == "N" || YorN == "n")
                {
                    return;
                }
                else
                {
                    cout << "Invalid input, the program will now leave this menu" << endl;
                    return;
                }
                continue;
            }
            break;
        }
        draw_PARCEL_SYSTEM2();
        if (option == "1")
        {
            while (true)
            {
                display_title("User Update");
                cout << "\n\n\t\t\t\t\tPlease enter the old phone number       : ";
                cin >> currentInfo;

                if (checkInfo(data, unit, "phone", currentInfo))
                {
                    cout << "\n\n\t\t\t\t\tPlease enter the new phone number       : ";
                    cin >> update;
                }
                else
                {
                    cout << "The phone number is incorrect" << endl;
                    string errorOption;
                    cout << "\nEnter 0 (return home page) OR 1 (Try again) >> ";
                    cin >> errorOption;
                    if (errorOption == "0")
                    {
                        return;
                    }
                    else if (errorOption == "1")
                    {
                        system("cls");
                        continue;
                    }
                    else
                    {
                        cout << "Invalid input, the program will now leave this menu" << endl;
                        return;
                    }
                }
                dataCode = "phone";
                break;
            }
        }
        else if (option == "2")
        {
            while (true)
            {
                cout << "\n\n\t\t\t\t\tPlease enter the old Email       : ";
                cin >> currentInfo;

                if (checkInfo(data, unit, "email", currentInfo))
                {
                    cout << "\n\n\t\t\t\t\tPlease enter the new Email :";
                    cin >> update;
                }
                else
                {
                    cout << "The email is incorrect" << endl;
                    string errorOption;
                    cout << "\nEnter 0 (return home page) OR 1 (Try again) >> ";
                    cin >> errorOption;
                    if (errorOption == "0")
                    {
                        return;
                    }
                    else if (errorOption == "1")
                    {
                        system("cls");
                        continue;
                    }
                    else
                    {
                        cout << "Invalid input, the program will now leave this menu" << endl;
                        return;
                    }
                }
                dataCode = "email";
                break;
            }
        }
        break;
    }
    updateData(data, unit, dataCode, update, currentInfo);
    cout << "Updated\nPress enter to continue" << endl;
    cin.clear();
    cin.ignore(512, '\n');
    cin.get();
}

// Pending creating user interface
void deleteUser(map<int, vector<vector<string>>> &data)
{
    string unit;
    string ic;

    cin >> unit;
    cin >> ic;
    deleteFromDatabase(data, stoi(unit), ic);
}

// Pending creating user interface
// ! NOT DONE
void parcelRetrieval(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    int lockerID; // determine automatically
}

void userMenu(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    // Retrieve parcel, update user information
    // TODO to be built
    while (true)
    {
        string option;
        display_user_option(option);
        system("cls");
        if (option != "1" || option != "2")
        {
            cout << "Please enter a valid selection" << endl;
            continue;
        }
        system("cls");
        if (option == "1")
        {
            cout << "Parcel Retrieval" << endl;

            continue;
        }
        else if (option == "2")
        {
            cout << "Update Information" << endl;

            continue;
        }
    }
}

void residentLogIn(map<int, vector<vector<string>>> &data)
{
    // declaring variables
    int unitNumber;
    string phoneNumber;
    string return_option;

    // printing out user interface
    draw_PARCEL_SYSTEM2();
    display_title("RESIDENT LOGIN");

    while (true)
    {
        // user entering their unit number and phone number
        user_unit_phone_enter(unitNumber, phoneNumber);

        // Functions to check for unit and phone registration
        bool unitChecked = checkRegistration(data, unitNumber);
        bool phoneChecked = checkInfo(data, unitNumber, "phone", phoneNumber);

        if (!unitChecked || !phoneChecked)
        {
            // returns error message that unit is not registered
            while (return_option != "0" || return_option != "1")
            {
                display_error_msg("Unit Number", "/ Phone Number", return_option);
                system("cls");

                if (return_option == "0")
                {
                    return;
                }
                else if (return_option == "1")
                {
                    break;
                }
                continue;
            }
        }
        else if (unitChecked && phoneChecked)
        {
            // Checks if phone number is in the parcel database

            // userMenu();
        }
        break;
    }
}

// Pending creating user interface
void managementMenu(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    // declaring variables
    string option;

    // printing out the user interface
    draw_PARCEL_SYSTEM2();

    while (true)
    {
        display_management_option(option);
        system("cls");

        if (option != "1" || option != "2" || option != "3" || option != "4" || option != "5")
        {
            cout << "Please enter a valid selection" << endl;
            continue;
        }
        system("cls");

        if (option == "1")
        {
            //TODO write function to place pacel and send sms
            cout << "Parcel Info" << endl;
            showEmptyLocker(parcelData);
            system("cls");
            continue;
        }
        else if (option == "2")
        {
            cout << "Seach for Residents" << endl;
            searchForResident(data);
            system("cls");
            continue;
        }
        else if (option == "3")
        {
            cout << "Register New Resident" << endl;
            userRegistration(data);
            system("cls");
            continue;
        }
        else if (option == "4")
        {
            cout << "Update exisiting resident information" << endl;
            string choice;
            cin >> choice;
            if (choice == "Change Data")
            {
                updateUserData(data);
            }
            else if (choice == "Delete Data")
            {
                deleteUser(data);
            }
            system("cls");
            continue;
        }
        else if (option == "5")
        {
            break;
        }
        break;
    }
}

void managementLogIn(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    // Declaring variables
    string ManagementID;
    string ManagementPS;
    string return_option;
    string managementIDStandard = "ID";
    string managementPSStandard = "PS";

    // printing out user interface
    draw_PARCEL_SYSTEM2();
    display_title("MANAGEMENT LOGIN");

    while (true)
    {
        // management entering their details
        mang_ID_PS_enter(ManagementID, ManagementPS);

        // Functions to check for Management ID and password
        bool password = ManagementPS.compare(managementPSStandard);
        bool ID = ManagementID.compare(managementIDStandard);

        if (!ID || !password)
        {
            // returns error messages if management entered the wrong credentials
            while (return_option != "0" || return_option != "1")
            {
                display_error_msg("Management ID", "/ Password", return_option);
                system("cls");

                if (return_option == "0")
                {
                    return;
                }
                else if (return_option == "1")
                {
                    break;
                }
                continue;
            }
        }
        else if (password && ID)
        {
            managementMenu(data, parcelData);
        }
    }
}
