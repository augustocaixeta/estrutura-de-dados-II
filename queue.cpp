#include <stdio.h>

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

struct Queue {
    Node *start;
    Node *end;
    int size;

    Queue() {
        start = NULL;
        end = NULL;
        size = 0;
    }

    int empty() {
        return start == NULL && end == NULL;
    }

    void push(int value) {
        Node *n = new Node(value);
        if (empty()) {
            start = n;
        } else {
            end->next = n;
        }
        end = n;
        size++;
        return 1;
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node *aux = start;
        start = start->next;
        delete(aux);
        size--;
        return 1;
    }

    void print() {
        if (empty()) {
            return;
        }
        Node *aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
        return 1;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.print();
}
