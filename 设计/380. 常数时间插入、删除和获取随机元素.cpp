380. 常数时间插入、删除和获取随机元素

https://leetcode-cn.com/problems/insert-delete-getrandom-o1/

设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();


=====================================================
题解：

列表vector有索引可以实现常数时间的insert和getRandom，则接下来的问题是如何实现常数时间的remove。
删除任意索引元素需要线性时间，问题的解决方案是总是删除最后一个元素。
1. 将要删除元素和最后一个元素交换。
2. 将最后一个元素删除。

对于数组：
index:      nums[val]       nums[last]
val:        val             last

对于hashmap：
key        value:
val  -->   m[val]
last -->   m[last]

为此，必须在常数时间获取到要删除元素的索引，因此需要一个哈希表来存储值到索引的映射。
设置一个unordered_map<int, int>，key是数字的值，value是数字在nums中的index位置。

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back(); // 把nums中最后一个数字记下来，我们接下来要做的是把val和last互换位置
        m[last] = m[val]; // m[last]在nums中的位置换成m[val]在nums中的位置
        nums[m[val]] = last; // 把nums中的val位置的值换成last值
        nums.pop_back();
        m.erase(val);
        return true;        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> m; // key是值，value是在nums中的index位置
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

