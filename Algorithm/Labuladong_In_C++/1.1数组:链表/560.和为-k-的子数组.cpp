/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> un_map;
    int result = 0;
    int sums_i = 0;

    int subarraySum(vector<int>& nums, int k) {
        un_map[0] = 1; // 在初始位置为0

        for(int i = 0; i < nums.size(); ++i){
            sums_i = sums_i + nums[i];
            
            if(un_map.find(sums_i - k) != un_map.end()){
                result += un_map[sums_i - k];
            }

            if(un_map.find(sums_i) != un_map.end()){
                // 能够找到对应这个数
                ++un_map[sums_i];
            }else{
                // 如果没有找到这个数
                un_map[sums_i] = 1;
            }
            
        }
        return result;
    }
};
// @lc code=end

