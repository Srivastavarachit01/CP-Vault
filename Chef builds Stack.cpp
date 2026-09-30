#include <queue>
#include <algorithm>

class StackUsingQueues {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    StackUsingQueues() {}

    void push(int x) {
        // Push new element into q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        std::swap(q1, q2);
    }

    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};