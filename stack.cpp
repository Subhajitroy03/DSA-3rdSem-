#include<iostream>
#define max 5
using namespace std;
class stack{
	int arr[max];
	int top_index;
	public:
		stack(){
			top_index=-1;
		}
		int isEmpty(){
			if(top_index==-1)
				return 1;
			else
				return 0;
		}
		int isFull(){
			if(top_index>=max-1)
				return 1;
			else
				return 0;
		}
		void push(int element){
			if (isFull()==0){
				top_index++;
				arr[top_index]=element;
			}
			else
				cout<<"Stack Overflowed"<<endl;			
		}
		int pop(){
			if(isEmpty()==0){
				int poped=arr[top_index];
				top_index--;
				return poped;
			}
			else
				cout<<"Stack Underflow"<<endl;		
		}
		void display(){
			if(isEmpty()==0){
				int i;
				for(i=0;i<=top_index;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
			else
				cout<<"Stack Underflow"<<endl;
		}		
};
