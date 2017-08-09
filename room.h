#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include "door.h"
#include "item.h"
#include <vector>

class Room{
private:
    int x;
    int y;
    Door W, S, A, D;
    vector<Item> i;
    bool darkRoom = false;
public:
    bool oneItem(string name){
        for (int j = 0; j < i.size(); j++){
            if (i.at(j).getName() == name)
                return true;
        }
        return false;
    }
    void setDarkRoom(){
        darkRoom = true;
    }
    bool getDarkRoom(){
        return darkRoom;
    }
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }
    int getX (){
        return x;
    }
    int getY (){
        return y;
    }
    void setW(bool value){
        this->W.setVal(value);
    }
    bool getW(){
        return W.getVal();
    }
    void setS(bool value){
        this->S.setVal(value);
    }
    bool getS(){
        return S.getVal();
    }
    void setA(bool value){
        this->A.setVal(value);
    }
    bool getA(){
        return A.getVal();
    }
    void setD(bool value){
        this->D.setVal(value);
    }
    bool getD(){
        return D.getVal();
    }
    vector<Item> getAllItemRoom(){
        return i;
    }
    void refreshItem(string name){
        vector<Item> vector;
        for (int j = 0; j < i.size(); j++){
            if (i.at(j).getName() != name){
                Item item1 = i.at(j);
                vector.push_back(item1);
            }
        }
        i = vector;
    }
    void setItem(string name){
        Item item;
        item.setName(name);
        i.push_back(item);
    }
    string getItem(){
        string itemS = " ";
        for (int j = 0; j < i.size(); j++){
            itemS.append(i.at(j).getName());
            itemS.append(" ");
        }
        return itemS;
    }
    Item addItemInBackpack(std::string name){
        Item item;
        for (int j = 0; j < i.size(); j++){
            if (i.at(j).getName() == name){
                item = i.at(j);
                i.at(j).setName("");
            }
        }
        return item;
    }
    int getCountDoors(){
        int count = 0;
        if (getW())
            count++;
        if (getS())
            count++;
        if (getA())
            count++;
        if (getD())
            count++;
        return count;
    }
    string getDoors(){
        string str = "";
        if (getW())
            str.append(" W");
        if (getS())
            str.append(" S");
        if (getA())
            str.append(" A");
        if (getD())
            str.append(" D");
        return str;
    }
};
#endif //GAME_ROOM_H
