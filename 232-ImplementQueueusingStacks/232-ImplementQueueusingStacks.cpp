// Last updated: 16/03/2026, 12:46:55
1class MyQueue {
2public:
3    stack<int> s1; stack<int> s2;
4    MyQueue() {
5        
6    }
7    // push to the rear
8    void push(int x) {
9        while(!s1.empty()){
10            s2.push(s1.top());
11            s1.pop();
12        }
13        s2.push(x);
14        while(!s2.empty()){
15            s1.push(s2.top());
16            s2.pop();
17        }
18    }
19    
20    int pop() {
21        int val = s1.top();
22        s1.pop(); return val;
23    }
24    
25    int peek() {
26        return s1.top();
27    }
28    
29    bool empty() {
30        return s1.empty();
31    }
32};
33
34/**
35 * Your MyQueue object will be instantiated and called as such:
36 * MyQueue* obj = new MyQueue();
37 * obj->push(x);
38 * int param_2 = obj->pop();
39 * int param_3 = obj->peek();
40 * bool param_4 = obj->empty();
41 */