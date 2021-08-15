#include "dataProcessor.h"
#include "parcelDataProcessor.h"
#include "../prettyStrings/pretty.h"
#include <cctype>

void residentLogIn(map<int, vector<vector<string>>> &data)
{
    // declaring variables
    int unitNumber;
    string phoneNumber;
    string return_option;

    // printing out user interface
    draw_PARCEL_SYSTEM2();
    display_RESIDENT_LOGIN();

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
    display_MANAGEMENT_LOGIN();

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

void searchForResident(map<int, vector<vector<string>>> &data)
{
    int unitNumber;
    draw_PARCEL_SYSTEM2(); 
    cout << "\n\t\t\tPlease enter the Unit Number: "; 
    cin >> unitNumber; 
    searchData(data, unitNumber); 
    system("cls"); 
}

void userRegistration(map<int, vector<vector<string>>> &data)
{
    string unit;
    string name;
    string phone;
    string email;
    string ic;
    while (true)
    {
        cout << "\n\t\t\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>\n";
        cout << "\t\t\t\t\t      |                |      \n";
        cout << "\t\t\t\t\t      |  Registration  |      \n";
        cout << "\t\t\t\t\t      |                |      \n";
        cout << "\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<      \n\n";
        cout << "\n\t\t\t\t\t                      			";
        cout << "\n\t\t\t\t\t   Unit Number     : ";
        cin >> unit;
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
        cout << "___________________________________________________________________________________________________________________\n";
        string YorN;
        cout << "Please confirm the entered information YES (Y) or NO (N) >> ";
        cin >> YorN;
        if (YorN == "y" || YorN == "Y")
        {
            break;
        }
        else if (YorN == "n" || YorN == "N")
        {
            continue;
        }
    }

    vector<string> registration = {unit, name, phone, email, ic};
    registerNew(data, registration);
}

void updateUserData(map<int, vector<vector<string>>> &data)
{
    string unit;
    string dataCode;
    string update;
    string currentInfo;
    string option;

    while (true)
    {
        display_USER_UPDATE();
        cout << "\n\t\t\t\t\t                      			";
        cout << "\n\t\t\t\t\t  Please key in the Unit Number   : ";
        cin >> unit;
        updateUserDataPrintOut();
        cin >> option;
        system("cls");
        draw_PARCEL_SYSTEM2();
        display_USER_UPDATE();
        if (option == "1")
        {
            cout << "\n\n\t\t\t\t\tPlease enter the old phone number       : ";
            cin >> currentInfo;

            if (checkInfo(data, stoi(unit), "phone", currentInfo))
            {
                cout << "\n\n\t\t\t\t\tPlease enter the new phone number :";
                cin >> update;
            }
            else
            {
                display_invalid_input();
                string errorOption;
                cout << "\nEnter 0 (return home page) OR 1 (Try again) >> ";
                cin >> errorOption;
            }
        }
        else if (option == "2")
        {
            cout << "\n\n\t\t\t\t\tPlease enter the old Email       : ";
            cin >> currentInfo;

            if (checkInfo(data, stoi(unit), "email", currentInfo))
            {
                cout << "\n\n\t\t\t\t\tPlease enter the new Email :";
                cin >> update;
            }
            else
            {
                display_invalid_input();
                string errorOption;
                cout << "\nEnter 0 (return home page) OR 1 (Try again) >> ";
                cin >> errorOption;
                while (errorOption != "0" || errorOption != "1")
                {
                    if (errorOption == "0")
                    {
                        return;
                    }
                    else if (errorOption == "1")
                    {
                        break;
                    }
                }
                continue;
            }
        }
    }

    updateData(data, stoi(unit), dataCode, update, currentInfo);
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

// Pending creating user interface
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
