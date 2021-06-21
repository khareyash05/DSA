#include <bits/stdc++.h>
#define int long long int
using namespace std;

int calc(vector<int> &psum, vector<int> &arr, int x, int n){
	int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	int n_trees = n - idx;
	int conserve = n_trees*x;
	return(psum[n] - psum[idx] - conserve);
}

int solve(vector<int> &arr, int n, int x)
{
	vector<int> psum(n+1); int res = 0;

	psum[0] = 0;
	for(int i = 1; i <= n; ++i){
		psum[i] = psum[i-1] + arr[i-1];
	}

	int l = 0, r = arr[n-1];

	while(l <= r){
		int mid = l + (r-l)/2;
		int harvest = calc(psum, arr, mid, n);
		if(harvest == x){
			return mid;
		}

		if(harvest > x){
			res = mid;
			l = mid + 1; //we need to raise our saw.
		}

		if(harvest < x){

			r = mid - 1;
		}
	} 
	return(res);
}

int32_t main(){
	int n, x; cin >> n >> x; 
	vector<int> forest(n);
	for(int i = 0; i < n; ++i){
		cin >> forest[i];
	}
	sort(forest.begin(), forest.end());
	cout << solve(forest, n, x);
}