#pragma once
#include "Subject.h"

class Figure : public Subject
{
	int x;
	int y;
	int size;
public:
	Figure() { size = 30; };

	int getX() { return x; }
	int getY() { return y; }
	int getSize() { return size; }

	void setX(int x) {
		if (x >= 0)
			this->x = x;
		notifyObservers();
	}
	void setY(int y) {
		if (y >= 0)
			this->y = y;
		notifyObservers();
	}
	void setSize(int size) {
		if (size > 0)
			this->size = size;
		notifyObservers();
	}
};

