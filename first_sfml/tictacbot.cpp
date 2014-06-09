//
//  tictacbot.cpp
//  first_sfml
//
//  Created by Ben de Haan on 5/19/14.
//
//

#include "tictacbot.h"
#include "tictactoe.h"
#include <cmath>
#define PI 3.14159265

ticTacBot::ticTacBot(int player, ticTacToe* game) {
    this->player = player;
    this->game = game;
    std::cout << "\nBot is player " << this->player << "\n";
}

int ticTacBot::twoInARow() {
    
    return twoHelper(this->player);

}

int ticTacBot::opTwoInARow() {
    int op = (this->player % 2) + 1;
    return twoHelper(op);
    

}


int ticTacBot::twoHelper(int player) {
    //can't do sum -- currently, a setup of 2 0 0 0 1 0 0 0 0
    //results in the thought that the top row has two 1s...instead of one 2
    //unless you changed players to -1 and 1.
    int lines[8][3] =
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
    int a, b, c;
    int op = player%2 + 1;
    
    for (i = 0; i < 8; i++) {
        a = this->game->getBox(lines[i][0] / 3, lines[i][0] % 3);
        b = this->game->getBox(lines[i][1] / 3, lines[i][1] % 3);
        c = this->game->getBox(lines[i][2] / 3, lines[i][2] % 3);
        sum = a+b+c;
        
        if ( (sum == (player * 2 + 0)) && (a !=op && b!=op && c!=op)) {
            std::cout<<"sum == "<<sum<<", i = "<<i<<"\n";
            std::cout<<"a = "<<a<<"; b = "<<b<<"; c = "<<c<<"; op = "<<op<<"\n";
            if (a == 0) {this->game->setBox(lines[i][0] / 3, lines[i][0] % 3, this->player);}
            else if (b == 0) {this->game->setBox(lines[i][1] / 3, lines[i][1] % 3, this->player);}
            else if (c == 0) {this->game->setBox(lines[i][2] / 3, lines[i][2] % 3, this->player);}
            return 1;
        }
    }
    return 0;
}


int* ticTacBot::rotate(int* coords, int no_rotations) {
    int x;
    double angle;
    coords[0]--;
    coords[1]--;
    x = coords[0];
    angle = PI*no_rotations/2;
    coords[0] = (int)(cos(angle) * coords[0] - sin(angle)*coords[1]) + 1;
    coords[1] = (int)(sin(angle) * x + cos(angle)*coords[1]) + 1;
    return coords;
}

int ticTacBot::tryFork() {
    
    return 0;
}

int ticTacBot::center() {
    
    if (this->game->getBox(1, 1) == 0) {
        this->game->setBox(1, 1, this->player);
        return 1;
    }
    return 0;
}

int ticTacBot::oppositeCorner() {
    
    return 0;
}

int ticTacBot::emptyCorner() {
    
    return 0;
}

int ticTacBot::emptySide() {
    
    return 0;
}



void ticTacBot::ticTacLogic() {
    if (twoInARow()) {
        std::cout<<"two in a row\n";
        return;
    }
    if (opTwoInARow()) {
        std::cout<<"op two in a row\n";
        return;
    }
    if (tryFork()) {
        std::cout<<"try fork\n";
        return;
    }
    if (center()) {
        std::cout<<"center\n";
        return;
    }
    if (oppositeCorner()) {
        std::cout<<"opposite corner\n";
        return;
    }
    if (emptyCorner()) {
        std::cout<<"empty corner\n";
        return;
    }
    emptySide();
    std::cout << "empty side\n";
}


void ticTacBot::beginPlay() {
    std::cout << "begin play! game state is " << game->getState() << "\n";
    std::cout << "initial board is\n";
    this->game->outputBoard();
    while (game->getState() == PLAYABLE) {
        //std::cout << "getTurn() is " <<game->getTurn() << "\nthis->player is " << this->player << "\n";
        if (game->getTurn() == this->player) {
            //std::cout<< "logic\n";
            ticTacLogic();
        }
    }
    
}