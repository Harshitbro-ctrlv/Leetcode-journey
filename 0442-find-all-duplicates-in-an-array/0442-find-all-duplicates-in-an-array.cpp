class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int ans = 0;
        vector<int> res(10);
        for(int i = 0; i< nums.size(); ++i){
            int index = abs(nums[i]);
            int targetValue = index -1;
            if(nums[targetValue] < 0){
                res.push_back(index);
            }else{
                nums[targetValue] = -nums[targetValue];
            }
        }
        res.erase(remove(res.begin(), res.end(), 0), res.end());
        return res;
    }
};