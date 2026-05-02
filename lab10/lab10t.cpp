#include <iostream>
#include <cstring>

using namespace std;

struct Pass {
    int code;
    char surname[30];
    int items;
    double weight;
};

struct StackNode {
    Pass data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { top = NULL; }
    
    void push(int c, const char* s, int i, double w) {
        StackNode* p = new StackNode;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;
        p->next = top;
        top = p;
    }
    
    void pop() {
        if (!top) return;
        StackNode* p = top;
        top = top->next;
        delete p;
    }
    
    void print() {
        if (!top) {
            cout << "Stek porozhniy!\n";
            return;
        }
        StackNode* p = top;
        cout << "Stan steku (vid vershyny do dna):\n";
        while (p) {
            cout << p->data.code << " | " << p->data.surname << " | " << p->data.items << " | " << p->data.weight << "\n";
            p = p->next;
        }
        cout << "-----------------------\n";
    }
    
    bool isEmpty() {
        return top == NULL;
    }
};

struct QueueNode {
    Pass data;
    QueueNode* next;
};

class Queue {
    QueueNode* head;
    QueueNode* tail;
public:
    Queue() { head = NULL; tail = NULL; }
    
    void enqueue(int c, const char* s, int i, double w) {
        QueueNode* p = new QueueNode;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;
        p->next = NULL;
        
        if (!head) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    
    void dequeue() {
        if (!head) return;
        QueueNode* p = head;
        head = head->next;
        if (!head) tail = NULL;
        delete p;
    }
    
    void print() {
        if (!head) {
            cout << "Cherha porozhnya!\n";
            return;
        }
        QueueNode* p = head;
        cout << "Stan cherhy (vid golovy do hvosta):\n";
        while (p) {
            cout << p->data.code << " | " << p->data.surname << " | " << p->data.items << " | " << p->data.weight << "\n";
            p = p->next;
        }
        cout << "-----------------------\n";
    }
    
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    cout << "=== TESTUVANNYA STEKU (LIFO) ===\n";
    Stack s;
    s.push(101, "Zalizniak", 2, 12.5);
    s.push(102, "Lozynskyi", 1, 5.0);
    s.push(103, "Fedyna", 4, 25.5);
    s.print();
    
    cout << "Vydalyayemo element (Pop):\n";
    s.pop();
    s.print();
    
    cout << "\n=== TESTUVANNYA CHERHY (FIFO) ===\n";
    Queue q;
    q.enqueue(101, "Zalizniak", 2, 12.5);
    q.enqueue(102, "Lozynskyi", 1, 5.0);
    q.enqueue(103, "Fedyna", 4, 25.5);
    q.print();
    
    cout << "Vydalyayemo element (Dequeue):\n";
    q.dequeue();
    q.print();
    
    return 0;
}