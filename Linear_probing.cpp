#include <iostream>
using namespace std;

class HashTable
{
    int productId[10];
    int quantity[10];
    int size = 10;

public:
    // Constructor
    HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            productId[i] = -1;   // Empty
            quantity[i] = 0;
        }
    }

    // Hash function
    int hashFunction(int key)
    {
        return key % size;
    }

    // Insert (Linear Probing)
    void insert(int key, int qty)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i) % size;

            if (productId[newIndex] == -1 || productId[newIndex] == -2)
            {
                productId[newIndex] = key;
                quantity[newIndex] = qty;
                cout << "Inserted Successfully\n";
                return;
            }
        }
        cout << "Hash table is full\n";
    }
    // Search
    void search(int key)
    {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i) % size;

            if (productId[newIndex] == key)
            {
                cout << "Product Found\n";
                cout << "Product ID: " << productId[newIndex]
                     << " Quantity: " << quantity[newIndex] << endl;
                return;
            }
        }
        cout << "Product not found\n";
    }
    // Delete
    void remove(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int newIndex = (index + i) % size;

            if (productId[newIndex] == key)
            {
                productId[newIndex] = -2;   // Deleted
                quantity[newIndex] = 0;
                cout << "Deleted Successfully\n";
                return;
            }
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
            if (productId[i] == -1)
                cout << "Empty";
            else if (productId[i] == -2)
                cout << "Deleted";
            else
                cout << "ID: " << productId[i]
                     << " Quantity: " << quantity[i];
            cout << endl;
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
    }
}