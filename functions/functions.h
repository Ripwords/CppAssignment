#include "dataProcessor.h"
#include "parcelDataProcessor.h"
#include "../prettyStrings/pretty.h"
#include <cctype>

void residentLogIn(map<int, vector<vector<string>>> data)
{
    int unitNumber;
    string phoneNumber;
    draw_PARCEL_SYSTEM2();
    display_RESIDENT_LOGIN();

    cout << "\t\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";
    cout << "\t\n\t                      			   		  	";
    cout << "\t\n\tPlease enter the Unit Number  >> ";
    cin >> unitNumber;
    cout << "\t\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\t\n\n\tPlease enter the Phone Number >> ";

    bool unitChecked = checkRegistration(data, unitNumber);
    if (!unitChecked)
    {
        // returns error message that unit is not registered
        cerr << /* Error Message*/ "Error" << endl;
        exit(0);
    }
    else
    {
        // continues
        cin >> phoneNumber;
        cout << "\t\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";
        bool phoneChecked = checkInfo(data, unitNumber, "phone", phoneNumber);
        if (!phoneChecked)
        {
            // returns error message that phone number is wrong
            cerr << /* Error Message*/ "Error" << endl;
        }
    }
}

void managementLogIn()
{
    string ManagementID;
    string ManagementPS;
    string managementIDStandard = "ID";
    string managementPSStandard = "PS";

    draw_PARCEL_SYSTEM2();
    display_MANAGEMENT_LOGIN();

    cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";
    cout << "\n\t\t\t\t                      			";
    cout << "\n\t\t\t\t   Management ID  : ";
    cin >> ManagementID;
    cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\t\t\t\t   Password       : ";
    cin >> ManagementPS;
    cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";

    system("cls");

    bool password = ManagementPS.compare(managementPSStandard);
    bool ID = ManagementID.compare(managementIDStandard);
    if (!ID)
    {
        if (!password)
        {
            // write anything here in case the program is working.
        }
        else
        {
            cerr << /* Wrong Password*/ "Wrong Password";
            exit(0);
        }
    }
    else
    {
        cerr << /* Wrong ID*/ "Wrong ID" << endl;
        exit(0);
    }
}

void searchForResident(map<int, vector<vector<string>>> data)
{
    int unitNumber;
    cout << "Unit Number: ";
    cin >> unitNumber;
    searchData(data, unitNumber);
}

void managementOptions(map<int, vector<vector<string>>> data, map<int, vector<string>> parcelData)
{
    int option;

    cout << "\nPlease select Choose an option :" << endl;
    do
    {
        cout << "1) Parcel info\n2) Search\n3) Register\n4) Update\n5) Exit\n(1 / 2 / 3 / 4 /5)" << endl;
        cin >> option;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            while (option < 1 || option > 5)
            {
                cout << "Please enter a valid choice" << endl;
                cout << "1) Parcel info\n2) Search\n3) Register\n4) Update\n5) Exit\n(1 / 2 / 3 / 4/ 5)" << endl;
                cin >> option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(512, '\n');
                    continue;
                }
            }
        }

        switch (option)
        {
        case 1:
            system("cls");
            cout << "Parcel Info" << endl;
            showEmptyLocker(parcelData);
            cout << endl;

            break;

        case 2:
            system("cls");
            cout << "Search For Residents";
            searchForResident(data);

            break;

        case 3:
            system("cls");
            cout << "Register New Resident";
            break;

        case 4:
            system("cls");
            cout << "Update an Existing Resident";
            break;

        case 5:
            system("cls");
            cout << "EXITED" << endl;
        }
    } while (option != 5);
}