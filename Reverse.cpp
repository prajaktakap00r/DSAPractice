#include<iostream>
using namespace std;

int reverse(int num){
    long rev=0;
    while(num>0){
        rev=rev*10+num%10;
        num=num/10;
    }
    return rev;
}

int main(){
    int x=1002;
    int rev=reverse(x);
    cout<<rev;

    return 0;
}