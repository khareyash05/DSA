#include<bits/stdc++.h>
using namespace std;
int count(int arr[],int sum,int n){
    int dp[n+1][sum+1]={-1};
    for(int i=0;i<sum+1;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=1,j=1;j<=sum;j++){
        if(j%arr[0]==0) dp[i][j]=j/arr[0];
        else dp[i][j]=INT_MAX-1;
    }
    for(int i=2,j=1;j<=sum;j++){
        if(j%arr[1]==0) dp[i][j]=j/arr[1];
        else dp[i][j]=INT_MAX-1;
    }
    for(int i=3,j=1;j<=sum;j++){
        if(j%arr[2]==0) dp[i][j]=j/arr[2];
        else dp[i][j]=INT_MAX-1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i]<=j)
                dp[i][j]=min(1+dp[i][j-arr[i]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];    
        }
    }
    return dp[n][sum];
}
int main(){
    int arr[] = {1,2,3};
    int sum=4;
    cout << count(arr,sum,3);
}
