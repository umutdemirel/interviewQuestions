//
//  MinStack.h
//  
//
//  https://leetcode.com/problems/min-stack/description/
//

#ifndef MinStack_h
#define MinStack_h

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> min;
    
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        for (int i = 0; i < min.size(); i++)
        {
            if (min[i] > x)
            {
                min.insert(min.begin() + i, x);
                return;
            }
        }
        min.push_back(x);
    }
    
    void pop() {
        int value = stack[stack.size() - 1];
        stack.pop_back();
        
        for (int i = 0; i < min.size(); i++)
        {
            if (min[i] == value)
            {
                //cout << "removing index : " << i << " value : " << value << endl;
                min.erase(min.begin() + i);
                return;
            }
        }
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return min[0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#endif /* MinStack_h */
