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
    std::ifstream myfile;
    std::string line;
    myfile.open("map.txt");
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


std::vector<std::pair<int, int> > Map::solvePath(Coordinates* unit, Coordinates* target){
    std::vector<std::pair<int, int> > temp;

    Terrain *start = this->getTerrain(unit);
    Terrain *end = this->getTerrain(target);
    Coordinates *endpos = end->getLocation();

    int size = this->get_height()*this->get_width();

    std::vector<bool> checked (size, false);
    std::vector<Terrain*> previous (size);
    std::vector<std::pair<int,Terrain*> > nodeIndex (size);
    std::vector<int> distances (size, INT_MAX);

    distances[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = 0;
    nodeIndex[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = std::pair<int, Terrain*>(0, start);

    std::vector<std::pair<int, Terrain*> > heap;
    heap.push_back(std::pair<int, Terrain*> (0,start));

    /*TEST STUFF PLEASE REMOVE
    heap.push_back(std::pair<int, Terrain*> (4, end));
    heap.push_back(std::pair<int, Terrain*> (3, end));
    heap.push_back(std::pair<int, Terrain*> (5, end));
    //END OF TEST STUFF*/

    std::make_heap(heap.begin(), heap.end(), comparison);

    std::vector<std::pair<int,int> > directions;
    directions.push_back(std::pair<int, int> (1,0));
    directions.push_back(std::pair<int, int> (0,1));
    directions.push_back(std::pair<int, int> (-1,0));
    directions.push_back(std::pair<int, int> (0,-1));

    while (heap.size()>0){
        std::pair<int, Terrain*> next = heap.front();
        std::pop_heap(heap.begin(),heap.end(), comparison); heap.pop_back();
        //std::cout<<next.first<<std::endl;

        Terrain *u = next.second;
        Coordinates *upos = u->getLocation();
        int uposindex = upos->getX()*this->width + upos->getY();

        if (distances[uposindex] == INT_MAX) {break;} //Unable to find path
        if (upos == endpos ){std::cout<<"Target found"<<std::endl;break;} //Search is completed

        for(auto iter = directions.begin(); iter!=directions.end(); ++iter) {
            int tempX = upos->getX()+(*iter).first;
            int tempY = upos->getY()+(*iter).second;
            if (this->contains(tempX, tempY)) {
                int vposindex = tempX*width + tempY;
                if (!checked[vposindex]){
                    int new_distance = distances[uposindex] + 1; //TODO IMPLEMENT TERRAIN DIFFICULTY
                    if (new_distance < distances[vposindex]) {
                        if (nodeIndex[vposindex].second) {
                            //std::cout<<"old node "<<tempX<<" "<<tempY<<std::endl;
                            //TODO IMPLEMENT VALUE DECREMENT
                        }
                        else {
                            std::pair<int, Terrain*> vnode (new_distance, this->getTerrain(tempX, tempY));
                            //std::cout<<"new node "<<tempX<<" "<<tempY<<std::endl;
                            heap.push_back(vnode); std::push_heap(heap.begin(),heap.end());
                            nodeIndex[vposindex] = vnode;
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                    }
                }
            }
        }
        checked[uposindex] = true;
    }


    /*TEST STUFF PLEASE REMOVE
    std::cout<<"asd"<<std::endl;
    std::cout<<(heap.front()).first<<std::endl;
    std::cout<<heap.size()<<std::endl;
    std::cout<<"asd"<<std::endl;
    //END OF TEST STUFF*/

    return temp;
}


bool comparison(std::pair<int, Terrain*> &a, std::pair<int, Terrain*> &b){
    return a.first>b.first;
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
