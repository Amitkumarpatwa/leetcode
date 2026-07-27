class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(st.size()) st.pop();
            }
            else st.push(s[i]);
        }
        string ans;
        while(st.size()){
           
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};