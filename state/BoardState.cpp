#include "BoardState.h"
#include <cstdio>

BoardState::BoardState (BoardState & old) {
	this->setState (old.getStateCopy ());
}
BoardState::BoardState (board_t board) {
	this->setState (board);
}
BoardState::BoardState (int rows, int cols, int ** board) {
	this->setState (rows, cols, board);
}
void BoardState::setState (int rows, int cols, int ** board) {
	board_t new_board = board_t (rows, row_t (cols));
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			new_board [i][j] = board [i][j];
		}
	}
	setState (new_board);
}
void BoardState::setState (board_t const &board) {
	gameSize [0] = (int) board.size ();
	gameSize [1] = (int) (board [0]).size ();
	boardSpaces = copyBoard (board);
}
board_t BoardState::getState (void) {
	return boardSpaces;
}
board_t BoardState::getStateCopy (void) {
	return copyBoard (boardSpaces);
}
board_t BoardState::copyBoard (board_t board) {
	board_t copy_board = board_t (board);
	return copy_board;
}
