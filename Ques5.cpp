#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

bool hasLoop(Node* head) {
    unordered_set<Node*> visited;

    while (head != NULL) {
        if (visited.count(head))
            return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "List 1 has loop? "
         << (hasLoop(head1) ? "Yes" : "No") << endl;

    Node* head2 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    head2->next = n2;
    n2->next = n3;
    n3->next = n4;

    n4->next = n2;

    cout << "List 2 has loop? "
         << (hasLoop(head2) ? "Yes" : "No") << endl;

    return 0;
}
