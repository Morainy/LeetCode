/*
 * =====================================================================================
 *
 *       Filename:  179largestNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月19日 16时36分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
class Solution{
	public:
		string largestNumber(vector<int>& nums);
		int myCmp(int a , int b);
		void quickSort(vector<int> & nums , int begin , int end);
		int partition(vector<int> & nums , int begin , int end);
};

int Solution::myCmp(int a , int b)
{
	char s1[20];
	char s2[20];
	bzero(s1 , 20);
	bzero(s2 , 20);
	
	sprintf(s1 , "%d" , a);
	sprintf(s2 , "%d" , b);
	int i = 0;
	while(i < strlen(s1) && i < strlen(s2)){
		if(s1[i] < s2[i]){
			return -1;
		}
		if(s1[i] > s2[i]){
			return 1;
		}
		i++;
	}
	if( i < strlen(s2)){
		if(s1[i-1] < s2[i]){
			return -1;
		}
		else{
			return 1;
		}
	}
	if( i < strlen(s1)){
		if(s2[i-1] <= s1[i]){
			return 1;
		}
		else{
			return -1;
		}
	}
	return 1;
}

int Solution::partition(vector<int> &nums , int begin , int end)
{
	int i , j;
	for(i = begin-1 , j = begin ; j < end ; j++){
		if(myCmp(nums[j] , nums[end]) < 0){
			i++;
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	int tmp = nums[i + 1];
	nums[i + 1] = nums[end];
	nums[end] = tmp;
	return i + 1;
}
void Solution::quickSort(vector<int>& nums , int begin , int end)
{
	if(begin >= end){
		return;
	}
	int r = partition(nums , begin , end);
	quickSort(nums , begin , r -1);
	quickSort(nums , r + 1 , end);
}
string Solution::largestNumber(vector<int>& nums)
{
	string res;
	char sstr[20];
	bzero(sstr , 20);
	
	bool flags = 0;
	for(int i = 0 ; i < nums.size() ; i++){
		if(nums[i] != 0){
			flags = 1;
		}
	}

	if(flags ==0){
		return "0";
	}
	quickSort(nums , 0 , nums.size() - 1);
	for(int i = nums.size() -1 ; i >= 0 ; i--){
		sprintf(sstr , "%d" , nums[i]);
		res += sstr;
	}
	return res;
}*/

class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            string ret;
            sort(nums.begin(),nums.end(),myCmp);
            for(int i=0;i<nums.size();++i){
                ret+=to_string(nums[i]);
            }
            if(ret[0]=='0') //for the case nums are all zeros
                return "0";
            return ret;
    }
	int myCmp(const int & m , const int & n)
	{
		return to_string(m)+to_string(n)>to_string(n)+to_string(m);
	}
}; 
int main(int argc ,char * argv[])
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(30);
	v1.push_back(34);
	v1.push_back(5);
	v1.push_back(9);

	Solution s;

	string s1;
	s1 = s.largestNumber(v1);
	cout<<"s1 = "<<s1<<endl;
}
