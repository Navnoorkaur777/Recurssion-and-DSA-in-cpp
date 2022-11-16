//Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.
//
//Input Format
//First line contains a single integer N denoting the size of the linked list.
//Second line contains N space separated integers denoting the elements of the linked list.
//Third line contains a single integer K denoting the number of elements that are to be appended.
//
//Constraints
//1 <= N <= 10^4
//1 <= K <= 10^4
//
//Output Format
//Display all the elements in the modified linked list.
//
//Sample Input
//7
//1 2 2 1 8 5 6
//3
//Sample Output
//8 5 6 1 2 2 1
//Explanation
//Initially the linked list is
//1? 2? 3 ? 4 ? 5 ? 6? null
//and k = 2. After appending the last two elements to the front , the new linked list looks like
//5? 6? 1? 2? 3 ? 4 ? null
#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};
void insert(node *&head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}
	node *p = head;
	while(p->next!=NULL){
		p=p->next;
	}
	node *temp = new node(data);
	p->next = temp;
}

void print(node* node)
{
	while (node != NULL) {
		cout << (node->data) << " ";
		node = node->next;
	}
	// cout << "NULL";
}
void rotate(node *&temp,int k,int a)
{

	k = k % a;
	if(k==0) return;
	node *current=temp;
	int count=1;
	while(count < (a- k))
	{
		count++;
		current=current->next;
	}

	node *q=current;
    
	while(current->next!=NULL)
	current=current->next;
	current->next=temp;
	temp=q->next;
	q->next=NULL;
	
}
int main() {
	node *temp=NULL;
	int n;
	cin>>n;
    int a=n;
	int k;
	while(n--)
	{
		
		cin>>k;
		insert(temp,k);
	}
	int q;
	cin>>q;

    
	rotate(temp,q,a);
	print(temp);

	return 0;
}
