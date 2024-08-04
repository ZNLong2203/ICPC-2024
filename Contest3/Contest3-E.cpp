#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<ll> ans;
    ll cnt = 0;
    vector<ll> left_max(n, 0), right_min(n, 0);
    
    left_max[0] = v[0];
    for(int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], v[i]);
    }
    
    right_min[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) {
        right_min[i] = min(right_min[i+1], v[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if((i == 0 || v[i] > left_max[i-1]) && (i == n-1 || v[i] <= right_min[i+1])) {
            cnt++;
            ans.push_back(v[i]);
        }
    }
    
    cout << cnt << " ";
    for(int i = 0; i < min(cnt, 100LL); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
