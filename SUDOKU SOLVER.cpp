//You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
//To learn more about sudoku, go to this link Sudoku-Wikipedia.
//
//Input Format
//First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.
//
//Constraints
//N=9 Solution exists for input matrix.
//
//Output Format
//Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.
//
//Sample Input
//9
//5 3 0 0 7 0 0 0 0 
//6 0 0 1 9 5 0 0 0 
//0 9 8 0 0 0 0 6 0 
//8 0 0 0 6 0 0 0 3 
//4 0 0 8 0 3 0 0 1 
//7 0 0 0 2 0 0 0 6 
//0 6 0 0 0 0 2 8 0 
//0 0 0 4 1 9 0 0 5 
//0 0 0 0 8 0 0 7 9 
//Sample Output
//5 3 4 6 7 8 9 1 2 
//6 7 2 1 9 5 3 4 8 
//1 9 8 3 4 2 5 6 7 
//8 5 9 7 6 1 4 2 3 
//4 2 6 8 5 3 7 9 1 
//7 1 3 9 2 4 8 5 6 
//9 6 1 5 3 7 2 8 4 
//2 8 7 4 1 9 6 3 5 
//3 4 5 2 8 6 1 7 9 
#include <iostream>
using namespace std;
#define N 9
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row,
                       int col, int num)
{
     
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}
 
bool solveSudoku(int grid[9][9], int row, int col,int n)
{
    if (row == N - 1 && col == N)
        return true;
 
    if (col == N) {
        row++;
        col = 0;
    }
   
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1,n);
 
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
             
            grid[row][col] = num;
            
            if (solveSudoku(grid, row, col + 1,n))
                return true;
        }
       
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int grid[9][9];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>grid[i][j];
		}
	}
    
    if (solveSudoku(grid, 0, 0,n))
        print(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
    
}
// int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
//                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
//                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
//                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
//                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
//                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
//                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
//                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
//                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

