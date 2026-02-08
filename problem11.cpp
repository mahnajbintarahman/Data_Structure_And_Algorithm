#include<iostream>
using namespace std;
int sumOfArray(int arr[], int n){
    if(n==0){
        return ;
    }
    return arr[n] + sumOfArray(arr,n-1);
}
int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n  ; i++){
        cin>>arr[i];
    }
    sumOfArray(arr,n);
    return 0;
}

// ct _ 1 to 3 lecture 
