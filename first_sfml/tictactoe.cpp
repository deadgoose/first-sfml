//
//  tictactoe.cpp
//  first_sfml
//
//  Created by Ben de Haan on 5/18/14.
//
//

#include "tictactoe.h"
#include <iostream>

int ticTacToeBox::getPlayer() {
    return this->player;
}

int ticTacToeBox::setPlayer(int player) {
    if (player!=0 && player!=1) {
        return 0;
    }
    this->player = player;
    return 1;
}



int ticTacToe::checkWinCondition() {
    int winning_lines[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    
    int i;
    int sum;
    for (i = 0; i < 8; i++) {
        sum = this->array_boxes[winning_lines[i][0]].getPlayer() +
        this->array_boxes[winning_lines[i][1]].getPlayer() +
        this->array_boxes[winning_lines[i][2]].getPlayer();
        
        if (sum == 3) {
            return 1;
        } else if (sum == 6) {
            return 2;
        }
    }
    return 0;
}

int ticTacToe::getWinner() {
    return this->winner;
}

void ticTacToe::endGame(int winner) {
    this->winner = winner;
    this->game_state = END;
}


int ticTacToe::setBox(int x, int y, int player) {
    /*If invalid return 0, else return 1*/
    ticTacToeBox* box;
    int win;
    
    if ((x>2 || x<0) && (y>2 || y<0)) {
        return 0;
    }
    
    box = &array_boxes[x*3 + y];
    
    if (this->player_turn == player &&
        box->getPlayer() == 0 &&
        this->game_state == PLAYABLE) {
        
        box->setPlayer(player);
        win = ticTacToe::checkWinCondition();
        if (win == 0) {
            this->player_turn = (player % 2) + 1; //2 becomes 1, 1 becomes 2
            if (this->player_turn == 1) {
                this->turn++;
            }
            return 1;
        }
        endGame(win);
        
        
    }
    return 0;
}

int ticTacToe::getBox(int x, int y) {
    
    if ((x>2 || x<0) && (y>2 || y<0)) {
        return -1;
    }
    return this->array_boxes[x*3 + y].getPlayer();
}

int ticTacToe::getPlayerTurn() {
    return this->player_turn;
}

int ticTacToe::getTurn() {
    return this->player_turn;
}

int ticTacToe::getState() {
    return this->game_state;
}

void ticTacToe::outputBoard() {
    int i, j;
    std::cout << "________\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            std::cout << "|" << this->array_boxes[i*3 + j].getPlayer();
        }
        std::cout << "|\n________\n";
    }
}


ticTacToe::ticTacToe() {
    int i;
    this->array_boxes = new ticTacToeBox[9];
    for (i = 0; i < 9; i++) {
        this->array_boxes[i/3 + i%3] = ticTacToeBox();
    }
    this->player_turn = 1;
    this->game_state = PLAYABLE;
    this->winner = 0;
    this->turn = 0;
    std::cout << "player turn is " << this->getTurn();
}

