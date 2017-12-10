#include "map.h"

Map::Map(int w, int h) : width(w), height(h) {
    for(int i = 0; i < width; i++){
        std::vector<Terrain*> temp;
        for(int j = 0; j < height; j++){
            temp.push_back(new Terrain(new Coordinates(i,j),0));
        }
        map.push_back(temp);
    }
}

Map::~Map(){
    for(std::vector<std::vector<Terrain*> >::iterator it = map.begin(); it != map.end(); it++){
        for(std::vector<Terrain*>::iterator iter = it->begin(); iter != it->end(); iter++){
            delete *iter;
        }
    }
}

int Map::get_width() const {return width;}
int Map::get_height() const {return height;}
const std::vector<std::vector<Terrain*> >& Map::get_map() const {return map;}

void Map::setMap() {
    try{
        std::ifstream myfile;
        std::string line;
        myfile.open("map.txt");
        if(!myfile.is_open()){
            throw 0;
        }
        std::vector<int> temp;
        
        while(std::getline(myfile, line)){
            std::string buf;
            std::stringstream ss(line);
            
            while (ss >> buf){
                temp.push_back(std::stoi(buf));
                }
        }
        
        myfile.close();
        int counter = 0;

        for(std::vector<std::vector<Terrain*> >::iterator it = map.begin(); it != map.end(); it++){
            for(std::vector<Terrain*>::iterator iter = it->begin(); iter != it->end(); iter++){
                (**iter).setType(temp[counter]);
                counter++;
            }
        }
    }catch (...) {
        std::cout << "Error reading map.txt file" << std::endl;
    }
}

bool Map::contains(Coordinates &coord) {
    return coord.getX()>0 && coord.getY()>0 && coord.getX()<width && coord.getY()<height;
}
bool Map::contains(int x, int y) {
    return x>=0 && y>=0 && x<width && y<height;
}


Terrain* Map::getTerrain(Coordinates *coord){
    return (map.at(coord->getX())).at(coord->getY());
}
Terrain* Map::getTerrain(int x, int y) {
    return (map[x][y]);
}


std::stack<std::pair<int, int> > Map::solvePath(Coordinates* unit, Coordinates* target){
    std::stack<std::pair<int, int> > temp; //Stack for directions, forms a path from start to finish

    Terrain *start = this->getTerrain(unit);
    Terrain *end = this->getTerrain(target);
    Coordinates *endpos = end->getLocation();

    int size = this->get_height()*this->get_width();

    std::vector<bool> checked (size, false); //All nodes are first unchecked
    std::vector<Terrain*> previous (size); //Holds data who is whose previous node
    std::vector<int> distances (size, INT_MAX); //Holds data of distances from start to given node

    distances[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = 0; //Distance from start to start is 0

    Heap *heap = new Heap();
    Node *startNode = new Node(0,start);
    std::vector<Node*> nodes; //Keeps track of all created nodes, makes memory handling easier
    std::vector<Node*> nodeIndex (size, heap->nonode);
    nodeIndex[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = startNode;
    nodes.push_back(startNode);


    heap->insert(startNode); //Insert first node to heap

    std::vector<std::pair<int,int> > directions; //Possible directions where unit can move
    directions.push_back(std::pair<int, int> (1,0));
    directions.push_back(std::pair<int, int> (0,1));
    directions.push_back(std::pair<int, int> (-1,0));
    directions.push_back(std::pair<int, int> (0,-1));


    while (heap->size()>0){
        Node *next = heap->removeMin();

        Terrain *u = next->second();
        Coordinates *upos = u->getLocation();
        int uposindex = upos->getX()*this->width + upos->getY();

        if (distances[uposindex] == INT_MAX) {break;} //Unable to find path
        if (upos == endpos ){std::cout<<"Target found, smallest distance "<< next->difficulty<<std::endl;break;} //Search is completed

        for(auto iter = directions.begin(); iter!=directions.end(); ++iter) {
            int tempX = upos->getX()+(*iter).first;
            int tempY = upos->getY()+(*iter).second;
            if (this->contains(tempX, tempY)) {
                int vposindex = tempX*width + tempY;
                if (!checked[vposindex]){
                    int new_distance = distances[uposindex] + 1;
                    /*__________New distance is based on terrain difficulty_____________TODO FIX Heap::decreaseKEY

                    if(u->getBuildingType() == -1){
                        if(u->getType() == 0){new_distance = distances[uposindex] + 1;}
                        else if(u->getType() == 1){new_distance = distances[uposindex] + 2;}
                        else if(u->getType() == 2){new_distance = distances[uposindex] + 3;}
                        else if(u->getType() == 3){new_distance = distances[uposindex] + 2;}
                        else{new_distance = distances[uposindex] + 10;}
                    }
                    else{new_distance = distances[uposindex] + 2;}
                    //__________________________________________________________________*/
                    if (new_distance < distances[vposindex]) {
                        if (nodeIndex[vposindex]->difficulty != -1) {
                            heap->decreaseKey(nodeIndex[vposindex],new_distance);
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                        else {
                            nodeIndex[vposindex] = new Node(new_distance, this->getTerrain(tempX, tempY));
                            nodes.push_back(nodeIndex[vposindex]);
                            heap->insert(nodeIndex[vposindex]);
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                    }
                }
            }
        }
        checked[uposindex] = true;
    }

    Terrain *cur = end;
    Terrain *prev;
    while (cur != start) {
        prev = previous[cur->getLocation()->getX()*this->width + cur->getLocation()->getY()];
        temp.push(std::pair<int, int> (cur->getLocation()->getX() - prev->getLocation()->getX(), cur->getLocation()->getY() - prev->getLocation()->getY()));
        cur = prev;
    }


    for (std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it){
        delete *it;
    }
    delete heap;

    return temp;
}

Coordinates* Map::findNearby(Coordinates *s, int building){
    Coordinates* temp;

    Terrain *start = this->getTerrain(s);

    int size = this->get_height()*this->get_width();

    std::vector<bool> checked (size, false); //All nodes are first unchecked
    std::vector<Terrain*> previous (size); //Holds data who is whose previous node
    std::vector<int> distances (size, INT_MAX); //Holds data of distances from start to given node

    distances[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = 0; //Distance from start to start is 0

    Heap *heap = new Heap();
    Node *startNode = new Node(0,start);
    std::vector<Node*> nodes; //Keeps track of all created nodes, makes memory handling easier
    std::vector<Node*> nodeIndex (size, heap->nonode);
    nodeIndex[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = startNode;
    nodes.push_back(startNode);


    heap->insert(startNode); //Insert first node to heap

    std::vector<std::pair<int,int> > directions; //Possible directions where unit can move
    directions.push_back(std::pair<int, int> (1,0));
    directions.push_back(std::pair<int, int> (0,1));
    directions.push_back(std::pair<int, int> (-1,0));
    directions.push_back(std::pair<int, int> (0,-1));


    while (heap->size()>0){
        Node *next = heap->removeMin();

        Terrain *u = next->second();
        Coordinates *upos = u->getLocation();
        int uposindex = upos->getX()*this->width + upos->getY();

        if (distances[uposindex] == INT_MAX) {break;} //Unable to find path
        if (u->getBuildingType() == building && u->getBuilding()->getReadiness()){temp = u->getLocation();break;} //Search is completed

        for(auto iter = directions.begin(); iter!=directions.end(); ++iter) {
            int tempX = upos->getX()+(*iter).first;
            int tempY = upos->getY()+(*iter).second;
            if (this->contains(tempX, tempY)) {
                int vposindex = tempX*width + tempY;
                if (!checked[vposindex]){
                    int new_distance = distances[uposindex] + 1;
                    /*__________New distance is based on terrain difficulty_____________TODO FIX Heap::decreaseKey()

                    if(u->getBuildingType() == -1){
                        if(u->getType() == 0){new_distance = distances[uposindex] + 1;}
                        else if(u->getType() == 1){new_distance = distances[uposindex] + 2;}
                        else if(u->getType() == 2){new_distance = distances[uposindex] + 3;}
                        else if(u->getType() == 3){new_distance = distances[uposindex] + 2;}
                        else{new_distance = distances[uposindex] + 10;}
                    }
                    else{new_distance = distances[uposindex] + 2;}
                    //__________________________________________________________________*/
                    if (new_distance < distances[vposindex]) {
                        if (nodeIndex[vposindex]->difficulty != -1) {
                            heap->decreaseKey(nodeIndex[vposindex],new_distance);
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                        else {
                            nodeIndex[vposindex] = new Node(new_distance, this->getTerrain(tempX, tempY));
                            nodes.push_back(nodeIndex[vposindex]);
                            heap->insert(nodeIndex[vposindex]);
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                    }
                }
            }
        }
        checked[uposindex] = true;
    }

    for (std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it){
        delete *it;
    }
    delete heap;

    return temp;
}


std::ostream& operator<<(std::ostream& os, Map& map){
    
    std::vector<std::vector<Terrain*> > temp = map.get_map();

    for(int i = 0; i<map.get_height(); ++i){
        for(std::vector<std::vector<Terrain*> >::iterator it = temp.begin(); it != temp.end(); ++it){
            std::vector<Terrain*>::iterator iter = it->begin()+i;
            os << **iter << " ";
        }
        os << std::endl;
    }
    return os;
}
