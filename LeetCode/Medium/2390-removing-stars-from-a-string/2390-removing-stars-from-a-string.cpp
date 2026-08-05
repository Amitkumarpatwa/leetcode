class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n= s.size();
        for(int i=0;i<n;i++){
            if(st.size()!=0 && s[i]=='*') st.pop();
            else st.push(s[i]);
        }

        string ans;
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};