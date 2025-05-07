#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int a, int b) {
        if (a < v && b < v) {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        } else {
            cout << "Invalid edge!" << endl;
        }
    }

    void printGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < v; i++) {
            cout << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        if (start >= v) {
            cout << "Invalid start vertex!" << endl;
            return;
        }
        vector<bool> visited(v, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for (int i : adjList[temp]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    void DFS(int start) {
        if (start >= v) {
            cout << "Invalid start vertex!" << endl;
            return;
        }
        vector<bool> visited(v, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, choice;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Print Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v;
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g.addEdge(u, v);
            break;
        }
        case 2:
            g.printGraph();
            break;
        case 3: {
            int start;
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            g.BFS(start);
            break;
        }
        case 4: {
            int start;
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            g.DFS(start);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}