class Solution {
private:
    // 私有函數執行主要的計算邏輯
    vector<int> computeSortedSquares(vector<int>& nums) {
        int n = nums.size(); // 獲取數組的大小
        vector<int> result(n, 0); // 初始化結果數組，大小與原數組相同，元素初值為0
        int k = n - 1; // 設置指針k，從結果數組的最後一個index開始

        for (int i = 0, j = n - 1; i <= j; ) { // 雙指針法，i從頭，j從尾，向中間遍歷
            if (pow(nums[i], 2) > pow(nums[j], 2)) { // 比較兩個指針指向的數字的平方大小
                result[k--] = pow(nums[i], 2); // 如果左邊的數字平方較大，將其加入結果數組並將k向左移
                i++; // 移動左邊的指針向右
            }
            else {
                result[k--] = pow(nums[j], 2); // 如果右邊的數字平方較大或相等，將其加入結果數組並將k向左移
                j--; // 移動右邊的指針向左
            }
        }
        return result; // 返回已排序的平方數組
    }

public:
    // 公有函數提供外部調用接口
    vector<int> sortedSquares(vector<int>& nums) {
        return computeSortedSquares(nums); // 調用私有函數處理並返回結果
    }
};
