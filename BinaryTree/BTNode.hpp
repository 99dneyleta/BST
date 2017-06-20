//
//  BTNode.hpp
//  BinaryTree
//
//  Created by Roman on 6/15/17.
//  Copyright © 2017 Roma. All rights reserved.
//

#ifndef BTNode_hpp
#define BTNode_hpp

#include <stdio.h>

//класс одного елемента бінарного дерева пошуку містить в собі конструктор по замовчуванню вказівник на такий же клас типу лівий нащадок і правий, ну і саме значення елемента

class BTNode {
    
public:
    BTNode(){
        this->Left = NULL;
        this->Right = NULL;
        Value = NULL;
    }
    BTNode(int value) {
        Value = value;
    }
    BTNode *Left;
    BTNode *Right;
    int Value;
};

#endif /* BTNode_hpp */
