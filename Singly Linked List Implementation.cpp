#include <iostream>
#include <string>

int size = 0;


struct Node
{
    float score;
    struct Node *next;

};

Node *h = NULL;



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

    if (position == 1) {
        n->next = h;
        h = n;
    } else {
        Node *t = h;
        for (int count = 1; count < position - 1; ++count) {
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
    }

    size++;
}

void deleteScore(int position){
    Node *t = h;
    if(position == 1){
        h = h->next;
        size--;
    }
    else if(position == size){
        
        int count = 1;
        while (count<(position-1)){
            t = t->next;
            count++;
        }
        h->next = NULL;
        size--;
    }
    else{
        int count = 1;
        while(count< (position-1)){
            t = t->next;
            count++;
        }
        t->next = t->next->next;
        size--;
    }}

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

    insertScore(1, 99);
    insertScore(2, 86);
    insertScore(3, 56);
    insertScore(4, 77);
    insertScore(5, 45);
    insertScore(6, 97);


    output(h);

    deleteScore(2);


    output(h);


    return 0;

}