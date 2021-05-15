#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    Node *next;
public:
    Node():data(0){next = 0;}
    Node(int x):data(x){next = 0;}
    Node(int x, Node *nextNode):data(x),next(nextNode){}
    friend class Stack;
};

class Stack{
private:
    Node *top;
    int size;
public:
    Stack():size(0),top(0){}
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void Stack::Push(int x){
    if(IsEmpty()){
        top = new Node(x);
        size += 1;
        return ;
    }
    Node *newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    size += 1;
}

void Stack::Pop(){
    if(IsEmpty()){
        std::cout << "Stack is empty!\n";
        return ;
    }
    Node *deleteNode = top;
    top = top->next;
    delete deleteNode;
    deleteNode = 0;
    size -= 1;
}

bool Stack::IsEmpty(){
    return (size == 0);
}

int Stack::Top(){
    if(IsEmpty()){
        std::cout << "Stack is Empty!\n";
        return -1;
    }
    return top->data;
}

int Stack::getSize(){
    return size;
}


int main(){
    Stack st;
    st.Pop();
    st.Push(123);
    std::cout << st.Top() << " " << st.getSize() << "\n";
    st.Push(456);
    std::cout << st.Top() << " " << st.getSize() << "\n";
    st.Push(789);
    std::cout << st.Top() << " " << st.getSize() << "\n";
    st.Pop();
    std::cout << st.Top() << " " << st.getSize() << "\n";
    st.Pop();
    std::cout << st.Top() << " " << st.getSize() << "\n";
    st.Pop();
    std::cout << st.Top() << " " << st.getSize() << "\n";



    return 0;
}