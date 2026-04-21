class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch: s){
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.size()==0) return false;
                char next = st.top();
                st.pop();

                if(next=='(' && ch!=')' || next == '{' && ch!='}' || next=='[' && ch!=']' )return false;
            }

        }
        return st.size()==0;

    }
};
