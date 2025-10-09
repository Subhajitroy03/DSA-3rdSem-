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
				if(temp->exp<exp){
					ptr->next=temp;
					head=ptr;
					return;
				}
				while(temp->next!=NULL && temp->next->exp>exp){
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
				cout<<temp->cof<<" x^"<<temp->exp;
				temp=temp->next;
				while(temp!=NULL){
					if(temp->cof>0){
						cout<<" + "<<temp->cof<<" x^"<<temp->exp;
					}else if(temp->cof<0){
						cout<<" "<<temp->cof<<" x^"<<temp->exp;
					}
					temp=temp->next;
				}

				cout<<endl;
			}
		}
		SLL operator +(SLL poly1){
			Node* ptr1=head;
			Node* ptr2=poly1.head;
			SLL result;
			while(ptr1!=NULL && ptr2!=NULL){
				if(ptr1->exp==ptr2->exp){
					result.insert(ptr1->cof+ptr2->cof,ptr1->exp);
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				else if((ptr1->exp)>(ptr2->exp)){
					result.insert(ptr1->cof,ptr1->exp);
					ptr1=ptr1->next;
				}else{
					result.insert(ptr2->cof,ptr2->exp);
					ptr2=ptr2->next;
				}
			}
			while(ptr1!=NULL){
				result.insert(ptr1->cof,ptr1->exp);
				ptr1=ptr1->next;
			}
			while(ptr2!=NULL){
				result.insert(ptr2->cof,ptr2->exp);
				ptr2=ptr2->next;
			}
			return result;
		}
		SLL operator *(SLL poly2){
			Node* ptr1=head;
			Node* ptr2=poly2.head;
			SLL result;
			
			while(ptr1!=NULL){
				SLL result_temp;
				while(ptr2!=NULL){
					result_temp.insert(ptr1->cof*ptr2->cof,ptr1->exp+ptr2->exp);
					ptr2=ptr2->next;
				}
				result=result+result_temp;
			
				ptr1=ptr1->next;
				ptr2=poly2.head;
			}
			return result;
		}
};

int main(){
	SLL list1;
	SLL list2;
	SLL list3;
	int count1,count2;
	cout<<"Enter the number of terms in polynomial 1: ";
	cin>>count1;
	int i,ele,exp;
	for(i=0;i<count1;i++){
		cout<<"Enter the coefficient: ";
		cin>>ele;
		cout<<"Enter the power of x: ";
		cin>>exp;
		list1.insert(ele,exp);
	}
	cout<<"Enter the number of terms in polynomial 2: ";
	cin>>count2;
	for(i=0;i<count2;i++){
		cout<<"Enter the coefficient: ";
		cin>>ele;
		cout<<"Enter the power of x: ";
		cin>>exp;
		list2.insert(ele,exp);
	}	
	cout<<"Poly 1"<<endl;
	list1.display();
	cout<<"Poly 2"<<endl;
	list2.display();
	cout<<"Addition"<<endl;
	list3=list1+list2;
	list3.display();
	cout<<"Multiplication"<<endl;
	list3=list1*list2;
	list3.display();
}
