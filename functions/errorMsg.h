#include "INCLUDES.h"

void check_Data(bool data) {
    if(data != 1){
        cerr << "\nIncorrect Data or Invalid.\n";
        exit(0);
    }   
}

bool managementCheckUp(string data, string dataS){
    bool x =  data.compare(dataS);
    

    if(x != false){
        cerr << "\nIncorrect Data or Invalid.\n";
        exit(0);
    }
    return x;
}

void managementOptions(){
    char option;
    cout << "\nChoose the function:";
    cout << "Parcel info\tSearch\tRegister\tUpdate (a / b / c / d)" << endl;
    cin >> option;

    switch(option){
        case 'a':
            system ("cls");
            cout << "Parcel Info" << endl;
            break;

        case 'b':
            system ("cls");

            break;

        case 'c':
            system ("cls");

            break;
        
        case 'd':
            system ("cls");

            break;
    }
}