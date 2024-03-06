#include <iostream>
using namespace std;
class OuterClass
{
public:
    void myName();
};
void OuterClass::myName()
{
    cout << "Prajakta kapoor";
}
int main()
{
    OuterClass obj;
    obj.myName();
}