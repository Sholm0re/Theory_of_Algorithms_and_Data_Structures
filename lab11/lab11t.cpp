#include <iostream>
#include <cstring>

using namespace std;

struct Pass {
    int code;
    char surname[30];
    int items;
    double weight;
};

struct DNode {
    Pass data;
    DNode* prev;
    DNode* next;
};

class Deque {
    DNode* head;
    DNode* tail;
    int count;
public:
    Deque() { 
        head = NULL; 
        tail = NULL; 
        count = 0;
    }

    void push_front(int c, const char* s, int i, double w) {
        DNode* p = new DNode;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;
        p->prev = NULL;
        p->next = head;

        if (head) head->prev = p;
        head = p;
        if (!tail) tail = p;
        count++;
    }

    void push_back(int c, const char* s, int i, double w) {
        DNode* p = new DNode;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;
        p->next = NULL;
        p->prev = tail;

        if (tail) tail->next = p;
        tail = p;
        if (!head) head = p;
        count++;
    }

    void pop_front() {
        if (!head) return;
        DNode* p = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete p;
        count--;
    }

    void pop_back() {
        if (!tail) return;
        DNode* p = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete p;
        count--;
    }

    void print() {
        DNode* p = head;
        while (p) {
            cout << p->data.code << " | " << p->data.surname << " | " << p->data.items << " | " << p->data.weight << "\n";
            p = p->next;
        }
        cout << "-----------------------\n";
    }
};

struct PNode {
    Pass data;
    PNode* next;
};

class PriorityQueue {
    PNode* head;
public:
    PriorityQueue() { head = NULL; }

    void enqueue(int c, const char* s, int i, double w) {
        PNode* p = new PNode;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;

        if (!head || head->data.items < p->data.items) {
            p->next = head;
            head = p;
        } else {
            PNode* curr = head;
            while (curr->next && curr->next->data.items >= p->data.items) {
                curr = curr->next;
            }
            p->next = curr->next;
            curr->next = p;
        }
    }

    void dequeue() {
        if (!head) return;
        PNode* p = head;
        head = head->next;
        delete p;
    }

    void print() {
        PNode* p = head;
        while (p) {
            cout << p->data.code << " | " << p->data.surname << " | " << p->data.items << " | " << p->data.weight << "\n";
            p = p->next;
        }
        cout << "-----------------------\n";
    }
};

int main() {
    cout << "=== TESTUVANNYA DEKU ===\n";
    Deque dq;
    cout << "Dodayemo v kinec (push_back):\n";
    dq.push_back(101, "Zalizniak", 2, 12.5);
    dq.push_back(102, "Lozynskyi", 1, 5.0);
    dq.print();

    cout << "Dodayemo na pochatok (push_front):\n";
    dq.push_front(103, "Fedyna", 4, 25.5);
    dq.print();

    cout << "Vydalyayemo z kincya (pop_back):\n";
    dq.pop_back();
    dq.print();

    cout << "Vydalyayemo z pochatku (pop_front):\n";
    dq.pop_front();
    dq.print();

    cout << "\n=== TESTUVANNYA CHERHY Z PRIORYTETOM ===\n";
    cout << "Priorytet: Kilkist rechey (chim bilshe, tym blyzhche do golovy)\n";
    PriorityQueue pq;
    pq.enqueue(101, "Zalizniak", 2, 12.5);
    pq.enqueue(102, "Lozynskyi", 1, 5.0);
    pq.enqueue(103, "Fedyna", 4, 25.5);
    pq.enqueue(104, "Hrytsak", 3, 15.0);
    pq.print();

    cout << "Vydalyayemo element z nayvyshchym priorytetom (dequeue):\n";
    pq.dequeue();
    pq.print();

    return 0;
}