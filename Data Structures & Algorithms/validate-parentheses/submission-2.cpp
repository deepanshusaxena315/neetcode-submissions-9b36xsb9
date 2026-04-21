class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch: s){
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.size()==0) return false;
                if(st.top()=='(' && ch==')' ) st.pop();
                else if(st.top()=='{' && ch=='}')st.pop();
                else if(st.top()=='[' && ch==']') st.pop(); 
                else return false;
            }

        }
        return st.size()==0;

    }
};
