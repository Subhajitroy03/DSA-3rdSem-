#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
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
		void addBeg(int d){
			Node* temp=new Node(d);
			if(!isEmpty()){
				temp->next=head;
			}
			head=temp;
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
		void push(int d){
			if(isEmpty()){
				addBeg(d);
				return;
			}
			Node* ptr=new Node(d);
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
		}
		void pop(){
			if(!isEmpty()){
				Node* temp=head;
				head=head->next;
				delete(temp);
			}	
		}
		int peek(){
			return(head->data);
		}
};
int main(void){
	SLL list;
	while(1){
		int ch;
		cout << "Menu:\n" << 
		"(1) Push" << endl <<
		"(2) Pop" << endl <<
		"(3) Display" << endl <<
		"(4) Peek" << endl <<
		"(5) isEmpty" << endl <<
		"(6)Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		int element;
		if(ch==1){
			cout<<"Enter element: ";
			cin>>element;
			list.push(element);
		}else if(ch==2){
			list.pop();
		}else if(ch==3){
			cout<<"The Queue list: "<<endl;
			list.display();
		}else if(ch==4){
			cout<<"The front element: "<<list.peek()<<endl;
		}else if(ch==5){
			if(list.isEmpty()){
				cout<<"The Queue is empty... "<<endl;
			}else{
				cout<<"The Queue is not empty... "<<endl;
			}
		}else if(ch==6){
			break;
		}
	}	
}
