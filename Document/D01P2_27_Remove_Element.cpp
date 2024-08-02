class Solution {
private:
    // 私有函數用於移除特定值，並返回更新後的數組長度
    int removeElementInternal(vector<int>& nums, int val) {
        int slowIndex = 0, fastIndex = 0;  // 初始化快慢指針，位置為數組的頭：慢指針用於標記新數組的填充位置，快指針用於歷遍數組。
        for (fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  // 快指針遍歷整個數組
            if (nums[fastIndex] != val) {  // 檢查當前元素是否不等於給定值 val
                nums[slowIndex++] = nums[fastIndex];  // 如果不等於 val，將其複製到慢指針的位置，然後慢指針後移
            }
        }
        return slowIndex;  // 返回新數組的長度，即慢指針的位置
    }

public:
    // 公有函數提供外部接口，調用內部處理函數並返回結果
    int removeElement(vector<int>& nums, int val) {
        return removeElementInternal(nums, val);  // 調用私有函數，並返回新的數組長度
    }
};
