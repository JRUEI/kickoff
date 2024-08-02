# Day 01 - 数组part01
2024.07.31 (Wed.)

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
- [ ] 977 有序数组的平方 

# Problem 1 - 704

問題描述：給定一個長度為 n 的升序整數數組 `nums` 和一個目標值 `target`，搜索 `nums` 中的 `target`，如果目標值存在返回其index，否則返回 -1。

解決方案：寫一個函數，使用二分搜尋法（binary search）尋找目標值 `target`

關鍵概念：binary search之中的while迴圈，可以使用以下三種寫法（其中代碼隨想錄介紹**左閉右閉**與**左閉右開**這兩種寫法），一旦區間的界定被確立之後，while的判斷會同時被確立（新區間的邊界）。

- 閉區間（左閉右閉）
- 左閉右開區間（、左開右閉區間）
- 開區間（左開右開）

## 紀錄與思考
#### [代碼隨想錄](<https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE>)

#### [每日精華（未完成）](<https://ppt.cc/f6K31x>)

#### [B站視頻（完成）](<https://www.bilibili.com/video/BV1fA4y1o715/>)
- `while(left (X) right)`，到底`(X)`要是`<`還是`<=`，要由你一開始定義左閉右閉還是左閉右開有關聯
- 承上，新的邊界一樣的思路去處理

#### 一刷（完成）
- 過濾、減半：binary search是利用input array已被sorted過的特性，每進行一次while迴圈，即過濾掉該次區間一半的elements
- 效率高（time complexity）：binary search為`O(logN)`> linear search為`O(logN)`

- 其他：
  - 寫function：習慣單獨寫function而非直接在public操作
  - index shifting：建立index shifting的概念，畢竟是面對array
    ```*.md
    利用 `mid` 的 index 作單位為 1 的 shifting，即可獲得新的 `left` 或 `right`
    ```
  - 加權平均的習慣：小a、大b兩數加權平均採用`a+(b-a)/2`而非`(a+b)/2`以避免overflow

    ```*.md
    當 `left` 和 `right` 都接近整數類型的最大值時（對於32位整數來說是 2147483647），left + right 會超過32位整數的範圍，導致溢出。
    ```
#### 二刷（未完成）
- 邊界條件：???

- 閉區間與左閉右開區間如何作轉換？差別在哪？

# Problem 2 - 27

問題描述：給定一 `val` ，將數組 `num` 中與 `val` 相同的元素移除後，會獲得一組更新後的數組，輸出其新數組的長度/元素數。

解決方案：使用雙指針法，重複的數字會被取代掉，新數組會產生。而當快指針歷遍整個數組，新數組完成更新。

關鍵概念：`fastIndex` 遍歷每個元素，而 `slowIndex` 則只在遇到不等於 `val` 的元素時才增加，從而在原地完成元素的替換。

## 紀錄與思考

#### [每日精華（未完成）](<>)

#### [B站視頻（未完成）](<>)

#### 一刷（完成）
1. 初始化指針：

    - `slowIndex` 初始化為 0，用於記錄新的數組長度及存儲位置。
      
      > 想像成是擠牙膏器，把尾端的牙膏往前端趕
      
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
