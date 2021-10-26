#include<bits/stdc++.h>
using namespace std;
bool dp[101][101]={false};
int countsum(int arr[],int sum,int n){
    // Initialisation COndition
    for (int i = 0; i <= n; i++)
        dp[i][0] = true; // Remember when sum is 0-> with any no. of elements there can be any empty subset answer hence true in initialisation
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    // Below code same as knapsack just variable change
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i]<=j)
                dp[i][j] = dp[i-1][j-arr[i]] || dp[i-1][j];
            if(arr[i]>j)    
                dp[i][j] = dp[i-1][j];
        }
    }
    int count=0;
    for(int i=1;i<n+1;i++){
        if(dp[i][10]==true)
            count++;
    }
    return count;
}
int main(){
    int arr[] = {3, 34, 4, 12, 5, 2 };
    int sum=7;
    cout << countsum(arr,sum,6);
}