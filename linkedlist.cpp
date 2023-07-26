#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    Node* nextPointer;
};

class Queue {
private:
    Node* frontPointer;
    Node* rearPointer;
    int count;

public:
    Queue() {
        frontPointer = nullptr;
        rearPointer = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Add data to the rear of the queue
    void enqueue(string data) {
        Node* nodePointer = new Node{data, nullptr};

        if (isEmpty()) {
            frontPointer = nodePointer;
            rearPointer = nodePointer;
        } else {
            rearPointer->nextPointer = nodePointer;
            rearPointer = nodePointer;
        }
    }

    // Look at the front item
    string peek() {
        if (!isEmpty()) {
            return frontPointer->data;
        }
        return ""; // Return an empty string to indicate an empty queue.
    }

    // Remove front item from the queue
    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPointer;
            frontPointer = frontPointer->nextPointer;
            delete temp;
        }
    }

    bool isEmpty() {
        return frontPointer == nullptr;
    }

    // Look at all items in the queue
    void print() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
        } else {
            Node* temp = frontPointer;
            while (temp != nullptr) {
                cout << "[" << temp->data << "] ";
                temp = temp->nextPointer;
            }
            cout << endl;
        }
    }

    int size() {
        int count = 0;
        Node* temp = frontPointer;
        while (temp != nullptr) {
            count++;
            temp = temp->nextPointer;
        }
        return count;
    }
};

int main() {
    //Test 1 Queue starts empty
    Queue queue;
    queue.print();

    //Test 2 Queue with one node
    queue.enqueue("Apple");
    cout << queue.size() << " item(s): ";
    queue.print();

    //Test 3 Removing one node;queue becomes empty
    queue.dequeue();
    queue.print();

    // Test 4 Trying to dequeue from empty (no crash)
    queue.dequeue();

    //Test 5 Trying to peek empty queue (no crash)
    cout << queue.peek();

    //Test 6 Adding three nodes
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    cout << queue.size() << " item(s): ";
    queue.print();

    //Test 7 Removing one node
    queue.dequeue();
    cout << queue.size() << " item(s): ";
    queue.print();

    // Test 8 Adding one additional node
    queue.enqueue("Elderberry");
    cout << queue.size() << " item(s): ";
    queue.print();
    // Test 9 - Peeking first node
    cout << "Peek: " << queue.peek() << endl;

    // Test 10 - Test enqueue and peek
    queue.enqueue("Grapes");
    cout << "Peek after enqueue: " << queue.peek() << endl;

    // Test 11 - Test dequeue, size, and print
    queue.dequeue();
    cout << "Queue size after dequeue: " << queue.size() << " item(s)" << endl;
    cout << "Updated queue contents after dequeue: ";
    queue.print();

    // Test 12 - Test multiple enqueues and dequeues
    queue.enqueue("Fig");
    queue.dequeue();
    queue.enqueue("Grapefruit");
    queue.enqueue("Honeydew");
    queue.dequeue();
    cout << "Queue size after multiple operations: " << queue.size() << " item(s)" << endl;
    cout << "Updated queue contents after multiple operations: ";
    queue.print();

    // Test 13 - Enqueue fruits from a library or dictionary
    vector<string> fruitLibrary = {
        "Apple", "Banana", "Cherry", "Date", "Elderberry",
        "Fig", "Grapes", "Honeydew", "Kiwi", "Lemon",
        "Mango", "Orange", "Pineapple", "Quince", "Raspberry"
    };
    cout << "Enqueueing fruits from library..." << endl;
    for (const string& fruit : fruitLibrary) {
        queue.enqueue(fruit);
    }

    cout << queue.size() << " item(s): ";
    queue.print();
}
