#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
	//left array r size holo n1
	int n1=mid-l+1;
	//right array r size holo n2
	int n2=r-mid;
	int left_arr[n1];
	int right_arr[n2];
	int i;
	//left array traverse hocche
	for(i=0;i<n1;i++){
		left_arr[i]=arr[l+i];
	}
	//right array traverse hocche
	for(i=0;i<n2;i++){
		right_arr[i]=arr[mid+1+i];
	}
	//merge two sorted array
	i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2){
		if(left_arr[i]<right_arr[j]){
			arr[k]=left_arr[i];
			k++;
			i++;
		}
		else if(left_arr[i]>right_arr[j]){
			arr[k]=right_arr[j];
			k++;
			j++;
		}
	}
	while(i<n1){
		arr[k]=left_arr[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=right_arr[j];
		j++;
		k++;
	}
}
void mergesort(int arr[],int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
void PrintArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(void){
	int arr[]={7,5,8,4,10,1};
	mergesort(arr,0,5);
	PrintArray(arr,6);
}
