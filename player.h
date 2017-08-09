#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "item.h"
#include <vector>
#include <cstring>

class Player {
private:
    int x;
    int y;
    vector<Item> backpack;
    int limitMove;
public:
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setLimitMove(int limit){
        this->limitMove = limit;
    }
    int getLimitMove(){
        return limitMove;
    }
    void getItem(Item value){
        backpack.push_back(value);
    }
    std::vector<Item> showBack(){
        return backpack;
    }
    void dropItem(Item value){
        vector<Item> temp;
        for (int i = 0; i < backpack.size(); i++){
            if (strcmp(backpack.at(i).getName().c_str(),value.getName().c_str()) != 0){
                temp.push_back(value);
            }
        }
        backpack.resize(temp.size());
        backpack = temp;
    }

    bool checkItem(string name){
        for (int i = 0; i < backpack.size(); i++){
            if (strcmp(backpack.at(i).getName().c_str(),name.c_str()) == 0){
                return true;
            }
        }
        return false;
    }
};
#endif //GAME_PLAYER_H
