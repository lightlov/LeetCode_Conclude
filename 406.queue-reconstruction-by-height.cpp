/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (59.00%)
 * Total Accepted:    73.2K
 * Total Submissions: 123.7K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * 
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first>b.first;
}


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<pair<int,int>> res;
        int index;
        for(int i=0;i<people.size();i++){
            index=find_index(people[i],res);
            res.insert(res.begin()+index,people[i]);
        }
        
        return res;
    }
    
    int find_index(pair<int,int> loc,vector<pair<int,int>>& res){
        if(res.size()==0) return 0;
        int i;
        if(loc.second==0){
            for( i=0;i<res.size();i++){
                if(loc.first<res[i].first) return i;
            }
            return i;
        }
        else{
            int count=loc.second;
            for( i=0;i<res.size();i++){
                if(loc.first<=res[i].first){
                    count--;
                    if(count==0) return i+1;
                }
            }
            return i;
        }
        
    }
};

