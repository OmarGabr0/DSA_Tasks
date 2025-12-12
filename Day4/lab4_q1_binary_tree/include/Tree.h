#ifndef TREE_H
#define TREE_H
using namespace std;

#include <stdio.h>
#include <iostream>
#include "Employee.h"

/// Node class
class Node {
public:
    Node * right ;
    Node * left ;
    Employee emp ;

    Node (const Employee & e):emp(e){
        right =nullptr;
        left = nullptr;
    }
};

/// Tree class
class Tree
{
public:
    Tree(){
        root = nullptr ;
    }

    void Insert( const Employee & e){
        Node * node=new Node(e) ;
        Node * parent =nullptr;
        Node * curr=root;

        /// if empty tree
        if(curr==nullptr){
            root = node ;
            return ;
        }

        /// search and place
        while(curr != nullptr){
            parent = curr ;
            ///move left if data smaller than current data
            if(e.id< curr->emp.id ){
                curr = curr->left ;
            } else {
                curr=curr->right;
            }
        }

        /// insert left or right of parent ?
        if(e.id<parent -> emp.id ){
            parent->left = node ;
        } else {
            parent -> right = node ;
        }
    }

    bool deleteNode(int id){
        Node * par ;
        Node * delNode=findNode(id,par);

        if(delNode == nullptr)
            return false;

        ///case 1 : the node is leaf
        if(delNode->left == nullptr && delNode->right==nullptr){
            if(delNode==root)
                root=nullptr;
            else if (isLeftChild(par,delNode))
                par->left=nullptr;
            else
                par->right=nullptr;

        ///case 2 if deleted node has left child only
        } else if (delNode->right==nullptr ){
            /// if it was the root
            if(delNode==root){
                root = delNode -> left ;
            ///case (pos 1) del node is the left of parent
            } else if (isLeftChild(par,delNode)){
                par->left=delNode->left;
            /// case( pos 3) del node is the right of parent
            } else{
                par->right =delNode->left;
            }

        ///case3: if deleted node has right child only
        } else if (delNode -> left == nullptr){
            ///case root
            if(delNode == root ){
                root = delNode -> right ;
            /// case (pos 2): del node is the left of parent
            }else if (isLeftChild(par,delNode) ){
                par->left = delNode -> right;
            /// case (pos 4) del node has right child
            }else {
                par->right = delNode->right;
            }

        ///case normal node in the middle of tree with children
        } else {
            //get the successor
            Node* parsucs;
            Node * sucs=GetSuccessor(delNode,parsucs);

            if(delNode->right==sucs){
                if(delNode==root){
                    root =sucs;
                }
                else if(isLeftChild(par,delNode)){
                    par->left=sucs;
                }else {
                    par->right=sucs;
                }

                // move left of node to be pointed by successor
                sucs->left = delNode->left;

            } else {

                // right of succsseor be pointed by only parent
                parsucs->left = sucs->right ;

                // sucs -> right point to right of node
                sucs->right = delNode->right ;

                // left -> left
                sucs->left = delNode->left ;

                //4
                if(delNode==root){
                    root=sucs;
                } else {
                    par->left=sucs ;
                }
            }
        }

        delete delNode;
        return true;
    }

    bool isLeftChild(Node * parent , Node * child){
        if(parent->left==child)
            return true;
        else
            return false;   /// fixed spelling from flase → false
    }

    bool Search ( int key){
        Node * par;
        Node * found = findNode(key,par);

        if(found!=nullptr){
            return true;
        } else {
            return false;
        }
    }

    void DFS(){
        TraverseInOrder(root);
    }

    Node * GetMaximum(){

        Node * curr = root ;
        Node * par = curr;

        while(curr!=nullptr){
            par=curr;
            curr=curr->right ;
        }
        return par;
    }
    Node * GetMinmum(){
        Node * curr = root ;
        Node * par = curr;

        while(curr!=nullptr){
            par=curr;
            curr=curr->left ;
        }
        return par;
    }
private:
    Node * root;

    /// O(log n )
    Node* findNode(int key,Node * & parent ){

        Node * curr =root ;
        parent = nullptr;

        while(curr != nullptr && curr->emp.id != key){
            parent = curr;

            if(key<curr->emp.id){
                curr=curr->left ;
            } else{
                curr=curr->right ;
            }
        }

        return curr ;
    }

    ///
    void TraverseInOrder(Node * curr){
        if(curr!= nullptr){
            TraverseInOrder(curr->left);
            cout<<curr->emp.id<<" " ;
            TraverseInOrder(curr->right);
        }
    }

    Node * GetSuccessor(Node * delNode,Node * &parsucs){
        Node * sucs=delNode;
        parsucs=delNode;
        /// one step right
        sucs=sucs->right;

        while(sucs->left !=nullptr){
            parsucs=sucs;
            sucs=sucs->left;
        }
        return sucs ;
    }

};

#endif // TREE_H
