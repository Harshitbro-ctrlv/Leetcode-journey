class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int> counts;
       for(int num: arr){
            counts[num]++;
       }
       unordered_set<int> unique;
       for(auto [num, count]: counts){
            if(unique.count(count)){
                return false;
            }
            unique.insert(count);
       }
       return true;
    }
};