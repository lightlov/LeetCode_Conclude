/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.76%)
 * Total Accepted:    305.8K
 * Total Submissions: 879.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
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
    vector<Interval> merge(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval x, Interval y){ return x.start < y.start; });
        vector<Interval> res;
        merge(res,intervals);

        return res;

    }
private:
    void merge(vector<Interval>& res,vector<Interval>& intervals){
        if(intervals.size()==0) return ;


        Interval result=intervals[0];
        intervals.erase(intervals.begin());

        //if(intervals.size()==0) res.push_back(result);

        for(int i=0;i<intervals.size();){
            if(ismerge(result,intervals[i])) {
                //cout<<"hebing";
                result=merge(result,intervals[i]);
                intervals.erase(intervals.begin()+i);

            }
            else{i++;}

        }
//        int flag=0;
//        for(int i=0;i<res.size();i++){
//            if(ismerge(res[i],result)){
//                res[i]=merge(res[i],result);
//                flag=1;
//            }
//        }
        
//        if(flag==0) 
        res.push_back(result);

        

        merge(res,intervals);


    }
    bool ismerge(Interval s1,Interval s2){
        if((s2.start>=s1.start&&s2.start<=s1.end)||(s1.start>=s2.start&&s1.start<=s2.end)) return true;

        return false;

    }

    Interval merge(Interval s1,Interval s2){
        
        s1.start=min(s1.start,s2.start);
        s1.end=max(s1.end,s2.end);
    

        return s1;

    }
    
};

class Solution {
public:
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
/*
将区间的左端点排序,然后从第一个区间开始,如果右端点大于等于第二个区间的左端点,则合并,在从右端点2和当前右端点中选一个大的继续比.
*/

