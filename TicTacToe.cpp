#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Square NxN board, win with N consecutive.
static int count = 0; //Counts the number of places filled in the Tic Tac Toe

class TicTacToe {
 public:
  ///
  /// \brief MakeMove Interface for the game playing system to add a new move to
  /// the game.
  /// \param player   Player making this move.
  /// \param location The selected location on the board.
  /// \return Result of the move, including the new game status such as Win, Invalid, etc.
  ///
  //Result MakeMove(Player player, Location location);

  /* Structure for calculating the location of the player */
  struct Location{
    int x;
    int y;
    public:
    void set_x(int val){
      x = val;
    }
    void set_y(int val){
      y = val;
    }
    int get_x(){
      return x;
    }
    int get_y(){
      return y;
    }
    int get_index(TicTacToe T){
      if(x >=T.get_max_size() || y >= T.get_max_size()){
        //cout << "Invalid points" << endl;
        return -1;
      }
     return x*T.get_max_size()+y;
    }
  };


  /* Structure for player information */
  struct Player{
    int id;
    char symbol;

    public:
    void create_id(int val){
      if(val<=0 || val>2){
        cout << "Invalid id. Game can be played between two people only" << endl;
        return;
      }
      id = val;
    }
    int get_id(){
      return id;
    }

    void create_symbol(char val){
      symbol = val;
    }
    char get_symbol(){
      return symbol;
    }

  };


  /* Structure for Result of the move */
  struct Result{
    string res;
    public:
    void set_result(string val){
      res = val;
    }
    string get_result(){
      return res;
    }
  };

  /* Initializations for the location, player and result */
  Location l;
  Player p1;
  Player p2;
  Result R;

  /* Calculate the move */
  Result MakeMove(Player player,Location location, TicTacToe t){
    if(get_prev_id() == player.get_id()){
      cout << "You have to play alternatively, dude" << endl;
      R.set_result("Invalid Move");
      return R;
    }
    if(location.get_x() >= t.get_max_size()  || location.get_y() >= t.get_max_size()){
      cout << "Out of range. Play again" << endl;
      R.set_result("Invalid Move");
      return R;
    }
    if(get_value_at_position(location.get_index(t)) == 'x' || get_value_at_position(location.get_index(t)) == 'o'){
      cout << "Position already filled" << endl;
      R.set_result("Invalid Move");
      return R;
    }
    set_value_at_position(location.get_index(t),player.get_symbol());
    if(gameWon(location.get_index(t),player.get_symbol())){
      R.set_result("Win");
      return R;
    }
    count++;
    if(count >= N*N){
      R.set_result("Draw");
      return R;
    }
    prev_id = player.get_id();
    R.set_result("Other player's turn");
    return R;

  }

  /* Set the size of the Tic Tac Toe */
  void set_max_size(int s){
    N = s;
  }


  /* Get the size of Tic Tac Toe */
  int get_max_size(){
    return N;
  }


  /* Set the value at a specific position */
  bool set_value_at_position(int i,char symbol){
    if(i>=N*N){
      cout << "Invalid position" << endl;
      return 0;
    }
    board[i] = symbol;
  }

  /* Find out the value at a given positon */
  char get_value_at_position(int i){
    if(i>=N*N){
      cout << "Invalid position" << endl;
      return 0;
    }
    return board[i];
  }


  /* Resize the vector to the given dimensions */
  void resize_vector(){
    board.resize(N*N);
  }

  /* Checks if the player won the game or not */
  bool gameWon(int i, char symbol){
    if(isVertical(i,symbol) || isHorizontal(i,symbol) || isDiagnal(i,symbol)){
       return true;
    }
    return false;
  }

  void set_prev_id(int val){
    prev_id = val;
  }

  int get_prev_id(){
    return prev_id;
  }
  TicTacToe(){
    N = 0;
  }
 private:

  int N;
  int prev_id;
  vector<char> board;


  /* Check if there is horizontal symmetry */
  bool isHorizontal(int i,char symbol){
    if(i >= N*N){
      cout <<"Invalid position" << endl;
      return false;
    }
    for(int j = i-(i%N);j<(i-(i%N))+N;j++){
      if(board[j] != symbol)
        return false;
    }
    return true;
  }

  /* Check if there is veritcal symmetry */
  bool isVertical(int i,char symbol){
    if(i >= N*N){
      cout << "Invalid position" << endl;
      return false;
    }
    for(int j = i%N;j<N*N;j = j+N){
      if(board[j] != symbol)
        return false;
    }
    return true;
  }

  /* Check if there is a left diagnal symmetry */
  bool leftDiagnal(char symbol){
    for(int j = 0;j<N*N;j = j+N+1){
      if(board[j] != symbol)
        return false;
    }
    return true;

  }

  /* Check if there is a Right diagnal symmetry */
  bool rightDiagnal(char symbol){
    for(int j = N-1;j<(N*N)-1;j= j+N-1){
      if(board[j] != symbol)
        return false;
    }
    return true;
  }

  /* Check if there is symmetry in both diagnals */
  bool isDiagnal(int i, char symbol){
    if(i >= N*N){
      cout << "Invalid position" << endl;
      return false;
    }
    if(!(i%(N+1)) && !(i%(N-1))){
      return (leftDiagnal(symbol) || rightDiagnal(symbol)?true:false);
    }
    if(!(i%(N+1))){
      return leftDiagnal(symbol)?true:false;
    }
    if(!(i%(N-1))){
      return rightDiagnal(symbol)?true:false;
    }
    return false;
  }
  /// Create a representation of the game state and any internal structures to help
  /// determine win conditions. The implementation should easily extend to different
  /// board sizes and run time should scale linearly (or better) with N.
};


int main(int argc, char** argv) {


  TicTacToe t;

  /* Test Case 1: Giving a size of 0 or less for the Tic Tac Toe */

  t.set_max_size(0);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }

  /* Test Case 2 : Valid 3x3 Tic Tac Toe that ends in the player 1's win(Vertical)*/
  t.set_max_size(3);
  if(t.get_max_size()<=0){
    cout << "Invalid size of Tic Tac Toe" << endl;
    return 0;
  }
  t.resize_vector();

  t.p1.create_id(1);
  t.p2.create_id(2);
  t.p1.create_symbol('x');
  t.p2.create_symbol('o');
  t.set_prev_id(2);
  t.l.set_x(1);
  t.l.set_y(1);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p1,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(0);
  t.l.set_y(0);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p2,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(2);
  t.l.set_y(2);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p1,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(0);
  t.l.set_y(1);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p2,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(0);
  t.l.set_y(2);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p1,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(2);
  t.l.set_y(0);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p2,t.l,t);
  cout << t.R.get_result() << endl;

  t.l.set_x(1);
  t.l.set_y(2);
  t.l.get_index(t);
  t.R = t.MakeMove(t.p1,t.l,t);
  cout << t.R.get_result() << endl;


  /* Test Case 3: A valid 3x3 Tic Tac Toe that ends in a draw */
//   t.set_max_size(3);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;


  /* Test Case 4: Trying to put a value in an already filled box */
//   t.set_max_size(3);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;


//   /* Test Case 5: Trying to put value at an index more than the size of the Tic Tac Toe */
//   t.set_max_size(3);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(5);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;


  /* Test Case 6: A 5x5 Tic Tac Toe with player 2's win (Horizontal)*/
//   t.set_max_size(4);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(0);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;


//   t.l.set_x(0);
//   t.l.set_y(3);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(3);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(3);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(3);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(3);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(3);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(3);
//   t.l.set_y(3);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

  /* Test Case 7: A 3x3 Tic Tac Toe with a Diagnal win */
//   t.set_max_size(3);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(1);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;

  /* Test Case 8: A player tries to take subsequent turns */
//   t.set_max_size(3);
//   if(t.get_max_size()<=0){
//     cout << "Invalid size of Tic Tac Toe" << endl;
//     return 0;
//   }
//   t.resize_vector();

//   t.p1.create_id(1);
//   t.p2.create_id(2);
//   t.p1.create_symbol('x');
//   t.p2.create_symbol('o');
//   t.set_prev_id(2);
//   t.l.set_x(1);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   //t.R.set_result(t.MakeMove(t.p1,t.l,t));
//   cout << t.R.get_result() << endl;

//   t.l.set_x(0);
//   t.l.set_y(0);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;

//   t.l.set_x(2);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;


//   t.l.set_x(2);
//   t.l.set_y(2);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p2,t.l,t);
//   cout << t.R.get_result() << endl;


//   t.l.set_x(2);
//   t.l.set_y(1);
//   t.l.get_index(t);
//   t.R = t.MakeMove(t.p1,t.l,t);
//   cout << t.R.get_result() << endl;
  return 0;
}
