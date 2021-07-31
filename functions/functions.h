#include "dataProcessor.h"
#include "parcelDataProcessor.h"
#include "../prettyStrings/pretty.h"
#include <cctype>

void residentLogIn(map<int, vector<vector<string>>> data)
{
    int unitNumber;
    string phoneNumber;
    draw_PARCEL_SYSTEM2();
    display_RESIDENT_LOGIN();

    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";
    cout << "\n\t\t\t\t\t                      			   		  	";
    cout << "\n\t\t\t\t\tPlease enter the Unit Number  >> ";
    cin >> unitNumber;
    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\t\t\t\t\tPlease enter the Phone Number >> ";
    cin >> phoneNumber;
    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	" << endl;

    bool unitChecked = checkRegistration(data, unitNumber);
    if (!unitChecked)
    {
        // returns error message that unit is not registered
        display_error_msg();
        exit(0);
    }
    else
    {
        // continues
        
        bool phoneChecked = checkInfo(data, unitNumber, "phone", phoneNumber);
        if (!phoneChecked)
        {
            // returns error message that phone number is wrong
            display_error_msg();
        }
    }
}

void managementLogIn()
{
    string ManagementID;
    string ManagementPS;
    string managementIDStandard = "ID";
    string managementPSStandard = "PS";

    draw_PARCEL_SYSTEM2();
    display_MANAGEMENT_LOGIN();

    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";
    cout << "\n\t\t\t\t\t                      			";
    cout << "\n\t\t\t\t\t   Management ID  : ";
    cin >> ManagementID;
    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\t\t\t\t\t   Password       : ";
    cin >> ManagementPS;
    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	";

    system("cls");

    bool password = ManagementPS.compare(managementPSStandard);
    bool ID = ManagementID.compare(managementIDStandard);
    if (!ID)
    {
        if (!password)
        {
            // write anything here in case the program is working.
            cerr << "INVALID Unit Number / Phone Number. Please try again =(" << endl;
        }
        else
        {
            cerr << /* Wrong Password*/ "Wrong Password";
            exit(0);
        }
    }
    else
    {
        cerr << /* Wrong ID*/ "Wrong ID" << endl;
        exit(0);
    }
}

void searchForResident(map<int, vector<vector<string>>> data)
{
    int unitNumber;
    draw_PARCEL_SYSTEM2();
    cout << "\n\t\t\tPlease enter the Unit Number: ";
    cin >> unitNumber;
    searchData(data, unitNumber);
    system("cls");
}

int generateOTP(){
    int i;
    srand (time(NULL));

    i = (rand() % 100000 + 99999);
    
    return i;

}

void managementOptions(map<int, vector<vector<string>>> data, map<int, vector<string>> parcelData)
{
    int option;
    

    draw_PARCEL_SYSTEM2() ;
    
    do
    {
        cout << "\t\t\t\t\t  ______________"  << endl;
        cout << "\t\t\t\t\t /              \\"<< endl;
        cout << "\t\t\t\t\t< 1) Parcel info >"<< endl;
        cout << "\t\t\t\t\t \\______________/"<< endl;
        cout << "\t\t\t\t\t\t  ______________" << endl;
        cout << "\t\t\t\t\t\t /              \\"<< endl;
        cout << "\t\t\t\t\t\t<   2) Search    >"<< endl;
        cout << "\t\t\t\t\t\t \\______________/"<< endl;
        cout << "\t\t\t\t\t  ______________"  << endl;
        cout << "\t\t\t\t\t /              \\"<< endl;
        cout << "\t\t\t\t\t<   3) Register  >"<< endl;
        cout << "\t\t\t\t\t \\______________/"<< endl;
        cout << "\t\t\t\t\t\t  ______________" << endl;
        cout << "\t\t\t\t\t\t /              \\"<< endl;
        cout << "\t\t\t\t\t\t<    4) Update   >"<< endl;
        cout << "\t\t\t\t\t\t \\______________/"<< endl;
        cout << "\t\t\t\t\t  ______________"  << endl;
        cout << "\t\t\t\t\t /              \\"<< endl;
        cout << "\t\t\t\t\t<    5) Exit     >"<< endl;
        cout << "\t\t\t\t\t \\______________/"<< endl;
        cout << "___________________________________________________________________________________________________________________\n";
        cout << "\nPlease select an option (1 / 2 / 3 / 4 /5) : " << endl;
        cin >> option;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            while (option < 1 || option > 5)
            {
                cout << "Please enter a valid choice" << endl;
                cout << "1) Parcel info\n2) Search\n3) Register\n4) Update\n5) Exit\n(1 / 2 / 3 / 4/ 5)" << endl;
                cin >> option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(512, '\n');
                    continue;
                }
            }
        }

        switch (option)
        {
        case 1:
            system("cls");
            cout << "Parcel Info" << endl;
            showEmptyLocker(parcelData);
            cout << endl;
            
            

            break;

        case 2:
            system("cls");
            cout << "Search For Residents";
            searchForResident(data);

            break;

        case 3:
            system("cls");
            cout << "Register New Resident";
            break;

        case 4:
            system("cls");
            cout << "Update an Existing Resident";
            break;

        case 5:
            system("cls");
            cout << "EXITED" << endl;
        }
    } while (option != 5);
}


// Send sms after parcel arrived
void sendSMS(int OTP){
    cout << "Your parcel had arrived." << endl;
    cout << "=================================================" <<endl;
    cout << "|\tThe SMS has been sent to your phone.\t|" << endl;
    cout << "=================================================" << endl;
    cout << endl;
    cout << "=================================" << endl;
    cout << "|\tThe OTP is : " << OTP << " \t|" << endl;
    cout << "=================================" << endl;
}

// Send email if the parcel is not collected for 3 days.
void sendEmail(int OTP){
    cout << "You have not collected your parcel for 3 days." << endl;
    cout << "Please collect your parcel with the OTP : " << OTP << endl;
}

// Parcel is not collected for a week.
void OneWeek(int periodOfStaying){
    cout << "You have not colelcted your parcel for " << periodOfStaying << " days." << endl;
    cout << "Please contact the management for further assist." << endl;
}

void userOptions(){
    char choice;
    bool parcelRegistered = true; // To check if the parcel is registered in the data base.    
    int periodOfStaying = 10; // to give how many days the parcel has been in the system. (current days - Parcel entered the system = periodofStaying)
    int OTP = generateOTP();
    
    
    cout << "Choose the option." << endl;
    cout << "Notifications, Collect a Parcel (N / C) :";
    cin >> choice;

    if(choice == 'N' || choice == 'n'){
        cout << "U have chosen Notifications" << endl;

        if(parcelRegistered){
                    if(periodOfStaying > 3){
                        if(periodOfStaying > 7){

                            OneWeek(periodOfStaying);
                        }
                        else{

                            sendEmail(OTP);
                        }
                    }
                    
                    else{
                       sendSMS(OTP); 
                       
                    }
        }
        
        else{
            cout << "==================================================" << endl;
            cout << "|\tThere is no parcel arrived. :(\t|" << endl;
            cout << "==================================================" << endl;
        }
    }
    else if(choice == 'C' || choice == 'c'){
        cout << "U have chosen to collect ur parcel";
    }
}