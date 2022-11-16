//Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.
//
//Input Format
//First Line contains T the number of test cases.
//For each test case :
//Line 1 : N1 the size of list 1
//Line 2 : N1 elements for list 1
//Line 3 : N2 the size of list 2
//Line 4 : N2 elements for list 2
//
//Constraints
//1 <= T <= 1000
//0<= N1, N2 <= 10^6
//-10^7 <= Ai <= 10^7
//
//Output Format
//For each testcase , print the node data of merged linked list.
//
//Sample Input
//1
//4
//1 3 5 7
//3
//2 4 6
//Sample Output
//1 2 3 4 5 6 7 
//Explanation
//The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .
#include<iostream>
#define ll long long int 
using namespace std;

class linkedNode{
	public:
		ll data;
		linkedNode* next;
	linkedNode(ll data){
		this->data=data;
		this->next=NULL;
	}
	
};
void print(linkedNode *&head){
	linkedNode *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void insertAtEnd(linkedNode *&head,ll data){
	if(head==NULL){
		head=new linkedNode(data);
		return;
	}
	
		linkedNode *p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		linkedNode *temp1=new linkedNode(data);
		p->next=temp1;
	
}
linkedNode* merge(linkedNode *&head1,linkedNode *&head2){
	linkedNode *p1=head1;
	linkedNode *p2=head2;
	linkedNode *dummy =new linkedNode(-1);
	linkedNode *p3=dummy;
	while(p1 !=NULL && p2!=NULL){
		if(p1==NULL){
			return p2;
		}
		if(p2==NULL){
			return p1;
		}
		if(p1->data<p2->data){
			p3->next=p1;
			p1=p1->next;
		}
		else{
			p3->next=p2;
			p2=p2->next;
		}
		p3=p3->next;
	}
	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
}
   while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	return dummy->next;
}
int main(){
	
	ll t;
	
	cin>>t;
	while(t--){
		linkedNode* head1=NULL;
	   linkedNode* head2=NULL;
		ll n1,n2;
		
		cin>>n1;
	    ll d;
		for(int i=0;i<n1;i++){
			cin>>d;
			insertAtEnd(head1,d);
		}
		
		cin>>n2;
		ll data2;
		for(int i=0;i<n2;i++){
			cin>>data2;
			insertAtEnd(head2,data2);
		}
		linkedNode *newhead=merge(head1,head2);
		print(newhead);
		cout<<endl;
	}
	
}
