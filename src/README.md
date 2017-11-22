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
	bool setHome(Building *home) //Returns true if succesful else false, also removes Settler from Buildings "residents" 
	int getHP() //Returns HP value
	int setHP() //Returns new HP value
Private:
	std::string name //SettlersName
	std::string task //Current task
	int hp //Current HitPoints
	Building *home //Building Settler is tied to, !!might be unneeded!!
	pair<vector<int> items, int maxsize> //Inventory, first part is content, second max size


Building()
Public:
	/!!TODO!!
Private:
	int type //Building "name"
	vector<Settler*> residents //Settlers tied to the building
	
	
Map(int width, int height)
Public:
	int getWidth() //Returns width
	int getHeight() //Returns height
	vector<vector<Terrain*> >& getMap() //Returns map
	void setMap() //Sets map from predifined file
Private:
	int width //Widht
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
Private:
	int x
	int y