//Consider an array for which on day i, ith element is the price of a given stock.
//we are permitted at most only one transaction(i.e buy one and sell one share of stock).Find the maximum profit.
//
//Note:Buying a stock is mandatory before selling.
//
//Input Format
//First line contains integer n as size of array. Next n lines contains n integer as element of array.
//
//Constraints
//None
//
//Output Format
//Print the maximum profit.
//
//Sample Input
//6
//7
//1
//5 
//3 
//6 
//4
//Sample Output
//5
//Explanation
//None
#include<iostream>
using namespace std;
int maxprofit(int *arr,int n){
	if(n==0 || n<=1){
		return 0;
	}
	int min1=arr[0];
	int res=0;
	for(int i=1;i<n;i++){
		res=max(res,arr[i]-min1);
		min1=min(min1,arr[i]);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxprofit(arr,n);
}
