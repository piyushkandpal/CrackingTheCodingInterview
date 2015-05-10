#include<iostream>
#include<queue>

using namespace std;
const int MAX = 100;
/*
bool routeExists(bool graph[][MAX],int start,int end)
{
    bool visited[MAX]={false};
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i=0;i<MAX ;i++)
        {
            if(graph[tmp][i] && !visited[i])
            {
                if (i==end)
                    return true;
                else
                {
                    q.push(i);
                    visited[i]=true;
                }
            }

        }
    }
    return false;
}

int main()
{
    int m,u,v;
    bool dgraph[MAX][MAX];
    freopen("values.txt","r",stdin);
    cout<<"enter number of nodes"<<endl;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        cin>>u>>v;
        dgraph[u][v]=true;
    }
    for (int i=0;i<m;i++)
        for(int j=0;j<m;j++)
    {
         cout<<"if route exists between ["<<i<<"] and ["<<j<<"] -->  "<<routeExists(dgraph,i,j)<<endl;
    }
}
*/

bool isRoute(int a, int b, bool graph[][MAX]){
    queue<int> Que;
    bool visited[MAX];
    memset(visited, false, sizeof(visited));
    Que.push(a);
    visited[a] = true;
    int tmp;
    while(!Que.empty()){
        tmp = Que.front();
        Que.pop();
        for(int i=0; i<MAX; i++){
            if(graph[tmp][i] && !visited[i]){
                if(b==i)
                    return true;
                Que.push(i);
                visited[i]=true;
            }
        }
    }
    return false;
}

int main(){
    freopen("values.txt", "r", stdin);
    int n, m, u, v;
    bool dgraph[MAX][MAX];
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        dgraph[u][v] = true;
    }
    cout<<isRoute(0, 3, dgraph);
    for (int i=0;i<m;i++)
        
    {
        for(int j=0;j<m;j++)
        {
             cout<<"if route exists between ["<<i<<"] and ["<<j<<"] -->  "<<isRoute(i,j,dgraph)<<endl;
        }
    }
}

