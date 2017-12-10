#include "priorityqueue.h"

Node::Node(int dif, Terrain *terrain) : difficulty(dif), terrain(terrain){
    previous = next = this;
    degree = 0;
    child = parent = this;
}

int Node::first(){return this->difficulty;}
Terrain* Node::second(){return this->terrain;}

bool Node::isSingle() {return this==next;}

void Node::insert(Node *node){
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
    if (this->child == this){
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
        this->child = node;
    }
    else {
        if (this->child == node){
            this->child = node->next;
        }
        node->remove();
    }
    node->parent = node;
    this->degree -= 1;
}

bool operator==(Node &a, Node &b) {
    return (a.second()) == (b.second());
}

Heap::Heap(){
    count = 0;
    nonode = new Node(-1, new Terrain(new Coordinates(-1,-1),-1));
    minnode = nonode;
}

Heap::~Heap(){
    delete nonode->terrain;
    delete nonode;
}

bool Heap::isEmpty(){return this->count==0;}

void Heap::insert(Node *node) {
    count += 1;
    this->insertNode(node);
}

void Heap::insertNode(Node *node){
    if (this->minnode->difficulty == -1){this->minnode = node;}
    else {
        this->minnode->insert(node);
        if (node->difficulty < this->minnode->difficulty){
            this->minnode = node;
        }
    }
}

Node* Heap::min() {return this->minnode;}

Node* Heap::removeMin(){
    if (this->minnode->difficulty == -1) {}

    Node *r_node = this->minnode;
    count -= 1;

    if (r_node->child != r_node) {
        Node *c = this->minnode->child;
        while (true) {
            c->parent = c;
            c = c->next;
            if (c == this->minnode->child){
                break;
            }
        }
        this->minnode->child = this->minnode;
        this->minnode->insert(c);
    }
    if (this->minnode->next == this->minnode){
        this->minnode = nonode;
        return r_node;
    }

    int log = 100;
    std::vector<Node*> d_roots (log, nonode);
    Node *c_pointer = this->minnode->next;

    while (true) {
        int c_degree = c_pointer->degree;
        Node *c = c_pointer;
        c_pointer = c_pointer->next;

        while (d_roots[c_degree]->difficulty != -1){
            Node *o = d_roots[c_degree];
            if (c->first() > o->first()) {
                Node *tmp = o;
                o = c;
                c = tmp;
            }
            o->remove();
            c->addChild(o);
            d_roots[c_degree] = nonode;
            c_degree += 1;

        }
        d_roots[c_degree] = c;
        if (c_pointer == this->minnode) {
            break;
        }
    }
    this->minnode = nonode;

    for (int d = 0; d < log; ++d) {
        if (d_roots[d]->difficulty != -1) {
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
    if (p == node){
        if (value < this->minnode->first()){
            this->minnode = node;
        }
        return;
    }
    else if(p->first() <= value){return;}
    while (p->parent != p){
        p->removeChild(node);
        this->insertNode(node);
        node = p;
        p = p->parent;
    }

}

int Heap::size() {return this->count;}
