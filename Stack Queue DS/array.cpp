#include<iostream>
#define capacity 10
using namespace std;
void display(int arr[],int size){
	int i =0;
	for(;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}
void insert(int arr[],int element,int position,int &size){
	if(position>size){
		cout<<"Invalid position"<<endl;
		return;
	}
	if(size==capacity){
		cout<<"array full"<<endl;
		return;	
	}
	int i;
	for(i=size;i>position;i--){
		arr[i]=arr[i-1];
	}
	arr[position]=element;
	size++;
	return;
}
void deletion(int arr[],int position,int &size){
	if(position>=size){
		cout<<"Invalid position.."<<endl;
		return;
	}
	if(size==0){
		cout<<"array empty"<<endl;
		return;
	}
	int i;
	for(i=position;i<size-1;i++){
		arr[i]=arr[i+1];
	}
	size--;
	return;
}
int main(void){
	int arr[capacity]={1,2,5,8,9};
	int size=5;
	insert(arr,100,3,size);
	insert(arr,200,3,size);
	insert(arr,400,3,size);
	insert(arr,500,3,size);
	insert(arr,600,3,size);
	display(arr,size);
	deletion(arr,0,size);
	deletion(arr,0,size);
	deletion(arr,0,size);

	deletion(arr,0,size);
	display(arr,size);
}
