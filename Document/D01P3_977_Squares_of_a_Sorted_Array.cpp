class Solution {
private:
    // 私有函數用於處理主要運算
    vector<int> computeSortedSquares(vector<int>& nums) {
        int n = nums.size();
        int negative = -1; // 最後一個負數的索引
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n) {
            if (i < 0) { // 沒有負數剩餘，只添加正數平方
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
            else if (j == n) { // 沒有正數剩餘，只添加負數平方
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else if (nums[i] * nums[i] < nums[j] * nums[j]) { // 負數平方小於正數平方，添加負數平方
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else { // 正數平方小於或等於負數平方，添加正數平方
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }

        return ans;
    }

public:
    // 公有函數，調用私有函數來獲取結果
    vector<int> sortedSquares(vector<int>& nums) {
        return computeSortedSquares(nums);
    }
};
