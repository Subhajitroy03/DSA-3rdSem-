#include<iostream>
using namespace std;
void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void SelectionSort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int smallestno_idx=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[smallestno_idx]){
				smallestno_idx=j;
			}
		}
		swap(arr,i,smallestno_idx);
	}
}
void insertion_sort(int arr[],int n){
	int i,j;
	for(i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		for(;j>=0;j--){
			if(key<arr[j]){
				//move left by shifting elements
				arr[j+1]=arr[j];
				
			}else{
				//stop
				break;
			}
		}
		arr[j+1]=key;
	}
}
void Bubblesort(int arr[],int n){
	int i,j;
	for (i=0;i<n-1;i++){
		int isSort=0;
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				isSort=1;
			}
		}
		if(isSort==0){
			return;
		}
		
	}		
}
void PrintArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

