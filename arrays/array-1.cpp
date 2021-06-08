#include<iostream>
using namespace std;
bool segment(int arr[],int n ,int k,int x){
  int i;
  for(i=0;i<n;i+=k){
    int j;
    for(j=i;(j<i+k) &&(j<n);j++){
      if(arr[j]==x) // If element found break this iteration and start with i+=k
        break;
    }
    if(j==(i+k)) // if j finishes without break we check if all elements in the loop were traversed if yes means no element hence false
      return false;        
  }
  // Now we have to check for the segment whose size less than k
  int j;
  for (j=i-k; j<n; j++) // i's value is stored the last value from previous loop and till the last element
    if (arr[j] == x)
      break;
    if (j == n) // if j reached last element in size short arrray return false
      return false; 
      
  return true;
}
int main(){
  int arr[] = {3,5,2,4,9,3,1,7,3,11,12,3,6,9};
  int k=3;
  int x=3;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << segment(arr,n,k,x);
}