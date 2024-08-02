class Solution {
private:
    // 私有函數執行主要的計算邏輯
    vector<int> computeSortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int k = n - 1;

        for (int i = 0, j = n - 1; i <= j; ) {
            if (pow(nums[i], 2) > pow(nums[j], 2)) {
                result[k--] = pow(nums[i], 2);
                i++;
            }
            else {
                result[k--] = pow(nums[j], 2);
                j--;
            }
        }
        return result;
    }

public:
    // 公有函數提供外部調用接口
    vector<int> sortedSquares(vector<int>& nums) {
        return computeSortedSquares(nums);
    }
};
