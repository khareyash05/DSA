#include<bits/stdc++.h>
using namespace std;
// Recursive Approach
int lcs(string X,string Y,int n,int m){
    if(n==0||m==0) return 0;
    else{
        if(X[n-1]==Y[m-1]) return 1+lcs(X,Y,n-1,m-1);
        else 
            return max(lcs(X,Y,n-1,m),lcs(X,Y,n,m-1));
    }
}
// Top-Down Approach
int lcs1(string X,string Y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    
        }
    }
    return dp[n][m];
}
string ans = "";
string lcsprint(string X,string Y,int n,int m){
    if(n==0||m==0) return " ";
    else{
        if(X[n-1]==Y[m-1]){
            ans+=X[n-1];
            lcsprint(X,Y,n-1,m-1);
        }
        else {
            if(lcsprint(X,Y,n-1,m).size()>=lcsprint(X,Y,n,m-1).size()){
                ans+=lcsprint(X,Y,n-1,m);
            }
            else ans+=lcsprint(X,Y,n,m-1);
        }
    }
    return ans;
}
int main(){
    string X = "abcdef";
    string Y = "abdef";
    int n = 6;
    int m=5;
    cout << lcs1(X,Y,n,m)<<"\n";
    cout << lcsprint(X,Y,n,m);
}