#include "dataProcessorIncludes.h"

using namespace std;

map<int, vector<string>> readParcelData(string filename)
{
    ifstream FILE(filename);
    FILE.open(filename);
    if (!FILE)
    {
        cerr << "Error reading " << filename << endl;
    }

    string unit;
    string lockerID;
    string currentStatus;

    map<int, vector<string>> data;

    auto storeData = [](auto &data, int unit, string lockerID, string currentStatus)
    {
        data[unit].push_back(lockerID);
        data[unit].push_back(currentStatus);
    };

    while (getline(FILE, lockerID, ','))
    {
        getline(FILE, currentStatus, ',');
        getline(FILE, unit, '\n');

        if (data.find(stoi(unit)) == data.end())
        {
            data[stoi(unit)] = {};
            storeData(data, stoi(unit), lockerID, currentStatus);
        }
        else
        {
            storeData(data, stoi(unit), lockerID, currentStatus);
        }
    }

    FILE.close();

    return data;
}