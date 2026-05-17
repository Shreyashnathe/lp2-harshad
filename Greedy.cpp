// File Name : Greedy.cpp

#include<bits/stdc++.h>
using namespace std;

// Selection Sort
void selectionSort()
{
    int n;

    cout<<"Enter Size : ";
    cin>>n;

    vector<int>a(n);

    cout<<"Enter Elements : ";

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minIndex])
            {
                minIndex=j;
            }
        }

        swap(a[i],a[minIndex]);
    }

    cout<<"Sorted Array : ";

    for(int x:a)
    {
        cout<<x<<" ";
    }

    cout<<endl;
}

// Prim MST
void prim()
{
    int n;

    cout<<"Enter Vertices : ";
    cin>>n;

    vector<vector<int>>g(n,vector<int>(n));

    cout<<"Enter Matrix :\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }

    vector<int>key(n,INT_MAX);
    vector<bool>mst(n,false);

    key[0]=0;

    int cost=0;

    for(int i=0;i<n;i++)
    {
        int u=-1;

        for(int j=0;j<n;j++)
        {
            if(!mst[j]&&(u==-1||key[j]<key[u]))
            {
                u=j;
            }
        }

        mst[u]=true;
        cost+=key[u];

        for(int v=0;v<n;v++)
        {
            if(g[u][v]&&!mst[v]&&g[u][v]<key[v])
            {
                key[v]=g[u][v];
            }
        }
    }

    cout<<"MST Cost : "<<cost<<endl;
}

// Dijkstra
void dijkstra()
{
    int n,m;

    cout<<"Enter Vertices and Edges : ";
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n);

    cout<<"Enter Edges(u v w):\n";

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src;

    cout<<"Enter Source : ";
    cin>>src;

    vector<int>dist(n,INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >pq;

    dist[src]=0;

    pq.push({0,src});

    while(!pq.empty())
    {
        int u=pq.top().second;

        pq.pop();

        for(auto x:adj[u])
        {
            int v=x.first;
            int w=x.second;

            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;

                pq.push({dist[v],v});
            }
        }
    }

    cout<<"Shortest Distances :\n";

    for(int i=0;i<n;i++)
    {
        cout<<i<<" = "<<dist[i]<<endl;
    }
}

// Main
int main()
{
    int ch;

    do
    {
        cout<<"\n===== MENU =====\n";

        cout<<"1.Selection Sort\n";
        cout<<"2.Prim MST\n";
        cout<<"3.Dijkstra\n";
        cout<<"4.Exit\n";

        cout<<"Enter Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                selectionSort();
                break;

            case 2:
                prim();
                break;

            case 3:
                dijkstra();
                break;

            case 4:
                cout<<"Program Ended\n";
                break;

            default:
                cout<<"Invalid Choice\n";
        }

    }while(ch!=4);

    return 0;
}


// // ================================
// // Selection Sort Testcase
// // ================================

// 1
// 5
// 64 25 12 22 11

// // Output:
// // Sorted Array : 11 12 22 25 64


// // ================================
// // Prim MST Testcase
// // ================================

// 2
// 4
// 0 10 6 5
// 10 0 0 15
// 6 0 0 4
// 5 15 4 0

// // Output:
// // MST Cost : 19


// // ================================
// // Dijkstra Testcase
// // ================================

// 3
// 5 6
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 1
// 0

// // Output:
// // Shortest Distances :
// // 0 = 0
// // 1 = 2
// // 2 = 3
// // 3 = 7
// // 4 = 6


// // ================================
// // Exit
// // ================================

// 4