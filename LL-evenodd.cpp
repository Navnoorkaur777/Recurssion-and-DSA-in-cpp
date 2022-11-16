//Given a list, modify it such that all odd elements appear before the even ones. The order of odd elements and even shall remain intact.
//
//See explantaion for more info.
//
//Input Format
//The first line contains an integer N, the number of elements in the list.
//
//The next line contains N space separated integral elements of the list.
//
//Constraints
//1 <= T <= 1000 0 <= N <= 10^6
//
//Output Format
//T lines of output
//
//Sample Input
//5
//1 2 3 4 5
//Sample Output
//1 3 5 2 4 
//Explanation
//Input : 1 -> 2 -> 3 -> 11-> 4 -> 5
//
//The order of odd elements and even does not change. For instance 3 comes before 5 in the input, so comes in the output.
//
//Output: 1 -> 3 -> 11 -> 5 -> 2 -> 4

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

void evenodd(Node* &head){
  Node *evenstart=NULL;
  Node *evenend=NULL;
  Node *oddstart=NULL;
  Node *oddend=NULL;
  Node *temp=head;
  while(temp!=NULL){
    int val=temp->data;
    if(val%2==0){
        if(evenstart==NULL){
evenstart=temp;
evenend=evenstart;
        }
        else{
            evenend->next=temp;
            evenend=evenend->next;
        }
    }
    else{
        if(oddstart==NULL){
oddstart=temp;
oddend=oddstart;
        }
        else{
            oddend->next=temp;
            oddend=oddend->next;
        }
    }
    temp=temp->next;
    

  }
  if(evenstart==NULL || oddstart==NULL){
        return;
    }
    oddend->next=evenstart;
    evenend->next=NULL;
    head=oddstart;
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
evenodd(head);
print(head);
    return 0;
}
