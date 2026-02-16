#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* firstChild;
    Node* nextSibling;

    // Constructor
    Node(string n) {
        name = n;
        firstChild = NULL;
        nextSibling = NULL;
    }
};

// Print tree nodes
void printTree(Node* root, int level = 0) {
    if (root == NULL)
        return;

    // Indentation
    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << root->name << endl;

    // Recursive calls
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int main() {

    // Book
    Node* book = new Node("Book");

    // Chapters
    Node* ch1 = new Node("Chapter 1");
    Node* ch2 = new Node("Chapter 2");
    book->firstChild = ch1;
    ch1->nextSibling = ch2;

    // Sections of Chapter 1
    Node* sec11 = new Node("Section 1.1");
    Node* sec12 = new Node("Section 1.2");
    ch1->firstChild = sec11;
    sec11->nextSibling = sec12;

    // Subsections of Section 1.1
    Node* sub111 = new Node("Subsection 1.1.1");
    Node* sub112 = new Node("Subsection 1.1.2");
    sec11->firstChild = sub111;
    sub111->nextSibling = sub112;

    // Section of Chapter 2
    Node* sec21 = new Node("Section 2.1");
    ch2->firstChild = sec21;

    cout << "Book Structure:\n";
    printTree(book);

    return 0;
}
