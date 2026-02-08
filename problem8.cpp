#include<iostream>
using namespace std;
 
int countOfDigits(int n){
    if(n/10 == 0){
        return 1;
    }
    return 1 + countOfDigits(n / 10);
}
int main(){
    int n;
    cin >> n;
    cout << "Count of digits: " << countOfDigits(n);
    return 0;
}
