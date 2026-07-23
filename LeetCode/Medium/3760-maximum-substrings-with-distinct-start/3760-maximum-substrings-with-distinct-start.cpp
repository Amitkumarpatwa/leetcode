class Solution {
public:
    int maxDistinct(string s) {
        int hash[26]={0};
        int count=0;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(hash[i]>0) count++;
        }

        return count;
    }
};