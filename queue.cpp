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

    int push(int value) {
        Node *n = new Node(value);
        if (!n) {
            return 0;
        }
        if (empty()) {
            start = n;
        } else {
            end->next = n;
        }
        end = n;
        size++;
        return 1;
    }

    int pop() {
        if (empty()) {
            return 0;
        }
        Node *aux = start;
        start = start->next;
        delete(aux);
        size--;
        return 1;
    }

    int print() {
        if (empty()) {
            return 0;
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
