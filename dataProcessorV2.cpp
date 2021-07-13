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
private:
    int unitNumber;
    vector<string> residents;

public:
    ApartmentUnit(int unitNum, vector<string> userData)
    {
        unitNumber = unitNum;
        residents = userData;
    }
};

int main()
{
    auto data = readFile("database.txt");

    return 0;
}