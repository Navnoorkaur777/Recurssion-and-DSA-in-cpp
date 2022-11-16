//Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.
//
//Note that:
//
//Every painter can paint only contiguous segments of boards.
//A board can only be painted by 1 painter at maximum.
//Input Format
//First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.
//
//Constraints
//1 <= K <= 10
//1 <= N <= 10
//1<= Length of each Board <= 10^8
//
//Output Format
//Output the minimum time required to paint the board.
//
//Sample Input
//2
//2
//1 10
//Sample Output
//10
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isvalid(ll arr[],ll n,int k,ll ans){
    ll currentsum=0;
    ll painter=1;
    for(ll i=0;i<n;i++){
        if(currentsum+arr[i] > ans){
           
            ++painter;
            if(painter>k)
            return false;
            currentsum=arr[i];
        }
        else{
            currentsum+=arr[i];
        }
        
        
    }
    return true;

}
ll binarysearch(ll arr[],ll n,ll k){
   ll s=INT_MIN,e=0,mid;
   ll ans=0;
   for(ll i=0;i<n;i++){
       s = max(s, arr[i]);
       e=e+arr[i];       
   }
   while(s<=e){
       mid=s+(e-s)/2;
       if(isvalid(arr,n,k,mid)){
           ans=mid;
           e=mid-1;
       }
       else{
           s=mid+1;
       }
   }
   ans=(ans%10000003);
   return ans;
}
int main() {
    ll n,k;
    cin>> k >> n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout <<binarysearch(arr,n,k);
    // cout<<answer;
    return 0;
    }
    
