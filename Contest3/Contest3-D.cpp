#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<ll, ll> prefix_count;
    ll prefix_sum = 0;
    ll cnt = 0;

    prefix_count[0] = 1;
    for (int i = 0; i < n; i++) {
        prefix_sum += v[i];
        ll remainder = prefix_sum % m;
        cnt += prefix_count[remainder];
        prefix_count[remainder]++;
    }

    cout << cnt << endl;
}

int main() {
    solve();
}
