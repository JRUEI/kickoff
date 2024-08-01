class Solution {
    int middle(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1; //閉區間
        while (left <= right) { // 防止區間為空，等於時依然有效
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2; //防止溢出，不直接加權平均
            //因為是開區間，所以有三個可能，三個if
            //target在左半，切掉右半，右半最小值為mid，所以mid往左shift就是新的區間
            if (nums[mid] > target) {
                right = mid - 1;
            }                
            //target在右半，切掉左半，左半最大值為mid，所以mid往右shift就是新的區間
            else if (nums[mid] < target) {
                left = mid + 1;
            }                
            //target在正中間
            else{
                return mid;
            }                
        }
        return -1; // 如果沒有找到target，返回-1
    }

public:
    int search(vector<int>& nums, int target) {
        int i = middle(nums, target);
        return i;
    }
};
