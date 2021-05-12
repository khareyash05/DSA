#include<bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n){
  int i=-1;
  for(int j=0;j<n;j++){
    if(arr[j]<0){
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int pos=i+1,neg=0;
  while(pos<n && neg<pos && arr[neg]<0){
    int temp = arr[neg];
    arr[neg] = arr[pos];
    arr[pos] = temp;
    pos++;
    neg+=2;
  }

  for(int k=0;k<n;k++){
    cout << arr[k] << " ";
  }
}
int main(){
  int arr[] = {2,-7,-3,6,-2,-1};
  int n = sizeof(arr)/sizeof(arr[0]);
  rearrange(arr,n);
}
