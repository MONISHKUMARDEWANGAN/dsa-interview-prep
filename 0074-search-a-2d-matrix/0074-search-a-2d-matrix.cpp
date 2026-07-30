class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0, high = rows - 1;
        int row = -1;

        // Find the candidate row
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][cols - 1]) {
                row = mid;
                break;
            }
            else if (target < matrix[mid][0]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (row == -1)  return false;

        low = 0;
        high = cols - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};