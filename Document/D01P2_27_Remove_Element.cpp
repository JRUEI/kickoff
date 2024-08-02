class Solution {
private:
    // remove element
    int removeElementInternal(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

public:
    // call function
    int removeElement(vector<int>& nums, int val) {
        return removeElementInternal(nums, val);
    }
};
