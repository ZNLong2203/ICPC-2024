#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to count how many cells, when blocked, would create exactly three regions
int countCellsForThreeRegions(vector<string>& grid, int n) {
    vector<vector<int>> component(2, vector<int>(n, -1));
    int componentCount = 0;

    // Flood-fill to assign components within each row
    auto markComponents = [&](int row) {
        int currentComponent = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[row][i] == '.') {
                if (i == 0 || grid[row][i-1] != '.') {
                    currentComponent++;
                }
                component[row][i] = currentComponent;
            }
        }
        componentCount = max(componentCount, currentComponent);
    };

    markComponents(0);
    markComponents(1);

    int criticalCount = 0;

    // Function to calculate distinct components when a cell is blocked
    auto countDistinctComponents = [&](int col) {
        set<int> distinct;
        // Add components from the left, right, above, and below
        if (col > 0 && grid[0][col] == '.') distinct.insert(component[0][col-1]);
        if (col+1 < n && grid[0][col] == '.') distinct.insert(component[0][col+1]);
        if (col > 0 && grid[1][col] == '.') distinct.insert(component[1][col-1]);
        if (col+1 < n && grid[1][col] == '.') distinct.insert(component[1][col+1]);

        return distinct.size();
    };

    // Evaluate each cell
    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == '.' && countDistinctComponents(i) == 3) {
            criticalCount++;
        }
        if (grid[1][i] == '.' && countDistinctComponents(i) == 3) {
            criticalCount++;
        }
    }

    return criticalCount;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];
        
        cout << countCellsForThreeRegions(grid, n) << "\n";
    }
    return 0;
}
