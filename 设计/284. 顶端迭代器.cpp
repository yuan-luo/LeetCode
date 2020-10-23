284. 顶端迭代器
https://leetcode-cn.com/problems/peeking-iterator/


给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。设计并实现一个支持 peek() 操作的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

示例:

假设迭代器被初始化为列表 [1,2,3]。

调用 next() 返回 1，得到列表中的第一个元素。
现在调用 peek() 返回 2，下一个元素。在此之后调用 next() 仍然返回 2。
最后一次调用 next() 返回 3，末尾元素。在此之后调用 hasNext() 应该返回 false。
进阶：你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？

=============================================================
题解：

next()可以返回队头元素，但会造成队头索引的移动。
这道题考的其实是：如何返回队头元素，但队头索引不动。

我们加一个cur下标用来记录当前元素的下一个元素的下标。
当调用next()的时候我们先返回cur，再把cur记录下一个元素的下标。

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    if (!Iterator::hasNext()) cur = -1;
            else cur = Iterator::next();
	}
	
	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
            return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = cur;
	    if (Iterator::hasNext()) cur = Iterator::next();
	    else cur = -1;
	    return res;
	}
	
	bool hasNext() const {
	    return cur != -1;
	}
private:
    int cur;
};



