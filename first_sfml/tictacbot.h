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



#endif /* defined(__first_sfml__tictacbot__) */


class ticTacBot {
    int player;
    ticTacToe* game;
public:
    ticTacBot(int player, ticTacToe game);
    void beginPlay();
};