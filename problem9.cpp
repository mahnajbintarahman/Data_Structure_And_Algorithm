//power function using recursion 
#include<iostream>
using namespace std;
int p(int a ,int b){
    if (b==0){
        return 1;
    }
    else{
        return a*p(a,b-1);
    }
}

int main (){
    int a,b;
    cin>>a>>b;

    cout<<p(a,b);
    return 0;

}