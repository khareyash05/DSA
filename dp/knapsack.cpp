#include<bits/stdc++.h>
using namespace std;
int dp[101][101]={-1};

// Recursive way
int knapsack(int wt[],int val[],int W,int n){
    if(n==0||W==0) return 0;
    if(wt[n]<=W){
        return (max(val[n]+knapsack(wt,val,W-wt[n],n-1),knapsack(wt,val,W,n-1)));
    }
    else if(wt[n]>W) return knapsack(wt,val,W,n-1);
}
// DP using Memoization
int knapsack1(int wt[],int val[],int W,int n){
    if(n==0||W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n]<=W){
        dp[n][W]=max(val[n]+knapsack(wt,val,W-wt[n],n-1),knapsack(wt,val,W,n-1));
        return dp[n][W];
    }
    else if(wt[n]>W){
        dp[n][W]=knapsack(wt,val,W,n-1);
        return dp[n][W] ;
    } 
}
// DP using Top-Down Approach
int knapsack2(int wt[],int val[],int W,int n){
    for(int i=0;i<n+1;i++) // Base Condition in recursion was used as Initialisation in this approach
        for(int j=0;j<W+1;j++)
            if(i==0||j==0) dp[i][j]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i]<=j){
                dp[i][j]= max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]); // n cooresponds to i and W to j
            }
            else if(wt[i]>j) dp[i][j]=dp[i-1][j];
        }
    }
    // just change n->i and W->j for top-down approach
    return dp[n][W];
}
int main(){
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;
    // int ans = knapsack(wt,val,W,4);
    int ans1 = knapsack2(wt,val,W,4);
    cout  << ans1;
}