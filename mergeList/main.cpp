//
//  main.cpp
//  mergeList
//
//  Created by Cong on 13-3-5.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void build(Node* &head, int n){
    
    head = new Node();
    
    head->data = n;
    n -= 2;
    Node* p = head;
    while(n >= 0){
        p->next = new Node();
        p = p->next;
        
        p->data = n;
        n -= 2;
    }
}


Node* mergeList(Node* head1, Node* head2){
    if(head1 == NULL && head2 == NULL){
        cout<<"Invalid input"<<endl;
        return NULL;
    }
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    Node* head;
    Node* p1 = head1;
    Node* p2 = head2;
    Node* p;
    if(p1->data > p2->data){
        head = p1;
        p = p1;
        p1 = p1->next;
 
    }else{
        head = p2;
        p = p2;
        p2 = p2->next;
    }
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data){
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
        if(p1 == NULL){
            p->next = p2;
        }else{
            p->next = p1;
        }
    }
    
    return head;
}


void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    Node* head1;
    Node* head2;
    build(head1, 10);
    build(head2, 9);
    print(head1);
    print(head2);

    print(mergeList(head1, head2));
    
    return 0;
}

