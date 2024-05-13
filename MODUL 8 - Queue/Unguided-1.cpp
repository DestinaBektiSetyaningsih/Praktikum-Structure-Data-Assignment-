#include <iostream>

struct QueueNode {
    std::string data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* back;
    int size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

    ~Queue() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 5; 
    }

    void enqueue(std::string data) {
        if (isFull()) {
            std::cout << "Antrian Penuh" << std::endl;
            return;
        }

        QueueNode* newNode = new QueueNode();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }

        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong" << std::endl;
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty()) {
            back = nullptr;
        }
    }

    int count() {
        return size;
    }

    void clear() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        back = nullptr;
        size = 0;
    }

    void view() {
        std::cout << "Data antrian teller: " << std::endl;
        QueueNode* temp = front;
        int i = 1;
        while (temp != nullptr) {
            std::cout << i << ". " << temp->data << std::endl;
            temp = temp->next;
            i++;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue("Andi");
    queue.enqueue("Maya");                                             
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    queue.dequeue();
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    queue.clear();
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    return 0;
}