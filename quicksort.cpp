#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int s,int e){
	//choose the pivot element
	int pivot=arr[s];
	int count=0;
	int i;
	for (i=s;i<=e;i++){
		if(arr[i]<pivot){
			count++;
		}
	}
	int pivotindex=s+count;
	swap(arr,pivotindex,s);
	//left right thik korte hbe
	i=s;
	int j=e;
	while(i<pivotindex and j>pivotindex){
		while(arr[i]<pivot){
			//do nothing
			i++;
		}
		while(arr[j]>pivot){
			//do nothing
			j--;
		}
		if(i<pivotindex && j>pivotindex){
			swap(arr,i,j);
			i++;
			j--;
		}
	}
	return pivotindex;
}
void PrintArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void quicksort(int arr[],int s,int e){
	//base case
	if(s>=e)
		return;
	//partition
	int p=partition(arr,s,e);
	//partiton fun will place the pivot element at its correct position, 
	//return the pivot index
	//left a choto and right a boro
	quicksort(arr,s,p-1);
	quicksort(arr,p+1,e);
	
}
int main(void){
	int arr[]={4,7,3,5,1};
	quicksort(arr,0,5);
	PrintArray(arr,6);
}
		
