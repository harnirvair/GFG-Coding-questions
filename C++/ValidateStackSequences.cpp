//Problem Link: https://leetcode.com/problems/validate-stack-sequences/submissions/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for (auto ele: pushed){
            s.push(ele);
            while(s.size()>0 && s.top()==popped[i]){
                s.pop();
                i++;
            }
        }
        return s.size()==0;
    }
};
