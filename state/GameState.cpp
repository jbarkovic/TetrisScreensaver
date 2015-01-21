#include "GameState.h"

void GameState::cloneFrom (GameState old) {
	setState (new BoardState (old.getBoardWithoutCurrentShape()), new ShapeState (old.currentShape));
}
void GameState::setState (BoardState boardState, ShapeState shapeState) { // Will take gameboard with or without current shape
	currentShape = new ShapeState(shapeState);
	int [][] boardWithout 	= boardState.getStateCopy();
	int [][] boardWith 		= boardState.getStateCopy();
	int [][] shapeCoords 	= currentShape.getCoords();
	int type = this->currentShape.getType ();
	for (int [] coord : shapeCoords) {
		boardWith 		[coord[0]] [coord[1]] 	= type;
		boardWithout 	[coord[0]] [coord[1]] 	= 0;
	}
	boardWithCurrentShape 	= new BoardState (boardWith);
	boardWithoutCurrentShape 	= new BoardState (boardWithout);
}
int [] GameState::getBoardSize () {
	return boardWithCurrentShape.size();
}
BoardState GameState::getBoardWithCurrentShape (void) {
	return boardWithCurrentShape;
}
BoardState GameState::getBoardWithoutCurrentShape (void) {
	return boardWithoutCurrentShape;
}
ShapeState GameState::getShape (void) {
	return currentShape;
}
void GameState::setCurrentShape (ShapeState newCurrentShape) {
	setState(boardWithoutCurrentShape, newCurrentShape);
}
void GameState::invalidate (void) {
	setState (boardWithoutCurrentShape, currentShape);
}

