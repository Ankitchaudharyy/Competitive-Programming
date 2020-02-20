// MONK AND THE ISLANDS

/*
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 104
1 ≤ M ≤ 105
1 ≤ X, Y ≤ N

SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

SAMPLE OUTPUT
2
2
*/


#include <bits/stdc++.h>
using namespace std;

#define l long
#define MAX 10001

int main(){

    int t, n, u, v;
    l m;
    cin>>t;

    queue<int> q;
    bool isVisited[MAX];
    int dist[MAX];

    while(t--){
        map<int, list<int>> adjList;
        memset(isVisited, false, sizeof(isVisited));
        memset(dist, -1, sizeof(dist));

        cin>>n>>m;

        for(l i=0; i<m; i++){
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        q.push(1);
        isVisited[1]=true;
        dist[1]=0;

        while(!q.empty()){
            int d = q.front();
            q.pop();

            for(auto neigh: adjList[d]){
                if(!isVisited[neigh]){
                    q.push(neigh);
                    isVisited[neigh]=true;
                    dist[neigh]=dist[d]+1;
                }
            }
        }
        cout<<dist[n]<<endl;
    }
    return 0;
}
