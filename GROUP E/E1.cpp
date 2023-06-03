/*
🔘PROBLEM STATEMET:-
Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum marks
obtained in that subject. Use heap data structure.Analyze the algorithm.
*/

/*
#️⃣Quick Revision Notes:-
🔸HEAP DATA STRUCTURE :- When dynamic allocation is done then we use this data structure.
TYPE :- 1. Min Heap :- Root < Child.
        2. Max Heap :- Root > Child.

1. Complete Binary Tree is requaired.
*/

#include<iostream>
using namespace std;

void MinHeap(int arr[],int  i){
    int parent = (i-1)/2;
    int current =i;
    while(parent >= 0 && arr[parent] > arr[current]){
    	swap(arr[parent],arr[current]);
    	current = parent;
    	parent = (current-1)/2;
    	
	}
}
void MaxHeap(int arr[],int  i){
    int parent = (i-1)/2;
    int current =i;
    while(parent >= 0 && arr[parent] < arr[current]){
    	swap(arr[parent],arr[current]);
    	current = parent;
    	parent = (current-1)/2;
    	
	}
}
int main(){
    int n;
    cout<<"Enter No of Students: ";
    cin>>n;

    int arr[n] = {};
    cout<<"Enter DSA Marks of "<<n<<" students : "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    
    for(int i=1; i<6 ;i++){
        MinHeap(arr,i);

    }
    cout<<"------------------------------"<<endl;
    cout << "Minimum Score: "<<arr[0]<<endl;

    for(int i=1; i<6; i++){
    	MaxHeap(arr, i);
	}
    cout<<"------------------------------"<<endl;
    cout << "Max Score: "<<arr[0]<<endl;
    return 0;
}
