#include<bits/stdc++.h>
#define MAX_NODE 10
using namespace std;

vector<int> adjList[MAX_NODE];
bool vis[MAX_NODE];
int distance[MAX_NODE];
int nodes, edges;
int startingNode;
queue<int> q;

void readData() {
    freopen("input.txt", "r", stdin);
    cin >> nodes >> edges;
    int t1, t2;
    for(int i=0; i<edges; i++)
    {
        cin >> t1 >> t2;
        adjList[t1].push_back(t2);
        adjList[t2].push_back(t1);
    } //adj list formed;
    cin >> startingNode;
}

void bfs(int s)
{
    q.push(s);
    vis[s]=true;
    printf("%d ", s);
    while(q.empty()!=true)
    {
        int tmp = q.front();
        q.pop();
        for(int i=0; i<adjList[tmp].size(); i++)
        {
            if(vis[adjList[tmp][i]]==false)
            {
                vis[adjList[tmp][i]]=true;
                printf("%d ", adjList[tmp][i]);
                q.push(adjList[tmp][i]);
            }
        }
    }
}
int main()
{
    readData();
    printf("The path of visiting is: ");
    bfs(startingNode);
    return 0;
}
