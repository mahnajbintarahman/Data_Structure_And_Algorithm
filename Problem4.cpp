#include<iostream>
using namespace std;
int uniqueStair(int n){
    if(n ==0 || n==1){
        return 1;
    }else{
        return uniqueStair(n - 1) + uniqueStair(n - 2);
    }
}
int main(){
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << "uniqueStair series up to " << n << " terms:" << endl;
    for(int i = 0; i < n; i++){
        cout << uniqueStair(i) << " ";
    }
    cout << endl;
    return 0;
}