// GAJJU BHAI IS HUNGRY

/*
Gajju Bhai is very hungry and hence decided to go to a restaurant. The city in which Gajju Bhai lives is a little wierd. All the places (like restaurants, houses, schools, hospital, etc) in the city are labeled by a unique number ranging from 1 to N. And all these places are connected by N-1 roads. Each road is 1 km long. And all the places are connected by atmost 1 road. Gajju Bhai lives at place numbered 1. There is exactly one path to reach from one place to another, and each place is reachable from any place in the city. There are total M restaurants in the city. Gajju Bhai will choose any one of those M restaurants. There is an equal probability of chosing a restaurant. Now since Gajju Bhai is busy in deciding a restaurant, your task is to find out the expected value of the distance Gajju Bhai will travel today, i.e. from going to his home to one of the restaurant and then returning back to his home.

Input
Input description.
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains 2 integers N and M. Where N is the number of places in the city, and M are the number of restaurants in the city.
Next N-1 lines contains 2 integers u and v, which denotes that place u and place v are connected by a road.
Last line of each test case contains M space seperated integers (value ranging between 1 and N both inclusive). Denoting the unique number of restaurants.

Output
Output description.
For each test case, output a single floating point number in a new line, the expected value of the distance Gajju Bhai will travel. (The answer should be correct upto 6 decimal places)

Constraints
1 ≤ T ≤ 10
1 ≤ M ≤ N ≤ 106
1 ≤ u, v ≤ N

Example
Input:
2
5 2
1 2
1 3
2 4
3 5
2 5
7 4
1 2
1 4
1 3
4 5
4 6
4 7
2 4 7 3

Output:
3.000000
2.500000

Explanation
Example case 1.
There are 5 places out of which 2 are restaurants, numbered 2 and 5. Distance from 1 to 2 is 1 km, and from 1 to 5 is 2 km. So he will travel 2 kms if he choses 2, and 4 kms if he choses 5. Probabilty of each is 1/2. Hence the expected value is 2/2 + 4/2, equal to 3.
 */


#include <bits/stdc++.h>
using namespace std;

#define l long

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        map<l,list<l>> adjList;
        l n, m, u, v;

        cin>>n>>m;
        l a[m];

        for(l i=0; i<n; i++) adjList[i].clear();

        for(l i=0; i<n-1; i++){
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(l i=0; i<m; i++) cin>>a[i];

        queue<l> q;
        bool isVisited[n+1];
        l dist[n+1];

        memset(isVisited, false, sizeof(isVisited));
        memset(dist, 0, sizeof(dist));

        q.push(1);
        isVisited[1] = true;
        dist[1] = 0;

        while(!q.empty()){
            l t = q.front();
            q.pop();

            for(auto neigh: adjList[t]){
                if(!isVisited[neigh]){
                    isVisited[neigh] = true;
                    dist[neigh] = dist[t] + 2;
                    q.push(neigh);
                }
            }
        }

        double sum = 0;
        for(l i=0; i<m; i++) sum += dist[a[i]];

        cout<<fixed<<setprecision(6)<<sum/m<<endl;
    }
    return 0;
}
