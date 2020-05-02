#include <stdio.h>
#define CELL_SIZE 9 /*array size*/
void print_board(char cell[]);
int play_game(int turn, char cells[],int *);
void initial_game(char cells[]);
int check_endgame(int turn, char cells[], int *);
int play_again(); 
int main() {
	
	do {
		char cell_value[CELL_SIZE] = { '1','2','3','4','5','6','7','8','9' };/*initialising board array for replacing with X's or O's */
		int turn = 1;
		int counter = 0; /*counting the turns in order to recognize draw situation*/
		int *ptr;
		ptr = &counter;
		int check_stop;
		initial_game(cell_value);
		while (check_endgame(turn, cell_value, ptr) < 0)
		{
			check_stop = play_game(turn, cell_value, ptr);
			/*check if everything went ok*/
			if (check_stop > 0)
			{	/*turn changer*/
				if (turn == 1)
				{
					turn = 2;
				}
				else {
					turn = 1;
				}
			}
			print_board(cell_value);
		}
	} while (play_again());
	return 0;
}

void initial_game(char cells[]) {
	printf("\n\n\tTic Tac Toe\n\n");
	printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
	/*initials the game every time*/
}

int play_game(int turn, char cells[],int *counter) {
	char char_turn;
	int place;
	/*turn charcter assignment*/
	if (turn == 1)
	{
		char_turn = 'X';
	}
	else {
		char_turn = 'O';
	}
	printf("It's %c's turn \n", char_turn);
	printf("please enter a place for your turn: \n");
	scanf_s("%d", &place);
	if (!feof(stdin)) {
		getchar();
	}
	if (place != 1 &&
		place != 2 &&
		place != 3 &&
		place != 4 &&
		place != 5 &&
		place != 6 &&
		place != 7 &&
		place != 8 &&
		place != 9)/*checking if input is in range*/ 
	{
		printf("input out of bound.please enter a number between 1 to 9. \n\n");
		return -1;
	}
	/* checing if its an emptyplace*/
	if (cells[place-1]=='X' || cells[place-1] == 'O')
	{
		printf("It's already full.choose another place. \n\n");
		return -1;
	}
	else {
		cells[place-1] = char_turn;
		*counter = *counter + 1;
		return 1;
	}
}

void print_board(char cell[]) {
	printf("\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", cell[0], cell[1], cell[2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", cell[3], cell[4], cell[5]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", cell[6], cell[7], cell[8]);
	printf("     |     |     \n\n"); /*printing the board for players */
}

int check_endgame(int turn, char cells[],int *counter) {
	
	char winner;
	if (turn==1)
	{
		winner = 'O';
	}
	else {
		winner = 'X';
	}
	if (cells[0]==cells[1] && cells[1] == cells[2] ||
		cells[3] == cells[4] && cells[4] == cells[5] || 
		cells[6] == cells[7] && cells[7] == cells[8] || 
		cells[0] == cells[3] && cells[3] == cells[6] || 
		cells[1] == cells[4] && cells[4] == cells[7] || 
		cells[2] == cells[5] && cells[5] == cells[8] || 
		cells[0] == cells[4] && cells[4] == cells[8] || 
		cells[2] == cells[4] && cells[4] == cells[6]  ) /*first row check then column check finally diagonal check*/
	{
		printf("\n\n");
		printf("%c is the winner \n", winner);
		printf("congratulations %c \n", winner);
		return 1;
	}
	else if(*counter==9){
	
		printf("It's a draw! \n\n");
		return 1;
	}
	else
	{
		return -1;
	}
}

int play_again() {
	int quit; /*local variable to determine quit*/
	printf("Do you want to play again? \n");
	printf("1-play again! \n");
	printf("2-Exit \n");
	scanf_s("%d", &quit);
	if (quit==1)
	{
		return 1;
	}
	else {
		return 0;
	}
}