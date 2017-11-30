#include "priorityqueue.h"


Node::Node(int dif, Terrain *terrain) : difficulty(dif), terrain(terrain){
    previous = next = this;
    degree = 0;
}
Node::~Node(){

}

int Node::first(){return this->difficulty;}
Terrain* Node::second(){return this->terrain;}

bool Node::isSingle() {return this==next;}

void Node::insert(Node *node){
    if (!node){return;}
    this->next->previous = node->previous;
    node->previous->next = this->next;
    this->next = node;
    node->previous = this;
}

void Node::remove(){
    this->previous->next = this->next;
    this->next->previous = this->previous;
    this->next = this->previous = this;
}

void Node::addChild(Node *node){
    if (!this->child){
        this->child = node;
    }
    else {
        this->child->insert(node);
    }
    node->parent = this;
    this->degree += 1;
}

void Node::removeChild(Node *node){
    if (node->parent != this)
        return;
    if (node->isSingle()){
        if (this->child != node){return;}
        delete this->child;
    }
    else {
        if (this->child == node){
            this->child = node->next;
        }
        node->remove();
    }
    delete node->parent;
    this->degree -= 1;
}

Heap::Heap(){
    size = 0;
}

Heap::~Heap(){

}

bool Heap::isEmpty(){return this->size==0;}

void Heap::insert(Node *node) {
    size += 1;
    this->insertNode(node);
}

void Heap::insertNode(Node *node){
    if (!this->minnode){this->minnode = node;}
    else {
        this->minnode->insert(node);
        if (node->second() < this->minnode->second()){
            this->minnode = node;
        }
    }
}

Node* Heap::min() {return this->minnode;}

Node* Heap::remove_min(){
    Node *r_node = this->minnode;
    size -= 1;

    if (this->minnode->child) {
        Node *c = this->minnode->child;
        while (true) {
            delete c->parent;
            c = c->next;
            if (c == this->minnode->child){
                break;
            }
        }
        delete this->minnode->child;
        this->minnode->insert(c);
    }
    if (this->minnode->next == this->minnode){
        delete this->minnode;
        return r_node;
    }

    int log = 100;
    std::vector<Node*> d_roots (log);
    Node *c_pointer = this->minnode->next;

    while (true) {
        int c_degree = c_pointer->degree;
        Node *c = c_pointer;
        c_pointer = c_pointer->next;

        while (d_roots[c_degree]){
            Node *o = d_roots[c_degree];
            if (c->first() > o->first()) {
                Node *tmp = o;
                o = c;
                c = tmp;
            }
            o->remove();
            c->addChild(o);
            delete d_roots[c_degree];
            c_degree += 1;

        }
        if (c_pointer == this->minnode) {
            break;
        }
    }
    delete this->minnode;

    for (int d = 0; d < log; ++d) {
        if (d_roots[d]) {
            d_roots[d]->next = d_roots[d]->previous = d_roots[d];
            this->insertNode(d_roots[d]);
        }
    }

    return r_node;
}

void Heap::decreaseKey(Node* node, int value) {
    if (value >= node->first()) {return;}
    node->difficulty = value;
    Node *p = node->parent;
    if (!p){
        if (value < this->minnode->first()){
            this->minnode = node;
        }
        return;
    }
    else if(p->first() <= value){return;}
    while (p->parent){
        p->removeChild(node);
        this->insertNode(node);
        node = p;
        p = p->parent;
    }

}
