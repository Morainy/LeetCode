/*
 * =====================================================================================
 *
 *       Filename:  57insertInterval.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月29日 18时46分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval{
	int start , end;
	Interval():start(0) , end(0){}
	Interval(int s , int e):start(s) , end(e){}
};

class Solution{
	public:
		vector<Interval> insert(vector<Interval>& intervals , Interval newInterval);
};

bool cmp(const Interval& inter1 , const Interval& inter2)
{
	return inter1.start < inter2.start;
}
vector<Interval> Solution::insert(vector<Interval>& intervals , Interval newInterval)
{
	int i = 0 , n = intervals.size();
	int start = newInterval.start;
	int end = newInterval.end;
	vector<Interval> res;

	while( i < n && intervals[i].end < start){
		res.push_back(intervals[i]);
		i++;
	}

	if(i < n){
		start = min(start , intervals[i].start);
	}
	while(i < n && intervals[i].start <= end){
		i++;
	}
	if(i-1 >= 0){
		end = max(intervals[i-1].end , end);
	}
	res.push_back(Interval(start , end));

	while(i < n){
		res.push_back(intervals[i]);
		i++;
	}
	return res;
}



int main(int argc , char * argv[])
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1 , 2));
	intervals.push_back(Interval(3 , 5));
	intervals.push_back(Interval(6 , 7));
	intervals.push_back(Interval(8 , 10));
	intervals.push_back(Interval(12 , 16));

	/*intervals.push_back(Interval(1 , 3));
	intervals.push_back(Interval(6 , 9));*/
	
	vector<Interval> res;

	Solution sol;
	res = sol.insert(intervals , Interval(4 , 9));

	for(int i = 0 ; i < res.size() ; i++){
		cout<<"("<<res[i].start<<","<<res[i].end<<")"<<endl;
	}
}

