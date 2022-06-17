#include <iostream>
#include <string>

using namespace std;

class Plants {

};

class Trees : Plants {
public:
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

};

class Fetus {

};

class Fruits : Fetus {

};

class Berries : Fetus {

};

int main() {
	return 0;
}