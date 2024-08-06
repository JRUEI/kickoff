# Day 01 - 数组part01
2024.07.31 Wed.

## Quest
#### 1. 二分查找 - Binary Search

```
熟悉 根据 左闭右开，左闭右闭 两种区间规则 写出来的二分法。
```
一刷
- [x] 704 二分查找

二刷
- [ ] 35 搜索插入位置
- [ ] 34 在排序数组中查找元素的第一个和最后一个位置

#### 2. 移除元素 - Remove Element
```
双指针法 是本题的精髓，今日需要掌握，至于拓展题目可以先不看。 
```
- [x] 27 移除元素

#### 3. 有序数组的平方
```
本题关键在于理解双指针思想
```
- [x] 977 有序数组的平方 

# <mark style="color:red;">Problem 1 - 704</mark>

問題描述：給定一個長度為 n 的升序整數數組 `nums` 和一個目標值 `target`，搜索 `nums` 中的 `target`，如果目標值存在返回其index，否則返回 -1。

解決方案：寫一個函數，使用二分搜尋法（binary search）尋找目標值 `target`

關鍵概念：binary search之中的while迴圈，可以使用以下三種寫法（其中代碼隨想錄介紹**左閉右閉**與**左閉右開**這兩種寫法），一旦區間的界定被確立之後，while的判斷會同時被確立（新區間的邊界）。

- 閉區間（左閉右閉）
- 左閉右開區間（、左開右閉區間）
- 開區間（左開右開）

## Code

```cpp
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
```

## Note
#### [文章講解 - 代碼隨想錄](<https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE>)

#### （未完成）[每日精華](<https://ppt.cc/f6K31x>)

#### （完成）[B站視頻](<https://www.bilibili.com/video/BV1fA4y1o715/>)
- `while(left (X) right)`，到底`(X)`要是`<`還是`<=`，要由你一開始定義左閉右閉還是左閉右開有關聯
- 承上，新的邊界一樣的思路去處理

#### 一刷（完成）
- 過濾、減半：binary search是利用input array已被sorted過的特性，每進行一次while迴圈，即過濾掉該次區間一半的elements
- 效率高（time complexity）：binary search為`O(logN)`> linear search為`O(logN)`
- 習慣養成：習慣單獨寫function放private，而非直接在public操作
  ```*.md
  這樣的設計提高了程式碼的可讀性和維護性，並且保持了良好的封裝性：數據處理的具體實現細節封裝在類內部，使得外部調用更簡潔、更安全。
  ```
- index shifting：建立index shifting的概念，畢竟是面對array
  ```*.md
  利用 `mid` 的 index 作單位為 1 的 shifting，即可獲得新的 `left` 或 `right`
  ```
- 避免overflow：小a、大b兩數加權平均採用`a+(b-a)/2`而非`(a+b)/2`以避免overflow

  ```*.md
  當 `left` 和 `right` 都接近整數類型的最大值時（對於32位整數來說是 2147483647），left + right 會超過32位整數的範圍，導致溢出。
  ```
#### 二刷（未完成）
- 邊界條件：???

- 閉區間與左閉右開區間如何作轉換？差別在哪？

# <mark style="color:red;">Problem 2 - 27</mark>

問題描述：給定一 `val` ，將數組 `num` 中與 `val` 相同的元素移除後，會獲得一組更新後的數組，輸出其新數組的長度/元素數。

解決方案：使用雙指針法，重複的數字會被取代掉，新數組會產生。而當快指針歷遍整個數組，新數組完成更新。

關鍵概念：`fastIndex` 遍歷每個元素，而 `slowIndex` 則只在遇到不等於 `val` 的元素時才增加，從而在原地完成元素的替換。

## Code

```cpp
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
```

## Note

#### [文章講解 - 代碼隨想錄](<https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html>)

#### （未完成）[每日精華](<https://ppt.cc/fbAgNx>)

#### （未完成）[B站視頻](<>)

#### 一刷（完成）
1. 初始化指針：

    - `slowIndex` 初始化為 0，用於記錄新的數組長度及存儲位置。
      
      ```*.md
       想像成是擠牙膏器，把尾端的牙膏往前端趕
      ```
      
    - `fastIndex` as a scanner，用於遍歷整個數組。

2. 遍歷數組：
    - 使用 `for` 迴圈從頭到尾遍歷數組，`fastIndex` 從 `0` 遍歷到 `nums.size() - 1`。

3. 判斷條件：
    - `if (val != nums[fastIndex])`：如果當前元素 `nums[fastIndex]` 不等於 `val`，則執行以下操作：
      - 將 `nums[fastIndex]` 的值賦給 `nums[slowIndex]`。
      - 將 `slowIndex` 增加 `1`。

4. 最終結果：
    - 當遍歷完所有元素後，`slowIndex` 的值即為移除所有等於 `val` 的元素後，數組的長度。
    - 因為我們在原地修改數組，所以 `nums` 的前 `slowIndex` 個元素即為移除後的數組。

#### 二刷（未完成）

# <mark style="color:red;">Problem 3 - 977</mark>

問題描述：
- 要求從一個已按非遞減順序排列的整數數組中生成一個每個數字平方後的新數組，並確保這個新數組也是非遞減順序。

解決方法：
- 利用雙指針技術從數組兩端開始向中間遍歷，將較大的平方數從結果數組的末尾向前填充。

關鍵概念：
- 雙指針法與非遞減順序的運用在對有序數組進行變換時保持高效性和有序性。

## Code

```cpp
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
```

## Note

#### [文章講解 - 代碼隨想錄](<https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html>)

圖片是動圖，點開看演示

![img.gif](https://code-thinking.cdn.bcebos.com/gifs/977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.gif)

#### （未完成）[每日精華](<https://ppt.cc/fK5IVx>)

#### （未完成）[B站視頻](<>)

#### 一刷（完成）

1. **雙指針應用**：

    - 使用兩個指針，`i` 從數組的開始，`j` 從數組的結尾開始遍歷。
      
      ```*.md
      「雙 手 捏 泡 泡 紙」：兩手不可同時捏且一次只能捏一顆。
      ```

2. **正負數平方**：

    - 比較兩端數字的平方大小，並將平方後數值大者放入新數組。

      ```*.md
      考慮到負數的平方可能大於正數的平方，因此從數值較大的一端開始填充到結果數組。
      ```

3. **避免排序**：

    - 直接利用已排序的輸入數組特性，選擇性地從兩端向新數組填充數值。

      ```*.md
      以0為中心，負數與正數都是有序的排序，而新數組中各元素的大小排序由指針歷遍數組時已決定。
      ```
4. **for迴圈的巧思**

    1. 初始化部分：

        int i = 0, j = n - 1：這裡初始化兩個變量 i 和 j。i 被初始化為 0，即數組的第一個元素的索引；j 被初始化為 n - 1，即數組的最後一個元素的索引。
   
    2. 條件部分：

        i <= j：這是循環繼續執行的條件。當 i 小於或等於 j 時，循環體將被執行。這意味著循環將繼續，只要 i 指針還沒有超過 j 指針。

    3. 增量部分：

        留空（即省略了）：在這個 for 循環中，增量部分被故意省略，這意味著循環中沒有自動的索引增加或減少。增量的操作將在循環的主體中根據條件手動完成。

