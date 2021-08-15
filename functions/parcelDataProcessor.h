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

void showLockerInfo(map<int, vector<string>> data)
{
    for (int i = 1; i < data.size() + 1; i++)
    {
        cout << i << " ";
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
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

// TODO Place Parcel Function is only for management's use
void placeParcel(map<int, vector<string>> &data, int lockerID, string unit, string phoneNumber)
{
    if (data[lockerID][1] == "EMPTY")
    {
        string OTP = generateOTP();
        data[lockerID][0] = unit;
        data[lockerID][1] = "OCCUPIED";
        data[lockerID][2] = phoneNumber;
        data[lockerID][3] = OTP;
        // function to send out the OTP to user to be placed here using the OTP variable
    }
}

void retrieveParcel(map<int, vector<vector<string>>> data, map<int, vector<string>> &parcelData, int lockerID, int unit, string phoneNumber, string inputPin)
{
    while (true)
    {
        if (checkInfo(data, unit, "phone", phoneNumber))
        {
            int tries = 0;
            while (tries < 3)
            {
                if (inputPin == parcelData[lockerID][3])
                {
                    parcelData[lockerID][0] = "0";
                    parcelData[lockerID][1] = "EMPTY";
                    parcelData[lockerID][2] = "0";
                    parcelData[lockerID][3] = "000000";
                    // message after retrieving parcel
                }
                else
                {
                    // Error message, entered wrong pinNumber
                    tries++;
                    char redo;
                    cin >> redo;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(512, '\n');
                        // input error message here
                        continue;
                    }
                    if (redo == 'y')
                    {
                        continue;
                    }
                    else if (redo == 'n')
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            // Entered a unit number of phone number that does not exist, error message here
            char redo;
            cin >> redo;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
                // input error message here
                continue;
            }
            if (redo == 'y')
            {
                continue;
            }
            else if (redo == 'n')
            {
                break;
            }
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