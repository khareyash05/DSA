<h1>DP . .. </h1>
WHen to use?? 
1. Choice present
2. Optimal Solution to find
<h2>O/1 Knapsack (Parent Problem) </h2>

```
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
```

<h3>Imp - In knapsack there are 2 arrays weight and val ...if only one array given take it for weight array and ignore val array  </h3>

<h4>1. Subset Sum</h4>
Here only one array <br>
Code same as knapsack because its about finding if exist or not so max function will not work hence instead we use || 

<h4>2. Count Subsets with given sum</h4>
