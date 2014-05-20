//
//  tictacbot.cpp
//  first_sfml
//
//  Created by Ben de Haan on 5/19/14.
//
//

#include "tictacbot.h"
#include "tictactoe.h"

ticTacBot::ticTacBot(int player, ticTacToe game) {
    this->player = player;
    this->game = &game;
}


void ticTacBot::beginPlay() {
    if (game->getTurn() == 0 && this->player == 1) {
        game->setBox(1, 1, this->player);
    }
    
}