#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node():data(0),next(0){};
    Node(int x):data(x),next(0){};
};
class Queue{
private:
    Node *front;
    Node *back;
    int size;
public:
    Queue():front(0),back(0),size(0){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int getFront();
    int getBack();
    int getSize();
};

void Queue::Push(int x){
    if(IsEmpty()){
        front = new Node(x);
        back = front;
        size += 1;
        return ;
    }
    Node *newNode = new Node(x);
    back->next = newNode;
    back = newNode;
    size += 1;
}

void Queue::Pop(){
    if(IsEmpty()){
        std::cout << "Queue is empty!\n";
        return ;
    }
    Node *deleteNode = front;
    front = front->next;
    delete deleteNode;
    deleteNode = 0;
    size -= 1;
}

int Queue::getFront(){
    if(IsEmpty()){
        std::cout << "Queue is empty!\n";
        return -1;
    }
    return front->data;
}

int Queue::getBack(){
    if(IsEmpty()){
        std::cout << "Queue is Empty!\n";
        return -1;
    }
    return back->data;
}

bool Queue::IsEmpty(){
    //return (!front && !back);
    return ((front && back) == 0);
}

int Queue::getSize(){
    return size;
}


int main(){
    Queue q;
    if(q.IsEmpty()) std::cout << "Queue is empty!\n";
    q.Push(123);
    std::cout << q.getFront() << " " << q.getBack() << "\n";
    q.Push(456);
    std::cout << q.getFront() << " " << q.getBack() << "\n";
    q.Push(789);
    std::cout << q.getFront() << " " << q.getBack() << "\n";
    q.Pop();
    std::cout << q.getFront() << " " << q.getBack() << "\n";
    q.Pop();
    std::cout << q.getFront() << " " << q.getBack() << "\n";
    q.Pop();
    std::cout << q.getFront() << " " << q.getBack() << "\n";

    return 0;
}