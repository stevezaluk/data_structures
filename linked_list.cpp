#include <iostream>

using namespace std;

class Node {
    public:
        string data;
        Node *head;
        Node *next;

    Node(string data, Node *head) {
        cout << "Making node\n";
        this->data = data;
        this->head = head;
    }

    string getData() {
        return this->data;
    }

    void setData(string d) {
        this->data = d;
    }

    Node *getNext() {
        return this->next;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    Node *getHead() {
        return this->head;
    }

    void setHead(Node *head) {
        this->head = head;
    }
};

int iter(Node *node) {
    node = node->getHead();
    // std::cout << "Iterating\n\n";

    int count = 1; 
    while(node->getNext() != NULL) {
        std::cout << "Node " << count << "  Data: " << node->getData() << endl;
        count++;
        node = node->getNext();
        
        if(node->getNext() == NULL) {
            std::cout << "Node " << count << " Data: " << node->getData() << endl;
        }
    
    }
    return count;
}

void append_node(Node *head, string data) {
    head = head->getHead();

    while(head->getNext() != NULL) {
        head = head->getNext();
        if(head->getNext() == NULL) {
            Node *node = new Node(data, node->getHead());
            head->setNext(node);
            break;
        }
    }
}

Node *getNode(Node *node, int index) {
    int count = 1;

    node = node->getHead();
    while(node->getNext() != NULL) {
        if(index == count) {
            return node;
        }
        count++;
        node = node->getNext();
    }

    return NULL;
}

int main() {
    std::cout << "Building linked list with 5 nodes\n";
    Node *one = new Node("one", one); // possibility of memory leak here. Gotta fix that
    Node *two = new Node("two", one);
    Node *three = new Node("three", one);
    Node *four = new Node("four", one);
    Node *five = new Node("five", one);
    one->setNext(two);
    two->setNext(three);
    three->setNext(four);
    four->setNext(five);
    five->setNext(NULL);

    std::cout << "Current Node: " << one->getData() << endl;
    
    int count = iter(two);

    std::cout << "Counted nodes: " << count << endl;;

    append_node(two, "six");

    count = iter(two);

    std::cout << "Counted Nodes: " << count << endl;

    Node *x = getNode(two, 6);
    std::cout << "Requested Node : " << x->getData() << endl;


    delete one;
    delete two;
    delete three;
    delete four;
    delete five;
    return 0;
}