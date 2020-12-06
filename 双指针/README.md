https://www.1point3acres.com/bbs/thread-678970-7-1.html 

第六章 多指针

基本问题：
（1）多指针是一个非常广泛的概念，并不是一个固定的算法。但基本上是通过一些变量的控制与循环把问题的复杂度控制在一两层for循环之内。可以用在数组、链表、区间、滑动窗口、流、回文串、和差问题等多个场景。（前项和其实并不完全是指针问题，但也归并在这里）。
（2）Quick Sort和Merge Sort的基本原理与实现，排序的稳定性问题
（3）Quick Select的实现与复杂度
（4）同向指针与相向指针的使用场景
（5）不同场景下循环终止条件？
（6）两数之和，之差，特定条件下（大小于某值等）的计数问题
（7）三数或三数以上之和的通用写法（两数之和+搜索）
（8）数组有没有排序？是否需要排序？
（9）数组有没有去重？是否需要去重？
（10）离线数据（内存中，有限长）还是在线数据（无法放入内存，长度未知）？
（11）链表操作中dummy node与previous node的使用技巧
（12）链表的中点，判断是否有环，寻找环的交叉点




多指针题目列表：
（必背：紫色；核心：蓝色；重点：绿色；普通：黄色；默认是LeetCode，如果是LintCode会以Lint开头）



数组：

912. Sort an Array (Quick Sort and Merge Sort)
https://leetcode.com/problems/sort-an-array/

75. Sort Colors
https://leetcode.com/problems/sort-colors/

26. Remove Duplicates from Sorted Array
https://leetcode.com/problems/re ... -from-sorted-array/

80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/re ... om-sorted-array-ii/

88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/

283. Move Zeroes
https://leetcode.com/problems/move-zeroes/

215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/

347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/

349. Intersection of Two Arrays
https://leetcode.com/problems/intersection-of-two-arrays/

350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/

845. Longest Mountain in Array
https://leetcode.com/problems/longest-mountain-in-array/

42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/

43. Multiply Strings
https://leetcode.com/problems/multiply-strings/

969. Pancake Sorting
https://leetcode.com/problems/pancake-sorting/

Lint-31. Partition Array
https://www.lintcode.com/problem/partition-array/description

Lint-625. Partition Array II
https://www.lintcode.com/problem/partition-array-ii/description

Lint-143. Sort Color II
https://www.lintcode.com/problem/sort-colors-ii/description

Lint-461. Kth Smallest Numbers in Unsorted Array
https://www.lintcode.com/problem ... d-array/description

Lint-544. Top k Largest Numbers
https://www.lintcode.com/problem ... numbers/description


链表：

21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/

86. Partition List
https://leetcode.com/problems/partition-list/

141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/

234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/

328. Odd Even Linked List
https://leetcode.com/problems/odd-even-linked-list/

142. Linked List Cycle II
https://leetcode.com/problems/linked-list-cycle-ii/

287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/

876. Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/


区间：

Lint-391. Number of Airplanes in the Sky
https://www.lintcode.com/problem ... the-sky/description

56. Merge Intervals
https://leetcode.com/problems/merge-intervals/

57. Insert Interval
https://leetcode.com/problems/insert-interval/

252. Meeting Rooms
https://leetcode.com/problems/meeting-rooms/

253. Meeting Rooms II
https://leetcode.com/problems/meeting-rooms-ii/

986. Interval List Intersections
https://leetcode.com/problems/interval-list-intersections/


回文串：

5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

345. Reverse Vowels of a String
https://leetcode.com/problems/reverse-vowels-of-a-string/

680. Valid Palindrome II
https://leetcode.com/problems/valid-palindrome-ii/

125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/


滑动窗口：

3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/lo ... peating-characters/

11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/

76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/

209. Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/

239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/

713. Subarray Product Less Than K
https://leetcode.com/problems/subarray-product-less-than-k/

395. Longest Substring with At Least K Repeating Characters
https://leetcode.com/problems/lo ... peating-characters/

480. Sliding Window Median
https://leetcode.com/problems/sliding-window-median/

567. Permutation in String
https://leetcode.com/problems/permutation-in-string/

727. Minimum Window Subsequence
https://leetcode.com/problems/minimum-window-subsequence/

Lint-604. Window Sum
https://www.lintcode.com/problem/window-sum/description


流：

295. Find Median from Data Stream
https://leetcode.com/problems/find-median-from-data-stream/

346. Moving Average from Data Stream
https://leetcode.com/problems/moving-average-from-data-stream/

352. Data Stream as Disjoint Intervals
https://leetcode.com/problems/data-stream-as-disjoint-intervals/

703. Kth Largest Element in a Stream
https://leetcode.com/problems/kth-largest-element-in-a-stream/


前项和：

53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/

238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/

303. Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/

325. Maximum Size Subarray Sum Equals k
https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

528. Random Pick with Weight
https://leetcode.com/problems/random-pick-with-weight/

560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/


和差问题：

1. Two Sum
https://leetcode.com/problems/two-sum/

15. 3Sum
https://leetcode.com/problems/3sum/

18. 4Sum
https://leetcode.com/problems/4sum/

Lint-382. Triangle Count
https://www.lintcode.com/problem/triangle-count/description

167. Two Sum II - Input array is sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

170. Two Sum III - Data structure design
https://leetcode.com/problems/two-sum-iii-data-structure-design/

653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

1099. Two Sum Less Than K
https://leetcode.com/problems/two-sum-less-than-k/

259. 3Sum Smaller
https://leetcode.com/problems/3sum-smaller/

Lint-57. 3Sum Closest
https://www.lintcode.com/problem/3sum-closest/description

Lint-443. Two Sum - Greater than target
https://www.lintcode.com/problem ... -target/description

Lint-533. Two Sum - Closet to target
https://www.lintcode.com/problem ... -target/description

Lint-587. Two Sum - Unique pairs
https://www.lintcode.com/problem/two-sum-unique-pairs/description

Lint-609. Two Sum - Less than or equals to target
https://www.lintcode.com/problem ... -target/description

Lint-610. Two Sum - Difference equals to target
https://www.lintcode.com/problem ... rget/my-submissions
