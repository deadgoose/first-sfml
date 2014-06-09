//
//  tictactoe.cpp
//  first_sfml
//
//  Created by Ben de Haan on 5/18/14.
//
//

#include "tictactoe.h"
#include <iostream>
#include <SFML/Audio.hpp>

sf::Mutex tic_tac_mutex;

int ticTacToeBox::getPlayer() {
    return this->player;
}

int ticTacToeBox::setPlayer(int player) {
    
    if ((player!=1 && player!=2) || (this->player != 0)) {
        return 0;
    }
    this->player = player;
    //std::cout << "input player: "<< player<< "; set box to player " << this->player << "\n";
    return 1;
}

ticTacToeBox::ticTacToeBox() {
    this->player = 0;
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
    
    tic_tac_mutex.lock();
    if ((x>2 || x<0) && (y>2 || y<0)) {
        tic_tac_mutex.unlock();
        return 0;
    }
    
    box = &array_boxes[x*3 + y];
    /*std::cout << "this->player turn is "<<this->player_turn<<"\n";
    std::cout << "box->getPLayer() is "<<box->getPlayer()<<"\n";
    std::cout << "this->game_state is "<<this->game_state<<" && PLAYABLE is " << PLAYABLE <<"\n";*/
    //you should just have setPlayer return a value
    //and based off of that you should update player turn etc
    if (this->player_turn == player &&
        box->setPlayer(player) == 1 &&
        this->game_state == PLAYABLE) {
        //std::cout << "i'm trying to set player to " <<player<<"\n";

        this->player_turn = (player % 2) + 1; //2 becomes 1, 1 becomes 2
        if (this->player_turn == 1) {
            this->turn++;
        }
        tic_tac_mutex.unlock();
        return 1;

        endGame(checkWinCondition());

        
        
    }
    tic_tac_mutex.unlock();
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
    tic_tac_mutex.lock();
    int i, j;
    std::cout <<"\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            std::cout << "|" << this->array_boxes[i*3 + j].getPlayer();
        }
        std::cout << "|\n\n";
    }
    tic_tac_mutex.unlock();
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

