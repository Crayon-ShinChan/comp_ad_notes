#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    map<int, std::string> mapPerson;
    mapPerson.insert(std::map<int, std::string>::value_type(1, "Tom"));
    mapPerson[2] = "Jim";
    mapPerson[3] = "Jerry";

    int nSize = mapPerson.size();
    for (int n = 1; n <= nSize; n++)
        cout << mapPerson[n] << endl;
}