class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int totalCells = rows * cols;
        int currentRow = rStart, currentCol = cStart;
        int step = 1;
        
        // Directions: right, down, left, up
        vector<int> directionX = {0, 1, 0, -1};
        vector<int> directionY = {1, 0, -1, 0};
        
        result.push_back({currentRow, currentCol});
        
        while (result.size() < totalCells) {
            for (int i = 0; i < 4; ++i) { // 4 directions in spiral
                int dx = directionX[i], dy = directionY[i];
                
                for (int j = 0; j < step; ++j) {
                    currentRow += dx;
                    currentCol += dy;
                    
                    // Check if the new position is within the grid boundaries
                    if (currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols) {
                        result.push_back({currentRow, currentCol});
                    }
                }
                
                // After moving right or left, we increase the step size
                if (i % 2 == 1) {
                    step++;
                }
            }
        }
        
        return result;
    }
};
