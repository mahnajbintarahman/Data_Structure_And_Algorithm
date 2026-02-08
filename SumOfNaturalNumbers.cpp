#include<iostream> 
using namespace std;
 int sumOfNaturalNumbers(int n){
    if(n <= 1){
        return n;
    }else{
    return n + sumOfNaturalNumbers(n - 1);
    }
 }
int main(){
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    int sum = sumOfNaturalNumbers(n);
    cout << "The sum of first " << n << " natural numbers is: " << sum << endl;
    return 0;
}