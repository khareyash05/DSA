#include<bits/stdc++.h>
using namespace std;
int union1(int a[],int b[]){
  unordered_set<int>set;
  for(int x:a)
    set.insert(x);
  for(int x:b)  
    set.insert(x);
  return set.size();
}
int main(){
  int a[]={3,4,5,6};
  int b[]= {2,3,5,7};
  cout << union1(a,b);
}