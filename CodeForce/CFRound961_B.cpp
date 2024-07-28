#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    ll l = 0, r = 0;
    ll sum = 0, ans = 0;
    
    while (r < n) {
        sum += v[r];
        
        while (v[r] - v[l] > 1 || sum > m) {
            sum -= v[l];
            l++;
        }
        
        if (sum <= m) {
            ans = max(ans, sum);
        }
        r++;
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
