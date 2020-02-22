#include <bits/stdc++.h>
using namespace std;

void initialize(int parent[], int size){
	parent[0] = -1;

	for(int i=1; i<size; i++) 
		parent[i]=i;
}

// O(n)
int root(int parent[], int i){
	while(parent[i] != i)
		i = parent[i];
	return i;
}

// O(1)
void union_f(int parent[], int a, int b){
	int pA = root(parent, a);
	int pB = root(parent, b);

	if(pB == pA) return;

	parent[pB] = pA;
	// OR Parent[pA] = pB;
}

int main(){

	int nodes, edges, a, b;
	cin>>nodes>>edges;

	int parent[nodes+1];
	initialize(parent, nodes+1);

	for(int i=0; i<edges; i++){
		cin>>a>>b;
		union_f(parent, a, b);
	}

	for(int i=0; i<=nodes; i++){
		cout<<i<<" -> "<<parent[i]<<endl;
	}

	return 0;
}

//INPUT --->
//11 8
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
// 1 -> 11
// 2 -> 1
// 3 -> 5
// 4 -> 3
// 5 -> 5
// 6 -> 5
// 7 -> 7
// 8 -> 8
// 9 -> 11
// 10 -> 7
// 11 -> 8

