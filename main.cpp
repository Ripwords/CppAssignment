#include "functions/dataProcessor.h"
#include "prettyStrings/pretty.h"

using namespace std;

int main()
{
    auto data = readFile("database.txt");
    string OTP;
    char choice;
    int unitNumber;
    string phoneNumber;
    string managementPS;
    string managementID;
    bool isPhoneCorrect;
    vector<string> names;
    string user_acc = "a";
    string manage_acc = "b";

    cout << "Specify if u r the user or the management ( a / b ): " << endl;
    cin >> choice;

    switch (choice)
    {
    case 'a':
        draw_WELCOME();
        cout << "Enter the unit Number: ";
        cin >> unitNumber;

        cout << "Enter your phone number: ";
        cin >> phoneNumber;
        isPhoneCorrect = checkInfo(data, unitNumber, "phone", phoneNumber);
        // cout << isPhoneCorrect;
        // cout << "\t" << title << endl;
        // searchData(data, unitNumber);
        // names = returnNames(data, unitNumber);

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


