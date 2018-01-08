#include <iostream>
#include <utility>
#include <string.h>

class TicTacToe {
 public:
  using Location = std::pair<int, int>;
  enum Player { NoPlayer = 0, Player1, Player2 };
  enum Result { NoWin = 0, Win, InvalidMove };
  
  int board[4][4]; //assuming 4x4 board
  TicTacToe();
  ~TicTacToe();
  
  ///
  /// \brief MakeMove Interface for the game playing system to add a new move to
  /// the game.
  /// \param player   Player making this move.
  /// \param location The selected location. X=first, Y=second
  /// \return Result of the move. Win if the move wins the game, Invalid move if
  /// input has errors, NoWin otherwise.
  ///
  
  Result MakeMove(Player player, Location location);
  
  void ResetGame();
  
 private:
};


TicTacToe::TicTacToe() {
  // Add any initializations for the data structures.
  memset(board, 0, sizeof(board)); //initializing 0
}

TicTacToe::~TicTacToe() {
  // Add any clean-up or deallocations needed.
}


TicTacToe::Result TicTacToe::MakeMove(Player player, Location location)
{
  if (location.first<0 || location.first>3 || location.second>3 || location.second<0 )
  {
    return InvalidMove;
  }
  //storing player value i.e. 1 for player 1 and 2 for player 2 at location
  board[location.first][location.second]=player;

  
  {
    if(board[location.first][0]==board[location.first][1] && board[location.first][1]==board[location.first][2] && board[location.first][2]==board[location.first][3] && board[location.first][0]>0 && board[location.first][1]>0 && board[location.first][2]>0 && board[location.first][3]>0)
    { //for horizontal
      return Win;
    }
    if(board[0][location.second]==board[1][location.second] && board[1][location.second]==board[2][location.second] && board[2][location.second]==board[3][location.second] && board[0][location.second]> 0 && board[1][location.second] >0 && board[location.second][3]>0 && board[2][location.second]>0)
    { //for vertical
      return Win;
    }
    
  }
  
  //checking diagonals 
  if(board[0][0] >0 && board[1][1] >0 && board[2][2] >0 && board[0][2]>0 && board[2][0]>0 && board[3][3]>0)
  {
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==board[3][3])||(board[0][3]==board[1][2]&& board[1][2]==board[2][1] && board[2][1]==board[3][0]))
    {
      return Win;
    }
  }
  // Validate parameters, update game state and check for win condition.
  return NoWin;
}

void TicTacToe::ResetGame() {
  memset(board, 0, sizeof(board)); //clear board back to 0
  // Clear the game state for a new game.
}


TicTacToe game;

int main(int argc, char** argv) {
  std::cout << "Starting test!" << std::endl;
  const TicTacToe::Player player1 = TicTacToe::Player1;
  const TicTacToe::Player player2 = TicTacToe::Player2;
    
  std::cout<<"testCase 1 checking"<<std::endl;
  if (game.MakeMove(player1, TicTacToe::Location(1, 0)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2, 0)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player1, TicTacToe::Location(0, 1)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2, 1)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player1, TicTacToe::Location(1, 2)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2, 2)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player1, TicTacToe::Location(1, 1)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2,3)) != TicTacToe::NoWin) {

    if(game.MakeMove(player2, TicTacToe::Location(2, 3))==1)

      std::cout << "WIN GAME" << std::endl;
    else
      std::cout << "INVALID MOVE" << std::endl;

    game.ResetGame(); //reset the board

  }
     
    std::cout<<"testCase 2 checking"<<std::endl;
  if (game.MakeMove(player1, TicTacToe::Location(1, 0)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2, 0)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player1, TicTacToe::Location(0, 1)) != TicTacToe::NoWin) {
    std::cout << "Test failed!" << std::endl;
  }
  if (game.MakeMove(player2, TicTacToe::Location(2, 4)) != TicTacToe::NoWin) {
    if(game.MakeMove(player2, TicTacToe::Location(2, 2))==1)

      std::cout << "WIN GAME" << std::endl;
    else
      std::cout << "INVALID MOVE" << std::endl;

    game.ResetGame(); //reset the board

  }
    
  
  
  // Add some useful test cases.
  //testcase 1:
  //player 1 location 1 0
  //player 2 location 2 0
  //player 1 location 0 1
  //player 2 location 2 1
  //player 1 location 1 2
  //player 2 location 2 2
  // Win condition
  
  //testcase 2:
  //player 1 location 1 0
  //player 2 location 2 0
  //player 1 location 0 1
  //player 2 location 2 3
  // InvalidMove condition
  
  //testcase 3:
  //player 1 location 1 0
  //player 2 location 2 0
  //player 1 location 0 1
  //player 2 location 2 1
  //player 1 location 2 2
  //player 2 location 1 2
  //Player 1 location 0 2
  //Player 2 location 0 0
  //Player 1 location 1 1
    // No Win condition
  
  return 0;
}

