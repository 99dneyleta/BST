//
//  main.cpp
//  BinaryTree
//
//  Created by Roman on 6/3/17.
//  Copyright © 2017 Roma. All rights reserved.
//

#include <iostream>
#include "BT.hpp"
//короч мейн тут викликаю функції адд додаю елемент в дерево пошуку функція show буде виводити дерево вона ще не зовсім готова типу виводить але не дуже красиво. Потім буде краще
int main(int argc, const char * argv[]) {
    BT tree;
    tree.Add(3);
    tree.Add(1);
    tree.Add(4);
  
   
    
    //tree.Show(tree.getHead());
    std::cout<<"    "<<3<<std::endl;
    std::cout<<"   / |"<<std::endl;
    std::cout<<"  1  4"<<std::endl;
    
}
