// Sieve of Erasthones

#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  bool isPrime[n+1];
  for(int i=0;i<n+1;i++)
    isPrime[i]=true;
  isPrime[0]=false;
  isPrime[1]=false ; 
  for(int i=2;i*i<=n+1;i++){
    for(int j=2*i;j<n+1;j+=i){
      isPrime[j]=false;
    }
  }
  for(int i=0;i<n+1;i++)
    cout << i << "\t" << isPrime[i] << "\n";
}