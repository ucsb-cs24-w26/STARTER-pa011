// card_list.h
// Author: Zhiyicheng
// // All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
#include <iostream>

using namespace std;

class CardList {
private:
    struct Node {
        Node* left;
        Node* right;
        Card info;
        Node* parent; 

        Node(Card c) {
        info = c;
       left = nullptr;right = nullptr;parent = nullptr;
        }
    };
    Node* root;
    void clear(Node* n);
    Node* getMax(Node* n) const;
    Node* getMin(Node* n) const;
    Node* getPredecessor(Node* n) const;
    Node* getSuccessor(Node* n) const;

public:
    CardList();
    ~CardList(); 
    void insert(Card c);
    void remove(Card c);
    bool contains(Card c) const;
    class Iterator {
    private:
        Node* curr; 
        friend class CardList; 
    public:
        Iterator(Node* n);
        Card operator*() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };
    Iterator begin() const; 
    Iterator end() const;  
    Iterator rbegin() const;
    Iterator rend() const;
};

#endif
