/*
🔘PROBLEM STATEMET:-
There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight
take to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph or use adjacency matrix representation of the graph. Check
whether the graph is connected or not. Justify the storage representation used.
*/

#include<iostream> 
using namespace std; 
 
string city[10]; 
int d[10][10]; 
int size; 
int val; 
 
void cityname(){ 
    cout<<"Enter the number of cities : "; 
    cin>>size; 
    for(int i=0;i<size;i++){ 
        cout<<"Enter Name city no. "<<i+1<<" : "; 
        cin>>city[i]; 
    } 
} 

void distance(){ 
    for(int i=0;i<size;i++){ 
        for(int j=0;j<size;j++){ 
            if(i!=j && d[i][j]==0){ 
                cout<<"Enter distance between "<<city[i]<<" -> "<<city[j]<<" : "; 
                cin>>val; 
                d[i][j]=val; 
                d[j][i]=val; 
            } 
        } 
    } 
} 
 
void add(){ 
    cout<<"Enter Name of city : "; 
    cin>>city[size]; 
    size++; 
    distance(); 
} 
 
void display(){ 
    for(int i=0;i<size;i++){ 
        cout<<"          "<<city[i]; 
    } 
    cout<<endl; 
    cout<<endl; 
    for(int i=0;i<size;i++){ 
        cout<<city[i]; 
        for(int j=0;j<size;j++){ 
            cout<<"         "<<d[i][j]; 
        } 
        cout<<endl; 
        cout<<endl; 
    } 
} 
 
int main(){ 
    cityname(); 
    distance(); 
    int ch; 
    while(true){ 
        cout<<"1. Add a city "<<endl; 
        cout<<"2. Display weight representation : "<<endl; 
        cout<<"3. Exit"<<endl; 
        cout<<"enter choice : "; 
        cin>>ch; 
        if(ch==1){ 
            add(); 
        } 
        else if(ch==2){ 
            display(); 
        } 
        else if(ch==3){ 
            break; 
        } 
    } 
}
