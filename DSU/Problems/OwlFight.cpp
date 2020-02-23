// OWL FIGHT

// Owl Arena is hosting a fight competition and many owls decided to take part in it.

// Strength of an owl is the number associated with that owl.

// Rules of the competition are:

//     An owl wins if its strength is greater than that of another.
//     An owl can ask his friend to fight that match for him.

// Note : If A and B are friends, and B and C are friends, then A and C are also friends.

// Input:
// First line contains the number of owls participating N and the number of connections M.
// M lines follow.
// Each line contains two integers u and v denoting that they are friends.
// Next line contains Q, the number of queries.
// Q lines follow.
// Each line contains two integers u and v. You need to tell who wins.

// Output:
// In each query, output the number of the owl that will win the match. If the owls(u and v) are in the same friend circle, output


// SAMPLE INPUT
// 7 3
// 1 2
// 3 4
// 1 7
// 4
// 1 2
// 5 6
// 3 7
// 1 5

// SAMPLE OUTPUT
// TIE
// 6
// 7
// 1

// Explanation
// 1,2 and 7 are friends. 3 and 4 are friends. 5,6 and 7 have no friends. now,
// First query: 1 and 2 : since both belong to the same friend circle, answer is a TIE.
// Second: 5 and 6: since there is no friend of 5 and no friend of 6 and 6 has higher strength. 6 will win.
// Third: 3 and 7: 3 has a friend 4 who has more strength than 3 and 7 has no friends whose strength is greater than his. so 4 vs 7. 7 will win.
// Fourth: 1 and 5: 1 has a friend 7 who has more strength than 1 and 5 has no friends. so 5 vs 7. 7 will win. And since the fight was b/w 1 and 5. 1 wins the fight.



#include <bits/stdc++.h>
using namespace std;

#define l long

void initialize(l parent[], l size){
    parent[0] = -1;
    
    for(int i=1; i<size; i++) parent[i] = i;
}

l root(l parent[], int i){
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
    else if(rank[pU] > rank[pV]) parent[pV] = pU;
    else {
        parent[pV] = pU;
        rank[pU]++;
    }
}

int main(){
    
    l n, m, u, v, q;
    cin>>n>>m;
    
    l parent[n+1], rank[n+1];
    memset(rank, 1, sizeof(rank));
    initialize(parent, n+1);
    
    for(l i=0; i<m; i++){
        cin>>u>>v;
        unionFind(parent, rank, u, v);
    }
    
    unordered_map<l, l> mx;
    
    for(l i=1; i<=n; i++){
         l rt = root(parent, i);
        if(mx.find(rt) == mx.end()){
            mx[rt] = i; 
        }
        else{
            mx[rt] = max(mx[rt], i);
        }
    }
    
    cin>>q;
    
    while(q--){
        cin>>u>>v;
        l uroot = root(parent, u);
        l vroot = root(parent, v);
        
        if(uroot != vroot){
            if(mx[vroot] > mx[uroot]) cout<<v<<endl;
            else cout<<u<<endl;
        }
        else cout<<"TIE"<<endl;
    }
    
    return 0;
}