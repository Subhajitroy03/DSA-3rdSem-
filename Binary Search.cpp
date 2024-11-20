#include<iostream>
using namespace std;
int BinarySearch(int arr[],int element,int start,int end){
	while(start<=end){
		int mid=(start+end)/2;
		if(arr[mid]==element){
			return mid;
		}else if(arr[mid]>element){
			return BinarySearch(arr,element,start,mid-1);
		}else if(arr[mid<element]){
			return BinarySearch(arr,element,mid+1,end);
		}
	}
	return -1;
}
int main(void){
	int arr[]={1,2,6,9,8,10,15,20,26,31,36,46};
	int element;
	cout<<"Enter element: ";
	cin>>element;
	int index=BinarySearch(arr,element,0,11);
	if(index==-1){
		cout<<"Not found"<<endl;
	}else{
		cout<<"Element found in position: "<<index+1;
	}
}
