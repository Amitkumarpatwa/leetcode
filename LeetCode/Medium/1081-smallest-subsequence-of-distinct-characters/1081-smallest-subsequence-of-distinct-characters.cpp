class Solution {
public:
    string smallestSubsequence(string s) {
        // Track the last occurrence index of each character
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        // Track whether a character is currently in our result stack
        vector<bool> visited(26, false);
        string result = ""; // Using a string as a stack
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // If the character is already included, we skip it
            if (visited[curr - 'a']) {
                continue;
            }
            
            // Maintain the monotonic increasing order where possible
            while (!result.empty() && result.back() > curr && lastIndex[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to the stack
            result.push_back(curr);
            visited[curr - 'a'] = true;
        }
        
        return result;
    }
};