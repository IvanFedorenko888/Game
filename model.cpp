#include "model.h"
#include <ctime>

void createPlayer(Player &p, vector<vector<Room>> &array);
void create (int &roomCount, vector<vector<Room>> &array);
bool MakeMove (string move, Player &p, vector<vector<Room>> &array);
void Model::playerW(){
    if (r.at(p.getX()).at(p.getY()).getW()){
        if (!MakeMove("W", p, r))
            youLose();
    } else
        error = 1;
    notify();
}
void Model::generatePlayer(){
    createPlayer(p,r);
}
void Model::createLabyrinth(int roomCount){
    create(roomCount,r);
}
void Model::youLose(){
    Won = 2;
    notify();
}
int Model::getWon (){
    return Won;
}
Player Model::getPlayer(){
    return p;
}
Room Model::getRoom(int x, int y){
    return r.at(x).at(y);
}
int Model::getShow() {
    return show;
}
void Model::playerA(){
    if (r.at(p.getX()).at(p.getY()).getA()){
        if (!MakeMove("A", p, r))
            youLose();
    }
    else
        error = 1;
    notify();
}
void Model::playerS(){
    if (r.at(p.getX()).at(p.getY()).getS()){
        if (!MakeMove("S", p, r))
            youLose();
    } else
        error = 1;
    notify();
}
void Model::playerD(){
    if (r.at(p.getX()).at(p.getY()).getD()){
        if (!MakeMove("D", p, r))
            youLose();
    } else
        error = 1;
    notify();
}
void Model::getItem(string get, int x, int y){
    if (get != "chest")
        p.getItem(r.at(x).at(y).addItemInBackpack(get));
    notify();
}
void Model::showBackpack(){
    show = 1;
    notify();
}
void Model::closeBackpack(){
    show = 0;
    notify();
}
void Model::dropItem(string value, int x, int y){
    Item item;
    item.setName(value);
    p.dropItem(item);
    r.at(x).at(y).setItem(value);
    notify();
}
void Model::openChest(int x,int y){
    for (int i = 0; i < p.showBack().size(); i++){
        if (strcmp(p.showBack().at(i).getName().c_str(),"key") == 0 && r.at(x).at(y).oneItem("chest")){
            Won = true;
            notify();
        } else{
            error = 1;
            notify();
        }
    }
}
int Model::getError(){
    return error;
}
void Model::setError(){
    error = 0;
}
void Model::upPlayerLimit(int x, int y){
    if (r.at(x).at(y).oneItem("food")){
        double newLimit = p.getLimitMove() * 0.1;
        p.setLimitMove((int) newLimit + p.getLimitMove());
        r.at(x).at(y).refreshItem("food");
    }
    notify();
}
bool MakeMove (string move, Player &p, vector<vector<Room>> &room)
{
    int currentPosition[2];
    currentPosition[0] = p.getX();
    currentPosition[1] = p.getY();
    if (p.getLimitMove() != 0){
        if (move == "W"){
            p.setX(currentPosition[0] - 1);
            p.setLimitMove(p.getLimitMove()-1);
            if (p.getLimitMove() == 0){
                if (room.at(p.getX()).at(p.getY()).getItem() != "chest")
                    return false;
                for (int i = 0; i < p.showBack().size(); i++){
                    if (p.showBack().at(i).getName() != "key")
                        return false;
                }
            }
        }
        if (move == "A"){
            p.setY(currentPosition[1]-1);
            p.setLimitMove(p.getLimitMove()-1);
            if (p.getLimitMove() == 0){
                if (room.at(p.getX()).at(p.getY()).getItem() != "chest")
                    return false;
                for (int i = 0; i < p.showBack().size(); i++){
                    if (p.showBack().at(i).getName() != "key")
                        return false;
                }
            }
        }
        if (move == "D"){
            p.setY(currentPosition[1]+1);
            p.setLimitMove(p.getLimitMove()-1);
            if (p.getLimitMove() == 0){
                if (room.at(p.getX()).at(p.getY()).getItem() != "chest")
                    return false;
                for (int i = 0; i < p.showBack().size(); i++) {
                    if (p.showBack().at(i).getName() != "key")
                        return false;
                }
            }
        }
        if (move == "S"){
            p.setX(currentPosition[0]+1);
            p.setLimitMove(p.getLimitMove()-1);
            if (p.getLimitMove() == 0){
                if (room.at(p.getX()).at(p.getY()).getItem() != "chest")
                    return false;
                for (int i = 0; i < p.showBack().size(); i++){
                    if (p.showBack().at(i).getName() != "key")
                        return false;
                }
            }
        }
        return true;
    }
    return false;
}

void createPlayer(Player &p, std::vector<std::vector<Room>> &array){
    srand(time(0));
    int x = rand()%array.size();
    int y = rand()%array.at(0).size();
    int limit = int(array.size()*array.at(0).size()*2);
    p.setX(x);
    p.setY(y);
    p.setLimitMove(limit);
}


void create (int &roomCount, std::vector<std::vector<Room>> &array){
    srand(time(0));
    int count = 2;
    int N = 0, W = 0;
    while (true){
        if (roomCount == 1){
            N = 1;
            W = 1;
            break;
        }else{
            if ( roomCount%count == 0){
                N = count;
                break;
            }
        }
        count++;
    }
    W = roomCount / N;
    for (int i = 0; i < N; i++){
        std::vector<Room> roomV;
        for (int j = 0; j < W; j++){
            Room room;
            room.setX(i);
            room.setY(j);
            room.setItem("");
            double dark = (double)rand()/RAND_MAX;
            if (dark > 0.6)
                room.setDarkRoom();
            roomV.push_back(room);
        }
        array.push_back(roomV);
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < W; j++){
            int countRand = 4;
            int mass[4] = {0,0,0,0};
            if (i - 1 < 0 || i + 1 > N-1){
                if (i - 1 < 0){
                    mass[0] = 2; // Up
                }
                if (i + 1 > N - 1){
                    mass[1] = 2; // Down
                }
                countRand -= 1;
            }
            if (j - 1 < 0 || j + 1 > W-1){
                if (j -1 < 0){
                    mass[2] = 2; // Left
                }
                if (j + 1 > W - 1){
                    mass[3] = 2; //Right
                }
                countRand -= 1;
            }
            int R = 1;
            if (i == (array.size()-1))
                R = 3;
            int countDoor = rand()%countRand + R;
            for (int k = 0; k < 4; k++){
                if ( mass[k] != 2){
                    if (array.at(i).at(j).getW() && mass[0] != 2){
                        mass[k] = 1;
                        countDoor -= 1;
                    }
                    if (array.at(i).at(j).getS() && mass[1] != 2){
                        mass[k] = 1;
                        countDoor -= 1;
                    }
                    if (array.at(i).at(j).getA() && mass[2] != 2){
                        mass[k] = 1;
                        countDoor -= 1;
                    }
                    if (array.at(i).at(j).getD() && mass[3] != 2){
                        mass[k] = 1;
                        countDoor -= 1;
                    }
                }
            }
            if (countDoor > 0)
                for (int q = 0; q < countDoor; q++){
                    int randDoor = rand()%4;
                    while(true){
                        if (mass[randDoor] == 0){
                            if (randDoor == 0){
                                mass[randDoor] = 1;
                                array.at(i).at(j).setW(true);
                                array.at(i-1).at(j).setS(true);
                                break;
                            }
                            if (randDoor == 1){
                                mass[randDoor] = 1;
                                array.at(i).at(j).setS(true);
                                array.at(i+1).at(j).setW(true);
                                break;
                            }
                            if (randDoor == 2){
                                mass[randDoor] = 1;
                                array.at(i).at(j).setA(true);
                                array.at(i).at(j-1).setD(true);
                                break;
                            }
                            if (randDoor == 3){
                                mass[randDoor] = 1;
                                array.at(i).at(j).setD(true);
                                array.at(i).at(j+1).setA(true);
                                break;
                            }
                        }
                        else{
                            int prov = 0;
                            for(int u = 0; u < 4; u++){
                                if (mass[u] != 0)
                                    prov++;
                            }
                            if (prov == 4)
                                break;
                        }
                        randDoor = rand()%4;
                    }
                }
        }
    }
    int chestX = rand()%array.size();
    int chestY = rand()%array.at(0).size();
    while (true){
        if (array.at(chestX).at(chestY).getW() || array.at(chestX).at(chestY).getS() || array.at(chestX).at(chestY).getA() || array.at(chestX).at(chestY).getD()){
            array.at(chestX).at(chestY).setItem("chest");
            break;
        }
        chestX = rand()%array.size();
        chestY = rand()%array.at(0).size();
    }
    int keyX = rand()%array.size();
    int keyY = rand()%array.at(0).size();
    while (true){
        if (array.at(keyX).at(keyY).getW() || array.at(keyX).at(keyY).getS() || array.at(keyX).at(keyY).getA() || array.at(keyX).at(keyY).getD() ){
            if (array.at(keyX).at(keyY).getItem() != "chest"){
                array.at(keyX).at(keyY).setItem("key");
                break;
            }
        }
        keyX = rand()%array.size();
        keyY = rand()%array.at(0).size();
    }
    int torchlightX = rand()%array.size();
    int torchlightY = rand()%array.at(0).size();
    while (true){
        if (array.at(torchlightX).at(torchlightY).getW() || array.at(torchlightX).at(torchlightY).getS() || array.at(torchlightX).at(torchlightY).getA() || array.at(torchlightX).at(torchlightY).getD()){
            if (array.at(torchlightX).at(torchlightY).getItem() != "chest" && array.at(torchlightX).at(torchlightY).getItem() != "key"){
                array.at(torchlightX).at(torchlightY).setItem("torchlight");
                break;
            }
        }
        torchlightX = rand()%array.size();
        torchlightY = rand()%array.at(0).size();
    }
    int foodX = rand()%array.size();
    int foodY = rand()%array.at(0).size();
    while (true){
        if (array.at(foodX).at(foodY).getW() || array.at(foodX).at(foodY).getS() || array.at(foodX).at(foodY).getA() || array.at(foodX).at(foodY).getD()){
            array.at(foodX).at(foodY).setItem("food");
            break;
        }
        foodX = rand()%array.size();
        foodY = rand()%array.at(0).size();
    }
}