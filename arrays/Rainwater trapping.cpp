#include<bits/stdc++.h>
using namespace std;
int maxWater(int arr[], int n){
    int left[n], right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i=0; i<n; i++){
        left[i] = max(left[i-1], arr[i]);
        right[n-i-1] = max(right[n-i], arr[n-i-1]);
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res = max(res, min(left[i], right[i])-arr[i]);
    }
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0;
}