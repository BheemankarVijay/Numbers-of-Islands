#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col) {
    // Boundary and water check
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
        return;
    }
    
    // Mark current cell as visited
    grid[row][col] = '0';
    
    // Visit all adjacent cells (up, down, left, right)
    dfs(grid, row - 1, col); // Up
    dfs(grid, row + 1, col); // Down
    dfs(grid, row, col - 1); // Left
    dfs(grid, row, col + 1); // Right
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int numIslands = 0;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] == '1') { // Land found
                numIslands++;
                dfs(grid, row, col); // Explore this island
            }
        }
    }
    return numIslands;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}