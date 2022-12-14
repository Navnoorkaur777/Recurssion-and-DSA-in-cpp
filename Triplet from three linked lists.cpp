//Given three linked lists, say a, b and c, find one node from each list such that the sum of the values of the nodes is equal to a given number say, Target. As any number of answers can be possible return the first one you get while traversing.
//
//Input Format
//The First Line contains 3 Integers n, m and k as the Size of the Three LinedLists. Next 3 Lines contains n, m and k integers Respectively as the elements of Linked Lists. Next Line contains the an Integer as Target.
//
//Constraints
//The Size of the Lists can be different.
//
//Output Format
//Display the 3 elements from each of the Lists whose sum is equals to the target separated by space.
//
//Sample Input
//3 3 3
//12 6 29
//23 5 8
//90 20 59
//101
//Sample Output
//6 5 90
//Explanation
//In the Given Sample Input, 6, 5 and 90 from lists 1, 2 and 3 respectively add to give 101.
#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
   int data;
   Node* next;
   Node(int data){
   	this->data=data;
   	this->next=NULL;
   }
};
//void insert(Node** head, int new_data) {
//   Node* new_node = new Node();
//   new_node->data = new_data;
//   new_node->next = (*head_ref);
//   *head_ref = new_node;
//}
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
void findTriplet(Node *head_one, Node *head_two, Node *head_three, int givenNumber) {
   bool is_triplet_found = false;
   Node *a = head_one;
   while (a != NULL) {
      Node *b = head_two;
      while (b != NULL) {
         Node *c = head_three;
         while (c != NULL) {
            int sum = a->data + b->data + c->data;
            if (sum == givenNumber) {
               cout << a->data << " " << b->data << " " << c->data << endl;
               is_triplet_found = true;
               break;
            }
            c = c->next;
         }
         if (is_triplet_found) {
            break;
         }
         b = b->next;
      }
      if (is_triplet_found) {
         break;
      }
      a = a->next;
   }
   if (!is_triplet_found) {
      cout << "No triplet found" << endl;
   }
}
int main() {
   Node* headA = NULL;
   Node* headB = NULL;
   Node* headC = NULL;
  int n,m,o,data,data1,data2;
cin>>n>>m>>o;
for(int i=0;i<n;i++){
    cin>>data;
    insert(headA,data);
}
for(int i=0;i<m;i++){
    cin>>data1;
    insert(headB,data1);
}
for(int i=0;i<o;i++){
    cin>>data2;
    insert(headC,data2);
}

 int givennumber;
  cin>>givennumber;
 findTriplet(headA,headB,headC,givennumber);
 
   return 0;
}
