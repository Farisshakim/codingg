#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;          
    int maxSize;        
    int currentSize;    

public:
    Stack(int size) {
        top = nullptr;
        maxSize = size;    
        currentSize = 0;   
    }

    ~Stack() {
        destroyStack();
    }

    // Push Stack
    void pushStack(int value) {
        if (isFull()) {
            cout << "Stack penuh" << endl;
            return;
        }
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Alokasi memori gagal" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        currentSize++;
        cout << "Data " << value << " berhasil ditambahkan ke stack" << endl;
    }

    // Pop Stack
    void popStack() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Data " << temp->data << " berhasil dihapus dari stack" << endl;
        delete temp;
        currentSize--;
    }

    // Stack Top
    void stackTop() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
        } else {
            cout << "Elemen teratas stack: " << top->data << endl;
        }
    }

    // Empty Stack
    bool isEmpty() {
        return top == nullptr;
    }

    // Full Stack
    bool isFull() {
        return currentSize >= maxSize;
    }

    // Stack Count
    int stackCount() {
        return currentSize;
    }

    // Destroy Stack
    void destroyStack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        currentSize = 0;
        cout << "Stack berhasil dikosongkan." << endl;
    }
};

int main() {
    int size;
    cout << "Tentukan tinggi stack: ";
    cin >> size;

    Stack stack(size); 
    char choice;
    int value;
    do {
        cout << "\nMenu Operasi Stack:\n";
        cout << "1. Push stack\n";
        cout << "2. Pop stack\n";
        cout << "3. Stack top\n";
        cout << "4. Empty stack\n";
        cout << "5. Full stack\n";
        cout << "6. Stack count\n";
        cout << "7. Destroy stack\n";
        cout << "0. Keluar\n";
        cout << ": ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> value;
                stack.pushStack(value);
                break;
            case '2':
                stack.popStack();
                break;
            case '3':
                stack.stackTop();
                break;
            case '4':
                if (stack.isEmpty()) {
                    cout << "Stack kosong." << endl;
                } else {
                    cout << "Stack tidak kosong." << endl;
                }
                break;
            case '5':
                if (stack.isFull()) {
                    cout << "Stack penuh." << endl;
                } else {
                    cout << "Stack tidak penuh." << endl;
                }
                break;
            case '6':
                cout << "Jumlah elemen dalam stack: " << stack.stackCount() << endl;
                break;
            case '7':
                stack.destroyStack();
                break;
            case '0':
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan OOT" << endl;
                break;
        }
    } while (choice != '0');

    return 0;
}


