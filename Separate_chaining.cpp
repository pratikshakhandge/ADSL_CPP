#include <iostream> 
using namespace std; 
class Node 
{ 
public: 
int productId; 
int quantity; 
Node* next; 
Node(int id, int qty) 
{ 
productId = id; 
quantity = qty; 
next = NULL; 
} 
}; 
class HashTable 
{ 
static const int size = 10; 
Node* table[size]; 
public: 
// Constructor 
HashTable() 
{ 
for (int i = 0; i < size; i++) 
table[i] = NULL; 
} 
// Hash function 
int hashFunction(int key) 
{ 
return key % size; 
} 
// Insert (Separate_chaining) 
void insert(int key, int qty) 
{ 
int index = hashFunction(key); 
Node* newNode = new Node(key, qty); 
newNode->next = table[index]; 
        table[index] = newNode; 
 
        cout << "Inserted Successfully\n"; 
    } 
 
    // Search 
    void search(int key) 
    { 
        int index = hashFunction(key); 
        Node* temp = table[index]; 
 
        while (temp != NULL) 
        { 
            if (temp->productId == key) 
            { 
                cout << "Product Found\n"; 
                cout << "Product ID: " << temp->productId 
                     << " Quantity: " << temp->quantity << endl; 
                return; 
            } 
            temp = temp->next; 
        } 
        cout << "Product not found\n"; 
    } 
 
    // Delete 
    void remove(int key) 
    { 
        int index = hashFunction(key); 
        Node* temp = table[index]; 
        Node* prev = NULL; 
 
        while (temp != NULL) 
        { 
            if (temp->productId == key) 
            { 
                if (prev == NULL) 
                    table[index] = temp->next; 
                else 
                    prev->next = temp->next; 
 
                delete temp; 
                cout << "Deleted Successfully\n"; 
                return; 
            } 
            prev = temp; 
            temp = temp->next; 
        } 
        cout << "Product not found\n"; 
    } 
 
    // Display 
    void display() 
    { 
        cout << "\nHash Table:\n"; 
        for (int i = 0; i < size; i++) 
        { 
            cout << i << " --> "; 
            Node* temp = table[i]; 
            while (temp != NULL) 
            { 
                cout << "[ID: " << temp->productId 
                     << ", Qty: " << temp->quantity << "] -> "; 
                temp = temp->next; 
            } 
            cout << "NULL\n"; 
        } 
    } 
}; 
 
int main() 
{ 
    HashTable h; 
    int ch, key, qty; 
 
    while (true) 
    { 
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n"; 
        cout << "Enter choice: "; 
        cin >> ch; 
 
        switch (ch) 
        { 
        case 1: 
            cout << "Enter Product ID: "; 
            cin >> key; 
            cout << "Enter Quantity: "; 
            cin >> qty; 
            h.insert(key, qty); 
            break; 
 
        case 2: 
            cout << "Enter Product ID to search: "; 
            cin >> key; 
            h.search(key); 
            break; 
 
        case 3: 
            cout << "Enter Product ID to delete: "; 
            cin >> key; 
            h.remove(key); 
            break; 
 
        case 4: 
            h.display(); 
            break; 
 
        case 5: 
            cout << "Exit\n"; 
            return 0; 
 
        default: 
            cout << "Invalid choice\n"; 
        } 
    }}