 // C++ program for maximum subarray sum
// using Divide and Conquer
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Find the maximum possible sum in arr[] such that arr[m]
// is part of it
int maxCrossingSum(vector<int> &arr, int l, int m, int h) {
 
 // Include elements on left of mid.
 int sum = 0;
 int leftSum = INT_MIN;
 for (int i = m; i >= l; i--) {
 sum = sum + arr[i];
 if (sum > leftSum)
 leftSum = sum;
 }
 // Include elements on right of mid
 sum = 0;
 int rightSum = INT_MIN;
 for (int i = m + 1; i <= h; i++) {
 sum = sum + arr[i];
 if (sum > rightSum)
 rightSum = sum;
 }
 // Return the sum of maximum left, right, and
 // cross subarray
 return (leftSum + rightSum);
}
// Returns sum of maximum sum subarray in arr[l..h]
int MaxSum(vector<int> &arr, int l, int h) {
 
 // Invalid Range: low is greater than high
 if (l > h)
 return INT_MIN;
 // Base Case: Only one element
 if (l == h)
 return arr[l];
 // Find middle point
 int m = l + (h - l) / 2;
 // Compute the maximum of the three cases:
 int leftSum = MaxSum(arr, l, m);
 int rightSum = MaxSum(arr, m + 1, h);
 int crossSum = maxCrossingSum(arr, l, m, h);
 // Return the maximum of the three
 if (leftSum >= rightSum && leftSum >= crossSum)
 return leftSum;
 else if (rightSum >= leftSum && rightSum >= crossSum)
 return rightSum;
 else
 return crossSum;
}
int maxSubarraySum(vector<int> &arr) {
 int n = arr.size();
 return MaxSum(arr, 0, n - 1);
}
int main() {
 vector<int> arr = {2, 3, 4, 5, 7};
 cout << maxSubarraySum(arr);
 return 0;
}