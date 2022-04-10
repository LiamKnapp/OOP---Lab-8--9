/********************************************//**
 * @brief this class is used for saving the unkown orientation that we are trying to find
 *
 * the label will be populated at the very end after the correct orientation is found
 *
 * @authors Liam
 * @date 2022-04-10
 ***********************************************/

#include "Header.h"

class UnkownOrient {
	double x;
	double y;
	double z;
	int label;
public:
	UnkownOrient() {
		x = 0;
		y = 0;
		z = 0;
		label = 0;
	}
	UnkownOrient(double x, double y, double z, int label) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->label = label;
	}

	void setX(double x) {
		this->x = x;
	}
	double getX() {
		return x;
	}

	void setY(double y) {
		this->y = y;
	}
	double getY() {
		return y;
	}

	void setZ(double z) {
		this->z = z;
	}
	double getZ() {
		return z;
	}

	void setLabel(int label) {
		this->label = label;
	}
	int getLabel() {
		return label;
	}

};