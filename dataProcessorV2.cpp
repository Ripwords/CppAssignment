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
    int unit;
    userInfo user_1;
    userInfo user_2;
};

int main()
{
    auto data = readFile("database.txt");

    return 0;
}