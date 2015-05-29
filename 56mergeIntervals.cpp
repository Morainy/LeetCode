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

vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> res;
	int start , end;

}

int main(int argc , char * argv[])
{

}
