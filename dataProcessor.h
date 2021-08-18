#include "INCLUDES.h"

// DATA PROCESSING
// MAPPING INFORMATION TYPE TO DATA CODE FOR EASIER RETRIEVAL OF DATA FROM VECTORS
map<string, int> dictionary = {
    {"name", 0},
    {"phone", 1},
    {"email", 2},
    {"ic", 3}};

// FUNCTION TO READ DATABASE GIVEN FILENAME AND OUTPUT A MAP DATA STRUCTURE
// STRUCTURE IS IN THE FORM OF:
// DATA = {
//     {
//         UNIT, {
//             {NAME_1, PHONE_1, EMAIL_1, IC_1},
//             {NAME_2, PHONE_2, EMAIL_2, IC_2}
//         }
//     }
// }
map<int, vector<vector<string>>> readFile(string filename)
{
    ifstream FILE;
    FILE.open(filename);
    if (!FILE)
    {
        cerr << "Error reading " << filename << endl;
    }

    string unit;
    string name;
    string phone;
    string email;
    string ic;

    map<int, vector<vector<string>>> data;

    auto storeData = [](map<int, vector<vector<string>>> &data, int unit, string name, string phone, string email, string ic)
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
            cerr << "ERROR unit registration is full" << endl;
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

// DATA QUERY
// FUNCTION TO PRINT OUT ALL THE INFORMATION OF A CERTAIN UNIT
void searchData(map<int, vector<vector<string>>> data, int unit)
{
    string datacode[4] = {"Name", "Phone", "Email", "IC"};
    try
    {
        cout << endl;
        for (int i = 0; i < data.at(unit).size(); i++)
        {
            for (int j = 0; j < data.at(unit)[i].size(); j++)
            {
                cout << "\t\t\t";
                cout << left << setw(6) << datacode[j] << ": ";
                cout << data.at(unit)[i][j] << endl;
            }
            cout << endl;
        }
    }
    catch (const out_of_range)
    {
        cerr << "Unit has not registered" << endl;
    }
}

// FUNCTION TO RETURN A VECTOR CONTAINING THE INFORMATION SPECIFIED WITH DATA CODE OF A CERTAIN UNIT
vector<string> returnInfo(map<int, vector<vector<string>>> data, int unit, string dataCode)
{
    vector<string> info;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data.at(unit)[i].size() > 3)
            {
                info.push_back(data[unit][i][dictionary[dataCode]]);
            }
        }
    }
    catch (const out_of_range)
    {
        cerr << "Unit has not registered" << endl;
    }

    return info;
}

// FUNCTION TO CHECK IF GIVEN INPUT ACCODING TO THE DATACODE IS INSIDE A CERTAIN UNIT NUMBER
bool checkInfo(map<int, vector<vector<string>>> data, int unitNumber, string dataCode, string infoInput = "")
{
    vector<string> info = returnInfo(data, unitNumber, dataCode);

    if (infoInput != "")
    {
        if (find(info.begin(), info.end(), infoInput) != info.end())
        {
            return true;
        }
        return false;
    }
    return false;
}

// FUNCTION TO CHECK IF A UNIT IS FULLY REGISTERED OR NOT
bool is_unitFull(map<int, vector<vector<string>>> data, int unit)
{
    if (data.find(unit) == data.end())
    {
        return false;
    }
    else
    {
        if (data[unit][0].size() < 4)
        {
            return false;
        }
        else if (data[unit][0].size() > 3 && data[unit][1].size() < 4)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

// DATA MODIFICATIONS
// FUNCTION TO REGISTER NEW RESIDENTS
void registerNew(map<int, vector<vector<string>>> &data, vector<string> registration)
{
    int unit = stoi(registration[0]);
    string name = registration[1];
    string phone = registration[2];
    string email = registration[3];
    string ic = registration[4];

    auto storeData = [](map<int, vector<vector<string>>> &data, int unit, string name, string phone, string email, string ic)
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
    };
    if (checkInfo(data, unit, "ic", ic))
    {
        cerr << "ERROR User has already been registered, press enter to continue" << endl;
        cin.get();
    }
    else
    {
        if (!is_unitFull(data, unit))
        {

            if (data.find(unit) == data.end())
            {
                data[unit] = {{}, {}};
            }
            storeData(data, unit, name, phone, email, ic);
        }
        else
        {
            cerr << "UNIT IS FULL" << endl;
        }
    }
}

// FUNCTION TO UPDATE EXISTING USER INFORMATION
void updateData(map<int, vector<vector<string>>> &data, int unit, string dataCode, string update, string currentInfo)
{
    if (data.find(unit) == data.end())
    {
        cerr << "ERROR unit not registered" << endl;
    }
    else
    {
        if (checkInfo(data, unit, dataCode, currentInfo))
        {
            for (int i = 0; i < 2; i++)
            {
                if (currentInfo == data.at(unit)[i][dictionary[dataCode]])
                {
                    data[unit][i][dictionary[dataCode]] = update;
                    break;
                }
            }
        }
    }
}

void deleteFromDatabase(map<int, vector<vector<string>>> &data, int unit, string ic)
{
    if (checkInfo(data, unit, "ic", ic))
    {
        for (int i = 0; i < 2; i++)
        {
            if (ic == data.at(unit)[i][3])
            {
                data[unit][i].erase(data[unit][i].begin(), data[unit][i].end());
                break;
            }
        }
    }
    else
    {
        cerr << "ERROR information incorrect" << endl;
    }
}

// FUNCTION TO UPDATE THE DATABASE ( ONLY RUN THIS AT THE END OF MAINLOOP OR WHEN USERDATA IS MODIFIED FROM "updateData")
void updateUserDatabase(map<int, vector<vector<string>>> &data, string filename)
{
    ofstream FILE;
    FILE.open(filename, ios::out);

    for (pair<int, vector<vector<string>>> el : data)
    {
        for (int i = 0; i < el.second.size(); i++)
        {
            if (el.second[i].size() > 2)
            {
                FILE << el.first << ",";
                for (int j = 0; j < el.second[i].size(); j++)
                {
                    if (j == el.second[i].size() - 1)
                    {
                        FILE << el.second[i][j] << endl;
                    }
                    else
                    {
                        FILE << el.second[i][j] << ",";
                    }
                }
            }
        }
    }

    FILE.close();
}

bool checkRegistration(map<int, vector<vector<string>>> data, int unit)
{
    bool unitExist = (data.find(unit) == data.end()) ? false : true;
    return unitExist;
}

bool checkPhoneNumber(map<int, vector<vector<string>>> data, string phoneNum)
{
   for (pair<int, vector<vector<string>>> el : data)
    {
        for (int i = 0; i < el.second.size(); i++)
        {
            if (el.second[i].size() > 2)
            {
                if (phoneNum.compare(el.second[i][1]) == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}