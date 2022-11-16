//Take as input N. N is the number of rows and columns on a square board. Our player starts in top-left corner of the board and must reach bottom-right corner. In one move the player can move 1 step horizontally (right) or 1 step vertically (down) or 1 step diagonally (south-east). But the diagonal step is allowed only when the player is currently on one of the diagonals (there are two diagonals)
//
//a. Write a recursive function which returns the count of different ways the player can travel across the board. Print the value returned.
//
//b. Write a recursive function which prints moves for all valid paths across the board (void is the return type for function).
//
//Input Format
//Enter the number N.
//
//Constraints
//None
//
//Output Format
//Display the total number of paths and display all the possible paths in a space separated manner.
//
//Sample Input
//3
//Sample Output
//VVHH VHVH VHHV VHD HVVH HVHV HVD HHVV DVH DHV DD 
//11
#include <iostream>
#include<vector>
using namespace std;

void countpaths(int i,int j,int n,int m,int &ans,vector<string>&v,string s){
    
    if(i==n-1 && j==m-1){
        ans++;
        v.push_back(s);
        return;
    }
    
    if(i>=n || j>=m)return ;
    
    countpaths(i+1,j,n,m,ans,v,s+"V");
    countpaths(i,j+1,n,m,ans,v,s+"H");
	if(i==j || i+j==n-1)
    countpaths(i+1,j+1,n,m,ans,v,s+"D");
}
int main()
{
    int n;
	cin>>n;
    
    int ans=0;
    vector<string>v;
    countpaths(0,0,n,n,ans,v,"");
    
   
    
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
	 cout<<ans<<endl;
    
   

    return 0;
}
