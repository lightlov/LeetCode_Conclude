/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (35.26%)
 * Total Accepted:    125.5K
 * Total Submissions: 355.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string result;
        if(nums.size()==0) return res;
        int start=0;
        int end=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) continue;
            else{
                end=i-1;
                if(start==end){
                    result+=to_string(nums[start]);
                    res.push_back(result);
                    result.clear();
                }
                else{
                    result+=to_string(nums[start]);
                    result+='-';
                    result+='>';
                    result+=to_string(nums[end]);
                    res.push_back(result);
                    result.clear();
                }
                start=i;
            }
        }
        
        if(start==nums.size()-1){
            result+=to_string(nums[start]);
            res.push_back(result);
            result.clear();
        }
        else{
            result+=to_string(nums[start]);
            result+='-';
            result+='>';
            result+=to_string(nums[nums.size()-1]);
            res.push_back(result);
            result.clear();
        }
        
        
        return res;
    }
};

