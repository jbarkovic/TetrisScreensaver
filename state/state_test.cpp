#include "BoardState.h"
#include <cstdio>
#include <cstdlib>

void printState (BoardState *bs);

int ** bs_state_1;
int ** bs_state_2;
int array1 [4][5] = {
	{0,1,0,1,4},
	{2,2,2,5,5},
	{6,7,8,9,0},
	{2,3,4,5,1}};
int array2 [4][5] = {
	{0,4,4,4,4},
	{4,0,4,4,4},
	{4,4,0,4,4},
	{4,4,4,0,4}};



int main (int argc, char ** argv) {
	printf ("Testing BoardState\n");

	bs_state_1 = (int **) malloc (4*sizeof(int*));
	bs_state_2 = (int **) malloc (4*sizeof(int*));
	for (int i=0;i<4;i++) {
		bs_state_1[i] = (int *) malloc (5*sizeof(int));
		bs_state_2[i] = (int *) malloc (5*sizeof(int));
		for (int j=0;j<5;j++) {
			bs_state_1[i][j] = array1 [i][j];
			bs_state_2[i][j] = array2 [i][j];
		}
	}

	BoardState * bs_test_1 = new BoardState (4, 5, bs_state_1);

	printf ("BS TEST 1: ");
	printState (bs_test_1);
	BoardState *bs_test_2 = new BoardState (*bs_test_1);
	bs_test_2->setState (4, 5, (int **) bs_state_2);

	printf ("BS TEST 2: ");
	printState (bs_test_2);
	printf ("BS TEST 1: ");
	printState (bs_test_1);


	for (int i=0;i<4;i++) {
		for (int j=0;j<5;j++) {
			if (bs_test_1->getState ()[i][j] != array1 [i][j]) {
				printf ("TEST FAILED: BoardState: state_test: internal BoardState was changed: %i & %i should not be different\n",bs_test_1->getState ()[i][j], array1[i][j]);
				return -1;
			}
		}
	}
	printf ("PASSED: BoardState Tests: state_test\n");
	return 0;
}
void printState (BoardState * bs) {
	board_t bs_state = bs->getState ();
	printf ("Rows: %i, Cols: %i\n",bs->rows(),bs->cols());
	for (int i=0;i<bs->rows ();i++) {
		for (int j=0;j<bs->cols ();j++) {
			printf ("[%i]", bs_state [i][j]);
		}
		printf ("\n");
	}
}
