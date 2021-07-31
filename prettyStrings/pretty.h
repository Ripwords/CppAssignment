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
void draw_PARCEL_SYSTEM2()
{
    cout << " #####    ####   #####     #####  ######  ##    \t  ######  ##    ##   ######  ########  ######  ##    ##   \n";
    cout << " ##  ##  ##  ##  ##  ##   ##      ##      ##    \t ##        ##  ##   ##          ##     ##      ###  ###   \n";
    cout << " #####   ######  #####    ##      #####   ##    \t  #####     ####     #####      ##     #####   ## ## ##   \n";
    cout << " ##      ##  ##  ##  ##   ##      ##      ##    \t      ##     ##          ##     ##     ##      ##    ##   \n";
    cout << " ##      ##  ##  ##   ##   #####  ######  ######\t ######      ##     ######      #      ######  ##    ##   \n";
    cout << "\n//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\" << endl;
}

void display_RESIDENT_LOGIN(void)
{
    cout << "\n\t\t\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\t\t\t\t\t      |                |      \n";
    cout << "\t\t\t\t\t      | RESIDENT LOGIN |      \n";
    cout << "\t\t\t\t\t      |                |      \n";
    cout << "\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<      \n\n";
}
void display_MANAGEMENT_LOGIN(void)
{
    cout << "\n\t\t\t\t\t      >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\t\t\t\t\t      |                  |      \n";
    cout << "\t\t\t\t\t      | MANAGEMENT LOGIN |      \n";
    cout << "\t\t\t\t\t      |                  |      \n";
    cout << "\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<      \n\n";
}

void display_error_msg(string info_a,string info_b,string &return_option)
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
    cout << "\nEnter 0 (return home page) OR 1 (Try again) >> ";
    cin >> return_option ;
}

void display_management_option (int &option)
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
    cout << "\n\t\t\t > INVALID option =( < \n";
    cout << "\nPlease enter a VALID option (1 / 2 / 3 / 4 / 5) ： " << endl;   
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
    cout << "Please enter the occupied locker ID for detail information OR enter the empty locker ID to register the parcel >> ";
}