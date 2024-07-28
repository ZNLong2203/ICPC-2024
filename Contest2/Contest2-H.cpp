#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void generateSubsets(const vector<int>& A, unordered_map<int, unordered_set<int>>& subsetSums) {
    int N = A.size();
    int totalSubsets = 1 << N; 

    for (int i = 1; i < totalSubsets; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                sum += A[j];
            }
        }
        subsetSums[sum].insert(i);
    }
}

bool areDisjoint(int set1, int set2) {
    return (set1 & set2) == 0;
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

    int mid = N / 2;
    vector<int> A1(A.begin(), A.begin() + mid);
    vector<int> A2(A.begin() + mid, A.end());

    unordered_map<int, unordered_set<int>> subsetSums1, subsetSums2;

    generateSubsets(A1, subsetSums1);
    generateSubsets(A2, subsetSums2);

    unordered_set<int> resultSet;

    for (const auto& [sum1, sets1] : subsetSums1) {
        if (subsetSums2.find(sum1) != subsetSums2.end()) {
            const unordered_set<int>& sets2 = subsetSums2[sum1];
            for (int set1 : sets1) {
                for (int set2 : sets2) {
                    if (areDisjoint(set1, set2 << mid)) {
                        resultSet.insert(sum1);
                    }
                }
            }
        }
    }

    vector<int> result(resultSet.begin(), resultSet.end());
    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
