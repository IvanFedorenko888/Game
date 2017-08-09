#ifndef GAME_ITEM_H
#define GAME_ITEM_H
#include <iostream>

using namespace std;

class Item {
private:
    string name;
public:
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
};
#endif //GAME_ITEM_H
