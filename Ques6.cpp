#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

bool checkDuplicate(Node* root, unordered_set<int> &s) {
    if (root == NULL)
        return false;

    if (s.count(root->data))
        return true;

    s.insert(root->data);

    return checkDuplicate(root->left, s) ||
           checkDuplicate(root->right, s);
}

int main() {
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(8);
    root1->left->left = new Node(1);
    root1->left->right = new Node(4);

    unordered_set<int> s1;
    cout << "Tree 1: "
         << (checkDuplicate(root1, s1) ? "Duplicates Found" : "No Duplicates")
         << endl;

    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(10);  

    unordered_set<int> s2;
    cout << "Tree 2: "
         << (checkDuplicate(root2, s2) ? "Duplicates Found" : "No Duplicates")
         << endl;


    return 0;
}
