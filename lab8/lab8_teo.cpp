#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int code;
    char surname[30];
    int items;
    double weight;
    Node* next;
};

void addNode(Node*& head, int c, const char* s, int i, double w) {
    Node* p = new Node;
    p->code = c;
    strcpy(p->surname, s);
    p->items = i;
    p->weight = w;
    p->next = NULL;
    
    if (!head) {
        head = p;
    } else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = p;
    }
}

void printList(Node* head) {
    Node* t = head;
    while (t) {
        cout << t->code << " | " << t->surname << " | " << t->items << " | " << t->weight << "\n";
        t = t->next;
    }
    cout << "----------------------------------\n";
}

void delNode(Node*& head, int c) {
    if (!head) return;
    if (head->code == c) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* t = head;
    while (t->next && t->next->code != c) {
        t = t->next;
    }
    if (t->next) {
        Node* d = t->next;
        t->next = d->next;
        delete d;
    }
}

void sortList(Node* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next) {
            if (curr->code > curr->next->code) {
                int tc = curr->code; 
                curr->code = curr->next->code; 
                curr->next->code = tc;
                
                char ts[30]; 
                strcpy(ts, curr->surname); 
                strcpy(curr->surname, curr->next->surname); 
                strcpy(curr->next->surname, ts);
                
                int ti = curr->items; 
                curr->items = curr->next->items; 
                curr->next->items = ti;
                
                double tw = curr->weight; 
                curr->weight = curr->next->weight; 
                curr->next->weight = tw;
                
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

Node* mergeLists(Node* h1, Node* h2) {
    Node* res = NULL;
    if (!h1) return h2;
    if (!h2) return h1;
    
    if (h1->code <= h2->code) {
        res = h1;
        res->next = mergeLists(h1->next, h2);
    } else {
        res = h2;
        res->next = mergeLists(h1, h2->next);
    }
    return res;
}

int main() {
    Node* list1 = NULL;
    addNode(list1, 105, "Halytskyi", 2, 15.5);
    addNode(list1, 102, "Lozynskyi", 1, 5.0);
    addNode(list1, 108, "Batiuk", 3, 20.0);

    Node* list2 = NULL;
    addNode(list2, 101, "Zalizniak", 2, 12.5);
    addNode(list2, 109, "Bilas", 1, 8.0);
    addNode(list2, 103, "Fedyna", 4, 25.5);

    cout << "Spysok 1 do sortuvannya:\n";
    printList(list1);
    
    sortList(list1);
    cout << "Spysok 1 pislya sortuvannya (za kodom):\n";
    printList(list1);

    sortList(list2);
    cout << "Spysok 2 pislya sortuvannya (za kodom):\n";
    printList(list2);

    Node* merged = mergeLists(list1, list2);
    cout << "Obyednanyy vidkalybrovanyi spysok:\n";
    printList(merged);

    cout << "Vyluchayemo element z kodom 105:\n";
    delNode(merged, 105);
    printList(merged);

    return 0;
}