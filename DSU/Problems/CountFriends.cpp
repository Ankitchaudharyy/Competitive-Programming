// COUNT FRIENDS

// There are N students and M relationships of the form u v, which means that student u and student v are friends. If two students are not friends directly but they have a mutual friend, then they too become friends. Your task is to count the number of friends of the
// student where


// Input:
// The first line consists of two integers N and M denoting the number of students and the number of relationships respectively.
// The next M lines consists of two integers u and v denoting that student u and student v are friends. u and v can never be equal and relationships are not repeated.

// Output:
// Print N space separated integers which tells us the number of friends of the
// student.

// Constraints:

// SAMPLE INPUT
// 4 3
// 4 3
// 2 4
// 2 3

// SAMPLE OUTPUT
// 0 2 2 2 

// Explanation
// For the sample test case -
// Student 1 has no friends.
// Student 2 is friends with student 3 and 4.
// Student 3 is friends with student 2 and 4.
// Student 4 is friends with student 2 and 3.



#include <bits/stdc++.h>
using namespace std;

#define l long

void initialize(l parent[], l rank[], l size){
    parent[0] = -1;
    
    for(l i=1; i<size; i++) parent[i] = i;
}

l root(l parent[], l i){
    while(parent[i] != i){
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
     return parent[i];
}

void unionFind(l parent[], l rank[], l a, l b){
    l pA = root(parent, a);
    l pB = root(parent, b);
    
    if(rank[pA] < rank[pB]) 
        parent[pA] = pB;
    else if(rank[pB] < rank[pA]) 
        parent[pB] = pA;
    else {
        parent[pB] = pA;
        rank[pA]++;
    }
}

int main(){
    
    l n, m, a, b;
    cin>>n>>m;
    
    l parent[n+1], rank[n+1];
    initialize(parent, rank, n+1);
    memset(rank, 1, sizeof(rank));;
    
    for(l i=0; i<m; i++){
        cin>>a>>b;
        unionFind(parent, rank, a, b);
    }
    
    l count[n+1] = {0};
    
    for(int i=1; i<n+1; i++)
        count[root(parent, i)]++;
        
    for(int i=1; i<n+1; i++){
        cout<<count[root(parent, i)]-1<<" ";
    }
        
    return 0;
}
