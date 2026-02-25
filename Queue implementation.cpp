#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

string firstNames[SIZE]; //first names of five students
int front = -1; // index of the first element
int rear = -1; // index of the rear element



bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
    }

void enqueue(string a){
    if (rear == SIZE-1){
        cout << "Queue Overflow" << endl;
    }
    else {
        if(front == -1){
        front = 0;
        }
        rear++;
        firstNames[rear] = a;
    }
}

void dequeue(){
    if (isEmpty()){
        cout << "The queue is empty" << endl;
    }
    else if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }

}

void showFront(){
    cout << firstNames[front] << endl;
}

void showBack(){
    cout << firstNames[rear] << endl;
}

int main(){
    dequeue();

    enqueue("David");
    enqueue("Abigail");
    enqueue("Abena");
    enqueue("Doris");

    showFront();
    showBack();

    dequeue();

    showFront();

    return 0;
}