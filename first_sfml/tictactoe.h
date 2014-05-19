//
//  tictactoe.h
//  first_sfml
//
//  Created by Ben Rainero on 5/18/14.
//
//

#ifndef first_sfml_tictactoe_h
#define first_sfml_tictactoe_h

class ticTacToeBox {
    int player;
    
public:
    int getPlayer();
    int setPlayer(int player);
};


class ticTacToe {
    ticTacToeBox* array_boxes;
    int player_turn;

public:
    ticTacToe();
    int setBox(int x, int y, int player);
    int getBox(int x, int y);
    
};



#endif
