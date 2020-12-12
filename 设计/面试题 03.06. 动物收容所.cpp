面试题 03.06. 动物收容所

动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。
在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。
换言之，收养人不能自由挑选想收养的对象。
请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。

enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

class AnimalShelf {
public:
    queue<vector<int>> cats;
    queue<vector<int>> dogs;

    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if (animal[1] == 0) cats.push(animal);
        else dogs.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> ans;
        if (cats.empty() && dogs.empty()) return vector<int> {-1, -1};
        else if (!cats.empty() && dogs.empty()) {
            ans = cats.front();
            cats.pop();
        } else if (cats.empty() && !dogs.empty()) {
            ans = dogs.front();
            dogs.pop();
        } else {
            if (cats.front()[0] < dogs.front()[0]) {
                ans = cats.front();
                cats.pop();
            } else {
                ans = dogs.front();
                dogs.pop();                
            }
        }
        return ans;
    }
    
    vector<int> dequeueDog() {
        vector<int> ans;
        if (dogs.empty()) return vector<int> {-1, -1};
        else {
            ans = dogs.front();
            dogs.pop();
        }
        return ans;
    }
    
    vector<int> dequeueCat() {
        vector<int> ans;
        if (cats.empty()) return vector<int> {-1, -1};
        else {
            ans = cats.front();
            cats.pop();
        }
        return ans;
    }
};
