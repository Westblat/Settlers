Source code, makefiles, etc. here.

How to create a makefile:

qmake -o makefile main.pro



Class descriptions:
//!!TODO!! ADD MORE CLASSES WITH SPECIFIC DESCRIPTIONS

Settler(std::string name, Building *home)
//Settler should be created with parameter name and building
Public:
	std::string getName //Returns name
	std::string getTask //Returns current task
	bool setTask(std::string task) //Returns true if succesful else false
	vector<int> getItems() //Returns vector of items
	bool addItem(int item) //Returns true if item added succesfully else false
	bool removeItem(int item) //Returns true if item found and removed else false
	Building getHome() //Returns home
	bool setHome(Building *home) //Returns true if succesful else false, also adds Settler to Buildings "residents" 
	int getHP() //Returns HP value
	int setHP() //Returns new HP value
	void pushPath(int x, int y) //Push direction to path
	void setDelay(int time) //Set wait time (actionDelay) for next simulation
	bool reduceDelay() //Reduces wait time by one, returns true if actionDelay==0
	int getDelay() //Returns actionDelay
Private:
	std::string name //SettlersName
	std::string task //Current task
	int hp //Current HitPoints
	Building *home //Building Settler is tied to, !!might be unneeded!!
	pair<vector<int> items, int maxsize> //Inventory, first part is content, second max size "-1 for unlimtited, 0 for 0, pos item for defined size"
	bool playerControlled //Determines if player can control this settler
	Coordinates location //Settlers keep track of their location
	std::queue<pair<int,int> > path //Movement path, contains directions 
	int actionDelay //How much time action takes
	

Game()
Public:
	Map& getMap() //Returns reference to game map
	vector<Building*>& getBuildings() //Returns vector of buildings
	vector<Settler*>& getSettlers() //Returns vector of Settlers
	void simulate() /* Iterates through all settlers and simulates next step, updates settlers position and inventory based on their current task */
Private:
	Map map
	vector<Building*> buildings
	vctor<Settler*> units
	TaskHandler Ai
	
	
Building()
/*When building is created it is set not ready (you have to build it first), buildings inventory is filled with items required to complete building,
build-member function removes items from inventory until its empty, then buildin is set ready and functional */
Public:
	bool addItem(int item) //Returns true if item added succesfully else false
	bool removeItem(int item) //Returns true if item found and removed else false
	bool build(int item) //See Building description for more detailed description,
	bool setReady() //Works for not ready buildings, automatically completes building, empties inventory and sets isReady->true
Private:
	int type //Building "name"
	pair<vector<int> items, int maxsize> //Same as in Settler
	bool isReady //Determines  if building is built
	vector<Settler*> residents //Settlers tied to the building
	
	
Map(int width, int height)
Public:
	int getWidth() //Returns width
	int getHeight() //Returns height
	vector<vector<Terrain*> >& getMap() //Returns map
	void setMap() //Sets map from predifined file
	bool contains(Coordinates coord) //Returns true if given coordinates x and y values are within map
Private:
	int width //Width
	int height //Height
	vector<vector<Terrain*> > map //Vector of vectors containing Terrain objects [x][y]-map
	
	
Terrain(Coordinates *coord, int type)
Public:
	Coordinates getLocation() //Returns location
	bool isBlocked() //Returns blocked 
	void toggleBlock() //Toggles blocked value true/false
	int getType() //Returns terrain type int
	void setType(int newType) //Sets terrain type
Private:
	Coordinates *location //Coordinates object for coordinates
	int type //Terrain type
	bool blocked //Represents if terrain is pathable
	
	
Coordinates(int x, int y)
Public:
	int get_x()
	int get_y()
	Coordinates get_next(int x, int y)
	bool updateCoords(int x, int y) //Sets new coordinate
Private:
	int x
	int y