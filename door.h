#ifndef GAME_DOOR_H
#define GAME_DOOR_H
class Door{
private:
    bool val = false;
public:
    void setVal(bool value){
        this->val = value;
    }
    bool getVal(){
        return val;
    }
};
#endif //GAME_DOOR_H
