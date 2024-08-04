#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime; /// isPrime bool vector  isPrime[x] = true <=> x = prime
vector<int>  prime;   /// Prime vector:          prime[n] = (n+1)th prime
vector<int>  lpf;     /// Lowest Prime Factor:     lpf[x] = min prime divisors of x
void linear_sieve(int lim) {
    prime.assign(1, 2);
    lpf.assign(lim + 1, 2);

    for (int i = 3; i <= lim; i += 2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i);
        for (int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= lim; ++j)
            lpf[prime[j] * i] = prime[j];
    }

    isPrime.assign(lim + 1, false);
    for (int x : prime) isPrime[x] = true;
}

int main()
{
    int n;
    cin >> n;
    linear_sieve(n - 2);

    int res = 0;
    for (int a : prime)
    {
        if (a > n / 2) break;
        res += isPrime[n - a];
    }

    cout << res;
    return 0;
}
