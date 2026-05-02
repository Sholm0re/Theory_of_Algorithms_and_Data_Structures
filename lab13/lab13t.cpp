#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// рис. 10.1
const int V = 5;
const int E = 7;

int adjMatrix[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 1, 1, 0}
};

int incMatrix[V][E];

void buildIncidenceFromAdjacency() {
    int edgeIndex = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            incMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] == 1) {
                incMatrix[i][edgeIndex] = 1;
                incMatrix[j][edgeIndex] = 1;
                edgeIndex++;
            }
        }
    }
}

void printIncidenceMatrix() {
    cout << "--- Matrytsya incydentnosti ---\n";
    for (int i = 0; i < V; i++) {
        cout << "v" << i + 1 << " | ";
        for (int j = 0; j < E; j++) {
            cout << incMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void buildEdgeListFromIncidence() {
    cout << "--- Spysok reber (z matrytsi incydentnosti) ---\n";
    for (int j = 0; j < E; j++) {
        int v1 = -1, v2 = -1;
        for (int i = 0; i < V; i++) {
            if (incMatrix[i][j] == 1) {
                if (v1 == -1) v1 = i + 1;
                else v2 = i + 1;
            }
        }
        cout << "e" << j + 1 << ": (" << v1 << ", " << v2 << ")\n";
    }
    cout << "\n";
}

void buildAdjacencyListFromAdjacencyMatrix() {
    cout << "--- Spysok sumizhnosti (z matrytsi sumizhnosti) ---\n";
    for (int i = 0; i < V; i++) {
        cout << "v" << i + 1 << " -> ";
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] == 1) {
                cout << "v" << j + 1 << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void buildAdjacencyMatrixFromIncidence() {
    int newAdj[V][V] = {0};
    for (int j = 0; j < E; j++) {
        int v1 = -1, v2 = -1;
        for (int i = 0; i < V; i++) {
            if (incMatrix[i][j] == 1) {
                if (v1 == -1) v1 = i;
                else v2 = i;
            }
        }
        if (v1 != -1 && v2 != -1) {
            newAdj[v1][v2] = 1;
            newAdj[v2][v1] = 1;
        }
    }

    cout << "--- Vidnovlena matrytsya sumizhnosti ---\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << newAdj[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void buildEdgeListFromAdjacencyMatrix() {
    cout << "--- Spysok reber (z matrytsi sumizhnosti) ---\n";
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] == 1) {
                cout << "(" << i + 1 << ", " << j + 1 << ")\n";
            }
        }
    }
    cout << "\n";
}

void buildAdjacencyListFromIncidence() {
    cout << "--- Spysok sumizhnosti (z matrytsi incydentnosti) ---\n";
    for (int i = 0; i < V; i++) {
        cout << "v" << i + 1 << " -> ";
        for (int j = 0; j < E; j++) {
            if (incMatrix[i][j] == 1) {
                for (int k = 0; k < V; k++) {
                    if (incMatrix[k][j] == 1 && k != i) {
                        cout << "v" << k + 1 << " ";
                    }
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cout << "=== Pochatkova matrytsya sumizhnosti ===\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    buildIncidenceFromAdjacency();
    printIncidenceMatrix();
    
    buildEdgeListFromIncidence();
    buildAdjacencyListFromAdjacencyMatrix();
    
    buildAdjacencyMatrixFromIncidence();
    buildEdgeListFromAdjacencyMatrix();
    buildAdjacencyListFromIncidence();

    return 0;
}