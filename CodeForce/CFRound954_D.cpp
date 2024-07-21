#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// Function to evaluate the arithmetic expression for a given substring
long long evaluate(const string& s, const string& ops, int l, int r) {
    vector<long long> nums;
    vector<char> operations;
    long long num = 0;
    for (int i = l; i <= r; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (i == r || !isdigit(s[i])) {
            nums.push_back(num);
            num = 0;
            if (i != r) {
                operations.push_back(ops[i]);
            }
        }
    }

    // Perform multiplication first
    for (int i = 0; i < operations.size();) {
        if (operations[i] == '*') {
            nums[i] *= nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operations.erase(operations.begin() + i);
        } else {
            ++i;
        }
    }

    // Perform addition
    long long result = nums[0];
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == '+') {
            result += nums[i + 1];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n == 2) {
            cout << stoi(s) << '\n';
            continue;
        }

        long long minResult = LLONG_MAX;
        int opsCount = n - 2;
        vector<int> opsPositions(opsCount);
        for (int i = 0; i < opsCount; ++i) {
            opsPositions[i] = i + 1;
        }

        int maxMask = 1 << opsCount;
        for (int mask = 0; mask < maxMask; ++mask) {
            string ops(n - 1, ' ');
            for (int i = 0; i < opsCount; ++i) {
                if (mask & (1 << i)) {
                    ops[opsPositions[i]] = '+';
                } else {
                    ops[opsPositions[i]] = '*';
                }
            }

            long long result = evaluate(s, ops, 0, n - 1);
            minResult = min(minResult, result);
        }

        cout << minResult << '\n';
    }

    return 0;
}
