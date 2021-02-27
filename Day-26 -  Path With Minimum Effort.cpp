/* Problem:
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 10
*/

// Solution:
class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int emax = 0x3f3f3f3f;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, emax));
        dp[0][0] = 0;
        
        int prev = -1;
        for (int k = 0; k < m*n; k++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    for (int i = 0; i < 4; i++) {
                        int xn = x + dx[i];
                        int yn = y + dy[i];
                        if (xn < 0 || yn < 0 || xn >= m || yn >= n || dp[x][y] >= dp[xn][yn]){
                            continue;
                        } 
                        int e = abs(heights[x][y] - heights[xn][yn]);
                        dp[xn][yn] = min(max(dp[x][y], e), dp[xn][yn]); 
                    }
                }
            }
            if (prev == dp[m-1][n-1] && k > max(m, n)){
                return prev;
            }
            prev = dp[m-1][n-1];
        }
        return dp[m-1][n-1];
    }
};