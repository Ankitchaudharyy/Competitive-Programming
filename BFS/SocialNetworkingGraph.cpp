// SOCIAL NETWORKING GRAPH

/*
In a social networking site, people are connected with other people. The whole system appears as a giant connected graph. In this question, you are required to answer the total number of people connected at t nodes away from each other (t distance connectivity). For example: Two persons directly connected are at 1 distance connectivity. While the two persons having a common contact without having direct connectivity, are at 2 distance connectivity.
First line of input line contains, two integers n and e, where n is the nodes and e are the edges. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. Next line contains single integer, m, which is number of queries. Next m lines, each have two inputs, one as source node and other as a required t distance connectivity which should be used to process query.

Note: The index of nodes will be 0-based. The example and the test case shown is of 1-based index. For submitting the solution, use 0-based indexing.

SAMPLE INPUT
9 10
1 2
2 3
1 7
2 4
3 4
4 7
7 8
9 7
7 6
5 6
3
4 2
5 3
2 1

SAMPLE OUTPUT
4
4
3

Explanation
After creating the graph, there was 3 queries,

1. Source node: 4, and we have to find out total number of nodes at a distance of 2 from node 4.
    1(4->2->1), 8(4->7->8), 9(4->7->9), 6(4->7->6) = 4

Similarly as above
2. Source node: 2, and we have to find out total number of nodes at a distance of 1 from node 2.
    1(2->1), 4(2->4), 3(2->3) = 3
*/


#include <bits/stdc++.h>
using namespace std;

#define MAX 10001

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, list<int>> adjList;
    bool isVisited[MAX];
    map<int, int> dist;

    memset(isVisited, false, sizeof(isVisited));

    int n, m, u, v, query, src, d, count=0;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cin>>query;

    while(query--){
        cin>>src>>d;
        count=0;

        queue<int> q;
        memset(isVisited, false, sizeof(isVisited));

        q.push(src);
        isVisited[src]=true;
        dist[src]=d;

        while(!q.empty()){
            int d = q.front();
            q.pop();

            for(auto neigh: adjList[d]){
                if(!isVisited[neigh]){
                    isVisited[neigh]=true;
                    dist[neigh] = dist[d] - 1;

                    if(dist[neigh]!=0) q.push(neigh);
                    else if(dist[neigh]==0) count++;
                }
            }
        }

        cout<<count<<endl;
    }

    return 0;
}
