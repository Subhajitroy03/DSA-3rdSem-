#include<iostream>
using namespace std;
int linearSearch(int arr[],int element,int length){
	int i;
	for(i=0;i<length;i++){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}
int main(void){
	int arr[]={1,2,6,9,8,10,15,20,26,31,36,46};
	int element;
	cout<<"Enter element: ";
	cin>>element;
	int index=linearSearch(arr,element,12);
	if(index==-1){
		cout<<"Not found"<<endl;
	}else{
		cout<<"Element found in position: "<<index+1;
	}
}
