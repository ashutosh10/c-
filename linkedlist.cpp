#include <iostream>
using namespace std;


template<class T>
class LinkedList
{
    class Node
    {
    public:
        T data;
        Node * next;
        Node(T idata): data(idata) 
        {
            next = nullptr;
        }
    };
    Node * head;

public:

    LinkedList() : head(nullptr) {}

    void push_back(T data)
    {
        Node * temp = new Node(data);
        if(head == nullptr)
        {
            head = temp;
            return;
        }
        Node * iterator = head;
        while(iterator->next != nullptr)
        {
            iterator = iterator->next;
        }
        iterator->next = temp;
    }

    uint32_t size()
    {
        uint32_t aSize = 0;
        Node * iterator = head;
        while(iterator)
        {
            aSize++;
            iterator = iterator->next;
        }
        return aSize;
    }

    void insert_at(uint32_t pos, T data)
    {
        if(pos > this->size())
            throw std::runtime_error("index out of range");

        Node * iterator = head;
        while(pos-- > 1)
        {
            iterator = iterator->next;
        }
        Node * temp = new Node(data);
        temp->next = iterator->next;
        iterator->next = temp;
    }

    void display()
    {
        Node * iterator = head;
        while(iterator)
        {
            cout << iterator->data << ' ';
            iterator = iterator->next;
        }
    }


    void reverse()
    {
        if(head == nullptr or head->next == nullptr)
            return;

        Node * previous = head;
        Node * current = previous->next;
        Node * next = current->next;

        while(next != nullptr)
        {
            
        }
    }
};


int main()
{
    LinkedList<int> aList;
    aList.push_back(1);
    aList.push_back(5);
    aList.push_back(3);
    aList.push_back(6);
    aList.push_back(8);
    aList.push_back(7);

    aList.insert_at(2,8);



    //cout << "Size of list : " << aList.size() << endl;
 
    aList.display();
}