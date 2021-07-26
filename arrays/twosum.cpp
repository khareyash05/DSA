#include<bits/stdc++.h>
using namespace std;
int twosum(int a[], int n, int x){
    sort(a, a+n);
    int i=0, j=n-1, sum;
    while(i<n && j<n &&i<=j){
        if(a[i]+a[j]==x){
            cout << "The two elements are " << a[i] << " and " << a[j] << endl;
            i++;j--;
        }
        else if(a[i]+a[j]<x){
            i++;
        }
        else{
            j--;
        }    
    }
}
int main() {
    // Input array 
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Input target
    int target = 12;
    twosum(a, 10, target);
}