#include<iostream>
using namespace std;
class Node{
	public:
	Node* prev;
	int data;
	Node* next;
	Node(int data){
		this->prev=NULL;
		this->data=data;
		this->next=NULL;		
	}
};
class DLL{
	public:
		Node* head;
		DLL(){
			head=NULL;	
		}
		bool isEmpty(){
			return(head==NULL);
		}
		void addBeg(int ele){
			Node* ptr=new Node(ele);
			if(!isEmpty()){
				head->prev=ptr;
				ptr->next=head;
			}
			head=ptr;
			
		}
		void addEnd(int ele){
			if(isEmpty()){
				addBeg(ele);
				return;
			}
			Node* ptr=new Node(ele);
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
		}
		void display(){
			if(!isEmpty()){
				Node* temp=head;
				while(temp!=NULL){
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		void delBeg(){
			if(!isEmpty()){
				Node* ptr=head;
				if(head->next!=NULL){
					head=head->next;
					head->prev=NULL;
					delete(ptr);
				}else{
					delete(ptr);
					head=NULL;
				}
					
			}
			
		}
		void delEnd(){
			if(!isEmpty()){
				Node* ptr=head;
				Node* temp=head->next;
				if(temp==NULL){
					delBeg();
					return;
				}
				while(temp->next!=NULL){
					temp=temp->next;
					ptr=ptr->next;
				}
				ptr->next=NULL;
				temp->prev=NULL;
				delete(temp);
			}
		}
		void displayreverse(){
			Node* ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			while(ptr!=NULL){
				cout<<ptr->data<<" ";
				ptr=ptr->prev;
			}
		}
		void delElement(int ele){
			if(isEmpty()){
				return;
			}
			Node* ptr=head;
			if(head->data==ele){
				delBeg();
			}else{
				while(ptr!=NULL){
					if((ptr->data)==ele){
						Node* temp=ptr->prev;
						temp->next=ptr->next;
						if(ptr->next!=NULL){
							ptr->next->prev=temp;
						}
						return;
					}
					ptr=ptr->next;
				}
				
			}
			
			
		}
};
int main(void){
	//menu driven is to be done..rest is done
}
