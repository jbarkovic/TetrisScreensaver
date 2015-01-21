#include <vector>

using std::vector;

typedef vector<int> row_t;
typedef vector<row_t> board_t;

class BoardState {
	private:
		int gameSize [2];
		board_t boardSpaces;
		board_t copyBoard (board_t board);
	public:
		BoardState (BoardState &old);
		BoardState (int rows, int cols, int ** board);
		BoardState (board_t board);
		int rows (void) {return gameSize [0];}
		int cols (void) {return gameSize [1];}
		void setState (board_t const &board);
		void setState (int rows, int cols, int ** board);
		board_t getState (void);
		board_t getStateCopy (void);
};
