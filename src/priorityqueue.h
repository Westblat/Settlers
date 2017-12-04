#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "terrain.h"
#include <vector>

class Node
{
public:
    Node(int, Terrain*);
    ~Node();
    int first();
    Terrain* second();
    bool isSingle();
    void insert(Node*);
    void remove();
    void addChild(Node*);
    void removeChild(Node*);
    int difficulty;
    int degree;
    Terrain *terrain;
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
};
bool operator==(Node & a, Node & b);


class Heap
{
public:
    Heap();
    ~Heap();
    bool isEmpty();
    void insert(Node*);
    void insertNode(Node*);
    Node* min();
    void merge(Heap*);
    Node* removeMin();
    void decreaseKey(Node*, int);
    int size();
    Node *nonode;
    Node *minnode;
private:
    int count;
};

#endif // PRIORITYQUEUE_H
