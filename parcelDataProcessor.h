#include "INCLUDES.h"

// FUNCTION TO READ THE PARCEL DATABASE TEXT FILE AND STORE IN DATA STRUCTURE
// PARCEL DATA IS STORED IN THE FOLLOWING DATA STRUCTURE
// DATA = {
//     {
//         LOCKER_ID, {
//             CURRENT_STATUS,
//             PHONE NUMBER,
//             OTP
//         }
//     }
// }

map<int, vector<string>> readParcelData(string filename)
{
    // Reading file
    ifstream FILE;
    FILE.open(filename);
    if (!FILE)
    {
        cerr << "Error reading " << filename << endl;
    }

    // Declaring variables
    string lockerID;
    string currentStatus;
    string phoneNumber;
    string pinNumber;
    map<int, vector<string>> data;

    // Function to store data in the dictionary
    auto storeData = [](map<int, vector<string>> &data, int lockerID, string currentStatus, string phoneNumber, string pinNumber)
    {
        data[lockerID].push_back(currentStatus);
        data[lockerID].push_back(phoneNumber);
        data[lockerID].push_back(pinNumber);
    };

    // while loop to retrieve all the data from the database
    while (getline(FILE, lockerID, ','))
    {
        getline(FILE, currentStatus, ',');
        getline(FILE, phoneNumber, ',');
        getline(FILE, pinNumber, '\n');

        if (data.find(stoi(lockerID)) == data.end())
        {
            data[stoi(lockerID)] = {};
            storeData(data, stoi(lockerID), currentStatus, phoneNumber, pinNumber);
        }
        else
        {
            storeData(data, stoi(lockerID), currentStatus, phoneNumber, pinNumber);
        }
    }

    // Close the file after reading
    FILE.close();

    return data;
}

// FUNCTION TO GENERATE OTP
// ONLY to be used in this file
string generateOTP()
{
    string OTP;
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
    {
        string num = to_string(rand() % 10);
        OTP += num;
    }

    return OTP;
}

// FUNCTION TO PRINT OUT ALL THE LOCKER INFORMATION ( FOR MANAGEMENT ONLY )
void showLockerInfo(map<int, vector<string>> data, int lockerID)
{
    for (int i = 1; i < 31; i++)
    {
        if (i == lockerID)
        {
            string names[3] = {"Status", "Phone Number", "OTP"};
            for (int j = 0; j < 3; j++)
            {
                cout << "___________________________________________________________________________________________________________________\n";
                cout << "\n\t\t\t\t" << left << setw(12) << names[j] << " : " << data[i][j] << endl;
            }
            cout << "___________________________________________________________________________________________________________________\n" << endl;
        }
    }
    cin.clear();
    cout << "Press enter to continue >> ";
    cin.ignore(512, '\n');
    cin.get();
}

// FUNCTION TO PLACE PARCEL IN THE DATABASE ( FOR MANAGEMENT ONLY )
string placeParcel(map<int, vector<string>> &data, int lockerID, string phoneNumber)
{
    string OTP = "000000";
    if (data[lockerID][0] == "EMPTY")
    {
        OTP = generateOTP();
        data[lockerID][0] = "OCCUPIED";
        data[lockerID][1] = phoneNumber;
        data[lockerID][2] = OTP;
    }
    return OTP;
}

// FUNCTION TO RETRIEVE THE PARCEL, AND UPDATE THE DATABASE ( FOR RESIDENTS ONLY )
void retrieveParcel(map<int, vector<vector<string>>> data, map<int, vector<string>> &parcelData, int lockerID, int unit, string phoneNumber, string inputPin)
{
    if (checkInfo(data, unit, "phone", phoneNumber))
    {
        if (inputPin == parcelData[lockerID][2])
        {
            parcelData[lockerID][0] = "EMPTY";
            parcelData[lockerID][1] = "0";
            parcelData[lockerID][2] = "000000";
        }
    }
}

// Function to check if phone number is in the parcel DATABASE
vector<int> phoneCheck(map<int, vector<string>> &data, string phone)
{
    vector<int> output;
    int lockerID = 0;
    for (pair<int, vector<string>> el : data)
    {
        if (phone == data.at(el.first)[1])
        {
            output.push_back(el.first);
        }
    }
    return output;
}

// FUNCTION TO UPDATE THE PARCEL DATABASE TEXT FILE
void updateParcelDatabase(map<int, vector<string>> &data, string filename)
{
    ofstream FILE;
    FILE.open(filename, ios::out);

    for (pair<int, vector<string>> el : data)
    {
        FILE << el.first << ",";
        for (int i = 0; i < el.second.size(); i++)
        {
            if (i == el.second.size() - 1)
            {
                FILE << el.second[i] << endl;
            }
            else
            {
                FILE << el.second[i] << ",";
            }
        }
    }
}