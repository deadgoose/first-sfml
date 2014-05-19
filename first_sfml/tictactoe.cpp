//
//  tictactoe.cpp
//  first_sfml
//
//  Created by Ben de Haan on 5/18/14.
//
//

#include "tictactoe.h"
int ticTacToeBox::getPlayer() {
    return this->player;
}

int ticTacToeBox::setPlayer(int player) {
    if (player!=0 || player!=1) {
        return 0;
    }
    this->player = player;
    return 1;
}




int ticTacToe::setBox(int x, int y, int player) {
    ticTacToeBox* box;
    
    if ((x>2 || x<0) && (y>2 || y<0)) {
        return -1;
    }
    
    box = &array_boxes[x*3 + y];
    
    if (player_turn == player && box->getPlayer() == 0) {
        box->setPlayer(player);
        return 1;
    }
    return 0;
}


ticTacToe::ticTacToe() {
    int i;
    this->array_boxes = new ticTacToeBox[9];
    for (i = 0; i < 9; i++) {
        this->array_boxes[i/3 + i%3] = ticTacToeBox();
    }
}

