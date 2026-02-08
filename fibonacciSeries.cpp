#include<iostream>
using namespace std;

int fibonacciSeries(int n){
    if(n <= 0){
        return 0;
    }else if(n == 1|| n== 2){
        return 1;
    }else{
        return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
    }
}
int main(){
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << "Fibonacci series up to " << n << " terms:" << endl;
    for(int i = 0; i < n; i++){
        cout << fibonacciSeries(i) << " ";
    }
    cout << endl;
    return 0;
}