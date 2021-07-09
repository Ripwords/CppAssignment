#include "dataProcessor.h"

using namespace std;

map<int, vector<vector<string>>> readFile(string filename);
void searchData(map<int, vector<vector<string>>> data, int unit);
vector<string> returnName(map<int, vector<vector<string>>> data, int unit);

int main()
{
    map<int, vector<vector<string>>> data = readFile("database.txt");

    searchData(data, 12);

    vector<string> names = returnName(data, 52);

    return 0;
}
