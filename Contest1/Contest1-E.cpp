#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> H(n);
	for(int i = 0; i < n; i++) cin >> H[i];
	
	vector<ll> dp(n, LLONG_MAX);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ll cost = (H[j] - H[i]) * (H[j] - H[i]) + c;
			if(dp[i] + cost < dp[j]) {
				dp[j] = dp[i] + cost;
			}
		}
	}
	cout << dp[n-1] << endl;
}

int main() {
	solve();
}