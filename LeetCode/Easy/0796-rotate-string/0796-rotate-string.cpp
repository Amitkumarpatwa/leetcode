class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string doubleString=s+s;

        if(doubleString.find(goal)!=-1) return true;
        return false;
    }
};