// TEACHER'S DILEMMA

// Monk is having a hard time teaching the
// standard students. He wants to divide the students into small groups so that he can conduct some fun-filled activities for them. But students also want their friends in the same group. So, if student A is a friend of student B, and student B is a friend of student C, then the students A,B and C must be in the same group, otherwise they will start crying. After dividing the students, he will choose a leader from each group who will lead their respective groups. Now he wants to know the number of ways he can choose the group leaders from all the groups. Print this answer modulo

// .

// Note: Two ways A and B will be considered different if at least 1 person is a leader in group A, and is not a leader in group B, or vice-versa.

// Input:
// The first line consists of two integers N and M denoting the number of students and the number of relationships respectively. The next M lines consists of two integers u and v denoting that student u and student v are friends. u and v can never be equal and relationships are not repeated.

// Output:
// Print the answer modulo

// in a single line.

// Constraints:


// SAMPLE INPUT

// 5 4
// 1 2
// 2 3
// 1 3
// 4 5

// SAMPLE OUTPUT

// 6

// Explanation

// According to the sample test case,
// 1, 2 and 3 must be in the same group.
// 4 and 5 must be in the same group.
// So, number of ways to choose leaders from these groups is
// .


#include <bits/stdc++.h>
using namespace std;

#define l long

void initialize(l parent[], l size){
    parent[0] = -1;
    
    for(l i=0; i<size; i++) parent[i] = i;
}

l root(l parent[], l i){
    while(parent[i] != i){
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    
    return parent[i];
}

void unionFind(l parent[], l rank[], l u, l v){
    l pU = root(parent, u);
    l pV = root(parent, v);
    
    if(rank[pU] < rank[pV]) parent[pU] = pV;
    else if(rank[pV] < rank[pU]) parent[pV] = pU;
    else{
        parent[pV] = pU;
        rank[pU]++;
    }
}

int main(){
    
    l n, m, u, v;
    cin>>n>>m;
    
    l parent[n+1], rank[n+1];
    initialize(parent, n+1);
    memset(rank, 1, sizeof(rank));
    
    for(l i=0; i<m; i++){
        cin>>u>>v;
        unionFind(parent, rank, u, v);
    }
    
    l count[n+1] = {0}, ans=1;
    
    
    for(l i=1; i<=n; i++){
        count[root(parent, i)]++;
    }
    
    for(l i=1; i<=n; i++){
        if(count[i]!=0){
            ans = (ans*count[root(parent, i)])%1000000007;
        }
    }
    
    cout<<ans;
    
    return 0;
}