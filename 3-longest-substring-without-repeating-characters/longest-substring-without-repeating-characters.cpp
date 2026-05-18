/* A map works well to store what we've already seen in the string and use it to compare to others in terms of length of our answer. The only thing we care about is the greatest length not an actual substring so we can create a sliding window in our string to find and save this length as we compare within the string.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen; //creates map to index our string on
        int L = 0; //creates a left for sliding window
        int maxLen = 0; // our answer value
        for(int R = 0; R < s.size(); R++){  //creates right for sliding window that iterates over the size of the string
            if(seen.count(s[R]))//when we find a repeat value
            {
                L = max(L, seen[s[R]] + 1); // Move L to one past where we last saw this character, max ensures we never move backwards
            }
            seen[s[R]] = R; //we reset where R is in the string
            maxLen = max(maxLen, R-L+1);//then update our length with our max length
        }
        return maxLen; //return answer
    }
};