#include<iostream>
#define MAX 5
using namespace std;
class Stack{
	int arr[MAX];
	int top_index;
	public:
		Stack(){
			top_index=-1;
		}
		bool isEmpty(){
			return (top_index == -1);
		}
		bool isFull(){
			return (top_index == MAX-1);
		}
		void push(int element){
			if (isFull()){
				cout<<"Stack Overflowed"<<endl;	
			}else{
				arr[++top_index]=element;	
			}	
		}
		int pop(){
			if(isEmpty()){
				cout<<"Stack Underflow"<<endl;
				return 0;
			}else{
				int poped=arr[top_index];
				top_index--;
				return poped;
			}
		}
		void peek(){
			if(isEmpty())
				cout << "Stack is empty" << endl;
			else
				cout << "Top element is: " << arr[top_index] << endl;
		}
		void display(){
			if(isEmpty()){
				cout<<"Stack Underflow"<<endl;
				return;
			}
			int i;
			for(i=0;i<=top_index;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;	
		}		
};

int main(void){
	Stack s;
	int item, choice;

	while(1){
		cout << "\n----- Stack Operation -----\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Check if stack is empty\n";
		cout << "5. Check if stack is full\n";
		cout << "6. Display the stack\n";
		cout << "7. Exit\n";
		cout << "-----------------------------\n";
		cout << "Enter your choice (1-7): ";
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter item to push: ";
				cin >> item;
				s.push(item);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.peek();
				break;
			case 4:
				if(s.isEmpty())
					cout << "Stack is empty";
				else
					cout << "Stack is not empty";
				break;
			case 5:
				if(s.isFull())
					cout << "Stack is full";
				else
					cout << "Stack is not full";
				break;
			case 6:
				s.display();
				break;
			case 7:
				exit(0);
			default:
				cout << "Invalid choice !";
				break;;
		}
	}
	return 0;
}