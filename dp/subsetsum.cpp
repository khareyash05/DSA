#include<bits/stdc++.h>
using namespace std;
bool dp[101][101]={false};
bool subsum(int arr[],int sum,int n){
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i]<=j)
                dp[i][j] = dp[i-1][j-arr[i]] || dp[i-1][j];
            if(arr[i]>j)    
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int arr[] = {3, 34, 4, 12, 5, 2 };
    int sum=-2;
    cout << subsum(arr,sum,5);
}