#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
	int num;
	Node *ahead;
	Node *next;
};
Node *Create(int N) {
	int n=1;
	Node *node=new Node;
	node->num=n;
	Node *head=node;
	Node *tail=head;
	while(n++<N) {
		node=new Node;
		node->num=n;
		tail->next=node;
		node->ahead=tail;
		tail=tail->next;
	}
	tail->next=head;
	head->ahead=tail;
	return head;
}
Node *Search(Node *head,int K) {
	while(head->num!=K) {
		head=head->next;
	}
	return head;
}
Node *Release(Node *head,int M) {
	int count=1;
	Node *temp=head;
	while(count<M) {
		temp=temp->next;
		count++;
	}
	temp->ahead->next=temp->next;
	temp->next->ahead=temp->ahead;
	cout<<temp->num;
	head=temp->next;
	delete temp;
	return head;
}
int main() {
	int N,K,M,flag=0,z;
	z=scanf("%d,%d,%d",&N,&K,&M);
	z=z+1;
	if(N<1||K<1||M<1) {
		cout<<"n,m,k must bigger than 0."<<endl;
		return 0;
	}
	if(K>N) {
		cout<<"k should not bigger than n."<<endl;
		return 0;
	}
	Node *head=Create(N);
	head=Search(head,K);
	while(head->next!=head) {
		if(flag%10==0)cout<<endl;
   		 else {
			if(flag==N)cout<<endl;
    		else cout<<" ";
		head=Release(head,M);
		flag++;
		}
	}
	cout<<head->num<<endl;
	return 0;
}

