#include<iostream>
using namespace std;

// Function to swap two elements in an array
void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

// Selection Sort implementation
void selection_sort(int arr[],int n){
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

// Insertion Sort implementation
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

// Bubble Sort implementation
void bubble_sort(int arr[],int n){
	int i,j;
	for (i=0;i<n-1;i++){
		int isSort=0;
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				isSort=1;
			}
		}
        // If no two elements were swapped in inner loop, array is sorted
		if(isSort==0){
			return;
		}
		
	}		
}

// Function to print the array
void PrintArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main() 
{
    int n, choice;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose a sorting algorithm:\n";
    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n";
    cin >> choice;

    switch (choice) {
        case 1:
            selection_sort(arr, n);
            break;
        case 2:
            insertion_sort(arr, n);
            break;
        case 3:
            bubble_sort(arr, n);
            break;
        default:
            cout << "Invalid choice.\n";
    }

    cout << "Sorted array: ";
    PrintArray(arr, n);

    return 0;
}
