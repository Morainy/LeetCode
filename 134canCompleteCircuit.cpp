/*
 * =====================================================================================
 *
 *       Filename:  134canCompleteCircuit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月12日 11时02分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;

/*class Solution{
private:
	int currentGas;
public:
	Solution():currentGas(0){}
	int canCompleteCircuit(vector<int>& gas , vector<int>& cost);
	int solve(vector<int>& gas , int start ,int cur, vector<int>& cost);		//start为起始站点索引，cur为当前站点索引
};


int Solution::solve(vector<int>& gas , int start ,int cur, vector<int>& cost)
{
	if(start == 0){
		if(cur == gas.size()-1){
			if(currentGas + gas[cur] >= cost[cur]){
				return start;
			}else{
				return -1;
			}
		}
	}
	if(cur == start-1){
		if(currentGas + gas[cur] >= cost[cur]){
			return start;
		}else{
			return -1;
		}
	}
	int size = gas.size();
	if(currentGas + gas[cur] >= cost[cur]){
		currentGas = currentGas + gas[cur] - cost[cur];
		cur = (cur+1) % size;
		return solve(gas , start , cur , cost);
	}else{
		return -1;
	}
}

int Solution::canCompleteCircuit(vector<int>& gas , vector<int>& cost)
{
	for (unsigned i = 0 ; i < gas.size() ; i++){
		if(solve(gas , i , i , cost) >= 0){
			return i;
		}
	}
	return -1;
}*/

class Solution{
	public:
		int canCompleteCircuit(vector<int>& gas , vector<int>& cost);
};

int Solution::canCompleteCircuit(vector<int>& gas , vector<int>& cost)
{
	vector<int> diff;
	for(int i = 0 ; i < gas.size() ; i++){
		diff.push_back(gas[i] - cost[i]);
	}

	for(int i = 0 ; i < gas.size() ; i++){
		if(diff[i] >= 0){
			int sum = 0 , cnt = 0;
			while(sum >= 0 && cnt < gas.size()){
				sum += diff[(i+cnt) % gas.size()];
				cnt++;
			}

			if(cnt == gas.size() && sum >= 0){
				return i;
			}else{
				i = i + cnt -1;
			}
		}
	}
	return -1;
}

int main(int argc , char* argv[])
{
	vector<int> gas;
	vector<int> cost;

	/*gas.push_back(1);
	gas.push_back(2);
	gas.push_back(3);
	gas.push_back(4);*/
	gas.push_back(5);
	
	/*cost.push_back(1);
	cost.push_back(2);
	cost.push_back(3);*/
	cost.push_back(4);
	//cost.push_back(5);

	Solution sol;
	cout<<"res = "<<sol.canCompleteCircuit(gas , cost)<<endl;
}
