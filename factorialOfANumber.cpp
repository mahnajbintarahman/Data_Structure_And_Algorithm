#include<iostream>
using namespace std;
int factorialOfANumber(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * factorialOfANumber(n - 1);
    }
}
int main(){
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    int factorial = factorialOfANumber(n);
    cout << "The factorial of " << n << " is: " << factorial << endl;
    return 0;
}
