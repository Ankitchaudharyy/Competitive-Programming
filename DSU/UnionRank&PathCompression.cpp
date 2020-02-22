#include <bits/stdc++.h>
using namespace std;

void initialize(int parent[], int rank[], int size){
	parent[0] = -1;

	for (int i = 1; i < size; ++i){
		parent[i] = i;
		rank[i] = 1;
	}
}

// PATH COMPRESSION TECHNIQUE
int root(int parent[], int i){
	while(parent[i] != i){
		parent[i] = parent[parent[i]];
        i = parent[i];
	}

	return parent[i];
}

void unionFind(int parent[], int rank[], int a, int b){
	int pA = root(parent, a);
	int pB = root(parent, b);

	if(rank[pA] < rank[pB])
		parent[pA] = pB;
	else if(rank[pA] > rank[pB])
		parent[pB] = pA;
	else{
		parent[pB] = pA;
		rank[pA]++;
	}
}

int main(){

	int nodes, edges, a, b;
	cin>>nodes>>edges;

	int parent[nodes+1], rank[nodes+1];
	initialize(parent, rank, nodes+1);

	for(int i=0; i<edges; i++){
		cin>>a>>b;
		unionFind(parent, rank, a, b);
	}

	for(int i=0; i<=nodes; i++){
		cout<<i<<" -> "<<parent[i]<<endl;
	}
	
	return 0;
}


// INPUT --->
// 11 8
// 1 2
// 11 2
// 2 9
// 8 2
// 7 10
// 3 4 
// 5 3
// 3 6


// OUTPUT --->
// 0 -> -1
// 1 -> 1
// 2 -> 1
// 3 -> 3
// 4 -> 3
// 5 -> 3
// 6 -> 3
// 7 -> 7
// 8 -> 1
// 9 -> 1
// 10 -> 7
// 11 -> 1
