#include <string>
#include <iostream>
using namespace std;
class Class
{
public:
    string name;
    int getName();
};

int main()
{
    Class obj;
    obj.name = "Prajakta";
    cout << "Name: " << obj.name << endl;
}