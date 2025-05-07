#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<vector<pair<int,int>>> adjList;

public:
    Graph(int v){
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int src, int des, int w){
        adjList[src].push_back({des, w});
        adjList[des].push_back({src, w});
    }

    void printGraph(){
        cout<<"Src --> (des, weight)"<<endl;
        for(int i=0;i<v;i++){
            cout<<i<<"-->";
            for(auto j : adjList[i]){
                cout<<"("<<j.first<<","<<j.second<<") ";
            }
            cout<<endl;
        }
    }

    void primsMST(int start){
        vector<int> parent(v, -1);
        vector<int> key(v, INT_MAX);
        vector<bool> visited(v, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});
        key[start] = 0;
        int minCost = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;
            minCost += key[u];

            for(auto &neighbour : adjList[u]){
                int v = neighbour.first;
                int w = neighbour.second;

                if(!visited[v] && w < key[v]){
                    key[v] = w;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout<<"Prims MST: "<<endl;
        for(int i=0;i<v;i++){
            if(parent[i] != -1){
                cout<<parent[i]<<"-"<<i<<" : "<<key[i]<<endl;
            }
        }
        cout<<"Minimum cost: "<<minCost<<endl;
    }

    void djisktra(int start){
        vector<int> dist(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(dist[u] < d) continue;

            for(auto &neighbour : adjList[u]){
                int v = neighbour.first;
                int w = neighbour.second;

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout<<"Djisktra shortest path"<<endl;
        for(int i=0;i<v;i++){
            cout<<start<<"-"<<i<<" : "<<dist[i]<<endl;
        }
    }
};

int main(){
    int v;
    cout<<"Enter number of vertices: ";
    cin>>v;

    Graph g(v);

    while(true){
        cout<<"--Menu--"<<endl;
        cout<<"1.Add Edge"<<endl;
        cout<<"2.Prims MST"<<endl;
        cout<<"3.Djisktra"<<endl;
        cout<<"4.Exit"<<endl;

        int choice;
        cout<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        int src, des, w, start;
        switch(choice){
        case 1:
            cout<<"Enter(src, des, weight): ";
            cin>>src>>des>>w;
            g.addEdge(src, des, w);
            break;
        
        case 2:
            cout<<"Enter start index: ";
            cin>>start;
            g.primsMST(start);
            break;
        
        case 3:
            cout<<"Enter start index: ";
            cin>>start;
            g.djisktra(start);
            break;
        
        case 4:
            cout<<"Existing...."<<endl;
            return 0;
            break;

        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}