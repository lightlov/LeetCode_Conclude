/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.70%)
 * Total Accepted:    164.2K
 * Total Submissions: 534.4K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        
        vector<Interval> res=merge(intervals);
        
        return res;
    }
    
    static bool cmp(Interval a,Interval b){   //static只对类可见？？？
        return a.start<b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans; 
        if(intervals.empty()) return ans;
        
        sort(intervals.begin(),intervals.end(),cmp);   
        int begin=0;//区间开头
        
        
        
        while(true){
            int left = intervals[begin].start,right = intervals[begin].end;
            int i;
            for(i=begin;i<intervals.size()-1;i++){
                if(right>=intervals[i+1].start) right = right>=intervals[i+1].end ? right:intervals[i+1].end; 
                else break;
            }    
            ans.push_back(Interval(left,right));
            begin=++i;
            if(begin>=intervals.size()) break;
        }
        return ans;
    }
};

