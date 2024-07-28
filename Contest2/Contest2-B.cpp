#include <bits/stdc++.h>
#define ll long long
using namespace std;

void generate_valid_numbers(ll current, int depth, int N, const vector<int>& digits, set<ll>& valid_numbers) {
    if (depth > 0) {
        valid_numbers.insert(current);
    }
    if (depth == 10) {
        return;
    }
    for (int digit : digits) {
        if (current * 10 + digit <= N) {
            generate_valid_numbers(current * 10 + digit, depth + 1, N, digits, valid_numbers);
        }
    }
}

void solve() {
    ll N;
    cin >> N;

    if (N < 100) {
        cout << N << endl;
        return;
    }

    set<ll> valid_numbers;

    for (int i = 1; i <= 9; i++) {
        generate_valid_numbers(i, 1, N, {i}, valid_numbers);
    }

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i != j) {
                generate_valid_numbers(i, 1, N, {i, j}, valid_numbers);
            }
        }
    }

    ll cnt = 0;
    for (ll num : valid_numbers) {
        if (num <= N) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
