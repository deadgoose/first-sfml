//
//  tictacbot.h
//  first_sfml
//
//  Created by Ben de Haan on 5/19/14.
//
//

#ifndef __first_sfml__tictacbot__
#define __first_sfml__tictacbot__

#include <iostream>
#include "tictactoe.h"





class ticTacBot {
    int player;
    ticTacToe* game;
    
    int twoInARow();
    int opTwoInARow();
    int twoHelper(int player);
    int* rotate(int* coords, int no_rotations);
    int tryFork();
    int center();
    int oppositeCorner();
    int emptyCorner();
    int emptySide();
    
    void ticTacLogic();
public:
    ticTacBot(int player, ticTacToe game);
    void beginPlay();
};

#endif /* defined(__first_sfml__tictacbot__) */
