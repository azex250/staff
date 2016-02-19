#include <iostream>
#include <set>
#include <stack>
#include <cstdlib>

#define RED     "\033[31m" 
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

using std::set;   
using std::stack;   
using std::cout;  
using std::cin;  
using std::rand;  

typedef struct {
	int i;
	int j;
	int c;
} position; 

class labyrinth {
public:
	labyrinth(int);
	~labyrinth();
	void printGrid(void);
	bool setStartPosition(int, int);
	bool openRandomCell(void);
	bool openCell(int, int);
	bool getWayOut(void);
protected:
	bool * greed;
	int greed_side;
	int greed_size;
	int cells_opened;
	position current_position;
	position start_position;
	stack<position> way_out;
	stack<position> tees;
	set<int> steps;

	struct {
		bool up;
		bool down;
		bool left;
		bool right;
	} possible_ways;

	bool setPosition(int, int);
	int checkDirection();
	bool makeStep();
	bool isExit();

};

labyrinth::labyrinth(int greedSide) {
	greed_side = greedSide;
	greed_size = greed_side * greed_side;
	cells_opened = 0;
	greed = new bool[greed_size];

	current_position.i = -1;
	current_position.j = -1;
	current_position.c = -1;
	start_position = current_position;

	for (int i = 0; i < greed_size; ++i) {
		greed[i] = false;
	}
}

labyrinth::~labyrinth() {
	delete[] greed;
}

bool labyrinth::setStartPosition(int x, int y) {
	openCell(x, y);
	if(setPosition(x, y)) {
		start_position = current_position;
		return true;
	}
	return false;
}

void labyrinth::printGrid(void) {

	cout<<"<---\n";
	for (int i = 0, j = 0; i < greed_size; ++i, ++j) {
		if (start_position.c == i) {
			cout << YELLOW;
		} else if (current_position.c == i) {
			cout << RED;
		} else if (steps.find(i) != steps.end()) {
			cout << BLUE;
		}
		if (j == greed_side) {
			j = 0;
			cout << '\n';
		}
		if (greed[i]) {
			cout<<" o";
		} else {
			cout<<" x";
		}
		cout << RESET;
	}
	cout<<"\n--->\n";
}

bool labyrinth::openRandomCell() {
	if (cells_opened == greed_size) {
		return false;
	} else {
		cells_opened++;
		for (int i;;) {
			i = rand() % greed_size;
			if (!greed[i]) {
				return greed[i] = true;
			}
		}
	}
}

bool labyrinth::setPosition(int i, int j) {
	if (i < greed_side && i >= 0 
		&& j < greed_side && j >=0 
		&& greed[i + j * greed_side]
	) {
		current_position.i = i;
		current_position.j = j;
		current_position.c = i + j * greed_side;
		way_out.push(current_position);
		steps.insert(current_position.c);
		return true;
	}
	return false;
}

int labyrinth::checkDirection() {
	possible_ways.up = false;
	possible_ways.down = false;
	possible_ways.left = false;
	possible_ways.right = false;

	int res = 0;


	if (current_position.j > 0 
		&& greed[current_position.i + (current_position.j - 1) * greed_side]
		&& steps.find(current_position.i + (current_position.j - 1) * greed_side) == steps.end()
	) {
		possible_ways.up = true;
		res++;
	}

	if (current_position.j  < greed_side 
		&& greed[current_position.i + (current_position.j + 1) * greed_side]
		&& steps.find(current_position.i + (current_position.j + 1) * greed_side) == steps.end()
	) {
		possible_ways.down = true;
		res++;
	}

	if (current_position.i > 0 
		&& greed[current_position.i - 1 + current_position.j * greed_side]
		&& steps.find(current_position.i - 1 + current_position.j * greed_side) == steps.end()
	) {
		possible_ways.left = true;
		res++;
	} 

	if (current_position.i  < greed_side 
		&& greed[current_position.i + 1 + current_position.j * greed_side]
		&& steps.find(current_position.i + 1 + current_position.j * greed_side) == steps.end()
	) {
		possible_ways.right = true;
		res++;
	}

	return res;
}

bool labyrinth::makeStep() {
	switch (checkDirection()) {
		case 0: {
			return false;
		}
		case 1: {
			break;
		}
		default: {
			tees.push(current_position);
		}
	}

	if (possible_ways.up) {
		setPosition(current_position.i, current_position.j - 1);
	} else if(possible_ways.down) {
		setPosition(current_position.i, current_position.j + 1);
	} else if(possible_ways.left) {
		setPosition(current_position.i - 1, current_position.j);
	} else {
		setPosition(current_position.i + 1, current_position.j);
	}
	
	return true;
}

bool labyrinth::isExit() {
	if (current_position.c != start_position.c 
		&& (current_position.i == 0 
		|| current_position.j == 0 || current_position.i == greed_side - 1 
		|| current_position.j == greed_side - 1)
	) {
		return true;
	}

	return false;
}

bool labyrinth::getWayOut() {
	steps.erase(steps.begin(), steps.end());
	while(tees.size()) {
		tees.pop();
	}
	while(way_out.size()) {
		way_out.pop();
	}

	setPosition(start_position.i, start_position.j);

	if (start_position.c < 0) {
		return false;
	}
	while(!isExit()) {
		if(!makeStep()) {
			if(!tees.size()) {
				return false;
			} else {
				current_position = tees.top();
				tees.pop();
				while(current_position.c != way_out.top().c) {
					way_out.pop();
				}
			}
		}
	}

	while(way_out.size()) {
		cout << "i=" << way_out.top().i << " j=" << way_out.top().j << "\n";
		way_out.pop();
	}
	return true;
}

bool labyrinth::openCell(int x, int y) {
	if (x < 0 || y < 0 || y >= greed_side || x >= greed_side) {
		return false;
	} else {
		greed[x + y * greed_side] = true;
		return true;
	}
}


int main(void) {
	/*labyrinth a(5);
	a.openCell(2, 1);
	a.openCell(1, 1);
	a.openCell(1, 2);
	a.openCell(1, 3);
	a.openCell(1, 4);
	a.openCell(3, 1);
	a.openCell(3, 2);
	a.openCell(3, 3);
	a.openCell(4, 3);
	//a.openCell(3, 4);
	//a.openCell(4, 1);
	a.setStartPosition(2,0);
	a.getWayOut();
	a.printGrid();
	*/
	
	int n, m;
	bool b;
	cout << "print grid size\n";
	cin >> n;
	labyrinth a(n);
	cout<<"print start position i j\n";
	cin >> n >> m;
	a.setStartPosition(n, m);
	a.printGrid();
	do {
		cout << "enter cell to open i j \n";
		cin >> n >> m;
		a.openCell(n, m);
		b = a.getWayOut();
		a.printGrid();
	} while(!b);

	

	return 0;
}