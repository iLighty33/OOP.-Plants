#include <iostream>
#include <string>

using namespace std;

class Plants {
public:
	static int fruits_;
	static int berries_;

	Plants() {
		count_++;
	}
	Plants(string name, int count) :Plants() {
		name_ = name;
		fruits_ += count;
	}

	virtual ~Plants() {
		count_--;
	}

	void setName(string name) {
		name_ = name;
	}

	string getName() {
		return name_;
	}
	static int getCounter() {
		return count_;
	}
	static int getFruits() {
		return fruits_;
	}

private:
	string name_;
	static int count_;
};

class Trees : Plants {
public:
	Trees() {}
	Trees(string name, int count) {
		Plants::setName(name);
		berries_ += count;
	}
	virtual ~Trees() {}
	void setName(string& name) {
		name_ = name;
	}
	string getName() {
		return name_;
	}

	int getFetus(int fetus) {
		fetus_ -= fetus;
		return fetus_;
	}
private:
	string name_;
	int fetus_;
};

class Bushes : Plants {
public:
	Bushes() {}
	Bushes(string name, int count) {
		Plants::setName(name);
		berries_ += count;
	}
	virtual ~Bushes() {}
};

class Fetus {
public:
	Fetus() {}
	virtual ~Fetus() {}
	static int getFetus() {
		return Plants::fruits_ + Plants::berries_;
	}
};

class Fruits : Fetus {
public:
	Fruits() {}

	virtual ~Fruits(){}
	static int getFetus(int fetus) {
		Plants::fruits_ -= fetus;
		return Plants::fruits_;
	}
};

class Berries : Fetus {
public:
	Berries() {}

	virtual ~Berries() {}
	static int getFetus(int fetus) {
		Plants::berries_ -= fetus;
		return Plants::berries_;
	}
};
int Plants::fruits_ = 0;
int Plants::berries_ = 0;
int Plants::count_ = 0;

int main() {

	Trees Bereza("Bereza", 5);
	Trees Topol("Topol", 6);

	Bushes Kustarnik("Kustarnik", 50);
	Bushes Repeynik("Repeynik", 30);

	std::cout << "Common quantity of objects: " << Plants::getCounter() << endl;
	std::cout << "Common quantity of fruits: " << Plants::fruits_ << endl;
	std::cout << "Common quantity of berries: " << Plants::berries_ << endl;

	int n = 5;

	std::cout << "getting Fetus: " << n << " " << Fruits::getFetus(n) << endl;
	std::cout << "getting Berries: " << n << " " << Berries::getFetus(n) << endl;
	std::cout << "Commont quantity of getted Fetus: " << Fetus::getFetus() << endl;
	
	return 0;
}