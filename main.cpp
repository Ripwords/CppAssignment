#include "functions/dataProcessor.h"
#include "prettyStrings/pretty.h"
#include "functions/errorMsg.h"


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
    bool isUnitCorrect;
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
        // There suppose to be a fucntion to return (unitNumber == 1 or True).
        isUnitCorrect = 1;
        //Delete Later
        check_Data(isUnitCorrect);
       
        cout << "Enter your phone number: ";
        cin >> phoneNumber;
        isPhoneCorrect = checkInfo(data, unitNumber, "phone", phoneNumber);
        cout << isPhoneCorrect;
        check_Data(isPhoneCorrect);


        cout << "its Working.";
        
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
        cerr << "Invalid Input.";
        break;
    }

    // searchData(data, 12);
    // auto names = returnName(data, 52);

    return 0;
}


