#include "BoardState.h"
#include "ShapeState.h"

class GameState {
	private:
		BoardState boardWithCurrentShape;
		BoardState boardWithoutCurrentShape;
		ShapeState currentShape;
	public:
		void cloneFrom (GameState const &old);
		void setState (BoardState boardState, ShapeState shapeState);
		int [] getBoardSize (void);
		BoardState getBoardWithCurrentShape (void);
		BoardState getBoardWithoutCurrentShape (void);
		ShapeState getShape (void);
		void setCurrentShape (ShapeState newCurrentShape);
		void invalidate (void);
};

