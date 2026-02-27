#include <iostream>
#include <string>


#include <iostream>
#include <string>

int size = 0;


struct Node
{
    float score;
    struct Node *next;
    struct Node *previous;

};

Node *h = NULL;
Node *tail = NULL;



bool isEmpty(){
    if (size == 0){
        return true;
    }
    else{
        return false;
    }
}

int listSize(){
    return size;
}

float get(int position){
    Node *t = h;
    int count = 1;
    while(count < position){
        t = t->next;
        count++;
    }
    return t->score;
}

void positionOf(float x){
    Node *t = h;
    int count = 1;
    while(count <= size){
        if (t->score == x)
        {
            std::cout << count << std::endl;
            break;
        }
        t = t->next;
        count++;

    }
}

void insertScore(int position, float x) {
    if (position < 1 || position > size + 1) {
        return;
    }

    Node *n = new Node;
    n->score = x;
    n->next = nullptr; 
    n->previous = nullptr;

    if (position == 1) {
        n->next = h;
        if (h != nullptr){
            h->previous = n;
        }
        h = n;
   } else {
        Node *t = h;
        for (int count = 1; count < position - 1; ++count) {
            t = t->next;
        }
        n->next = t->next; 
        n->previous = t;   

        if (t->next != nullptr) {
            t->next->previous = n;
        }
        t->next = n; 
    }

    size++;
}

void deleteScore(int position){
    if (h == NULL || position < 1 || position > size) {
        return;
    }

    Node *t = h;

    if (position == 1) {
        h = h->next;
        if (h != NULL) h->previous = NULL; 
        delete t; 
        size--;
    } else {
        for (int count = 1; count < position; count++) {
            t = t->next;
        }

        if (t->next != NULL) t->next->previous = t->previous;
        if (t->previous != NULL) t->previous->next = t->next;

        delete t; 
        size--;
    }
}

void output(Node *head){
    Node *t = head;
    while (t != NULL){
        std::cout << t->score << " ";
        t = t->next;
    }
    std::cout << std::endl;
}


int main(){
    if(isEmpty()){
        std::cout << "The linked list is empty" << std::endl;
    }

    insertScore(1, 75);
    insertScore(2, 34);
    insertScore(3, 95);
    insertScore(4, 12);
    insertScore(5, 35);
    insertScore(6, 100);


    output(h);

    deleteScore(5);


    output(h);


    return 0;

}