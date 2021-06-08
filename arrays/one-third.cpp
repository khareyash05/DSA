#include <bits/stdc++.h>
using namespace std;

void onethird(int arr[],int size){
  sort(arr,arr+size);
  int count =0,ansIndex =0;
  int i=1;
  int mxcount = INT_MIN;
  for(;i<size;i++){
    if(arr[i]==arr[ansIndex]){
      count++;
      if(count>(int(size/3)))
        break;
    }
    else{
      ansIndex=i;
      count=1;
    }
  }
  if(count>(int(size/3)))
    cout << arr[i];
  else
    cout << "No element found"  ;
}

int main() {
  int arr[]={1,4,3};
  int size = sizeof(arr)/sizeof(arr[0]);
  onethird(arr,size);
}
