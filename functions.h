#include "dataProcessor.h"
#include "parcelDataProcessor.h"
#include "pretty.h"
#include <cctype>

void searchForResident(map<int, vector<vector<string>>> &data)
{
    int unitNumber;
    string return_option;

    while (true)
    {
        draw_PARCEL_SYSTEM2();
        display_title("Search Residents");
        cout << "\n\n\t\t\tPlease enter the Unit Number: ";
        cin >> unitNumber;
        if (!checkRegistration(data, unitNumber))
        {
            cin.clear();
            cin.ignore(512, '\n');
            display_error_msg("Unit Number", " ", return_option);
            if (return_option == "1")
            {
                system("cls");
                continue;
            }
            else if (return_option == "0")
            {
                system("cls");
                return;
            }
            else
            {
                display_invalid_input();
                return;
            }
        }
        break;
    }
    searchData(data, unitNumber);
    cin.clear();
    cin.ignore(512, '\n');
    cout << "\nPress enter to continue >> ";
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
    string return_option = "0";
    while (true)
    {
        display_title("Registration");
        cout << "\n\t\t\t\t   Unit Number     : ";
        cin >> unit;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            display_error_msg("Unit Number", " ", return_option);
            if (return_option == "1")
            {
                system("cls");
                break;
            }
            else if (return_option == "0")
            {
                system("cls");
                return;
            }
            else
            {
                display_invalid_input();
                return;
            }
            system("cls");
        }
        if (return_option == "1")
        {
            return_option = "0";
            continue;
        }

        cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t   Full Name       : ";
        cin.clear();
        cin.ignore(512, '\n');
        getline(cin, name);
        cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t   Phone Number    : ";
        cin >> phone;
        cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t   Email Address   : ";
        cin >> email;
        cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t   IC Number       : ";
        cin >> ic;
        system("cls");
        draw_PARCEL_SYSTEM2();
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Unit Number   |  " << setw(23) << left << unit << "| ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Full Name     |  " << setw(23) << left << name << "| ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Phone Number  |  " << setw(23) << left << phone << "|";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| Email Address |  " << setw(23) << left << email << "|";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n\t\t\t\t\t| IC Number     |  " << setw(23) << left << ic << "|   ";
        cout << "\n\t\t\t\t\t+----------------------------------------+   ";
        cout << "\n___________________________________________________________________________________________________________________\n\n";
        string YorN;
        cout << "Please confirm the entered information YES (Y) or NO (N) >> ";
        cin >> YorN;
        if (YorN == "y" || YorN == "Y")
        {
            display_updateSuccessful("<REGISTERED>");
            cin.clear();
            cin.ignore(512, '\n');
            cin.get();
            break;
        }
        else if (YorN == "n" || YorN == "N")
        {
            cout << "\nDo you want to modify your information? Y(retry) or N(Exit) >> ";
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
            display_invalid_input();
            return;
        }
    }
    vector<string> registration = {to_string(unit), name, phone, email, ic};
    registerNew(data, registration);
}

// FOR MANAGEMENT ONLY
void updateUserData(map<int, vector<vector<string>>> &data)
{
    int unit;
    string dataCode;
    string update;
    string currentInfo;
    string option;
    string return_option;

    while (true)
    {
        while (true)
        {
            draw_PARCEL_SYSTEM2();
            display_title("User Update");
            cout << "\n\n\t\t\t\t  Please key in the Unit Number   : ";
            cin >> unit;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
                system("cls");
                display_error_msg("Unit Number", " ", return_option);
                if (return_option == "1")
                {
                    system("cls");
                    continue;
                }
                else if (return_option == "0")
                {
                    system("cls");
                    return;
                }
                else
                {
                    display_invalid_input();
                    system("cls");
                    return;
                }
            }
            else
            {
                if (!checkRegistration(data, unit))
                {
                    cout << "\n\t\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
                    cout << "\n\t\t   * |############################################| *";
                    cout << "\n\t\t   * |                                            | *";
                    cout << "\n\t\t   * |   Unit is not registered in the database   | *";
                    cout << "\n\t\t   * |          please refer to management        | *";
                    cout << "\n\t\t   * |                                            | *";
                    cout << "\n\t\t   * |############################################| *";
                    cout << "\n\t\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
                    cout << "\n___________________________________________________________________________________________________________________\n";
                    cin.clear();
                    cin.ignore(512, '\n');
                    cout << "\n\t\t Press ENTER to return MENU >> ";
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
                display_error_msg("OPTION", " ", return_option);
                if (return_option == "1")
                {
                    system("cls");
                    continue;
                }
                else if (return_option == "0")
                {
                    system("cls");
                    return;
                }
                else
                {
                    display_invalid_input();
                    system("cls");
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
                cout << "\n\n\t\t\tPlease enter the old phone number       : ";
                cin >> currentInfo;

                if (checkInfo(data, unit, "phone", currentInfo))
                {
                    cout << "\n\n\t\t\tPlease enter the new phone number       : ";
                    cin >> update;
                }
                else
                {
                    display_error_msg("Phone Number", " ",return_option) ;
                    if (return_option == "0")
                    {
                        system("cls");
                        return;
                    }
                    else if (return_option == "1")
                    {
                        system("cls");
                        continue;
                    }
                    else
                    {
                        display_invalid_input();
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
                display_title("User Update");
                cout << "\n\n\t\t\tPlease enter the old Email       : ";
                cin >> currentInfo;

                if (checkInfo(data, unit, "email", currentInfo))
                {
                    cout << "\n\n\t\t\tPlease enter the new Email       : ";
                    cin >> update;
                }
                else
                {
                    string errorOption;
                    display_error_msg("Email", " ", errorOption);
                    if (errorOption == "0")
                    {
                        system("cls");
                        return;
                    }
                    else if (errorOption == "1")
                    {
                        system("cls");
                        continue;
                    }
                    else
                    {
                        display_invalid_input();
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
    display_updateSuccessful("<UPDATED>");
    cin.clear();
    cin.ignore(512, '\n');
    cin.get();
    system("cls");
}

// Pending creating user interface
void deleteUser(map<int, vector<vector<string>>> &data)
{
    string unit;
    string name;
    string phone;
    string email;
    string ic;
    string YorN;
    while (true)
    {
        draw_PARCEL_SYSTEM2();
        display_title("Delete User");
        display_deleteUser(unit, ic, YorN);
        if (YorN == "y" || YorN == "Y")
        {
            cout << "\n\n\t===============================================================" << endl;
            cout << "\t**             User Information has been ERASED !            **" << endl;
            cout << "\t===============================================================" << endl;
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\n\n\t\t\t Press ENETR to exit >> ";
            cin.get();
            break;
        }
        else if (YorN == "n" || YorN == "N")
        {
            cout << "\nDo you still want to modify your input? Y(Retry) or N(Exit) >> ";
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
            display_invalid_input();
            return;
        }
    }
    deleteFromDatabase(data, stoi(unit), ic);
}

// Pending creating user interface
void parcelRetrieval(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData, int unit, string phone)
{
    int tries = 3;
    vector<int> lockerID = phoneCheck(parcelData, phone);
    string OTP;
    if (lockerID.size() == 0)
    {
        cout << "\n\n\t=====================================================================" << endl;
        cout << "\t* No parcel is recieved, any enquiry please refer to the management *" << endl;
        cout << "\t=====================================================================" << endl;
        cin.clear();
        cin.ignore(512, '\n');
        cout << "\n\n\t\t\t Press ENETR to exit >> ";
        cin.get();
        system("cls");

        return;
    }
    while (tries >= 0)
    {
        display_title("Parcel Collect");
        cout << "\n\t\t\t Please enter your given OTP >> ";
        cin >> OTP;
        cout << endl;
        for (int i = 0; i < lockerID.size(); i++)
        {
            if (OTP == parcelData[lockerID[i]][2])
            {
                cout << "\n\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
                cout << "\n\t   * |############################################| *";
                cout << "\n\t   * |                                            | *";
                cout << "\n\t   * |                 Thank You                  | *";
                cout << "\n\t   * |   Parcel has been retrieved successfully   | *";
                cout << "\n\t   * |                                            | *";
                cout << "\n\t   * |############################################| *";
                cout << "\n\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
                cout << "\n___________________________________________________________________________________________________________________\n";
                retrieveParcel(data, parcelData, lockerID[i], unit, phone, OTP);
                cin.clear();
                cin.ignore(512, '\n');
                cout << "\n\n\t\t\t Press ENTER to exit >> ";
                cin.get();
                system("cls");
                return;
            }
        }
        cout << "\n\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
        cout << "\n\t   * |############################################| *";
        cout << "\n\t   * |                                            | *";
        cout << "\n\t   * |                INVALID OTP =(              | *";
        cout << "\n\t   * |         You have " << tries-- << " tries remaining         | *";
        cout << "\n\t   * |                                            | *";
        cout << "\n\t   * |############################################| *";
        cout << "\n\t   * *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *";
        cout << "\n___________________________________________________________________________________________________________________\n";
        cin.clear();
        cin.ignore(512, '\n');
        cout << "\n\n\t\t\t Press ENETR to continue >> ";
        cin.get();
        system("cls");
        continue;
    }
    if (tries == -1)
    {
        display_invalid_input();
        system("cls");
    }
}

void userMenu(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData, int unit, string phone)
{
    // Retrieve parcel, update user information
    while (true)
    {
        string option;
        display_user_option(option);
        system("cls");
        if (option != "1" && option != "2" && option != "3")
        {
            display_invalid_input();
            system("cls");
            continue;
        }
        system("cls");
        if (option == "1")
        {
            parcelRetrieval(data, parcelData, unit, phone);
            continue;
        }
        else if (option == "2")
        {
            updateUserData(data);
            continue;
        }
        else if (option == "3")
        {
            return;
        }
    }
}

void residentLogIn(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    // declaring variables
    int unitNumber;
    string phoneNumber;
    string return_option;

    // printing out user interface
    draw_PARCEL_SYSTEM2();

    while (true)
    {
        // user entering their unit number and phone number
        display_title("RESIDENT LOGIN");
        cout << "\n\t\t\t\t\t                      			   		  	";
        cout << "\n\t\t\t\t\t  Please enter the Unit Number  >> ";
        cin >> unitNumber;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            system("cls");
            display_error_msg("Unit Number", "/ Phone Number", return_option);

            if (return_option == "0")
            {
                return;
            }
            else if (return_option == "1")
            {
                system("cls");
                continue;
            }
            else
            {
                display_invalid_input();
                return;
            }
            continue;
        }
        cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n\t\t\t\t\t  Please enter the Phone Number >> ";
        cin >> phoneNumber;
        system("cls");

        // Functions to check for unit and phone registration
        bool unitChecked = checkRegistration(data, unitNumber);
        bool phoneChecked = checkInfo(data, unitNumber, "phone", phoneNumber);

        if (!unitChecked || !phoneChecked)
        {
            while (true)
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
                else
                {
                    display_invalid_input();
                    return;
                }
            }
            continue;
        }
        else if (unitChecked && phoneChecked)
        {
            userMenu(data, parcelData, unitNumber, phoneNumber);
        }
        break;
    }
}

// Pending creating user interface
void managementMenu(map<int, vector<vector<string>>> &data, map<int, vector<string>> &parcelData)
{
    // declaring variables
    string option;

    while (true)
    {
        draw_PARCEL_SYSTEM2();
        display_management_option(option);
        system("cls");

        if (option != "1" && option != "2" && option != "3" && option != "4" && option != "5")
        {
            display_invalid_input();
            system("cls");
            continue;
        }
        system("cls");

        if (option == "1")
        {
            string return_option = "1";
            int lockerOption;
            cout << "Place Parcel" << endl;
            system("cls");
            while (true)
            {
                display_parcel_info(parcelData);
                cout << "Please enter the EMPTY locker ID to register the parcel >> ";
                cin >> lockerOption;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(512, '\n');
                    display_error_msg("Unit Number", " ", return_option);
                    system("cls");
                    if (return_option == "0")
                    {
                        break;
                    }
                    else if (return_option == "1")
                    {
                        continue;
                    }
                    else
                    {
                        display_invalid_input();
                        break;
                    }
                }
                if (lockerOption > 30 || lockerOption < 1)
                {
                    cin.clear();
                    cin.ignore(512, '\n');
                    display_error_msg("Locker ID", " ", return_option);
                    system("cls");
                    if (return_option == "0")
                    {
                        break;
                    }
                    else if (return_option == "1")
                    {
                        continue;
                    }
                    else
                    {
                        display_invalid_input();
                        break;
                    }
                }
                if (parcelData[lockerOption][0] != "EMPTY")
                {
                    display_error_msg("Locker ID is ", "UNAVAILABLE", return_option);
                    system("cls");
                    if (return_option == "0")
                    {
                        break;
                    }
                    else if (return_option == "1")
                    {
                        continue;
                    }
                    else
                    {
                        display_invalid_input();
                        return;
                    }
                }
                break;
            }
            if (return_option == "1")
            {
                string userPhone;
                while (true)
                {
                    cout << "Enter resident's phone number >> ";
                    cin >> userPhone;
                    if (!checkPhoneNumber(data, userPhone))
                    {
                        cin.clear();
                        cin.ignore(512, '\n');
                        display_error_msg("Phone Number", "is not REGISTERED", return_option);
                        system("cls");

                        if (return_option == "0")
                        {
                            return;
                        }
                        else if (return_option == "1")
                        {
                            display_parcel_info(parcelData);
                            continue;
                        }
                        else
                        {
                            display_invalid_input();
                            system("cls");
                            return;
                        }
                    }
                    break;
                }
                string OTP = placeParcel(parcelData, lockerOption, userPhone);
                display_sendSMS(OTP);
                popUpMsg(OTP, lockerOption);
            }
            system("cls");
            continue;
        }
        else if (option == "2")
        {
            display_title("Searching for..?");
            string choice;
            display_search(choice);
            system("cls");
            if (choice == "1")
            {
                searchForResident(data);
            }
            else if (choice == "2")
            {
                int lockerNum;
                string return_option;

                while (true)
                {
                    draw_PARCEL_SYSTEM2();
                    display_title("Search Locker");
                    cout << "\n\t\t\tPlease enter the Locker ID: ";
                    cin >> lockerNum;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(512, '\n');
                        display_error_msg("Locker Number", " ", return_option);
                        if (return_option == "1")
                        {
                            system("cls");
                            continue;
                        }
                        else if (return_option == "0")
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            display_invalid_input();
                            return;
                        }
                    }
                    if (lockerNum > 30 || lockerNum < 1)
                    {
                        {
                        cin.clear();
                        cin.ignore(512, '\n');
                        display_error_msg("Locker Number", " ", return_option);
                        if (return_option == "1")
                        {
                            system("cls");
                            continue;
                        }
                        else if (return_option == "0")
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            display_invalid_input();
                            return;
                        }
                    }
                    }
                    break;
                }
                if (lockerNum <= 30 && lockerNum >= 1)
                {
                    showLockerInfo(parcelData, lockerNum);
                    system("cls");
                }
                continue;
            }
            else
            {
                display_invalid_input();
            }
            system("cls");
            continue;
        }
        else if (option == "3")
        {
            userRegistration(data);
            system("cls");
            continue;
        }
        else if (option == "4")
        {
            string choice;
            display_title("Edit User Info");
            display_EditUser(choice);
            if (choice == "1")
            {
                system("cls");
                updateUserData(data);
            }
            else if (choice == "2")
            {
                system("cls");
                deleteUser(data);
            }
            else
            {
                display_invalid_input();
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
    string ID = "ID";
    string PW = "PS";

    // printing out user interface

    while (true)
    {
        draw_PARCEL_SYSTEM2();
        display_title("MANAGEMENT LOGIN");
        // management entering their details
        mang_ID_PS_enter(ManagementID, ManagementPS);

        // Functions to check for Management ID and password

        if (ManagementID != ID || ManagementPS != PW)
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
            continue;
        }
        else if (PW == ManagementPS && ID == ManagementID)
        {
            managementMenu(data, parcelData);
        }
        break;
    }
}
