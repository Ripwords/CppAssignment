#include "functions/dataProcessor.h"
#include "prettyStrings/pretty.h"

using namespace std;

map<int, vector<vector<string>>> readFile(string filename);
void searchData(map<int, vector<vector<string>>> data, int unit);
vector<string> returnNames(map<int, vector<vector<string>>> data, int unit);
vector<string> returnPhones(map<int, vector<vector<string>>> data, int unit);

int main()
{
    auto data = readFile("database.txt");

    string user_acc = "a";
    string manage_acc = "b";
    char choice;
    cout << "Specify if u r the user or the management ( a / b ): " << endl;

    string phoneNumber;
    string OTP;
    int unitNumber;
    vector<string> names;
    vector<string> phones;

    string managementID;
    string managementPS;
    cin >> choice;

    switch (choice)
    {
    case 'a':
        cout << "Enter the unit Number: ";
        
        cin >> unitNumber;
        cout << "\t" << title << endl;
        // searchData(data, unitNumber);
        phones = returnPhones(data, unitNumber);
        names = returnNames(data, unitNumber);

        cout << "Enter your Phone Number: ";
        cin >> phoneNumber;

        // TODO : function to check for phone number will be here
        // If User not Registered, tell him to contact the management.
        // if (phoneNumber != phones)
        // {
        //     cout << "This user is not registered." << endl;
        //     cout << "Please proceed to the management office to update your info";
        // }

        break;

    case 'b':
        cout << "please enter the user ID: ";
        cin >> managementID;

        cout << "Please enter the password: ";
        cin >> managementPS;
        break;

    default:
        cerr << "Invalid Input LOL";
        break;
    }

    // searchData(data, 12);
    // auto names = returnName(data, 52);

    return 0;
}

