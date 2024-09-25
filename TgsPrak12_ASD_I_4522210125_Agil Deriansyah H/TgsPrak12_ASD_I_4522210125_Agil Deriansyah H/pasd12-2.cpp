#include <iostream>
using namespace std;

struct node {
    int info;
    struct node *next;
};

class stack {
    struct node *top;
public:
    stack();
    void push(int);
    int pop();
    bool isempty();
    void display();
};

stack::stack() {
    top = NULL;
}

void stack::push(int data) {
    node *p = new node;
    if (p == NULL) {
        cout << "Memori Penuh" << endl;
        exit(0);
    }
    p->info = data;
    p->next = top;
    top = p;
}

int stack::pop() {
    if (top == NULL) {
        cout << "Stack Kosong" << endl;
        return -1;
    }
    node *temp = top;
    top = top->next;
    int value = temp->info;
    delete temp;
    return value;
}

bool stack::isempty() {
    return (top == NULL);
}

void stack::display() {
    if (top == NULL) {
        cout << "Tidak Ada Tampilan" << endl;
        return;
    }
    cout << "Isi Stack:" << endl;
    node *p = top;
    while (p != NULL) {
        cout << p->info << endl;
        p = p->next;
    }
}

class graph {
private:
    int n;
    int **A;
public:
    graph(int size = 2);
    ~graph();
    bool isconnected(int, int);
    void addedge(int x, int y);
    void dfs(int, int);
};

graph::graph(int size) {
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (int i = 0; i < n; ++i)
        A[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = 0;
}

graph::~graph() {
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
}

bool graph::isconnected(int x, int y) {
    return (A[x - 1][y - 1] == 1);
}

void graph::addedge(int x, int y) {
    A[x - 1][y - 1] = A[y - 1][x - 1] = 1;
}

void graph::dfs(int x, int required) {
    stack s;
    bool *visited = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    cout << "Depth First Search - DFS - Awal Vertex = " << x << endl;
    while (!s.isempty()) {
        int k = s.pop();
        cout << k << " ";
        if (k == required) break;
        for (int i = n; i >= 1; --i) {
            if (isconnected(k, i) && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
    delete[] visited;
}

int main() {
    graph g(8);
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 5);
    g.addedge(2, 6);
    g.addedge(4, 7);
    g.addedge(2, 8);
    g.dfs(1, 2);
    return 0;
}
