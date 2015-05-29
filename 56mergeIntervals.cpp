/*
 * =====================================================================================
 *
 *       Filename:  56mergeIntervals.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月29日 10时59分36秒
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
	int start;
	int end;
	Interval():start(0) , end(0){}
	Interval(int s , int e):start(s) , end(e){}
};

class Solution{
	public:
		vector<Interval> merge(vector<Interval>& intervals);
};

bool cmp(const Interval& inter1 ,const Interval& inter2)
{
	return inter1.start < inter2.start;
}

vector<Interval> Solution::merge(vector<Interval>& intervals)
{
	vector<Interval> res;
	int start , end;
	sort(intervals.begin() , intervals.end() , 	cmp);
	
	int i = 0;
	while(i < intervals.size()){
		start = intervals[i].start;
		end = intervals[i].end;
		while( i+1 < intervals.size() && end >= intervals[i+1].start){
			i++;
			if(end < intervals[i].end){
				end = intervals[i].end;
			}
		}
		if(end < intervals[i].end){
			end = intervals[i].end;
		}
		res.push_back(Interval(start , end));
		i++;
	}

	return res;
}

int main(int argc , char * argv[])
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,4));
	intervals.push_back(Interval(0,2));
	intervals.push_back(Interval(3,5));
	//intervals.push_back(Interval(8,10));

	Solution sol;
	vector<Interval> res;
	res = sol.merge(intervals);
	
	for(int i = 0 ; i < res.size() ; i++){
		cout<<"("<<res[i].start<<","<<res[i].end<<")"<<endl;
	}
}
