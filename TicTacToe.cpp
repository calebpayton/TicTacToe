/*
 * Author: Caleb A. Payton
 * Tic-Tac-Toe game that randomly decides who goes first, computer or player.
 * Have not yet created an AI for the computer's move. It simply choses a random move each turn.
 */

#include <iostream>
#include<time.h> 
#include<cstdlib>

using namespace std;

class TicTacToe {
      public:
             char board[9]; 
             int turn;
             
             TicTacToe() { 			   
			        int i;
                    for (i=0; i<9; i++) {
                        	board[i] = ' ';
                    }
             } //end constructor
              
             void drawBoard(void);
             bool checkMove(int);
             bool checkWin(void);
             char winner(void);
             bool catsGame(void);
             int whoseMove(void);
             int gamePlay(void);
} ; //end class TicTacToe

void TicTacToe::drawBoard(void) {
            
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n"; 

} //end drawBoard

bool TicTacToe::checkMove(int space) {
	if (board[space] == ' '){
		return true;
	} else if ((board[space] == 'X') || (board[space] == 'O')) {
		return false;
	}	
} //end checkMove
 
int TicTacToe::whoseMove(void){
	srand(time(NULL));
	turn = rand()%2;	
	return turn;
} //end whoseMove

char TicTacToe::winner(void) {	
    if((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X'))
		return 'X';	
	if((board[3] == 'X') && (board[4] == 'X') && (board[5] == 'X'))
		return 'X';	
	if((board[6] == 'X') && (board[7] == 'X') && (board[8] == 'X'))
		return 'X';	
	if((board[0] == 'X') && (board[3] == 'X') && (board[6] == 'X'))
		return 'X';	
	if((board[1] == 'X') && (board[4] == 'X') && (board[7] == 'X'))
		return 'X';	
	if((board[2] == 'X') && (board[5] == 'X') && (board[8] == 'X'))
		return 'X';	
	if((board[0] == 'X') && (board[4] == 'X') && (board[8] == 'X'))
		return 'X';	
	if((board[2] == 'X') && (board[4] == 'X') && (board[6] == 'X'))
		return 'X';	
	if((board[0] == 'O') && (board[1] == 'O') && (board[2] == 'O'))
		return 'O';	
	if((board[3] == 'O') && (board[4] == 'O') && (board[5] == 'O'))
		return 'O';	
	if((board[6] == 'O') && (board[7] == 'O') && (board[8] == 'O'))
		return 'O';	
	if((board[0] == 'O') && (board[3] == 'O') && (board[6] == 'O'))
		return 'O';	
	if((board[1] == 'O') && (board[4] == 'O') && (board[7] == 'O'))
		return 'O';	
	if((board[2] == 'O') && (board[5] == 'O') && (board[8] == 'O'))
		return 'O';	
	if((board[0] == 'O') && (board[4] == 'O') && (board[8] == 'O'))
		return 'O';	
	if((board[2] == 'O') && (board[4] == 'O') && (board[6] == 'O'))
		return 'O';	
	else
		return ' ';
} //end winner

bool TicTacToe::checkWin(void) {
	if((winner() == 'X') || (winner() == 'O'))
		return true;
} //end checkWin

int TicTacToe::gamePlay(void) {
    int playermove, computermove;
	
	if(turn == 0){
		cout << "Enter space on board (0-8): ";
		cin >> playermove;
		
		if(checkMove(playermove) == true) {
			board[playermove] = 'O';
			turn = 1;
		} else if (checkMove(playermove) == false) {
			cout << "Invalid Move!" << endl;
			gamePlay();
		}
	}

	if(turn == 1) {
		srand(time(NULL));
		computermove = rand()%9;
		
		if(checkMove(computermove) == true) {
			board[computermove] = 'X';
			turn = 0;
		} else if(checkMove(computermove) == false) {
			turn = 1;
		}		
	}
} //end gamePlay

bool TicTacToe::catsGame(void) {
	int catsCount = 0;
	int i;
	for(i = 0; i < 9; i++) {
		if(board[i] == ' ')
			catsCount = catsCount + 1;
	}
	
	if(catsCount > 0)
		return false;
	else if((catsCount == 0) && !checkWin())
		return true;
} //end catsGame

int main() {
       TicTacToe Game;
        
        Game.whoseMove();
        if(Game.whoseMove() == 0)
       		cout << "You get the first move!" << endl;
		else if(Game.whoseMove() == 1)
			cout << "Computer gets the first move!" << endl;
	    
        do {       		 
             Game.drawBoard();             
             Game.gamePlay(); 
             
             if(Game.catsGame())
       	    	break;
       } while(!Game.checkWin()); //end while
       
       Game.drawBoard();
       
    	if((Game.catsGame()) && (Game.winner() == ' '))
       		cout << "\nCat wins!" << endl;
       	else if(Game.winner() == 'X')
		    cout << "\nX wins!" << endl;
		else
			cout << "\nO wins!" << endl;    	

} //end main
