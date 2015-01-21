#include "ShapeState.h"
#include <iostream>

ShapeState::ShapeState (int num_coords, int coords [][2], SHAPETYPE type) {
	setState (num_coords, coords, type);
}
ShapeState::ShapeState (ShapeState & old) {
	setState (old.num_coords, old.getCoordsCopy(), old.type);
}
void ShapeState::setState (int num_coords, int coords [][2], SHAPETYPE type) {
	this->coords = shcoords_t (coords, coords + sizeof(coords)/sizeof (int [2]));
	this->type = type;
}
void ShapeState::setState (shcoords_t coords, SHAPETYPE type) {
	this->coords = coords;
	this->type = type;
}
shcoords_t ShapeState::getCoordsCopy () {
	shcoords_t copy = shcoords (coords);

/*	int copy [][] = new int [4][2];

	// I unrolled the loop here
	copy [0][0] = this->coords [0][0];
	copy [0][1] = this->coords [0][1];
	copy [1][0] = this->coords [1][0];
	copy [1][1] = this->coords [1][1];
	copy [2][0] = this->coords [2][0];
	copy [2][1] = this->coords [2][1];
	copy [3][0] = this->coords [3][0];
	copy [3][1] = this->coords [3][1];*/
	return copy;
}
bool ShapeState::contains (int coord [2]) {
	bool contains = true;
	// I unrolled the loop here
	contains &= (!memcmp (this->coords[0],coord,2));
	contains &= (!memcmp (this->coords[1],coord,2));
	contains &= (!memcmp (this->coords[2],coord,2));
	contains &= (!memcmp (this->coords[3],coord,2));
	return contains;
}
