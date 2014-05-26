//
//  tictactoe.h
//  first_sfml
//
//  Created by Ben Rainero on 5/18/14.
//
//

#ifndef first_sfml_tictactoe_h
#define first_sfml_tictactoe_h
#define INITIAL 0
#define PLAYABLE 1
#define END 2

class ticTacToeBox {
    int player;
    
public:
    int getPlayer();
    int setPlayer(int player);
};


class ticTacToe {
    ticTacToeBox* array_boxes;
    int player_turn;
    int game_state;
    int winner;
    int turn;
    
    

public:
    ticTacToe();
    
    int getPlayerTurn();
    int setBox(int x, int y, int player);
    int getBox(int x, int y);
    int checkWinCondition();
    void endGame(int win);
    int getWinner();
    int getTurn();
    int getState();
    
};



#endif
