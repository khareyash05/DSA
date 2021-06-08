#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[],int n,int k ){
  if(n==1)
    return 0;
  sort(arr,arr+n);
  int ans = arr[n-1]-arr[0];
  int small = arr[0]+k;
  int big = arr[n-1]-k;
  for(int i=1;i<n-1;i++){
    int subtract = arr[i]-k;
    int add = arr[i]+k;
    if(subtract>=small || add<=big )
      continue;
    // Either subtraction causes a smaller
    // number or addition causes a greater
    // number. Update small or big using
    // greedy approach (If big - subtract
    // causes smaller diff, update small
    // Else update big)
    if(big-subtract <=add-small)  
      subtract=small;
    else
      big=add;   
  }
  return min(ans,big-small);
}
int main(){
  int arr[] = {1,5,15,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k ; 
  cin >> k;
  cout << getMinDiff(arr,n,k);
}
