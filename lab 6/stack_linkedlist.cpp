// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct node{
    struct node* link;
    int data;
} *top = NULL;


void push(int data){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(newNode));
    if(newNode == NULL){
        cout << "Stack Overflow";
        exit(1);
    }
    newNode -> data = data;
    newNode -> link = NULL;
    
    newNode -> link = top;
    top = newNode;
}
int isEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}

int pop(){
    struct node* temp;
    temp = top;
    if(isEmpty()){
        cout << "Stack Underflow";
        exit(1);
    }
    int val = temp -> data;
    top = top -> link;
    free(temp);
    temp = NULL;
    return val;
}

void display(){
    struct node* temp;
    temp = top;
    if(isEmpty()){
        cout << "Stack Underflow";
        exit(1);
    }
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> link;
    }
    cout << endl;
}

int main() {
    auto start = high_resolution_clock::now();
     push(8);
     push(10);
     push(5);
     push(11);
     push(15);
     push(23);
     push(6);
     push(18);
     push(20);
     push(17);
     display();
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     push(4);
     push(30);
     push(3);
     push(1);
     display();
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
