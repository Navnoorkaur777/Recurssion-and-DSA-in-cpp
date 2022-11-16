//Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.
//
//Input Format
//Enter a number
//
//Constraints
//None
//
//Output Format
//Display all the possible codes
//
//Sample Input
//1125
//Sample Output
//[aabe, aay, ale, kbe, ky]
#include <bits/stdc++.h>
using namespace std;

vector<string>ans;

void gs(char *in,char *out,int i,int j){
	//base case
	if(in[i]=='\0'){
		out[j]='\0';
		ans.push_back(out); // store
		return;
	}

	//recursive case
	int fd = in[i]-'0';
	//map the numbers corresponding to the Letters
	char ch = 'a' + fd -1;
	out[j]=ch;
	gs(in,out,i+1,j+1);

	// take the two digit numbers
	if(in[i+1]!='\0'){
		int sd = in[i+1]-'0';
		int no = 10*fd + sd;
		if(no <= 26){ // check this
			ch = 'a'+no-1;
			out[j]=ch;
			gs(in,out,i+2,j+1);
		}
	}
}

int main(){
	char in[100];
	char out[100];

	cin>>in;
	gs(in,out,0,0);
	cout<<"[";
	for(int i=0;i<ans.size();i++){ // print 
		cout<<ans[i];
		if(i != ans.size()-1)cout<<", ";
	}
	cout<<"]";

return 0;
}
