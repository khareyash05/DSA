#include<bits/stdc++.h>
using namespace std;
void smallestSubWithGrtSum(int arr[], int n, int sum){
    int start=0,end=0;
    int currsum =0,min_len=0;
    while(start<n && end<n){
        currsum+=arr[end++];
        while(currsum>sum && start<end){
            min_len = min(min_len,end-start);
            currsum-=arr[start++];
        }
    }
    if(min_len==0)
        cout<<"No subarray with sum "<<sum<<endl;
    else
        cout<<min_len<<endl;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // Input target 
    int target=15;
    smallestSubWithGrtSum(a,10, target);
}