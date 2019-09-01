
#include<iostream>
using namespace std;

enum Color { red, green, blue };
 class Shape 
{
public:
	virtual void draw(Color color = green) const 
	{
		cout << "Green" << endl;
	}
};

class Circle : public Shape
{
public:
	virtual void draw(Color color = red) const override
	{
	
		cout << "Red" << endl;

	}
};

int main()
{
	Shape* sp = new Circle;
	sp->draw(); // Invokes Circle::draw(green) even though the default parameter for Circle is red.
	return 0;
}