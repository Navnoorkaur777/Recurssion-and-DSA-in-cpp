//Take as input N, the size of a chess board. We are asked to place N number of queens in it, so that no queen can kill other.
//
//a. Write a recursive function which returns the count of different distinct ways the queens can be placed across the board. Print the value returned.
//
//b. Write a recursive function which prints all valid configurations (void is the return type for function).
//
//Input Format
//Enter the number N(Size of the chessboard)
//
//Constraints
//None
//
//Output Format
//Display the number of possible ways of arranging N queens and print all the possible arrangements in a space separated manner
//
//Sample Input
//4
//Sample Output
//{1-2} {2-4} {3-1} {4-3}  {1-3} {2-1} {3-4} {4-2}
//2

#include <iostream>
#include<vector>
using namespace std;

int ans=0;

bool issafe(int row,int col,int n,vector<vector<int>>&mat){
    
      for(int i=row-1;i>=0;i--){
		  if(mat[i][col]==1)return false;
	  }

	  for(int i=row-1,j=col-1;i>=0 && j>=0;j--,i--){
		  if(mat[i][j]==1)return false;
	  }

	   for(int i=row-1,j=col+1;i>=0 && j<n;j++,i--){
		  if(mat[i][j]==1)return false;
	  }
	
    return true;
    
}

void print(vector<vector<int>>&mat){
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1){
                cout<<"{"<<i+1<<"-"<<j+1<<"}"<<" ";
            }
        }
    }
}
void solve(int i,int n,vector<vector<int>>&mat,int k){
    
    if(i==n){
        ans++;
        print(mat);
        return ;
    }
    
   for(int j=0;j<n;j++){
       

    if(issafe(i,j,n,mat)){
        mat[i][j]=1;
        
        solve(i+1,n,mat,k);
            
        mat[i][j]=0;
    }
    
   }
}
int main()
{
    int n;
    cin>>n;
    
     vector<vector<int>>mat(n,vector<int>(n,0));
     
     solve(0,n,mat,0);
     cout<<endl;
     cout<<ans<<endl;

    return 0;
}
