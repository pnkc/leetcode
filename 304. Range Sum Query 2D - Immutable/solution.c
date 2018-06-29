/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    vector<vector<int>> dp;
    //use 2D dp array to store each row's sum
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        dp.resize(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        for(int r= 0; r< matrix.size(); r++){
            for(int c= 0; c< matrix[0].size(); c++){
                dp[r][c+1]= dp[r][c]+ matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum= 0;
        for(int i= row1; i<= row2; i++){
            sum+= dp[i][col2+1]- dp[i][col1];
            //sum up each row's sum
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */