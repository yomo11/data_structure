#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    Node *left;
    Node *right;
    Node *parent;
    int data;
public:
    //Node():leftchild(0),rightchild(0),parent(0),data(0){}
    //Node(int x):leftchild(0),rightchild(0),parent(0),data(x){};
    Node(int x):data(x){}

    friend class BST;
};

class BST{
private:
    Node *_root;
    void _createBST(std::vector<int> v);
    Node *_find(int key);
    void _insertNode(int x);
    void _removeNode(int x);
    void _inorderprint(Node *node);
    void _preorderprint(Node *node);
    void _postorderprint(Node *node);
    Node *predecessor(int x);
    Node *successor(int x);
public:
    BST(){}
    BST(std::vector<int> v){_createBST(v);}

    void inorderprint(){_inorderprint(_root);}
    void preorderprint(){_preorderprint(_root);}
    void postorderprint(){_postorderprint(_root);}
    void insert(int x){_insertNode(x);}
    void remove(int x){_removeNode(x);}
};

void BST::_createBST(std::vector<int> v){
    for(int data : v){
        _insertNode(data);
    }
}

Node *BST::_find (int key){
    Node *cur = _root;
    while(cur->data!=key && cur!=nullptr){
        if(cur->data < key){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }
    if(cur==nullptr){
        return cur;
    }
    else{
        std::cout << "BST do not have this node!\n";
        return nullptr;
    }
}

void BST::_insertNode(int x){
    Node * newNode = new Node(x);
    if(_root == nullptr){
        _root = newNode;
        return ;
    }
    Node *cur = _root;
    while(true){
        if(newNode->data > cur->data){
            if(cur->right != nullptr){
                cur = cur->right;
            }
            else{
                cur->right = newNode;
                newNode->parent = cur;
                return ;
            }
        }
        else{
            if(cut->left != nullptr){
                cur = cur->left;
            }
            else{
                cur->left = newNode;
                newNode->parent = cur;
                return ;
            }
        }
    }

}

Node * BST::predecessor(int x){//find 前驅 node
    Node *cur = _find(x);
    if(cur->left != nullptr){
        cur = cur->left;
        while(cur->right != nullptr){
            cur = cur->right;
        }
        return cur;
    }
    while(cur->parent != nullptr && cur->parent->left == cur){
        cur = cur->parent;
    }
    return cur->parent;
}

Node * BST::successor(int x){//find 後繼 node
    Node *cur = _find(x);
    if(cur->right != nullptr){
        cur = cur->right;
        while(cur->left != nullptr){
            cur = cur->left;
        }
        return cur;
    }
    while(cur->parent != nullptr && cur->parent->right != cur){
        cur = cur->parent;
    }
    return cur->parent;
}

void BST::_removeNode(int x){
    if(_root == nullptr){
        throw("error : it is an empty BST!\n");
    }
    Node *deleteNode = _find(x);
    Node *tmp;
    if(deleteNode->left == nullptr && deleteNode->right == nullptr){//deleteNode is a leaf node
        tmp = nullptr;
    }
    else if(deleteNode->left == nullptr || deleteNode->right == nullptr){
        //if deleteNode has a leftchild or right child
        tmp = (deleteNode->left == nullptr) ? deleeteNode->right : deleteNode->left;
        tmp->parent = deleteNode->parent;
    }
    else{
            tmp = successor(x);
            Node *tmp_right;
            if(tmp->right == nullptr){
                tmp_right = nullptr;
            }
            else{
                tmp_right = tmp->right;
                tmp->right->parent = tmp->parent;
            }

            if(tmp->parent->right == tmp){
                tmp->parent->right = tmp_right;
            }
            else{
                tmp->parent->left = tmp_right;
            }

            if(deleteNode->parent == nullptr){
                tmp->right = deleteNode->right;
                tmp->left = deleteNode->left;
                _root = tmp;
                delete deleteNode;
            }
            else if(deleteNode->parent->right == deleteNode){
                deleteNode->parent->right = tmp;
                tmp->parent = deleteNode->parent;
                tmp->right = deleteNode->right;
                tmp->left = deleteNode->left;
                delete deleteNode;
            }
            else{
                deleteNode->parent->left = tmp;
                tmp->parent = deleteNode->parent;
                tmp->right = deleteNode->right;
                tmp->left = deleteNode->left;
                delete deleteNode;
            }

            return ;
    }

    //case 1 ans 2
    if(deleteNode->parent != nullptr){
        if(deleteNode->parent->right == deleteNode){
            deleteNode->parent->right = tmp;
        }
        else{
            deleteNode->parent->left = tmp;
        }
    }
    else{
        _root = tmp;
    }
    delete deleteNode;

    return ;
}

void BST::_inorderprint (Node *node){
    if(node == nullptr){
        return ;
    }
    std::cout << node->data << " ";
    _inorderprint(node->left);
    _inorderprint(node->right);
}

void BST::_preorderprint (Node *node){
    if(node == nullptr){
        return ;
    }
    _preorderprint(node->left);
    std::cout << node->data << " ";
    _preorderprint(node->right);
}

void BST::_postorderprint (Node *node){
    if(node == nullptr){
        return ;
    }
    _postorderprint(node->left);
    _postorderprint(node->right);
    std::cout << node->data << " ";
}