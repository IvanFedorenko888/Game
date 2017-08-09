#ifndef GAME_LISTENER_H
#define GAME_LISTENER_H
#include "listen.h"
#include <iostream>
#include <vector>

using namespace std;

class Listener {
private:
    vector<Listen*> listener;

public:
    void setListener (Listen *l){
        listener.push_back(l);
    }
    void notify(){
        for (int i = 0; i < listener.size(); i++){
            listener.at(i)->update();
        }
    }
};
#endif //GAME_LISTENER_H
