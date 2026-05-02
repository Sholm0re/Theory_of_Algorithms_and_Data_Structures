#include <iostream>
#include <cstring>

using namespace std;

struct Pass {
    int code;
    char surname[30];
    int items;
    double weight;
};

struct Node {
    Pass data;
    Node* prev;
    Node* next;
};

class List {
public:
    Node* head;
    Node* tail;

    List() { 
        head = NULL; 
        tail = NULL; 
    }

    void clear() {
        Node* p = head;
        while (p) {
            Node* t = p;
            p = p->next;
            delete t;
        }
        head = NULL;
        tail = NULL;
    }

    void addBack(int c, const char* s, int i, double w) {
        Node* p = new Node;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;
        p->next = NULL;

        if (!head) {
            p->prev = NULL;
            head = p;
            tail = p;
        } else {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    }

    void print() {
        Node* p = head;
        while (p) {
            cout << p->data.code << " | " << p->data.surname << " | " << p->data.items << " | " << p->data.weight << "\n";
            p = p->next;
        }
        cout << "-----------------------\n";
    }

    void remove(int c) {
        Node* p = head;
        while (p) {
            if (p->data.code == c) {
                if (p->prev) p->prev->next = p->next;
                else head = p->next;

                if (p->next) p->next->prev = p->prev;
                else tail = p->prev;

                delete p;
                return;
            }
            p = p->next;
        }
    }

    int count() {
        int n = 0;
        Node* p = head;
        while (p) { 
            n++; 
            p = p->next; 
        }
        return n;
    }

    void swapAfter(int p_idx) {
        Node* p = head;
        for (int i = 0; i < p_idx && p; i++) p = p->next;
        if (!p || !p->next || !p->next->next) return;

        Node* a = p->next;
        Node* b = a->next;

        a->next = b->next;
        if (b->next) b->next->prev = a;
        else tail = a;

        b->prev = a->prev;
        a->prev->next = b;

        b->next = a;
        a->prev = b;
    }

    void merge(List& other) {
        if (!other.head) return;
        if (!head) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
        other.head = NULL;
        other.tail = NULL;
    }

    Node* getKth(int k) {
        Node* p = head;
        for (int i = 0; i < k && p; i++) p = p->next;
        return p;
    }

    void insertBeforeKth(int k, int c, const char* s, int i, double w) {
        if (k == 0 || !head) {
            Node* p = new Node;
            p->data.code = c;
            strcpy(p->data.surname, s);
            p->data.items = i;
            p->data.weight = w;
            p->prev = NULL;
            p->next = head;
            if (head) head->prev = p;
            head = p;
            if (!tail) tail = p;
            return;
        }

        Node* target = getKth(k);
        if (!target) {
            addBack(c, s, i, w);
            return;
        }

        Node* p = new Node;
        p->data.code = c;
        strcpy(p->data.surname, s);
        p->data.items = i;
        p->data.weight = w;

        p->prev = target->prev;
        p->next = target;
        target->prev->next = p;
        target->prev = p;
    }

    List split(int k) {
        List newList;
        Node* target = getKth(k);
        if (!target) return newList;

        newList.head = target;
        newList.tail = tail;

        tail = target->prev;
        if (tail) tail->next = NULL;
        else head = NULL;

        target->prev = NULL;
        return newList;
    }

    List copy() {
        List newList;
        Node* p = head;
        while (p) {
            newList.addBack(p->data.code, p->data.surname, p->data.items, p->data.weight);
            p = p->next;
        }
        return newList;
    }

    Node* find(int c) {
        Node* p = head;
        while (p) {
            if (p->data.code == c) return p;
            p = p->next;
        }
        return NULL;
    }
};

int main() {
    List l1;
    l1.addBack(101, "Zalizniak", 2, 12.5);
    l1.addBack(102, "Lozynskyi", 1, 5.0);
    l1.addBack(103, "Fedyna", 4, 25.5);

    cout << "Pochatkovy spysok:\n";
    l1.print();

    cout << "Kilkist elementiv: " << l1.count() << "\n\n";

    cout << "Dodayemo v kinets (104, Hrytsak):\n";
    l1.addBack(104, "Hrytsak", 1, 7.5);
    l1.print();

    cout << "Vstavka pered 1-m indexom (105, Batiuk):\n";
    l1.insertBeforeKth(1, 105, "Batiuk", 3, 20.0);
    l1.print();

    cout << "Vyluchennya elementa z kodom 102:\n";
    l1.remove(102);
    l1.print();

    cout << "Obmin susidiv pislya 0-go indexa:\n";
    l1.swapAfter(0);
    l1.print();

    cout << "Kopia spysku:\n";
    List l2 = l1.copy();
    l2.print();

    cout << "Rozbyttya l2 z indexu 2:\n";
    List l3 = l2.split(2);
    cout << "Persha chastyna:\n";
    l2.print();
    cout << "Druga chastyna:\n";
    l3.print();

    cout << "Zlyttya nazad:\n";
    l2.merge(l3);
    l2.print();

    cout << "Poshuk koda 104:\n";
    Node* f = l2.find(104);
    if (f) cout << "Znaydeno: " << f->data.surname << "\n\n";

    cout << "Ochyshchennya spyskiv...\n";
    l1.clear();
    l2.clear();

    return 0;
}