//Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).
//
//His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
//
//Input Format
//First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.
//
//Constraints
//2 <= N <= 100,000
//0 <= xi <= 1,000,000,000
//2 <= C <= N
//
//Output Format
//Print one integer: the largest minimum distance.
//
//Sample Input
//5 3
//1 2 8 4 9
//Sample Output
//3
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main(){
	
	int arr[100009];

		ll n,c;
		cin>>n>>c;
		for(int i=0;i<n;i++){
		cin>>arr[i];
		}
		sort(arr, arr+n);

		ll lo=1,hi=arr[n-1],ans=0;
		while(lo<=hi){
			ll mid=(lo+hi)/2;
			int a=arr[0],temp=1;
			for(int i=1;i<n;i++){
				if(arr[i]-a>=mid)
                    temp++,a=arr[i];
			}
			if(temp<c)
			hi=mid-1;
			else{
                ans=mid;
                lo=mid+1;
            }
		}
		cout<<ans<<endl;
	
	return 0;
}
