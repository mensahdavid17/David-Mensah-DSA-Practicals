#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<std::string> shoppingList;

    shoppingList.push("bucket");
    shoppingList.push("broom");

    cout << "current shopping list: " << shoppingList.top() << endl;

    //remove top element
    shoppingList.pop();


    if (shoppingList.empty()) {
        cout << "Shopping list is empty." << endl;
    
    } else{
        cout << "Shopping list size: " << shoppingList.size() << endl;
    }

    return 0;




}