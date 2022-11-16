//Kartik Bhaiya, mentor at Coding Blocks, organized a party for their interns at Coding Blocks. In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, she/he doesn’t know anyone in the party. We can only ask questions like “does A know B? “.
//Find the stranger (celebrity) in minimum number of questions.
//
//Input Format
//First line contains N, number of persons in party. Next line contains the matrix of N x N which represents A knows B when it's value is one.
//
//Constraints
//None
//
//Output Format
//Print the celebrity ID which is between 0 and N-1. If celebrity is not present then print "No Celebrity".
//
//Sample Input
//4
//0 0 1 0
//0 0 1 0
//0 0 0 0
//0 0 1 0
//Sample Output
//2
//Explanation
//In the given case there are 4 persons in the party let them as A, B, C, D. The matrix represents A knows B when it's value is one. From the matrix, A knows C, B knows C and D knows C. Thus C is the celebrity who doesnot know anyone and it's ID is 2. Hence output is 2.
#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int p=-1;
    for (int i = 0; i < n; i++)
    {
        // variable to check if ith person is celebrity or not
        bool isCelebrity = true;
        for (int j = 0; j < n; j++)
        {
            if(i != j){
                //if ith person knows jth person or jth person dosent know ith person
                //then ith person is not celebrity
                if(a[i][j] == 1 || a[j][i] == 0){
                    isCelebrity = false;
                }
            }
        }
        if(isCelebrity == true){
            p = i;
            break;
        }
    }
	if(p != -1){
        cout << p;
    }
	else{
        string a={"No Celebrity"};
		cout<<a;
	}
    return 0;
}
