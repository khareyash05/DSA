#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,5,7,6,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        if(arr[mid]>arr[mid+1]){
            high=mid;
        }
    }
    cout<<arr[low];
}