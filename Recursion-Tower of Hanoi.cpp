//Using a helper stick (peg), shift all rings from peg A to peg B using peg C. All rings are initally placed in ascending order, smallest being on top.
//
//No bigger ring can be placed over a smaller ring.
//
//a. Write a recursive function which prints the steps required to solve the tower of Hanoi problem for N discs.
//
//b. Write a recursive function which returns number of steps required to solve the tower of Hanoi problem for N discs.
//
//Let T1 be the Source Tower, T2 be the Destination Tower and T3 be the Auxillary Tower.
//
//Input Format
//Enter the number of discs
//
//Constraints
//None
//
//Output Format
//Display the steps required to solve the tower and also print the total number of steps required
//
//Sample Input
//2
//Sample Output
//Move 1th disc from T1 to T3
//Move 2th disc from T1 to T2
//Move 1th disc from T3 to T2
//3
#include<iostream>
using namespace std;
void toh(int n,string from,string to,string helper,int &count){
	int c=0;
	if(n==0){
	
	  return;
}
    count++;
	toh(n-1,from /*a*/,helper/*b*/,to /*c*/,count);

	cout<<"Move "<<n<<"th disc from "<<from<<" to "<<to<<endl;
	toh(n-1,helper/*b*/,to /*c*/,from/*a*/,count);  
	
}
int main(){
	int n;
	cin>>n;
	int count=0;
	toh(n,"T1","T2","T3",count);
	cout<<count;
}

