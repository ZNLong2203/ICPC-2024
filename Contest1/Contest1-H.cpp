#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_A = 1000000;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> count(MAX_A + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            count[a[i]]++;
        }

        int max_gcd = 1;
        for (int i = MAX_A; i >= 1; --i) {
            int divisors_count = 0;
            for (int j = i; j <= MAX_A; j += i) {
                divisors_count += count[j];
            }
            if (divisors_count >= 2) {
                max_gcd = i;
                break;
            }
        }

        cout << max_gcd << endl;
    }
    return 0;
}
