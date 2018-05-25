#include<bits/stdc++.h>
#define MAX_NODE 10
using namespace std;

vector<int> adjList[MAX_NODE];
bool vis[MAX_NODE];
int distance[MAX_NODE];
int nodes, edges;
int startingNode;
queue<int> q;

void readData()
{
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

void dfs(int s)
{
    vis[s] = true;
    for(int i = 0; i < adjList[s].size(); ++i)
    {
        if(vis[adjList[s][i]] == false)
        {
            printf("%d ", adjList[s][i]);
            dfs(adjList[s][i]);
        }
    }
}

int main()
{
    readData();
    printf("The path of visiting is: ");
    dfs(startingNode);
    return 0;
}
