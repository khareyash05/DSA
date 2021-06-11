#include<bits/stdc++.h>
using namespace std;
int indexOf(vector<int>& arr,int ele){
  for(int i=0;i<arr.size();i++){
    if(arr[i]==ele)
      return i;
  }
  return -1;
}
void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int min_swap(vector<int>arr,int N){
  int ans=0;
  vector<int>temp;
  temp=arr;
  for(int i=0;i<N;i++){
    if(arr[i]!=temp[i]){//element out of position in array
      ans++;
      swap(arr,i,indexOf(arr,temp[i]));
    }
  }
  return ans;
}
int main()
{

    vector<int> a = {101, 758, 315, 730, 
                   472, 619, 460, 479};
    
    int n = a.size();
    
    // Output will be 5
    cout << minSwaps(a, n);
}
