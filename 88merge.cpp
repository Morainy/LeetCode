/*
 * =====================================================================================
 *
 *       Filename:  88merge.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月29日 15时50分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution{
public:
	void merge(vector<int>& nums1 , int m , vector<int>& nums2 , int n);
};

void Solution::merge(vector<int>& nums1 , int m , vector<int>& nums2 , int n)
{
	if(m < nums1.size()){
		nums1.erase(nums1.begin() + m , nums1.end());
	}
	if(n < nums2.size()){
		nums2.erase(nums2.begin() + n , nums2.end());
	}
	int p1 = 0 , p2 = 0;
	int index1 = 0;
	while(p1 < m && p2 < n){
		if (nums1[index1] < nums2[p2]){
			p1++;
			index1++;
		}else{
			nums1.insert(nums1.begin() + index1 , nums2[p2]);
			index1++;
			p2++;
		}
	}
	if(p1 == m && p2 < n){
		while(p2 < n){
			nums1.push_back(nums2[p2]);
			p2++;
		}
	}
}
