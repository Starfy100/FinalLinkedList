#include <iostream>

/*
Author: Nicolas F.
Tic Tac Toe: Program will set up a 3x3 board for two players to play Tic Tac Toe
If a player wins or ties, the board will be reset and scores displayed

Start Date: 9/20/19
 */
using namespace std;


void turn(int &player, char &XY);
void clear(char board[3][3],int board2[3][3]);
void print(char board[3][3],int board2[3][3]);
bool legal(char board[3][3]);
bool tie(int board2[3][3]);
void win(int board2[3][3]);

void turn(int &player, char &XY) {//flips player turns every time a spot is filled in
  if (player == 1) {
    XY = 'X';
    player = 2;
  }
  else {
    XY = 'O';
    player = 1;
  }
}

void clear(char board[3][3], int board2[3][3]) { //clears the board arrays
  for (int j = 0; j < 3; j++){
    for (int i = 0; i < 3; i++){
      board[i][j] = 32;
      board2[i][j] = 0;
    }
  }
}

void print(char board[3][3], int board2[3][3]) { //"draws" the board 
  cout << " " << "1" << "2" << "3" << endl;
  for (int j = 0; j < 3; j++){
    cout << j+1;
    for (int i = 0; i < 3; i++){
      cout << board[i][j];
    }
    cout << "\n";
  }
}


bool legal(char board[3][3], char row, char col) { //checks to see if a move is legal
  if (board[col-'1'][row-'1'] == 32) {
    return true;
  }
  return false;
} 


bool tie(int board2[3][3]) { //checks to see if there is a tie
  if (board2[0][0] != 0 && board2[0][1] != 0 && board2[0][2] != 0 && board2[1][0] != 0 && board2[1][1] != 0 && board2[1][2] != 0 && board2[2][0] != 0 && board2[2][1] != 0 && board2[2][2] != 0) {
    return true;
  }
    
    return false;
}


void win(char board[3][3],int board2[3][3], int player, int xwin, int owin) { //checks to see if a player has won
  if (board2[0][0] == player && board2[1][1] == player && board2[2][2] == player) {
    //diagonal win
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }
  
  if (board2[0][0] == player && board2[0][1] == player && board2[0][2] == player) {
    //left column
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }
  
  if (board2[1][0] == player && board2[1][1] == player && board2[1][2] == player) {
    //middle column
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }

  if (board2[2][0] == player && board2[2][1] == player && board2[2][2] == player) {
    //right column
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }
  
  if (board2[0][2] == player && board2[1][1] == player && board2[2][0] == player) {
    //diagonal win
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }

  if (board2[0][0] == player && board2[1][0] == player && board2[2][0] == player) {
    //top row
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }


  if (board2[0][1] == player && board2[1][1] == player && board2[2][1] == player) {
    //middle row
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }
  
  if (board2[0][2] == player && board2[1][2] == player && board2[2][2] == player) {
    //bottom row
    cout << "Victory!" << endl;
    print(board, board2);
    clear(board, board2);
    if (player == 2) {
      xwin++;
    }
    if (player == 1) {
      owin++;
    }
  }

  if (tie(board2) == true) {
    cout << "Tie!" << endl;
    print(board, board2);
    clear(board, board2);
  }

  
  else {
    //cout << "nope" << endl;
  }

  cout << "X Wins: " << xwin << endl;
  cout << "O Wins: " << owin << endl;
  
}


int main() {

  
char board[3][3]; //printed array
int board2[3][3]; //internal array, used to check wins/ties
bool gamestart = true; //keeps the game running
int player = 2; //keeps track of the player turn
//1 = Player X, 2 = Player O
char XY = 'X'; //keeps track of what is written to the array
char row; //keeps track of current row
char col; //keeps track of current column
int xwin = 0; //counts X wins
int owin = 0; //counts O wins


 clear(board, board2);

  
  while (gamestart == true) {

    print(board, board2);
    cout << "Player Turn is: " << player << endl;
    cout << "Select row (1,2 or 3)" << endl; 
    cin.get(row);
    cin.get();
    if (row == '1') {
      cout << "Select column (1,2 or 3)" << endl;
      cin.get(col);
      cin.get();
      if (col == '1') {
      //cout << "row: " << row << endl;
      //cout << "col: " << col << endl;
	legal(board, row, col);
	if (legal(board, row, col) == true){
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
	
      }
  
      if (col == '2') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      if (col == '3') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      else {
	cout << "please enter 1, 2, or 3" << endl;
      }
    }

    
    if (row == '2') {
      cout << "Select column (1,2, or 3)" << endl;
      cin.get(col);
      cin.get();
      
      if (col == '1') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      if (col == '2') {
	legal(board, row, col);
	if (legal(board, row, col) == true){
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      if (col == '3') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      
      else {
	cout << "please enter 1, 2, or 3" << endl;
      }
    }

    if (row == '3') {
      cout << "select column (1, 2, or 3)" << endl;
      cin.get(col);
      cin.get();
      if (col == '1') {
	legal(board, row, col);
	if (legal(board, row, col) == true){
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      if (col == '2') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      
      if (col == '3') {
	legal(board, row, col);
	if (legal(board, row, col) == true) {
	  board[col-'1'][row-'1'] = XY;
	  board2[col-'1'][row-'1'] = player;
	  win(board, board2, player, xwin, owin);
	  turn(player, XY);
	}
      }
      
      else {
	cout << "please enter 1, 2, or 3" << endl;
      }

    }
    
    else {
      cout << "please enter 1, 2, or 3" << endl;
    }
   
  }

  return 0;
}
