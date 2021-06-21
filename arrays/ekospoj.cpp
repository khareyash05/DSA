bool height(vector <ll> v, ll mid, ll m) {
	 ll sum = 0;
	for (ll i = 0; i < v.size(); i++) {
		if (mid < v[i]) {
			sum += v[i] - mid;
		}
		if (sum == m) {
			return true;
		}
	}
	return false;
}

ll bs(vector<ll>v, ll m) {
	ll s = v[0];
	ll e = v[v.size() - 1];
	ll ans = 0;
	while (s <= e) {
		ll mid = s + (e - s) / 2;
		if (height(v, mid, m)) {
			ans = mid;
			e = mid - 1;

		} else {

			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> v;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << bs(v, m);
}