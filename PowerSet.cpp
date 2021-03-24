#include<bits/stdc++.h>
using namespace std;
void powerSet(string s ,int i,string curr){
  if(i==s.length()){
    cout << curr << "  ";
    return ;
  }
  powerSet(s,i+1,curr+s[i]);
  powerSet(s,i+1,curr);
}

int main(){
  string s,curr = " " ;
  cin >> s;
  int i;
  cin >> i ;
  powerSet(s,i,curr);
}