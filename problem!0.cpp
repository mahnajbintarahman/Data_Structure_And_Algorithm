#include<iostream>
using namespace std;
int printArray(int arr[], int n){
    if(n==0){
        return 0;
    }
    printArray(arr,n-1);
    cout<<arr[n-1]<<" ";
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n  ; i++){
        cin>>arr[i];
    }
    printArray(arr,n);
    return 0;
    
 }