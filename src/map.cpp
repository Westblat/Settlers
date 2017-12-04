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
    std::vector<int> distances (size, INT_MAX);

    distances[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = 0;

    Heap *heap = new Heap();
    Node *startNode = new Node(0,start);
    //Node *endNode = new Node(INT_MAX, end);
    std::vector<Node*> nodeIndex (size, heap->nonode);
    nodeIndex[start->getLocation()->getX()*this->width + start->getLocation()->getY()] = startNode;


    heap->insert(startNode);
    std::cout<<" <- First node"<<std::endl;

    std::vector<std::pair<int,int> > directions;
    directions.push_back(std::pair<int, int> (1,0));
    directions.push_back(std::pair<int, int> (0,1));
    directions.push_back(std::pair<int, int> (-1,0));
    directions.push_back(std::pair<int, int> (0,-1));

    //*

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
                    int new_distance = distances[uposindex] + 1; //TODO IMPLEMENT TERRAIN DIFFICULTY
                    if (new_distance < distances[vposindex]) {
                        if (nodeIndex[vposindex]->difficulty != -1) {
                            std::cout<<"old node "<<tempX<<" "<<tempY<<std::endl;
                            heap->decreaseKey(nodeIndex[vposindex],new_distance);
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                        else {
                            Node* vnode = new Node(new_distance, this->getTerrain(tempX, tempY));
                            //std::cout<<"new node "<<tempX<<" "<<tempY;
                            heap->insert(vnode);
                            //std::cout<<std::endl;
                            nodeIndex[vposindex] = vnode;
                            distances[vposindex] = new_distance;
                            previous[vposindex] = u;
                        }
                    }
                }
            }
        }
        checked[uposindex] = true;
        std::cout<<"Checked: "<<upos->getX()<<" "<<upos->getY()<<" Best path: "<<next->difficulty<<std::endl;
    }

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
