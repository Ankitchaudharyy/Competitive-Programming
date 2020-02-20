// PLAYING WITH NUMBERS

/*
Chef’s brother has visited the Chef during his summer vacation. Chef’s brother loves to play with numbers. So Chef gave him 2 numbers A and B. Chef asked his brother to find the minimum number of steps required to reach B from A given only the following operations can be performed any number of times:

Decrement the current number by 1
Increment the current number by 3
Multiply the current number by 2

Chef’s brother found this problem very easy and asked you to solve it. Can you solve this problem for him?

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output
For each test case, output a single line containing the answer.

Constraints
1 ≤ T ≤ 100
0 ≤ A,B ≤ 2*103

Example
Input:
2
4 7
0 10

Output:
1
4

Explanation
Test case 1. You can reach from 4 to 7 in just one step by adding 3.
Test case 2. It is possible to reach 10 from 0 in just 4 steps. 0 -> 3 -> 6 -> 5 -> 10 First add 3 to the number 2 times to get 6, then subtract 1 from it to get 5, and then just double it to get 10.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, a, b;
    cin>>t;

    bool isVisited[2001];
    int ways[2001];

    while(t--){
        cin>>a>>b;

        memset(isVisited, false, sizeof(isVisited));
        memset(ways, 0, sizeof(ways));

        queue<int> q;
        q.push(a);

        isVisited[a] = true;
        ways[a] = 0;

        while(!q.empty()){
            int t = q.front();
            q.pop();

            if(t==b){
                cout<<ways[t]<<endl;
                break;
            }

            int p = t*2;
            if(p<=2000 && !isVisited[p]){
                q.push(p);
                isVisited[p]=true;
                ways[p] = ways[t]+1;
            }

            int o = t-1;
            if(o>0 && !isVisited[o]){
                q.push(o);
                isVisited[o]=true;
                ways[o] = ways[t]+1;
            }

            int u = t+3;
            if(u<=2000 && !isVisited[u]){
                q.push(u);
                isVisited[u]=true;
                ways[u] = ways[t]+1;
            }
        }
    }
    return 0;
}
