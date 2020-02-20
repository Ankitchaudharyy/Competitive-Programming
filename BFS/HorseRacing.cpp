// HORSE RACING

/*
Geralt owns S horses. He wants to keep only horses that can run very fast. He decides which horses are fast by making them race against each other. If a horse comes in last, then Geralt will sell it.
The race course consists of N checkpoints and E roads. Geralt positions his horses at the first S checkpoints i.e., checkpoints 1 to S. The checkpoint N is chosen as the finish line. The horses need 1 unit of time to cross one road. If the horses have two or more paths to choose, then they choose the one which is shortest. The horses start the race at the same instant. When a horse reaches checkpoint N, it finishes the race.
Find the total number of horses that Geralt will sell i.e., the number of horses that come in last.
NOTE : The roads are bidirectional.

 Input
The first line of the input consists of S (the number of horses), N (the number of checkpoints) and E (the number of roads)
Each of the next E lines contains a and b, indicating that there is a road between checkpoints a and b

Output
Print a single integer, the number horses that come in last.

Constraints
1 ≤ S < N ≤ 300000
1 ≤ E ≤ 300000
1 ≤ a , b ≤ N

Example
Input:
3 5 4
1 5
2 4
3 4
5 4

Output:
2

Explanation
There are 3 horses, each starting at checkpoint 1, 2 and 3 respectively. Checkpoint 5 is the finish line. The horse starting at checkpoint 1 finishes the race first, in 1 unit of time. The horses at 2 and 3 come in last and finish the race at the same instant. Hence, Geralt will sell 2 horses.
*/


#include <bits/stdc++.h>
using namespace std;

#define l long

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<l, list<l>> adjList;

    l s, n, e, u, v;
    cin>>s>>n>>e;

    for(l i=0; i<=n; i++) adjList[i].clear();

    for(l i=0; i<e; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<l> q;
    bool isVisited[n+1];
    l dist[n+1];

    memset(isVisited, false, sizeof(isVisited));
    memset(dist, 0, sizeof(dist));

    q.push(n);
    isVisited[n]=true;
    dist[n]=0;

    while(!q.empty()){
        l t = q.front();
        q.pop();

        for(auto neigh: adjList[t]){
            if(!isVisited[neigh]){
                isVisited[neigh]=true;
                dist[neigh]=dist[t]+1;
                q.push(neigh);
            }
        }
    }

    l maxDist = INT_MIN;
    l ans = 0;

    for(l i=1; i<=s; i++){
        maxDist = max(maxDist, dist[i]);
    }

    for(int i=1; i<=s; i++){
        if(dist[i]==maxDist) ans++;
    }

    cout<<ans;

    return 0;
}