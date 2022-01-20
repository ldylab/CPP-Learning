/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(); // 多少行
        int col = matrix[0].size(); // 多少列

        if(row == 0 || col == 0) return;

        vec_sum_ = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

        for(int i = 1; i <= row; ++i){
            for(int j = 1; j <= col; ++j){
                vec_sum_[i][j] = vec_sum_[i - 1][j] + vec_sum_[i][j - 1] - vec_sum_[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 左上角： row1 col1
        // 右下角： row2 col2
        // 左下角： row2 col1
        // 右上角： row1 col2
        // 最右下端都+1 各自-1并变化 都-1
        return vec_sum_[row2 + 1][col2 + 1] - vec_sum_[row1][col2 + 1] - vec_sum_[row2 + 1][col1] + vec_sum_[row1][col1];
    }

public:
    vector<vector<int>> vec_sum_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

