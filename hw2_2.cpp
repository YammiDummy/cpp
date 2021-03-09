#include <iostream>
#include <string>

using namespace std;

class Fruit {
	private:
		
		string m_name;
		string m_color;
	
	public:
		
		Fruit (string name, string color)
		:m_name(name), m_color(color) {}
	
	string getName () {
		return m_name;
	}
	
	string getColor () {
		return m_color;
	}
	
	friend class GrannySmith;
};

class Apple: public Fruit {
	
	public:
	
		Apple (string color)
		:Fruit("apple", color) {}
};

class Banana: public Fruit {
	
	public:
		Banana():Fruit("banana", "yellow"){}
};

class GrannySmith: public Apple {
	
	public:
		GrannySmith ()
		:Apple("green") {
			m_name = "Granny Smith apple";
		}
};

int main () {
	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
