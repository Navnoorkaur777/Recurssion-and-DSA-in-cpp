//You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.
//
//Input Format
//A single integer N, denoting the size of chess board.
//
//Constraints
//1<=N<=11
//
//Output Format
//A single integer denoting the count of solutions.
//
//Sample Input
//4
//Sample Output
//2
#include <iostream>
using namespace std;

bool isSafe(int board[][40],int i,int j,int n){

    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }

    int x=i;
   int  y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }


x=i;
y=j;
while(x>=0 && j<n){
    if(board[x][y]==1){
        return false;
    }
    x--;
    y++;
}


    return true;


}


int solveNQueen(int board[][40],int i,int n){
    if(i==n){
        return 1;
    }
    int cnt=0;
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
           
            board[i][j]=1;
              cnt += solveNQueen(board,i+1,n);
		}
            board[i][j]=0;
    }
return cnt;
}

int main() {
    int board[40][40];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    int  solution=solveNQueen(board,0,n);
  cout<<solution<<endl; 
    return 0;
}


