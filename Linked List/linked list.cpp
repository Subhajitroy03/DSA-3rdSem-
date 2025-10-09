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
		void addEnd(int d){
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
		void delBeg(){
			if(!isEmpty()){
				Node* temp=head;
				head=head->next;
				delete(temp);
			}	
		}
		void delEnd(){
			if(isEmpty()){
				return;
			}
			Node* temp=head;
			while((temp->next)->next!=NULL){
				temp=temp->next;
			}
			Node* p=temp->next;
			delete(p);
			temp->next=NULL;
		}
		int count(){
			if(isEmpty()){
				return 0;
			}
			Node* temp=head;
			int len=0;
			while(temp!=NULL){
				len++;
				temp=temp->next;
			}
			return len;
		}
		int search(int a){
			if(isEmpty()){
				return -1;
			}
			Node* temp=head;
			int i=0;
			while(temp!=NULL){
				i++;
				if(temp->data==a){
					return i;
				}
				temp=temp->next;
			}
			return -1;
		}
		void deleteElement(int ele){
			if(isEmpty()){
				return;
			}
			Node* temp=head;
			if(temp->data==ele){
				delBeg();
				return;
			}
			while(temp->next!=NULL){
				if((temp->next)->data==ele){
					Node* todelete=temp->next;
					temp->next=(temp->next)->next;
					delete(todelete);
					return;
				}
				temp=temp->next;
			}
			cout<<"Item not found..so not deleted.."<<endl;
		}				
		int smallNum(){
			if(!isEmpty()){
				Node* temp=head;
				int small=temp->data;
				while(temp!=NULL){
					if(small>(temp->data)){
						small=temp->data;
					}
					temp=temp->next;
				}
				return small;
			}
		}
		int bigNum(){
			if(!isEmpty()){
				Node* temp=head;
				int big=temp->data;
				while(temp!=NULL){
					if(big<(temp->data)){
						big=temp->data;
					}
					temp=temp->next;
				}
				return big;
			}
		}
		void reverse(){
			if(count()>=2){
				Node* ptr=NULL;
				Node* prev=head;
				Node* next=head->next;
				while(next!=NULL){
					prev->next=ptr;
					ptr=prev;
					prev=next;
					next=next->next;
					
				}
				prev->next=ptr;
				head=prev;
			}
			
			
		}
};
int main(void){
	SLL list;
	while(1){
		int ch;
		cout << "Menu:\n" << 
		"(1) Insert a Node at the Beginning of the List" << endl <<
		"(2) Insert a Node at the End of the List" << endl <<
		"(3) Delete a Node from the Beginning of the List" << endl <<
		"(4) Delete a Node from the End of the List" << endl <<
		"(5) Delete any Item from the List" << endl <<
		"(6) Display the Whole List" << endl <<
		"(7) Search for an Element x in the List" << endl <<
		"(8) Reverse the List" << endl <<
		"(9) Find the Largest Number from the List" << endl <<
		"(10) Find the Smallest Number from the List" << endl <<
		"(11) Count the Number of Nodes in the List" << endl <<
		"(12) Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		int element;
		if(ch==1){
			cout<<"Enter element: ";
			cin>>element;
			list.addBeg(element);
			cout<<"Added succesfully..."<<endl;
		}else if(ch==2){
	
			cout<<"Enter element: ";
			cin>>element;
			list.addEnd(element);
			cout<<"Added succesfully..."<<endl;
		}else if(ch==3){
			list.delBeg();
			cout<<"Deleted Succesfully...."<<endl;
		}else if(ch==4){
			list.delEnd();
			cout<<"Deleted Succesfully...."<<endl;
		}else if(ch==5){
		
			cout<<"Enter element to delete: ";
			list.deleteElement(element);
			cout<<"Deleted Succesfully...."<<endl;
		}else if(ch==6){
			cout<<"The linked list: "<<endl;
			list.display();
		}else if(ch==7){
		
			cout<<"Enter element to search: ";
			int index=list.search(element);
			if(index<0){
				cout<<"Element not found...";
			}else{
				cout<<"Element found in the position: "<<index<<endl;
			}
		}else if(ch==8){
			list.reverse();
			cout<<"Reversed succesfully...";
		}else if(ch==9){
			cout<<"The largest element in the list is: "<<list.bigNum()<<endl;
		}else if(ch==10){
			cout<<"The smallest element in the list is: "<<list.smallNum()<<endl;
		}else if(ch==11){
			cout<<"No of nodes in the list: "<<list.count()<<endl;
		}else if(ch==12){
			break;
		}
	}	
}
