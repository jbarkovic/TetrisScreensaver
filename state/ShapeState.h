#include "SHAPETYPE.h"
#include <vector>
typedef <vector<int [2] > shcoords_t;

class ShapeState {
	private:
		shape_coords_t coords;
		SHAPETYPE type;
	public:
		ShapeState (int num_coords, int coords [][2], SHAPETYPE type);
		ShapeState (ShapeState &old);
		void setState (shcoords_t coords, SHAPETYPE type);
		void setState (int num_coords, int coords [][2], SHAPETYPE type);
		shcoords_t getCoords () {return coords;}
		shcoords_t getCoordsCopy ();
		SHAPETYPE getType () {return type;}
		bool contains (int coord [2]);
};
