#include<iostream>
using namespace std;
class Node{
	public:
		int cof;
		int exp;
		Node* next;
		Node(int cof,int exp){
			this->cof=cof;
			this->exp=exp;
			this->next=NULL;
		}
};
class SLL{
	public:
		Node* head;
		SLL(){
			head=NULL;
		}
		bool isEmpty(){
			return(head==NULL);
		}
		void insert(int ele,int exp){
			Node* ptr=new Node(ele,exp);
			if(isEmpty()){
				head=ptr;
				return;
			}else{
				Node* temp=head;
				Node* temp2=NULL;
				if(temp->exp>exp){
					ptr->next=temp;
					head=ptr;
					return;
				}
				while(temp->next!=NULL && temp->next->exp<=exp){
					temp=temp->next;
				}
				temp2=temp->next;
				temp->next=ptr;
				ptr->next=temp2;
			}
		}
		void display(){
			if(!isEmpty()){
				Node* temp=head;
				while(temp!=NULL){
					cout<<"("<<temp->cof<<","<<temp->exp<<")"<<" ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		void remove(){
			Node* temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			Node* todelete=temp->next;
			temp->next=NULL;
			delete(todelete);
			
		}
};
int main(){
	//menu driven to be added
}
