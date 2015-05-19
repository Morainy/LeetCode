/*
 * =====================================================================================
 *
 *       Filename:  4medianOfTwoSortedArrays.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月22日 13时12分12秒
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

class Solution{
	public:
		double findMedianSortedArrays(vector<int> & nums1 , vector<int> & nums2);
		int findKthElm(vector<int> & nums1 ,int aBeg , int aEnd ,  vector<int>&nums2 ,int bBeg , int bEnd , int k);
		int min(int a , int b);
};

inline int Solution::min(int a , int b)
{
	return a < b?a:b;
}
int Solution::findKthElm(vector<int> & nums1 ,int aBeg , int aEnd ,  vector<int>& nums2 ,int bBeg , int bEnd , int k)
{
	int length1 = aEnd - aBeg + 1;
	int length2 = bEnd - bBeg + 1;
	if(length1 < length2){
		return findKthElm(nums2 , bBeg , bEnd , nums1 , aBeg , aEnd , k);
	}
	if(length2 <= 0){
		return nums1[k - 1];
	}
	if(k == 1){
		return min(nums1[0] , nums2[0]);
	}
	
	int j = min(length2 , k/2);
	int i = k -j;
	if(nums1[i - 1] < nums2[j-1]){
		vector<int> nums1Temp , nums2Temp;
		nums1Temp.assign(nums1.begin() + i ,nums1.end());
		nums2Temp.assign(nums2.begin() , nums2.begin() + j);
		return findKthElm(nums1Temp , 0 , nums1Temp.size() -1 , nums2Temp , 0 , nums2Temp.size() -1 , k - i);
	}
	else{
		vector<int> nums1Temp , nums2Temp;
		nums1Temp.assign(nums1.begin() , nums1.begin() + i);
		nums2Temp.assign(nums2.begin() + j , nums2.end());
		return findKthElm(nums1Temp , 0 , nums1Temp.size() -1 , nums2Temp ,0 , nums2Temp.size() -1 , k-j);
	}
}

double Solution::findMedianSortedArrays(vector<int> & nums1 , vector<int> & nums2)
{
	int length1 = nums1.size();
	int length2 = nums2.size();

	int k = (length1 + length2)/2;

	if((length1 + length2) & 0x1){
		return (double)findKthElm(nums1 , 0 , length1 -1 , nums2 , 0 , length2-1 , k + 1);
	}
	else{
		int res1 = findKthElm(nums1 , 0 , length1-1 , nums2 ,0 , length2-1 , k + 1);
		int res2 = findKthElm(nums1 , 0 , length1-1 , nums2 , 0 , length2-1 , k);
		return (double)(res1 + res2) / 2;
	}
}

int main(int argc ,char * argv[])
{
	vector<int> nums1;
	vector<int> nums2;
	nums2.push_back(1);
	//nums2.push_back(5);
	nums1.push_back(1);
	//nums1.push_back(3);
	//nums1.push_back(4);
	//nums1.push_back(6);
	//nums1.push_back(7);
	//nums1.push_back(8);

	Solution sol;
	double res = sol.findMedianSortedArrays(nums1 , nums2);
	cout<<"res = "<<res<<endl;
	return 0;
}
