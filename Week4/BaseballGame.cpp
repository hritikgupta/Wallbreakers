// 682. Baseball Game (https://leetcode.com/problems/baseball-game/)
// Author: Hritik Gupta

class Solution {
public:
    
    int stringToint(string s){
        int val = 0;
        int idx = 0;
        int sign = 1;
        
        if(s[0] == '-'){
            sign = -1;
            idx = 1;
        }
        
        for(int i=idx; i<s.size(); i++){
            val = val*10 + (s[i]-'0');
        }
        return val*sign;
    }
    
    int calPoints(vector<string>& ops) {
        
        if(ops.size() == 0)
            return 0;
        
        stack<int> s;
        
        for(int i=0; i<ops.size(); i++){
            string op = ops[i];
            
            if(op == "+"){
                int a = s.top();
                s.pop();
                int c = a + s.top();
                s.push(a);
                s.push(c);
            }
            else if(op == "D"){
                s.push(2*s.top());
            }
            else if(op == "C"){
                s.pop();
            }
            else{
                s.push(stringToint(op));
            }
        }
        
        int ans = 0;
        
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};


/*
                           .
["5","-2","4","C","D","9","+","+"]

14
5
9
-4
-2
5


*/