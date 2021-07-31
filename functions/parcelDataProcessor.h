#include "INCLUDES.h"

map<int, vector<string>> readParcelData(string filename)
{
    ifstream FILE;
    FILE.open(filename);
    if (!FILE)
    {
        cerr << "Error reading " << filename << endl;
    }

    string unit;
    string lockerID;
    string currentStatus;

    map<int, vector<string>> data;

    auto storeData = [](map<int, vector<string>> &data, int lockerID, string unit, string currentStatus)
    {
        data[lockerID].push_back(unit);
        data[lockerID].push_back(currentStatus);
    };

    while (getline(FILE, lockerID, ','))
    {
        getline(FILE, currentStatus, ',');
        getline(FILE, unit, '\n');

        if (data.find(stoi(lockerID)) == data.end())
        {
            data[stoi(lockerID)] = {};
            storeData(data, stoi(lockerID), unit, currentStatus);
        }
        else
        {
            storeData(data, stoi(lockerID), unit, currentStatus);
        }
    }

    FILE.close();

    return data;
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
    return emptyLocker;
}

// void placeParcel(map<int, vector<string>> data)
// {
// }

// void retrieveParcel(map<int, vector<string>> data)
// {
// }
