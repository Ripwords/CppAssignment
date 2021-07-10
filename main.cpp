#include "functions/dataProcessor.h"

using namespace std;

map<int, vector<vector<string>>> readFile(string filename);
void searchData(map<int, vector<vector<string>>> data, int unit);
vector<string> returnName(map<int, vector<vector<string>>> data, int unit);

int main()
{
    auto data = readFile("database.txt");

    searchData(data, 12);

    auto names = returnName(data, 52);

    return 0;
}
