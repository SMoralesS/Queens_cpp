# Queens_cpp
Repository with a c++ program where, in a (*N*)x(*N*) chess board  accommodate (*N*) queens on the board without them attacking each other.
To compile use the command:

g++ queens.cpp queens_methods.cpp -o queens.out

in a folder with the 3 files.

In the queens.h file you will find two classes:

  queen: 
  
          -Instances: posx, posy: defines the queen position.
          -Methods:   void pos(int,int): allow us to modify the position of the queen.
                      bool attacks(queen): return true if the 2 queens are attacking each other.
                      
  board:      
  
          -Instances: vector<queen> queens: is a vector of queens, it represent the queens on the board.
                      int size_board: is the (*N*) value, the size of the board.
                      int n: the number of requested solutions.
          -Methods:   board(): Constructor, gives an initialization message.
                      void getNsol(): Robust (using exceptions) way of read a number for the number of requested solutions.
                      void getSize(): Robust (using exceptions) way of read a number for the size of the board.
                      void generateQueens(int): generate (int) queens inside the board.
                      void printQueens(): print the board with ones in the position of the queens.
                      bool attackEachOther(): return true if at least 2 queens in the board are attacking each other.
                      void findSolutions(): find n solutions.
