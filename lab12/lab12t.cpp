#include <iostream>
#include <cstring>

using namespace std;

struct Pass {
    char surname[30];
    int items;
    double weight;
};

struct Node {
    Pass data;
    Node* left;
    Node* right;
};

void insertByName(Node*& root, Pass p) {
    if (!root) {
        root = new Node;
        root->data = p;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (strcmp(p.surname, root->data.surname) < 0) {
        insertByName(root->left, p);
    } else {
        insertByName(root->right, p);
    }
}

void insertByItems(Node*& root, Pass p) {
    if (!root) {
        root = new Node;
        root->data = p;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (p.items < root->data.items) {
        insertByItems(root->left, p);
    } else {
        insertByItems(root->right, p);
    }
}

void printTree(Node* root) {
    if (root) {
        printTree(root->left);
        cout << root->data.surname << " | " << root->data.items << " | " << root->data.weight << "\n";
        printTree(root->right);
    }
}

void getStats(Node* root, double& sum, int& count) {
    if (root) {
        sum += root->data.weight;
        count++;
        getStats(root->left, sum, count);
        getStats(root->right, sum, count);
    }
}

void transfer(Node* root1, Node*& root2) {
    if (root1) {
        insertByItems(root2, root1->data);
        transfer(root1->left, root2);
        transfer(root1->right, root2);
    }
}

void deleteTree(Node*& root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

int main() {
    Node* tree1 = NULL;
    Node* tree2 = NULL;

    Pass p1 = {"Zalizniak", 2, 12.5};
    Pass p2 = {"Batiuk", 3, 20.0};
    Pass p3 = {"Fedyna", 4, 25.5};
    Pass p4 = {"Hrytsak", 1, 7.5};
    Pass p5 = {"Lozynskyi", 2, 15.0};

    insertByName(tree1, p1);
    insertByName(tree1, p2);
    insertByName(tree1, p3);
    insertByName(tree1, p4);
    insertByName(tree1, p5);

    cout << "Derevo 1 (posortovane za prizvyshchem):\n";
    printTree(tree1);

    double sum = 0;
    int count = 0;
    getStats(tree1, sum, count);
    if (count > 0) {
        cout << "\nSerednya vaga bagazhu: " << sum / count << "\n\n";
    }

    transfer(tree1, tree2);
    
    cout << "Vydalennya Dereva 1...\n\n";
    deleteTree(tree1);

    cout << "Derevo 2 (posortovane za kilkistyu rechey):\n";
    printTree(tree2);

    deleteTree(tree2);

    return 0;
}