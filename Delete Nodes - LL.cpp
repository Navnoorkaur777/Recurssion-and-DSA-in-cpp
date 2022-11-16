//Given a singly linked list delete all nodes which are having a greater value among any of the nodes residing on the right side.
//
//Input Format
//First line contains N, the number of nodes in the linked list.
//Next line contains the N nodes data .
//
//Constraints
//0<N<10^9
//
//Output Format
//Print the linked list after deleting the nodes which are having a greater value on right side.
//
//Sample Input
//8
//12 15 10 11 5 6 2 3
//Sample Output
//15 11 6 3 
//Explanation
//In the given case 12 is having right node greater than itself i.e. 12<15 so delete it.
//Similarly, 10<11, 5<6 and 2<3 so delete 10, 5 and 2 as well.
//Thus, linked list becomes 15->11->6->3.
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insert(Node *&head,int data){
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node *p = head;
	while(p->next!=NULL){
		p=p->next;
	}
	Node *temp = new Node(data);
	p->next = temp;
}

Node * reversell(Node* &head){
    Node *prev=NULL;
    Node *curr=head;
    Node *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
prev=curr;
curr=forward;
    }
    head=prev;
 return head;
}


Node *deletenode(Node* &head){
    head=reversell(head);
    Node *curr=head;
    int ma=head->data;
    Node* prev=head;
    head=head->next;
    while(head){
if(head->data>=ma){
    ma=head->data;
    prev=head;
    head=head->next;
}
else{
    prev->next=head->next;
    head=prev->next;
}
    }
   head=reversell(curr);
    return head;

}




void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
Node *head=NULL;
int n,data;
cin>>n;
for(int i=0;i<n;i++){
    cin>>data;
    insert(head,data);
}

head=deletenode(head);
print(head);
    return 0;
}
