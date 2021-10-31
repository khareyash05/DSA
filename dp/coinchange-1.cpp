// Unbounded Knapsack
#include<bits/stdc++.h>
using namespace std;
int count(int S[], int n, int target)
{
    int T[n + 1][target + 1];
 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0) {
                T[0][j] = 0;
            }
            else if (j == 0) {
                T[i][0] = 1;
            }
            else if (S[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                T[i][j] = T[i - 1][j] + T[i][j - S[i - 1]];
            }
        }
    }
 
    return T[n][target];
}
int coinchange1(int coin[],int sum,int n){
    int dp[101][101]={0};
    // Initialisation COndition
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; // Remember when sum is 0-> with any no. of elements there can be any empty subset answer hence true in initialisation

    // Below code same as knapsack just variable change
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i]<=j)
                dp[i][j] = dp[i][j-coin[i]] + dp[i-1][j];
            if(coin[i]>j)    
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int arr[] = {1,2,3};
    int sum=4;
    cout << count(arr,sum,3);
}