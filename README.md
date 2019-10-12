# Queens_cpp
Repository with a c++ program where, in a (*N*)x(*N*) chess board  accommodate (*N*) queens on the board without them attacking each other.

In the reinas.h file you will find two classes:

  reina: 
  
          -Instances: posx, posy: defines the queen position.
          -Methods:   void pos(int,int): allow us to modify the position of the queen.
                      bool atacaA(reina): return true if the 2 queens are attacking each other.
                      
  tablero:      
  
          -Instances: vector<reina> reinas: is a vector of reinas(queens), it represent the reinas(queens) on the board.
                      int tam_tablero: is the (*N*) value, the size of the board.
                      int n: the number of requested solutions.
          -Methods:   tablero(): Constructor, gives an initialization message.
                      void getNsol(): Robust (using exceptions) way of read a number for the number of requested solutions.
                      void getSize(): Robust (using exceptions) way of read a number for the size of the board.
                      void generarReinas(int): generate (int) queens inside the board.
                      void imprimirReinas(): print the board with ones in the position of the queens.
                      bool seAtacan(): return true if at least 2 queens in the board are attacking each other.
                      void encontrarSoluciones(): find n solutions.
