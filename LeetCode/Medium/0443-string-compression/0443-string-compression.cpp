class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0,i=0;
        int n=chars.size();
        while(i < n){
            char current_char=chars[i];
            int count=0;
            // duplicate count 
            while(i<n && current_char==chars[i]){
                count++;
                i++;
            }

            // assign karna hai

            chars[index]=current_char;
            index++;
            if(count>1){
                // convert the count into string

                string count_str=to_string(count);

                for(auto  ch : count_str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};