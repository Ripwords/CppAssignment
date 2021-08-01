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
    cout << "\n\t\t\t\t\t                      			   		  	";
    cout << "\n\t\t\t\t\tPlease enter the Phone Number >> ";
    cin >> phoneNumber;
    cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	" << endl;
    system("cls");

    bool unitChecked = checkRegistration(data, unitNumber);
    bool phoneChecked = checkInfo(data, unitNumber, "phone", phoneNumber);
    string a = "Unit Number" ;
    string b = "/ Phone Number" ;
    string return_option ;
    if (!unitChecked || !phoneChecked )
    {   
        // returns error message that unit is not registered        
        while (return_option != "0" || return_option != "1") 
        {
            display_error_msg(a, b, return_option);
            system ("cls") ;

        //     if (return_option == "0")
        //     {

        //     }
        //     else (return_option == "1")
        //     {

        //     }
        }                 
    }
    else
    {
        // continues to check phone number
        
        
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
    string a = "Management ID" ;
    string b = "/ Password" ;
    string return_option ;
    if (!ID || !password)
    {
        while (return_option != "0" || return_option != "1")
            {
                display_error_msg(a, b, return_option);
                system ("cls") ;
                // if (return_option == "0")
                // {
                // }
                // else (return_option == "1")
                // {
                // } 
            }
    }
    else
    {
    
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

string generateOTP()
{
    string OTP;
    srand (time(NULL));

    for (int i = 0; i < 6; i++) 
    {
        string num = to_string(rand() % 10);
        OTP += num;
    }
    
    return OTP;

}

void managementOptions(map<int, vector<vector<string>>> data, map<int, vector<string>> parcelData)
{
    int option;
    

    draw_PARCEL_SYSTEM2() ;
    
    do
    {
        display_management_option (option) ;
        system("cls");
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(512, '\n');
            while (option < 1 || option > 5)
            {
                draw_PARCEL_SYSTEM2() ;
                display_management_option (option) ;
                

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

//  TODO : Needs to be refactored
// Send sms after parcel arrived
void sendSMS(string OTP)
{
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
void sendEmail(string OTP){
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
    int periodOfStaying = 3; // to give how many days the parcel has been in the system. (current days - Parcel entered the system = periodofStaying)
    string OTP = generateOTP();
    
    
    cout << "Choose the option." << endl;
    cout << "Notifications, Collect a Parcel (N / C) :";
    cin >> choice;

    if(choice == 'N' || choice == 'n'){
        cout << "U have chosen Notifications" << endl;

        if(parcelRegistered)
        {
            if(periodOfStaying > 3)
            {
                if(periodOfStaying > 7)
                {
                    OneWeek(periodOfStaying);
                }
                else
                {
                    sendEmail(OTP);
                }
            }
            else
            {
                sendSMS(OTP); 
            }
        }
        else
        {
            cout << "==================================================" << endl;
            cout << "|\tThere is no parcel arrived. :(\t|" << endl;
            cout << "==================================================" << endl;
        }
    }
    else if(choice == 'C' || choice == 'c')
    {
        cout << "U have chosen to collect ur parcel";
    }
}