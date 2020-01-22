/*
 * https://leetcode.com/problems/min-stack/
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
	stack<int> s;
	stack<int> m;

    MinStack() {
    }
    
    void push(int x) {
    	s.push(x);    
		if (!m.empty() && m.top() < x)
			m.push(m.top());
		else
			m.push(x);	
    }
    
    void pop() {
		s.pop();
    	m.pop();
    }
    
    int top() {
       	return s.top(); 
    }
    
    int getMin() {
    	return m.top(); 
    }
};

int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;   //--> Returns -3.
	minStack.pop();
	cout << minStack.top() << endl;      //--> Returns 0.
	cout << minStack.getMin() << endl;   //--> Returns -2.

	return 0;
}
