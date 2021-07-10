#include "functions/dataProcessor.h"

using namespace std;

struct userInfo
{
    string name;
    string phone;
    string email;
    string ic;
};

class ApartmentUnit
{
public:
    ApartmentUnit(int unit, vector<string> user_1, vector<string> user_2 = NULL)
    {
        unit = unitNumber;
        users.push_back(user_1);
        if (user_2 != NULL)
        {
            users.push_back(user_2);
        }
    }

    vector<string> getNames()
    {
        vector<string> names;
        for (int i = 0; i < users.size(); i++)
        {
            names.push_back(users[i].name)
        }
        return names;
    }

private:
    int unitNumber;
    vector<userInfo> users = {};
};

int main()
{
    auto data = readFile("database.txt");

    return 0;
}