#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void matrix_multiply(ll a[2][2], ll b[2][2], ll mod) {
    ll product[2][2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                product[i][j] = (product[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = product[i][j];
        }
    }
}

void matrix_pow(ll base[2][2], ll exp, ll mod, ll result[2][2]) {
    result[0][0] = result[1][1] = 1;
    result[0][1] = result[1][0] = 0;
    while (exp > 0) {
        if (exp % 2 == 1) {
            matrix_multiply(result, base, mod);
        }
        matrix_multiply(base, base, mod);
        exp /= 2;
    }
}

ll fibonacci(ll n, ll mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    ll base[2][2] = {{1, 1}, {1, 0}};
    ll result[2][2];
    matrix_pow(base, n - 1, mod, result);
    return result[0][0];
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, M;
        cin >> a >> b >> M;
        ll g = gcd(a, b);
        cout << fibonacci(g, M) % M << endl;
    }
}

int main() {
    solve();
    return 0;
}