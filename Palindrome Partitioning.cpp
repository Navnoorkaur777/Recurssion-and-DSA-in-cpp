//You are given a string. You need to partition that string such that each substrings after partitioning would be palindromic string. You have to do this work with minimum number of partitioning.
//
//Input Format
//First line contains integer t which is number of test case. For each test case, it contains a string S.
//
//Constraints
//1<=t<=50 1<=S<=1000
//
//Output Format
//Print the minimum number of partitioning.
//
//Sample Input
//1
//ababbbabbababa
//Sample Output
//3
//Explanation
//a|babbbab|b|ababa
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s,int i,int j)
{
	while(i<=j)
	{
		if(s[i++]!=s[j--])
		   return false;
	}
	return true;
	
}

int helper(string s,int i,int j,int** dp){
	if(i>=j){
		return 0;
	}

	if(ispalindrome(s,i,j)){
		return 0;
	}

	if(dp[i][j]!=-1) return dp[i][j];

	int ans=INT_MAX;
	for(int k=i;k<j;k++){

		if(dp[i][k] == -1){
			int a=helper(s,i,k,dp);
			dp[i][k]=a;
		}

		if(dp[k+1][j] ==-1){
			int b=helper(s,k+1,j,dp);
			dp[k+1][j]=b;
		}

		int temp=dp[i][k]+dp[k+1][j]+1;
		ans=min(ans,temp);

	}
	
	return dp[i][j]=ans;


}

int main() {
	int t;
	cin >> t;

	for(int l=0;l<t;l++){
		string s;
		cin >> s;

		

		int** dp=new int*[s.size()+1];
		for(int i=0;i<s.size()+1;i++){
			dp[i]=new int[s.size()+1];
			for(int j=0;j<s.size()+1;j++){
				dp[i][j]=-1;
			}
		}

		cout << helper(s,0,s.size()-1,dp) <<endl;
}
}
