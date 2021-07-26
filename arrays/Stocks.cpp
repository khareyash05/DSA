// Program for Buy and Sell Stocks-I
#include<bits/stdc++.h>
using namespace std;
int buysell(int arr[], int n){
    int minsofar = arr[0];
    int maxprofit = 0;
    for(int i=1; i<n; i++){
        minsofar = min(minsofar, arr[i]);
        int profit = arr[i] - minsofar;
        maxprofit = max(maxprofit, profit);
    }
    return maxprofit;
}
int main(){
    int arr[] = {100,200,50,300,350,400,250};
    cout << buysell(arr,7);
    return 0;
}