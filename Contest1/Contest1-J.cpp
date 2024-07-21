#include <bits/stdc++.h>
#define ll long long
using namespace std;

## Câu này khoai, thi cũng không làm đc =))
vector<int> getMaxOfMins(const vector<int>& A, int N) {
    vector<int> left(N), right(N);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        right[i] = s.empty() ? N : s.top();
        s.push(i);
    }

    vector<int> S(N + 1, INT_MIN);

    for (int i = 0; i < N; ++i) {
        int length = right[i] - left[i] - 1;
        S[length] = max(S[length], A[i]);
    }

    for (int i = N - 1; i >= 1; --i) {
        S[i] = max(S[i], S[i + 1]);
    }

    return vector<int>(S.begin() + 1, S.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> result = getMaxOfMins(A, N);
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
