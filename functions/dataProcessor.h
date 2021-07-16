#include "dataProcessorIncludes.h"

using namespace std;

map<string, int> dictionary = {
    {"name", 0},
    {"phone", 1},
    {"email", 2},
    {"ic", 3}};

map<int, vector<vector<string>>> readFile(string filename)
{
    ifstream FILE;
    FILE.open(filename);
    if (!FILE) {
        cerr << "Error reading " << filename << endl;
    }

    string unit;
    string name;
    string phone;
    string email;
    string ic;

    map<int, vector<vector<string>>> data;

    auto storeData = [](auto &data, int unit, string name, string phone, string email, string ic)
    {
        if (data[unit][0].size() < 4)
        {
            data[unit][0].push_back(name);
            data[unit][0].push_back(phone);
            data[unit][0].push_back(email);
            data[unit][0].push_back(ic);
        }
        else if (data[unit][0].size() > 3 && data[unit][1].size() < 4)
        {
            data[unit][1].push_back(name);
            data[unit][1].push_back(phone);
            data[unit][1].push_back(email);
            data[unit][1].push_back(ic);
        }
        else
        {
            cout << "ERROR unit registration is full" << endl;
        }
    };

    while (getline(FILE, unit, ','))
    {
        getline(FILE, name, ',');
        getline(FILE, phone, ',');
        getline(FILE, email, ',');
        getline(FILE, ic, '\n');

        if (data.find(stoi(unit)) == data.end())
        {
            data[stoi(unit)] = {{}, {}};
            storeData(data, stoi(unit), name, phone, email, ic);
        }
        else
        {
            storeData(data, stoi(unit), name, phone, email, ic);
        }
    }

    FILE.close();

    return data;
}

void searchData(map<int, vector<vector<string>>> data, int unit)
{
    try
    {
        for (int i = 0; i < data.at(unit).size(); i++)
        {
            for (int j = 0; j < data.at(unit)[i].size(); j++)
            {
                cout << data.at(unit)[i][j] << endl;
            }
            cout << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }
}

vector<string> returnInfo(map<int, vector<vector<string>>> data, int unit, string dataCode)
{
    vector<string> info;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data[unit][i].size() > 3)
            {
                info.push_back(data[unit][i][dictionary[dataCode]]);
            }
        }
        // PRINTING OUT THE INFO
        // for (int i = 0; i < info.size(); i++)
        // {
        //     cout << info[i] << endl;
        // }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }

    return info;
}

bool checkInfo(map<int, vector<vector<string>>> data, int unitNumber, string dataCode, string infoInput = "")
{
    vector<string> info = returnInfo(data, unitNumber, dataCode);

    if (infoInput != "")
    {
        if (find(info.begin(), info.end(), infoInput) != info.end())
        {
            cout << "YAYYY";
            return true;
        }
        cout << "NO";
        return false;
    }
    cout << "NOOO";
    return false;
}
