#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> petals(n), quantities(n);

    for (int i = 0; i < n; i++) cin >> petals[i];
    for (int i = 0; i < n; i++) cin >> quantities[i];

    vector<pair<ll, ll>> flowers(n);
    for (int i = 0; i < n; i++) flowers[i] = {petals[i], quantities[i]};
    
    sort(flowers.begin(), flowers.end());

    ll l = 0;
    ll max_petals = 0;
    ll current_cost = 0;
    ll current_petals = 0;
    
    for (int r = 0; r < n; r++) {
        ll petals_r = flowers[r].first;
        ll quantity_r = flowers[r].second;
        
        current_petals += quantity_r * petals_r;
        current_cost += quantity_r * petals_r;

        while (flowers[r].first - flowers[l].first > 1 || current_cost > m) {
            ll petals_l = flowers[l].first;
            ll quantity_l = flowers[l].second;
            
            current_petals -= quantity_l * petals_l;
            current_cost -= quantity_l * petals_l;
            l++;
        }

        if (current_cost <= m) {
            max_petals = max(max_petals, current_petals);
        }
    }

    cout << max_petals << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
