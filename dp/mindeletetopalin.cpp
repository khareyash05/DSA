// min deletion to make palindromic subsequence is len of string - len of palin
#include<bits/stdc++.h>
using namespace std;
int mindelete(string X,int n){
    return len(X)-len(lps(X,n))
}
int main()