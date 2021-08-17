#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void draw_WELCOME(void) 
{ 
    cout << "  \t\t\tw       w   EEEE  LL      CCCC   OOO   M     M   EEEE\n"; 
    cout << "  \t\t\tw   w   w  E      LL     C      O   O  MM   MM  E    \n"; 
    cout << "  \t\t\tw   w   w  EEEEE  LL     C      O   O  M M M M  EEEEE\n"; 
    cout << "  \t\t\t w w w w   E      LL     C      O   O  M  M  M  E    \n";   
    cout << "  \t\t\t  w   w     EEEE  LLLLLL  CCCC   OOO   M     M   EEEE\n";
} 
void draw_TO(void)
{
	cout << "\n\t\t\t\t\t   TTTTTTTT   OOO \n"; 
    cout << "  \t\t\t\t\t   T  TT  T  O   O\n"; 
    cout << "  \t\t\t\t\t      TT     O   O\n"; 
    cout << "  \t\t\t\t\t      TT     O   O\n";   
    cout << "  \t\t\t\t\t      T       OOO \n";
 
}   
void draw_PARCEL_SYSTEM(void)
{
	cout << "\n\t PPP    AAA   RRRR    CCCC   EEEE  LL    \t SSSS  Y   Y   SSSS  TTTTTTTT   EEEE  M     M\n"; 
    cout << "  \tP   P  A   A  RR  R  C      E      LL    \tS      Y   Y  S      T  TT  T  E      MM   MM\n"; 
    cout << "  \tPPPP   AAAAA  R RR   C      EEEEE  LL    \tSSSSS   YYY   SSSSS     TT     EEEEE  M M M M\n"; 
    cout << "  \tP      A   A  R  R   C      E      LL    \t    S    Y        S     TT     E      M  M  M\n";   
    cout << "  \tP      A   A  R   R   CCCC   EEEE  LLLLL \tSSSS     Y    SSSS      T       EEEE  M     M\n";
    cout << "\n========================================================================================================\n";
}

void draw_PARCEL_SYSTEM2(void)
{
    cout << " #####    ####   #####     #####  ######  ##    \t  ######  ##    ##   ######  ########  ######  ##    ##   \n";
    cout << " ##  ##  ##  ##  ##  ##   ##      ##      ##    \t ##        ##  ##   ##          ##     ##      ###  ###   \n";
    cout << " #####   ######  #####    ##      #####   ##    \t  #####     ####     #####      ##     #####   ## ## ##   \n";
    cout << " ##      ##  ##  ##  ##   ##      ##      ##    \t      ##     ##          ##     ##     ##      ##    ##   \n";
    cout << " ##      ##  ##  ##   ##   #####  ######  ######\t ######      ##     ######      #      ######  ##    ##   \n";
    cout << "\n//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\" << endl;
}

void display_selection(string &choice)
{
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t* Manangemnt(M) *\t\t|\t\t* Resident(R) *  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\t\t\n\tPlease select the option (M/R) to continue >> ";
    cin >> choice;
}

void display_EditUser(string &choice)
{
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*   Update (1)  *\t\t|\t\t*  Delete (2) *  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\t\t\n\tPlease select the option ( 1 / 2 ) to continue >> ";
    cin >> choice;
}

void display_search(string &choice)
{
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*  Resident (1) *\t\t|\t\t*  Locker (2) *  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\t\t\n\tPlease select the option ( 1 / 2 ) to continue >> ";
    cin >> choice;
}

void display_title(string info_a)
{
    cout << "\n\t\t\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\t\t\t\t\t      |                  |      \n";
    cout << "\t\t\t\t\t      | " << setw(16) << left << info_a << setw(3) << right << "|\n";
    cout << "\t\t\t\t\t      |                  |      \n";
    cout << "\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<      \n\n";    
}

void display_error_msg(string info_a, string info_b, string &return_option)
{
    cout <<"\n\n\t\t\t\t\t                 /||||/            \n";
    cout <<"\t\t\t\t\t                (o   o)            \n";
    cout <<"\t\t\t\t\t|~ ~ ~ ~ ooO ~ ~ (_) ~ ~ ~ ~ ~ ~ ~|\n";
    cout <<"\t\t\t\t\t| INVALID                         |\n";
    cout <<"\t\t\t\t\t| " << left << setw(15) << info_a << left << setw(17) << info_b  << "|\n";
    cout <<"\t\t\t\t\t| Please try again =(             |\n";
    cout <<"\t\t\t\t\t|~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Ooo ~ ~|\n";
    cout <<"\t\t\t\t\t                |__|__|            \n";
    cout <<"\t\t\t\t\t                 || ||             \n";
    cout <<"\t\t\t\t\t                ooO Ooo            \n";
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\nEnter 0 (return MENU option) OR 1 (Try again) >> ";
    cin >> return_option ;
}

void display_invalid_input(void)
{
    cout << "\n\t\t\t   ____________________________    ";
    cout << "\n\t\t\t  /                            \\  ";
    cout << "\n\t\t\t /        Invalid input.        \\ ";
    cout << "\n\t\t\t|                                | ";
    cout << "\n\t\t\t \\     Press ENTER to exit.     / ";
    cout << "\n\t\t\t  \\____________________________/  ";
    cout << "\n\t\t\t     \\       /                    ";
    cout << "\n\t\t\t      \\     /                     ";
    cout << "\n\t\t\t       \\   /                      ";
    cout << "\n\t\t\t        \\ /                       ";
    cout << "\n\t\t\t       {O,O}                       ";
    cout << "\n\t\t\t       ./)_)                       ";
    cout << "\n\t\t\t         \" \"                      ";
    cout << "\n___________________________________________________________________________________________________________________\n";
    cin.clear();
    cin.ignore(512, '\n');
    cin.get();
}

void mang_ID_PS_enter(string &ManagementID, string &ManagementPS) //! To be renamed by Bryan
{
    cout << "\n\t\t\t\t\t                      			";
    cout << "\n\t\t\t\t\t   Management ID  : ";
    cin >> ManagementID;
    cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\n\t\t\t\t\t   Password       : ";
    cin >> ManagementPS;
    system("cls");
}

void display_deleteUser(string unit, string ic, string YorN) //! To be renamed by Bryan
{
    cout << "\n\t\t\t\t\t                      			";
    cout << "\n\t\t\t\t\t   Unit Number       : ";
    cin >> unit;
    cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\n\n\t\t\t\t\t   Owner IC Number   : ";
    cin >> ic;
    system("cls");
    cout << "\n\t\t\t\t\t+----------------------------------------+   ";
    cout << "\n\t\t\t\t\t| Unit Number  |  " << setw(23) << left << unit << "| ";
    cout << "\n\t\t\t\t\t+----------------------------------------+   ";
    cout << "\n\t\t\t\t\t| IC Number    |  " << setw(23) << left << ic << "|   ";
    cout << "\n\t\t\t\t\t+----------------------------------------+   ";
    cout << "\n___________________________________________________________________________________________________________________\n";
    cout << "Please confirm the information to be DELETED !!! YES (Y) or NO (N) >> ";
    cin >> YorN;
}

void display_sendSMS(string OTP) //! To be renamed by Bryan
{
    cout << "\n\t\t\t   _______                   ";
    cout << "\n\t\t\t _|  \\_/  |______________   ";
    cout << "\n\t\t\t| |__/-\\__|___________   |  ";
    cout << "\n\t\t\t|  |                  |  |   ";
    cout << "\n\t\t\t|  | The SMS has been |  |   ";
    cout << "\n\t\t\t|  |   sent to the    |  |   ";
    cout << "\n\t\t\t|  |       user       |  |   ";
    cout << "\n\t\t\t|  |  OTP : " << OTP << setw(6) << "    |  |";
    cout << "\n\t\t\t|  |__________________|  |   ";
    cout << "\n\t\t\t|________________________|   ";
    cout << "\n\t\t\t     _|____________|_        ";
    cout << "\n\t\t\t    /  ************  \\      ";
    cout << "\n\t\t\t  /   **************   \\    ";
    cout << "\n\t\t\t  -----------------------    ";
}

void display_updateSuccessful(void)
{

    cout << "\n\t\t\t     /\\                     ";
    cout << "\n\t\t\t    /  \\                    ";
    cout << "\n\t\t\t   /    \\                   ";
    cout << "\n\t\t\t  /______\\                  ";
    cout << "\n\t\t\t ___|  |_________________    ";
    cout << "\n\t\t\t|  _|  |______________   |   ";
    cout << "\n\t\t\t|  ||__|              |  |   ";
    cout << "\n\t\t\t|  | User information |  |   ";
    cout << "\n\t\t\t|  |     has been     |  |   ";
    cout << "\n\t\t\t|  |   successfully   |  |   ";
    cout << "\n\t\t\t|  |      UPDATED     |  |   ";
    cout << "\n\t\t\t|  |__________________|  |   ";
    cout << "\n\t\t\t|________________________|   ";
    cout << "\n\t\t\t     _|____________|_        ";
    cout << "\n\t\t\t    /  ************  \\      ";
    cout << "\n\t\t\t  /   **************   \\    ";
    cout << "\n\t\t\t  -----------------------    ";
    cout << "press Enter to go back Menu >>       ";
}

void display_management_option(string &option)
{
    cout << "\t\t\t\t\t  _______________" << endl;
    cout << "\t\t\t\t\t /               \\" << endl;
    cout << "\t\t\t\t\t< 1) Place Parcel >" << endl;
    cout << "\t\t\t\t\t \\_______________/" << endl;
    cout << "\t\t\t\t\t\t  ______________"  << endl;
    cout << "\t\t\t\t\t\t /              \\"<< endl;
    cout << "\t\t\t\t\t\t<   2) Search    >"<< endl;
    cout << "\t\t\t\t\t\t \\______________/"<< endl;
    cout << "\t\t\t\t\t  ______________"    << endl;
    cout << "\t\t\t\t\t /              \\"  << endl;
    cout << "\t\t\t\t\t<   3) Register  >"  << endl;
    cout << "\t\t\t\t\t \\______________/"  << endl;
    cout << "\t\t\t\t\t\t  ______________"  << endl;
    cout << "\t\t\t\t\t\t /              \\"<< endl;
    cout << "\t\t\t\t\t\t<    4) Edit     >"<< endl;
    cout << "\t\t\t\t\t\t \\______________/"<< endl;
    cout << "\t\t\t\t\t  ______________"    << endl;
    cout << "\t\t\t\t\t /              \\"  << endl;
    cout << "\t\t\t\t\t<    5) Exit     >"  << endl;
    cout << "\t\t\t\t\t \\______________/"  << endl;
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\nPlease enter a VALID option ( 1 / 2 / 3 / 4 / 5 ) : ";
    cin >> option ;
}

void display_user_option(string &option)
{
    cout << "\t\t\t\t\t  _____________________"    << endl;
    cout << "\t\t\t\t\t /                     \\"  << endl;
    cout << "\t\t\t\t\t<  1) Parcel Retrieval  >"  << endl;
    cout << "\t\t\t\t\t \\_____________________/"  << endl;
    cout << "\t\t\t\t\t\t  _____________________"  << endl;
    cout << "\t\t\t\t\t\t /                     \\"<< endl;
    cout << "\t\t\t\t\t\t<  2) Update User Info  >"<< endl;
    cout << "\t\t\t\t\t\t \\_____________________/"<< endl;
    cout << "\t\t\t\t\t  _____________________"    << endl;
    cout << "\t\t\t\t\t /                     \\"  << endl;
    cout << "\t\t\t\t\t<        3) Exit        >"  << endl;
    cout << "\t\t\t\t\t \\_____________________/"  << endl;
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\nPlease enter a VALID option ( 1 / 2 / 3 ) : ";
    cin >> option ;
}

void display_parcel_info (map<int, vector<string>> data)
{
    string random_1 = "   =======";
    string random_2 = "==================== ";
    cout << "      ID          Status             ";
    cout << "      ID          Status             ";
    cout << "      ID          Status             " << endl;
    for (int i=0; i < 10; i++) 
    {
        
        for (int j=i+1; j < 21 + i + 1; j+=10)
        {
            cout << setw(5+3) << random_1 << setw(12+3) << random_2 << "      ";
        }
        cout << endl;
        cout << "   >       |                 <      ";
        cout << "    >       |                 <     ";
        cout << "     >       |                 <\n";
        for (int j=i+1; j < 21 + i + 1; j+=10)
        {
            cout << "   >" << right << setw(3) << j << "    |    ";
            cout <<setw(12) << data[j][1] << " <       ";
        }
        cout << endl;
        cout << "   >       |                 <      ";
        cout << "    >       |                 <     ";
        cout << "     >       |                 <\n";
    }
    cout << setw(5+3) << random_1 << setw(12+3) << random_2 << "      ";
    cout << setw(5+3) << random_1 << setw(12+3) << random_2 << "      ";
    cout << setw(5+3) << random_1 << setw(12+3) << random_2 << "      ";
    cout << "\n___________________________________________________________________________________________________________________\n";
    cout << "Please enter the EMPTY locker ID to register the parcel >> ";
}

void copyToClipBoard(const char *text)
{
    const char *output = text;
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

void popUpMsg(string OTP, int lockerID)
{
    string msg;
    msg += "Parcel System : \n";
    msg += "\n";
    msg += "There's a parcel for you!\n";
    msg += "The parcel is in locker : ";
    msg += to_string(lockerID);
    msg += "\n";
    msg += "\n";
    msg += "The OTP is : ";
    msg += OTP;
    msg += "\nThe OTP has been copied to your clipboard\n";
    copyToClipBoard(OTP.c_str());
    MessageBoxA(NULL, msg.c_str(), "NEW SMS NOTIFICATION!", MB_ICONINFORMATION | MB_OK);
}

void updateUserDataPrintOut()
{
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*Phone Number(1)*\t\t|\t\t*   Email(2)  *  \n";
    cout << "\t\t\t*               *\t\t|\t\t*             *  \n";
    cout << "\t\t\t*****************\t\t|\t\t***************  \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "\t\t\t                 \t\t|                     \n";
    cout << "___________________________________________________________________________________________________________________\n";
    cout << "\t\t\n\tPlease select the option ( 1 / 2 ) to continue >> ";
}

