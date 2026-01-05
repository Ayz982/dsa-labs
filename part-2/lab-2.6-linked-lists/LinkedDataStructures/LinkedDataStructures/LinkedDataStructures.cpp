#include <iostream>
#include <string>
#include <utility>

using namespace std;

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* pNext;

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node* head;
    int Size;

public:
    List();
    ~List();

    void clear();
    void pop_front();
    void push_front(T data);
    void removeAt(int index);
    void pop_back();
    void push_back(T data);
    void insert(T data, int index);
    int getSize() const { return Size; }

    void selectionSort();
    void print(const string message);

    T& operator[](const int index); 
};

int main()
{
    List<string> words;

    words.push_back("banana");
    words.push_back("apple");
    words.push_back("cherry");
    words.push_back("data");

    cout <<"Size " << words.getSize() << "\n";
    words.print("Initial list");

    words.selectionSort();
    words.print("Sorted list");

    return 0;
}

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::clear()
{
    while (Size) {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front()
{
    if (head == nullptr) return;
    Node* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node(data, head);
    Size++;
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index < 0 || index >= Size) return;

    if (index == 0) {
        pop_front();
    }
    else {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    if (Size == 0) return;
    removeAt(Size - 1);
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {
        head = new Node(data);
        
    }
    else {
        Node* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index < 0 || index > Size) return;

    if (index == 0) {
        push_front(data);
    }
    else {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template<typename T>
void List<T>::selectionSort()
{
    if (!head || !head->pNext) return;

    for (Node* i = head; i->pNext != nullptr; i = i->pNext) {
        Node* minNode = i;

        for (Node* j = i->pNext; j != nullptr; j = j->pNext) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }

        if (minNode != i) {
            T temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}

template<typename T>
void List<T>::print(const string message)
{
    if (head == nullptr) {
        cout << message << ": List is empty." << endl;
        return;
    }

    cout << message << ": [ ";

    Node* current = head;

    while (current != nullptr) {
        cout << current->data;
        if (current->pNext != nullptr) {
            cout << " -> ";
        }
        current = current->pNext;
    }

    cout << " ]" << endl;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    if (index < 0 || index >= Size) {
        throw out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->pNext;
    }
    return current->data;
}

