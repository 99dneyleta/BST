
#include "BT.hpp"
#include <list>

BTNode* BT::getHead() {
    return this->_head;
}



void AddTo(BTNode *node, int value) {
    if(value < node->Value) {
        if(node->Left == NULL) {
            node->Left = new BTNode(value);
        }
        else {
            AddTo(node->Left, value);
        }
    }
    else {
        if(node->Right == NULL) {
            node->Right = new BTNode(value);
        }
        else {
            AddTo(node->Right, value);
        }
    }
    
}




void BT::Add(int value) {
    if(_head == NULL) {
        _head = new BTNode(value);
    }
    else {
        AddTo(_head,value);
        
    }
    _count++;
}



bool BT::Remove(int value) {
    BTNode *curr = nullptr, *parent = nullptr;
    curr = FindWithParent(value, "node", this->_head);
    parent = FindWithParent(value, "parent", this->_head);
    if(curr == NULL) {
        return false;
    }
    
    _count--;
    
    if(curr->Left == NULL && curr->Right == NULL) {
        if(parent->Left == curr)
            parent->Left = NULL;
        else
            parent->Right = NULL;
        curr = NULL;
    }
    
    else if(curr->Left == NULL || curr->Right == NULL) {
        if(curr->Right != NULL) {
            if(parent->Right == curr)
                parent->Right = curr->Right;
            else
                parent->Left = curr->Right;
            curr = NULL;

        }
        else {
            if(parent->Right == curr)
                parent->Right = curr->Left;
            else
                parent->Left = curr->Left;
            curr = NULL;
          
        }
    }
    
    else if(curr->Left != NULL && curr->Right != NULL) {
        
    }
    return true;
}
 



BTNode Min(BTNode * root) {
    if(root->Left != NULL)
        return Min(root->Left);
    else
        return *root;
}



BTNode* BT::Remove(int value, BTNode *root) {
    if (root == NULL)
        return root;
    if(value < root->Value)
        root->Left = Remove(value, root->Left);
    else if (value > root->Value)
        root->Right = Remove(value, root->Right);
    else if (root->Left != NULL && root->Right != NULL) {
        root->Value = Min(root->Right).Value;
        root->Right = Remove(root->Value, root->Right);
    }
    else {
        if(root->Left != NULL)
            root = root->Left;
        else
            root = root->Right;
    }
    
    return root;
}






BTNode* BT::FindWithParent(int value, std::string str, BTNode *node) {
    BTNode *k = new BTNode(-1);
    if(node->Value == value) {
        k = node;
    }
    
    if(node->Left != NULL){
        if(value == node->Left->Value) {// || (value == node->Right->Value)) {
        if(str == "parent")
            k = node;
        else {
            if(value == node->Left->Value)
                k = node->Left;
            else k = node->Right;
        }
    }
        else {
            if(node->Left != NULL && k->Value == -1) {
                k = FindWithParent(value, str, node->Left);
            }
        }
    }
    if(node->Right != NULL ) {
        if(value == node->Right->Value) {
            if(str == "parent") {
                k =  node;
            }
            else {
                if(value == node->Left->Value)
                    k = node->Left;
                else k = node->Right;
            }
        }
        
    else {
        if(node->Right != NULL && k->Value == -1) {
                k = FindWithParent(value, str, node->Right);
        }
    }
    }
    
    return k;
}




void BT::Show(BTNode *node){
    std::list<BTNode*> lvls;
    BTNode *curr = node;
    int currlvl = 0;
    int nxtlvl = 0;
    std::string lvlsnumbs, lvllink;
    std::cout<<"  ";
        int flag = 1;
    do{
        
        if(!lvls.empty()){
            
            curr = *lvls.begin();
            lvls.pop_front();
            currlvl-=1;
        }
        if(curr!= NULL)
            lvlsnumbs += std::to_string(curr->Value) + "    ";
        if(curr->Left != NULL){
        lvls.push_back(curr->Left);
            nxtlvl+=1;
            lvllink+="  /";
        }
        if(curr->Right !=NULL) {
        lvls.push_back(curr->Right);
            lvllink+="  |";
            nxtlvl+=1;
        }
        if(currlvl == 0){
            currlvl = nxtlvl;
            nxtlvl = 0;
            lvlsnumbs += '\n';
            lvllink += '\n';
            
        }

        
        curr = NULL;
        
        
    }while (!lvls.empty() || curr != NULL);
    std::cout<<lvlsnumbs;
    std::cout<<lvllink;
    
}


