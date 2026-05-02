#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int V = 5;

// рис. 10.1
int adjMatrix[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 1, 1, 0}
};

bool visitedDFS[V];
bool visitedBFS[V];

void DFS(int v, int& dfsNum, int dfsOrder[]) {
    visitedDFS[v] = true;
    dfsOrder[v] = dfsNum++;
    cout << "v" << v + 1 << " ";

    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !visitedDFS[i]) {
            DFS(i, dfsNum, dfsOrder);
        }
    }
}

void BFS(int startVertex) {
    queue<int> q;
    int bfsOrder[V];
    int bfsNum = 1;

    visitedBFS[startVertex] = true;
    q.push(startVertex);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        bfsOrder[v] = bfsNum++;
        cout << "v" << v + 1 << " ";

        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] == 1 && !visitedBFS[i]) {
                visitedBFS[i] = true;
                q.push(i);
            }
        }
    }
    
    cout << "\nBFS-nomery:\n";
    for (int i = 0; i < V; i++) {
        cout << "BFS(v" << i + 1 << ") = " << bfsOrder[i] << "\n";
    }
}

int main() {
    int dfsOrder[V];
    int dfsNum = 1;
    
    for (int i = 0; i < V; i++) {
        visitedDFS[i] = false;
        visitedBFS[i] = false;
    }

    cout << "=== Obhid grafa v glybynu (DFS) ===\n";
    cout << "Poryadok obhodu: ";
    DFS(0, dfsNum, dfsOrder); 
    
    cout << "\nDFS-nomery:\n";
    for (int i = 0; i < V; i++) {
        cout << "DFS(v" << i + 1 << ") = " << dfsOrder[i] << "\n";
    }

    cout << "\n=== Obhid grafa v shyrynu (BFS) ===\n";
    cout << "Poryadok obhodu: ";
    BFS(0); 

    return 0;
}