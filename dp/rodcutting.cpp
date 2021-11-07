// This is a version of Unbounded Knapsack because we can repeat length of rods
#include<bits/stdc++.h>
using namespace std;
int rodcut(int price[],int length[],int W,int n){
    int dp[n+1][W+1]={0};
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=W;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(length[i-1]<=j)
                dp[i][j]=max(price[i]+dp[i][j-length[i]],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
 
    // Function Call
    cout << "Maximum obtained value  is "
         << rodcut(price, length, Max_len,n) << endl;
}