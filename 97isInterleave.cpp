/*
 * =====================================================================================
 *
 *       Filename:  97isInterleave.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月04日 16时57分37秒
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
using namespace std;

/*class Solution{
	public:
		bool isInterleave(string s1 , string s2 , string s3);
};

bool Solution::isInterleave(string s1 , string s2 , string s3)
{
	int start1 = 0 , start2 = 0 , start3 = 0;
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();
	
	if(len3 != len1 + len2){
		return false;
	}
	if(start2 == len2 -1 && start1 == len1 -1){
		return true;
	}
	
	for(start3 = 0 ; start3 < s3.length() ; start3++){
		if(start1 < s1.length() && start2 < s2.length() && s3[start3] == s1[start1] && s3[start3] == s2[start2]){
			if(isInterleave(s1.substr(start1+1 , len1 - start1-1) , s2.substr(start2 , len2-start2) , s3.substr(start3+1 , len3-start3-1)) == false){
				return isInterleave(s1.substr(start1 , len1 - start1) , s2.substr(start2+1 , len2 - start2-1) , s3.substr(start3+1 , len3 - start3-1));
			}else{
				return true;
			}
		}
		if(start1 < s1.length() && s3[start3] == s1[start1]){
			start1++;
		}else if(start2 < s2.length() && s3[start3] == s2[start2]){
			start2++;
		}else{
			return false;
		}
	}
}*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int res=0;
        if((s1.length()+s2.length())!=s3.length())
            return res;
        check(0,0,0,s1,s2,s3,res);
        return res;
    }
    void check(int s1_i,int s2_i,int s3_i,string &s1,string& s2,string& s3,int &res){
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();

        if(s3_i==len3){
            res=1;
        }
        else if(s1_i==len1||s1[s1_i]!=s3[s3_i]){
            if(s2_i<len2&&s2[s2_i]==s3[s3_i])
                check(s1_i,s2_i+1,s3_i+1,s1,s2,s3,res); 
        }
        else if(s2_i==len2||s2[s2_i]!=s3[s3_i]){
            if(s1_i<len1&&s1[s1_i]==s3[s3_i])
                check(s1_i+1,s2_i,s3_i+1,s1,s2,s3,res);
        }
        else if(s1[s1_i]==s2[s2_i]&&s1[s1_i]==s3[s3_i]){
            int a,b,c;

            for(a=1;a+s1_i<len1&&s1[a+s1_i]==s1[s1_i];a++);
            for(b=1;b+s2_i<len2&&s2[b+s2_i]==s2[s2_i];b++);
            for(c=1;c+s3_i<len3&&s3[c+s3_i]==s3[s3_i];c++);
            if(a+b==c)
                check(s1_i+a,s2_i+b,s3_i+c,s1,s2,s3,res);
            else{
                if(a<=c)
                    check(s1_i+a,s2_i+c-a,s3_i+c,s1,s2,s3,res);
                if(b<=c)
                    check(s1_i+c-b,s2_i+b,s3_i+c,s1,s2,s3,res);
            }   
        }
    }
};

int main(int argc , char* argv[])
{
	string s1("aabcc");
	string s2("dbbca");
	//string s3("aadbbcbcac");
	string s3("aadbbbaccc");
	
	Solution sol;
	cout<<"res = "<<sol.isInterleave(s1 , s2 , s3)<<endl;

}

