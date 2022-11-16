//Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
//The output strings should be printed in the sorted order considering '(' has higher value than ')'.
//
//Input Format
//Single line containing an integral value 'n'.
//
//Constraints
//1<=n<=11
//
//Output Format
//Print the balanced parentheses strings with every possible solution on new line.
//
//Sample Input
//2
//Sample Output
//()() 
//(()) 
#include <iostream>
using namespace std;
void generateParenthesis(int n,int openB,int closeB,string s){
	if(closeB==n){
		cout<<s<<endl;
		return;
	}
	if(closeB<openB){
		generateParenthesis(n,openB,closeB+1,s+')');
	}
	if(openB<n){
generateParenthesis(n,openB+1,closeB,s+'(');
	}
}
int main(){
	int n;
	cin>>n;
	generateParenthesis(n,0,0,"");
}
