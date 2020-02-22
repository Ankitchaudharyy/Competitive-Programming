#include <bits/stdc++.h>
using namespace std;

void initialize(int parent[], int size){
	parent[0] = -1;

	for(int i=1; i<size; i++) 
		parent[i]=i;
}

// O(1)
bool find(int parent[], int a, int b){
	if(parent[a] == parent[b]) 
		return true;
	else 
		return false;
}

// O(n)
void union_f(int parent[], int size, int a, int b){
	int temp = parent[a];

	for(int i=1; i<size; i++)
		if(parent[i]==temp) 
			parent[i] = parent[b];
}

int main(){

	int nodes, edges, a, b;
	cin>>nodes>>edges;

	int parent[nodes+1];
	initialize(parent, nodes+1);

	for(int i=0; i<edges; i++){
		cin>>a>>b;
		union_f(parent, nodes+1, a, b);
	}

	for(int i=0; i<=nodes; i++){
		cout<<i<<" -> "<<parent[i]<<endl;
	}

	return 0;
}


//INPUT --->
// 11 8
// 1 2
// 2 11
// 2 9
// 2 8
// 7 10
// 3 4 
// 3 5
// 3 6

// OUTPUT --->
// 0 -> -1
// 1 -> 8
// 2 -> 8
// 3 -> 6
// 4 -> 6
// 5 -> 6
// 6 -> 6
// 7 -> 10
// 8 -> 8
// 9 -> 8
// 10 -> 10
// 11 -> 8
