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
For initialisation, remember for sum=0 there can be an empty subset <br>
Code same as knapsack because its about finding if exist or not so max function will not work hence instead we use || 

<h4>2. Count Subsets with given sum</h4>
In subset sum instead of || use + as we have to count all subsets with given sum

<h4>3. Equal Sum Partition</h4>
Q - Divide array into 2 parts such that sum of subsets is equal <br>
i.e. <h5>S1-S2=0 and S1+S2=sum of array</h5>
<code>if(sum%2==0) return subsetsum(arr,sum/2)</code>
sum should be even and we need to find only one subset with "sum/2" sum<br>
Just subset sum problem with sum/2

<h4>4. Minimum SUbset Sum Difference</h4>
<h5>In this S1-S2 = min</h5>
SInce S2= Sum of array - S1 so answer is min(Sum-2S1)<br>
Just like equal sum partition find for sum/2 and then where the answer is true find min of that
```

	int diff = INT_MAX;

	// Find the largest j such that dp[n][j]
	// is true where j loops from sum/2 t0 0
	for (int j = sum / 2; j >= 0; j--) {
		// Find the
		if (dp[n][j] == true) {
			diff = sum - 2 * j;
			break;
		}
	}
	return diff;```

