/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.06%)
 * Total Accepted:    220K
 * Total Submissions: 563.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
//        for(int i=0;i<candidates.size();i++){
//            if(i>0&&candidates[i]==candidates[i-1]){continue;}
        func(res,combination,candidates,target,0);
//        }
        return res;
    }
    
    void func(vector<vector<int>> &res,vector<int> &combination,vector<int>& candidates, int target,int cnt){
        
        if(cnt>=candidates.size()) return;
//        combination.push_back(candidates[cnt]);
//        target-=candidates[cnt];
//        if(target<0){return;}
//        else if(target==0){res.push_back(combination);return;}
        for(int i=cnt;i<candidates.size();i++){
            if(target<candidates[i]) break;
            if(i>cnt&&candidates[i]==candidates[i-1]){continue;}
            combination.push_back(candidates[i]);
            if(target>candidates[i]){
                target-=candidates[i];
                func(res,combination,candidates,target,i+1);
                target+=candidates[i];
            }
            else{
                res.push_back(combination);
            }
            combination.pop_back();
            
            
//            func(res,combination,candidates,target,i);
            
        }
    }
};
/*
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]){continue;}
            func(res,combination,candidates,target,i);
        }
        return res;
    }
    
    void func(vector<vector<int>> &res,vector<int> combination,vector<int>& candidates, int target,int cnt){
        
        
        combination.push_back(candidates[cnt]);
        target-=candidates[cnt];
        if(target<0){return;}
        else if(target==0){res.push_back(combination);return;}
        for(int i=cnt+1;i<candidates.size();i++){
            if(i>cnt+1&&candidates[i]==candidates[i-1]){continue;}
            func(res,combination,candidates,target,i);
            
        }
    }
};
*/
