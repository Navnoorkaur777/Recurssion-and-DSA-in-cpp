//Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.
//
//Input Format
//First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.
//
//Constraints
//n < 10^5
//
//Output Format
//Output a single line containing the node value at the kth element from last.
//
//Sample Input
//1 2 3 4 5 6 -1
//3
//Sample Output
//4
//Explanation
//The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4
#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	//constructor
	node(int d){
		data=d;
		next=NULL;
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

void createList(node*&head)
{	
	int data;
	cin>>data;
	while(data!=-1)
	{
		insert(head,data);
		cin>>data;
	} 
}
node* kth_element(node*&head,int k)
{
    node * slow = head;
    node * fast = head;
    while(k--)
    {
        fast = fast->next;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
	node*head=NULL;
	createList(head);
	int k;
    cin>>k;
    node* element=kth_element(head,k);
    cout<<element->data;
    
    return 0;
}
