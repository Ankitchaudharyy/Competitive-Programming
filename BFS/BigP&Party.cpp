//BIG P AND PARTY

/*
Big P has recently become very famous among girls .
Big P goes to a party and every girl present there wants to dance with him. However, Big P cannot dance with all of them, because there are many of them.
Now if a girl gets to dance with Big P, she considers herself to be " 1-Lucky ". A person that dances with someone who has danced with a person who has danced with Big P considers themselves " 2-Lucky ", and so on.
The Luckiness is defined on the basis of above mentioned rule. ( 1-Lucky -> Luckiness = 1).
Note1: Luckiness of Big P is 0 .
Note2: No one has negative luckiness.
Note3: If a person's luckiness cannot be determined from the above rules (he/she has not danced with anyone with finite luckiness), his/her luckiness is INF (infinity).
Note4: If a person A is not Big P himself, and has danced with someone with luckiness X, and has not danced with anyone with Luckiness smaller than X, then A has luckiness X+1 .

Input Format:
The first line has two numbers A,number of persons in the party and B, number of dancing couples Then B lines follow, each containing two distinct persons, denoting that the two persons have danced. Persons are represented by numbers between 0 and A-1.
Big P is represented by 0.

Output Format:
Output A-1 lines , ith line containing the luckiness of ith person. (1<= i <= A-1)
If luckiness cannot be calculated for a person - print "-1"(without the quotes).
[A<=1000 , B <=(A*(A-1))/2 ]


SAMPLE INPUT
5 6
0 1
0 2
3 2
2 4
4 3
1 2

SAMPLE OUTPUT
1
1
2
2
*/


#include <bits/stdc++.h>
using namespace std;

int main(){

    map<int, list<int>> adjList;

    int a, b, u, v;
    cin>>a>>b;

    for(int i=0; i<a; i++) adjList[i].clear();

    for(int i=0; i<b; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<int> q;
    bool isVisited[a];
    int dist[a];

    memset(isVisited, false, sizeof(isVisited));
    memset(dist, -1, sizeof(dist));

    q.push(0);
    isVisited[0]=true;
    dist[0]=0;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto neigh: adjList[t]){
            if(!isVisited[neigh]){
                isVisited[neigh]=true;
                dist[neigh]=dist[t]+1;
                q.push(neigh);
            }
        }
    }

    for(int i=1; i<a; i++) cout<<dist[i]<<endl;

    return 0;
}
