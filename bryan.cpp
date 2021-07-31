#include "functions/functions.h"
#include <iomanip>

using namespace std;

int main() 
{
    // string a = "Unit Number" ;
    // string b = "/ Phone Number" ;
    // display_error_msg(a,b);    .

    auto data = readParcelData("parcelData.txt");
    // showLockerInfo(testData);
    display_parcel_info(data);
    // int row = 10;

    // for (int i=0; i < row; i++)
    // {
    //     for (int j=i+1; j < 21 + i + 1; j+=row)
    //     {
    //         cout << left << setw(3) << j << " " << left <<setw(14) <<data[j][1];
    //     }
    //     cout << endl;
    // }

    return 0;
}