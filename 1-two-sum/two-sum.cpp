/* So the nieve approach to this problem would be simply comparing the first value of the array to every subsequent number in the array. Since we can't have more than one solution in an array and you cannot use the same element twice. So something akin to
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size();i++) //Grabs the first element of the array
        {
            for(int x = i+1; x < nums.size(); x++) //Grabs the n+1 element and the ones after it for comparision
            {
                if(nums[i]+nums[x] == target)
                    return {i,x}; //Returns Correct array places for solution when found
            }
        }
        return {}; //Empty list edgecase
    }
};
However this is inefficent since it is a nested loop and runs at O(n^2). A more refined solution would be first creating a hash map of our array, then finding the value we're missing, and searching the map for our missing integar's location.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; //Creates our index of values

        for (int i = 0; i< nums.size(); i++){
            int complement = target - nums[i]; // Finds our missing value for solution

            if (seen.count(complement)){
                return {seen[complement], i}; //returns our two indices
            }

            seen[nums[i]] = i;
        }
        return {}; // no solution edgecase
    }
};