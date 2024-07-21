#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N, C;
    cin >> N >> C;
    vector<ll> H(N + 5);
    vector<ll> dp(N + 5, LLONG_MAX);

    for (ll i = 1; i <= N; i++) {
        cin >> H[i];
    }

    dp[1] = 0;
    deque<ll> dq;
    dq.push_back(1);

    for (ll i = 2; i <= N; i++) {
        while (dq.size() > 1 && (dp[dq[1]] + (H[i] - H[dq[1]]) * (H[i] - H[dq[1]]) + C <= dp[dq[0]] + (H[i] - H[dq[0]]) * (H[i] - H[dq[0]]) + C)) {
            dq.pop_front();
        }

        long long cost = (H[i] - H[dq.front()]) * (H[i] - H[dq.front()]) + C;
		if (dp[dq.front()] != LLONG_MAX && cost <= LLONG_MAX - dp[dq.front()]) {
		    dp[i] = dp[dq.front()] + cost;
		} else {
		    dp[i] = LLONG_MAX;
		}


        while (dq.size() > 1 && dp[i] <= dp[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << dp[N] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
