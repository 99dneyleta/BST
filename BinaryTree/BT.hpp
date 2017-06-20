//
//  BT.hpp
//  BinaryTree
//
//  Created by Roman on 6/3/17.
//  Copyright © 2017 Roma. All rights reserved.
//

#ifndef BT_hpp
#define BT_hpp

#include <stdio.h>
#include <iostream>
#include "BTNode.hpp"
//твій основний клас  містить в собі вказівник на початок дерева(голова) типу елемента ну і кількість всіх елементів. І функції реалізовані ще не всі, але все ж таки будуть ось такі

class BT {
private:
    BTNode *_head;
    int _count;
public:
    BT(){ 
        this->_head = NULL;
        this->_count = NULL;
    }
    
    void Add(int value);
    bool Contains(int value);
    BTNode* Remove(int value,BTNode*);
    BTNode* FindWithParent(int value, std::string node, BTNode *);
    void Preorder(BTNode node);
    void PostOrder(BTNode node);
    void InOrder(BTNode node);
    void Clear();
    int getCount();
    BTNode* getHead();
    void Show(BTNode*);

};

#endif /* BT_hpp */
