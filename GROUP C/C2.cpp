/*
🔘PROBLEM STATEMENT:- 
You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of money to
connectdifferent pairs of cities. You want a set of lines that connects all your offices
with a minimum total cost. Solve the problem bysuggesting appropriate data structures
*/ 

/*
#️⃣Quick Revision Notes:-

🔹Prims Algorithm :- It is use to find MINIMUM COST SPANNING TREE
Spanning Tree :- No of Vertex = V then Edges= V-1 (Graph should be Connected in Nature)

1. Start with an arbitrary vertex.
2. Add it to the minimum spanning tree (MST).
3. Find the minimum-weight edge connected to the MST.
4. Add the vertex connected by the edge to the MST.
5. Repeat steps 3 and 4 until all vertices are included in the MST.
# Note: At each step, choose the edge with the minimum weight that connects the MST to a vertex not yet in the MST.
*/ 


#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;

int m[20][20], total,connections,size,cost,visited[20];
string office_name[20],start_point,end_point;
unordered_map<string,int>map;

void insert(){
    cout<<"Enter number of offices: ";
    cin>>size;

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            m[i][j]=999;
        }
    }

    for(int i=0; i<size; i++){
        cout<<"Enter Name of Office "<<i+1<<" : ";
        cin>>office_name[i];
        map[office_name[i]]=i;
    }

    cout<<"Enter Number of Connections : ";
    cin>>connections;

    cout<<"Give cost of Connections : "<<endl;
    for(int i=0; i<connections; i++){
        cout<<"Enter start Point : ";
        cin>>start_point;

        cout<<"Enter end point : ";
        cin>>end_point;

        cout<<"Enter Cost : ";
        cin>>cost;

        m[map[start_point]] [map[end_point]]=m[map[end_point]][map[start_point]]=cost;
        cout<<endl;
    }
}

void display(){
    cout<<"---- A D J AE C E N C Y  M A T R I X -----"<<endl;
    cout<<"                  ";
    for(int i=0; i<size; i++){
        cout<<left<<setw(15)<<office_name[i];
    }
    cout<<endl;
    for(int i=0; i<size; i++){
        cout<<left<<setw(15)<<office_name[i];
        for(int j=0; j<size; j++){
            cout<<left<<setw(15)<<m[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
