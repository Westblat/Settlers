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
    Node* remove_min();
    void decreaseKey(Node*, int);
private:
    Node *minnode;
    int size;
};

#endif // PRIORITYQUEUE_H
