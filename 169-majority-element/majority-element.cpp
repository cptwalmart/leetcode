class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for(int i=0; i < nums.size(); i++){
            seen[nums[i]]++;
            if(seen[nums[i]]>(n/2))
                return nums[i];
        }
        return 0;
    }
};