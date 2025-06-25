#include <stdio.h>

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

struct Stack {
    Node *end;
    int size;

    Stack() {
        end = NULL;
        size = 0;
    }

    // O(1)
    int empty() {
        return end == NULL;
    }

    // O(1)
    int push(int value) {
        Node *n = new Node(value);
        if (!n) {
            return 0;
        }
        n->next = end;
        end = n;
        size++;
        return 1;
    }

    // O(1)
    int pop() {
        if (empty()) {
            return 0;
        }
        Node *aux = end;
        end = end->next;
        delete(aux);
        size--;
        return 1;
    }

    // O(n)
    int print() {
        if (empty()) {
            return 0;
        }
        Node *aux = end;
        while (aux != NULL) {
            printf("%d\n", aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
        return 1;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.print();
}
