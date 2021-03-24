#include<iostream>
using namespace std;
int jos(int n,int k){
  if(n==1)
    return 0;
  return ((jos(n-1,k)+k)%n) ; 
}

int main(){
  int n,k;
  cin >> n>>k;
  int ans = jos(n,k);
  cout << ans;
}