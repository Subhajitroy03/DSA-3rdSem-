#include<iostream>
#define max 50
using namespace std;
class Node{
	public:
	int element;
	int prio;	
};
class priorityQueue{
	public:
		Node arr[max];
		int front;
		int rear;
		
	priorityQueue(){
		front=-1;
		rear=-1;
	}
	int isEmpty(){
		if(rear==-1){
			return 1;
		}
		else{
			return 0;
		}
	}
	int isFull(){
		if(rear==max-1){
			return 1;
		}
		else{
			return 0;
		}
	}
	void enqueue(int ele,int p){
		if(isEmpty()==1){
			front=0;
			rear=0;
			arr[rear].prio=p;
			arr[rear].element=ele;
			return;
		}
		if(isFull()==0){
			Node key;
			key.element=ele;
			key.prio=p;
			int j=rear;
			arr[rear+1]=key;
			for(;j>=front;j--){
				if(key.prio<arr[j].prio){
					//move left by shifting elements
					arr[j+1]=arr[j];
					
				}else{
					//stop
					break;
				}
			}
			arr[j+1]=key;
			rear++;
		}
	}
	void dequeue(){
		if(isEmpty()==0){
			front++;
		}
	}
	void display(){
		if(isEmpty()==0){
			int i;
			for(i=front;i<=rear;i++){
				cout<<" element: "<<arr[i].element<<" priority: "<<arr[i].prio<<endl;
			}
		}
		
	}
		
};
int main(){
	priorityQueue Pq;
	Pq.enqueue(5,2);
	Pq.enqueue(9,6);
	Pq.enqueue(8,1);
	Pq.enqueue(3,3);
	Pq.enqueue(10,7);
	Pq.enqueue(80,4);
	Pq.display();
	cout<<"After deletion.."<<endl;
	Pq.dequeue();
	Pq.display();

}
