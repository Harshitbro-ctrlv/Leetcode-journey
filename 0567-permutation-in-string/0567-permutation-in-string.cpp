class Solution {
private:
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i<26; i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            count1[s1[i]-'a']++;
        }
        int i = 0;
        int k = s1.length();
        int count2[26] = {0};
        while(i < k){
            count2[s2[i]-'a']++;
            i++;
        }
        if(checkEqual(count1, count2)){
            return 1;
        }
        while(i < s2.length()){
            char ch = s2[i];
            count2[ch -'a']++;
            char oldch = s2[i-k];
            count2[oldch - 'a']--;
            i++;
        
            if(checkEqual(count1, count2)){
                return 1;
            }
        }
        return 0;
    }
};