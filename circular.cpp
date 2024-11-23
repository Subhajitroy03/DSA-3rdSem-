#include<iostream>
#define max 5
using namespace std;
class Circular_Queue{
	public:
		int arr[max];
		int front;
		int rear;
		Circular_Queue(){
			front=-1;
			rear=-1;
		}
		int is_empty(){
			if(rear==-1){
				return 1;
			}else{
				return 0;
			}
		}
		int  is_Full(){
			if(front==(rear+1)%max){
				return 1;
			}else{
				return 0;
			}
		}
		void enqueue(int element){
			if(is_Full()==1){
				cout<<"Queue already full..overflow condition"<<endl;
				return;
			}
			if(rear==-1){
				front=(front+1)%max;
			}
			rear=(rear+1)%max;
			arr[rear]=element;
		}
		void dequeue(){
			if(is_empty()==1){
				cout<<"Queue already empty..underflow condition"<<endl;
				return;
			}
			if(front==rear){
				front=-1;
				rear=-1;
			}else{
				front=(front+1)%max;
			}
				
		}
		void display(){
			if(is_empty()==1){
				cout<<"Empty queue.."<<endl;
				return;
			}
			int i=front;
			while(i!=(rear+1)%max){
				cout<<arr[i]<<" ";
				i=(i+1)%max;
			}
		}
		int peek(){
			if(is_empty()==1){
				cout<<"Empty queue.."<<endl;
			}else{
				return arr[front];
			}
			
		}
};
int main() {
    Circular_Queue cq;
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Peek\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> element;
            cq.enqueue(element);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            element = cq.peek();
            if (element != -1) {
                cout << "Front element: " << element << endl;
            }
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
