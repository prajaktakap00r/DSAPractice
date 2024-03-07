#include <iostream>
using namespace std;
class OuterClass
{
public:
    int a;
    void myName();
};
void OuterClass::myName()
{
    cout << "Prajakta kapoor";
}
int main()
{
    OuterClass obj;
    obj.a = 10;
    obj.myName();
    cout << "\n";
    cout << obj.a;
}