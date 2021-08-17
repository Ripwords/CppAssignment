#include "INCLUDES.h"

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
    string unit;
    string lockerID;
    string currentStatus;
    string phoneNumber;
    string pinNumber;
    map<int, vector<string>> data;

    // Function to store data in the dictionary
    auto storeData = [](map<int, vector<string>> &data, int lockerID, string unit, string currentStatus, string phoneNumber, string pinNumber)
    {
        data[lockerID].push_back(unit);
        data[lockerID].push_back(currentStatus);
        data[lockerID].push_back(phoneNumber);
        data[lockerID].push_back(pinNumber);
    };

    // while loop to retrieve all the data from the database
    while (getline(FILE, lockerID, ','))
    {
        getline(FILE, unit, ',');
        getline(FILE, currentStatus, ',');
        getline(FILE, phoneNumber, ',');
        getline(FILE, pinNumber, '\n');

        if (data.find(stoi(lockerID)) == data.end())
        {
            data[stoi(lockerID)] = {};
            storeData(data, stoi(lockerID), unit, currentStatus, phoneNumber, pinNumber);
        }
        else
        {
            storeData(data, stoi(lockerID), unit, currentStatus, phoneNumber, pinNumber);
        }
    }

    // Close the file after reading
    FILE.close();

    return data;
}

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

void showLockerInfo(map<int, vector<string>> data, int lockerID)
{
    for (int i = 1; i < 31; i++)
    {
        if (i == lockerID)
        {
            string names[4] = {"Unit", "Status", "Phone Number", "OTP"};
            for (int j = 0; j < 4; j++)
            {
                cout << "\n___________________________________________________________________________________________________________________\n";
                cout << "\t\t\t\t" << left << setw(12) << names[j] << " : " << data[i][j] << endl;
            }
            cout << endl;
        }
    }
    cin.clear();
    cout << "Press enter to continue >> " << endl;
    cin.ignore(512, '\n');
    cin.get();
}

vector<int> showEmptyLocker(map<int, vector<string>> data)
{
    vector<int> emptyLocker;
    for (int i = 1; i < data.size() + 1; i++)
    {
        if (data[i][1] == "EMPTY")
        {
            cout << i << " ";
            emptyLocker.push_back(i);
            for (int j = 0; j < data[i].size(); j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
    return emptyLocker;
}

string placeParcel(map<int, vector<string>> &data, int lockerID, string unit, string phoneNumber)
{
    string OTP = "000000";
    if (data[lockerID][1] == "EMPTY")
    {
        OTP = generateOTP();
        data[lockerID][0] = unit;
        data[lockerID][1] = "OCCUPIED";
        data[lockerID][2] = phoneNumber;
        data[lockerID][3] = OTP;
    }
    return OTP;
}

// Pending refactoring
void retrieveParcel(map<int, vector<vector<string>>> data, map<int, vector<string>> &parcelData, int lockerID, int unit, string phoneNumber, string inputPin)
{
    if (checkInfo(data, unit, "phone", phoneNumber))
    {
        if (inputPin == parcelData[lockerID][3])
        {
            parcelData[lockerID][0] = "0";
            parcelData[lockerID][1] = "EMPTY";
            parcelData[lockerID][2] = "0";
            parcelData[lockerID][3] = "000000";
        }
    }
}

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

// Function to check if phone number is in the parcel DATABASE
int phoneCheck(map<int, vector<string>> &data, string phone)
{
    int lockerID = 0;
    for (pair<int, vector<string>> el : data)
    {
        if (phone == data.at(el.first)[2])
        {
            lockerID = el.first;
        }
    }
    return lockerID;
}