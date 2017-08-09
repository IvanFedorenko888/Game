#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "listener.h"
#include "player.h"
#include "room.h"

class Model : public Listener{
private:
    Player p;
    vector<vector<Room>> r;
    int show = 0;
    int Won = 0; // если 0 - идет игра, если 1 - победил, если 2 - проиграл
    int error = 0;
public:
    int getWon ();
    int getShow();
    Player getPlayer();
    Room getRoom(int, int);
    void youLose();
    void createLabyrinth(int);
    void generatePlayer();
    void playerW();
    void playerA();
    void playerS();
    void playerD();
    void getItem(string, int, int);
    void showBackpack();
    void closeBackpack();
    void dropItem(string, int, int);
    void openChest(int,int);
    int getError();
    void setError();
    void upPlayerLimit(int, int);
};
#endif //GAME_MODEL_H
