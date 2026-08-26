class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> b = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'},
        };
        
        stack<char> st;

        for(char ch : s){
            if(b.count(ch)){
                if (!st.empty() && b[ch] == st.top()){
                    st.pop();
                } else {
                    return false;
                } 
            }else {
                st.push(ch);
            }
        }

        return st.empty();

    }
};
