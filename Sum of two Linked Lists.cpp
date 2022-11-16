//Given two numbers represented by two linked lists, write a program that prints the sum list. The sum list is linked list representation of addition of two input numbers in linked lists. It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Use Recursion).
//
//Input Format
//First line contains N,M, number of nodes in the 1st and 2nd list.
//Next line contains N nodes of 1st list.
//Next line contains M nodes of 2nd list.
//
//Constraints
//0<N<10^6
//
//Output Format
//Print the sum list after adding the two linked lists.
//
//Sample Input
//3 3
//5 6 3
//8 4 2
//Sample Output
//1 4 0 5
//Explanation
//After adding the two numbers represented by linked lists i.e. 563 + 842 =1405 is represented as sum list. Sum list =1 -> 4 -> 0 -> 5.
#include <bits/stdc++.h>
using namespace std;
void sum(vector<int> a, vector<int> b, vector<int> &ans)
{
    // cout<<a[0]<<endl;
    int temp = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 && j >= 0)
    {

        temp = a[i] + b[j] + carry;
        ans.push_back(temp % 10);
        carry = temp / 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        temp = a[i] + carry;
        ans.push_back(temp % 10);
        carry = temp / 10;
        i--;
    }
    while (j >= 0)
    {
        temp = b[j] + carry;
        ans.push_back(temp % 10);
        carry = temp / 10;
        j--;
    }
    if (carry != 0)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    int val1;
    int val2;
    for (int i = 0; i < n; i++)
    {
        cin >> val1;
        a.push_back(val1);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> val2;
        b.push_back(val2);
    }
    vector<int> ans;
    sum(a, b, ans);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
