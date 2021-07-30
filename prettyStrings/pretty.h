#include <iostream>
#include <windows.h>
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

void display_error_msg()
{
    cout <<"\n\n\t\t\t\t\t                 /||||/            \n";
    cout <<"\t\t\t\t\t                (o   o)            \n";
    cout <<"\t\t\t\t\t|~ ~ ~ ~ ooO ~ ~ (_) ~ ~ ~ ~ ~ ~ ~|\n";
    cout <<"\t\t\t\t\t| INVALID                         |\n";
    cout <<"\t\t\t\t\t| Unit Number / Phone Number.     |\n";
    cout <<"\t\t\t\t\t| Please try again =(             |\n";
    cout <<"\t\t\t\t\t|~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Ooo ~ ~|\n";
    cout <<"\t\t\t\t\t                |__|__|            \n";
    cout <<"\t\t\t\t\t                 || ||             \n";
    cout <<"\t\t\t\t\t                ooO Ooo            \n";
}