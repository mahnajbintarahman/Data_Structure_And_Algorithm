 #include<iostream>//Min Max find out 
 #include<vector>
 using namespace std;
 void findMinMax(vector<int>& arr , int low , int high, int &minValue,int &maxValue){
    if (low==high){
        minValue = maxValue = arr[low];
        return;
    }
    if(high == low+1){
        if(arr[low]< arr[high]){
            minValue = arr[low];
            maxValue = arr[high];
            return;
        }

        else{
            minValue = arr[high];
            maxValue = arr[low];
            return;
        } 
    }
     int mid = (low+high)/2;
        int leftMin , leftMax ;
        int rightMin ,rightMax;

        findMinMax(arr, low ,mid ,leftMin,leftMax);
        findMinMax(arr,mid+1,high,rightMin,rightMax);
        
        minValue = (leftMin < rightMin) ? leftMin : rightMin; 
        maxValue = (leftMax > rightMax) ? leftMax : rightMax; 
 }
 int main(){
    vector<int> arr = {9, 6, 4, 7, 10, 14, 8, 11};
    int minValue , maxValue;
    findMinMax(arr,0, arr.size()-1,minValue ,maxValue);
    cout<<"Minimum Value is : "<<minValue<<endl;
    cout<<"Maximum Value is : "<<maxValue<<endl;
    return 0;
 }
