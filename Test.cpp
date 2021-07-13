#include "functions/dataProcessor.h"

using namespace std;

int main()
{
    char choice;
    cout << "Specify if you are a user or management (m or u)";
    cin >> choice;
    string phoneNumber;

    switch (choice)
    {
    case 'm':
        // ! calls managementVerificationFunction to verify that it really is the management
        break;

    case 'u':
        cout << "Enter your Phone Number: ";
        cin >> phoneNumber;
        // * enters phone number.
        // !checks if phone number is registered
        // !! if not then ask if user wants to register or not
        // !! if registered, checks if parcel is available
        // enter OTP.
        break;
    default:
        cerr << "Invalid Input";
        break;
    }
    return 0;
}