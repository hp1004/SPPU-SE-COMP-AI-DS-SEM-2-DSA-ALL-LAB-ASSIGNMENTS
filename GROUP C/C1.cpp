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
#include<cstring>
using namespace std;

//max size to handle cities
const int MAX_CITIES = 100;

//struct of the flight similar to node
struct Flight{
	string source;
	string dest;
	int cost;
};

//graph 
class Graph{
	public:
		int adjList[MAX_CITIES][MAX_CITIES]; //created 2d array to store adjacency list
		int numCities;
		
		//constructor
		Graph() {
			numCities = 0;
			memset(adjList, 0, sizeof(adjList));
		}
		
		//function to add a flight/add a weight to cell
		void addFlight(Flight flight) {
			int sourceIndex = getCityIndex(flight.source); //source index index of row
			int destIndex = getCityIndex(flight.dest); // dest index, index of coloumn
			adjList[sourceIndex][destIndex] = flight.cost;//adding the weight to the corresponding cell of 2d array	
		}
		
		//function to check if graph is connected using BFS
		bool isConnected() {
			bool visited[MAX_CITIES]; //to cehck is the node is visited or not
			memset(visited, false, sizeof(visited));
			//start BFS from any vertex
			int start = 0;
			visited[start] = true;
			for(int i = 0; i<numCities; i++) {
				if(adjList[start][i] > 0 && !visited[i]){
					visited[i] = true;
					//in this we check if the cell has a weight > 0 and its corresponding visited index is not visited
					//and mark as visited
			}
			for(int i = 0; i<numCities; i++) {
				if(!visited[i]) {
					return false;
					//again we traverse the visited array
					//and we encounter false that means the graph is not connected
				}
			}
			return true;
		}
}
	
			//function to het the index of the source and dest
			int getCityIndex(string city) {
				for(int i = 0; i<numCities; i++) {
					if(city == cities[i]) {
						return i;
					}
				}
				cities[numCities] = city;
				numCities++;
				return numCities-1;
			}
			//Array to store names of cities
			string cities[MAX_CITIES];
		
};


int main() {
    Graph g;
    int choice;
    Flight flight;
    do {
        cout << "\n1. Add a flight\n2. Check if graph is connected\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter source city: ";
            cin >> flight.source;
            cout << "Enter destination city: ";
            cin >>flight.dest;
            cout << "Enter cost of flight: ";
            cin >> flight.cost;
            g.addFlight(flight);
            break;
        case 2:
            if (g.isConnected())
                cout << "\nGraph is connected";
            else
                cout << "\nGraph is not connected";
            break;
        case 3:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice";
            break;
        }
    } while (choice != 3);
    return 0;
}
