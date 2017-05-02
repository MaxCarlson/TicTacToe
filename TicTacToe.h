/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToe.h
 * Author: C-60
 *
 * Created on May 1, 2017, 5:09 PM
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

using namespace std;

class TicTacToe {
public:
    TicTacToe(char playerToken, char aiMarker){
        this->userMarker = playerToken;
        this->aiMarker = aiMarker;
        this->winner = '-';
        this->board = setBoard();
    }
    
    static char setBoard() {
        char board[] = new char[9];
        for (int i = 0; i < 9; i++){
            board[i] = '-';
        }
        return board;
    }
    
    bool playTurn(int spot){
        bool isValid = withinRange(spot) && !isSpotTaken(spot);
        if (isValid) {
            board[spot-1] = currentMarker;
            currentMarker = (currentMarker == userMarker) ? aiMarker : userMarker;
        }
        return isValid;
    }
    
    // CHeck if out spot is in range
    
    bool withinRange(int number){
        return number > 0 && number < 10;
    }
    
    //check if spot is taken
    
    bool isSpotTaken(int number){
        return board[number-1] != '-';
    }
    
    void printBoard(){
        cout << endl;
        for(int i = 0; i < 9; i++){
            if (i % 3 == 0 && i != 0){
                cout << endl;
                cout << "------------";
                
            }
            cout << " | " << board[i];
        }
        cout << endl;
        
    }
    
    void printIndexBoard() {
        cout << endl;
        for(int i = 0; i < 9; i++){
            if (i % 3 == 0 && i != 0){
                cout << endl;
                cout << "------------";
                
            }
            cout << " | " << i+1;
        }
        cout << endl;
    }
    
    bool isThereAWinner(){
        bool diagonalsAndMiddles = rightDi() || leftDi || middleRow() || secondCol() && board[4] != '-'; 
        bool topAndFirst = topRow() || firstCol() && board[0] != '-';
        bool bottomAndThird = bottomRow() || thirdCol() && board[8] != '-';
        if(diagonalsAndMiddles){
            this->winner = board[4];
        } else if (topAndFirst){
            this->winner = board[0];
        } else if (bottomAndThird){
            this->winner = board[8];
        } 
        return diagonalsAndMiddles || topAndFirst || bottomAndThird;
    }
    
    bool topRow() {
        return board[0] == board[1] && board [1] == board[2];
    }
    
    bool middleRow() {
        return board[3] == board[4] && board[4] == board[5];
    }
    
    bool bottomRow() {
        return board[6] == board[7] && board[7] == board[8];
    }
    
    bool firstCol(){
        return board[0] == board[3] && board[3] == board[6];
    }
    
    bool secondCol(){
        return board[1] == board[4] && board[4] == board[7];
    }
    
    bool thirdCol(){
        return board[2]==board[5] &&board[5] == board[8];
    }
    
    bool rightDi() {
        return board[0] ==board[4] &&board[4] ==board[8];
    }
    
    bool leftDi(){
        return board[2] ==board[4] && board[4] ==board[6];
    }
    
    
    bool isTheBoardFilled(){
        for(int i = 0; i < 9; i++){
            if (board[i]=='-'){
                return false;
            }
        }
        return true;
    }
    
    string gameOver(){
        bool didSomeoneWin = isThereAWinner();
        if(didSomeoneWin){
            return "We have a winner! The Winner is " + this->winner + "'s";
            
        }else if (isTheBoardFilled()){
            return "Draw: Game Over!";
        } else {
            return "not over";
        }
    }
    
    
    
    
    
    TicTacToe(const TicTacToe& orig);
    virtual ~TicTacToe();

protected:
    
    char board[];
    char userMarker;
    char aiMarker;
    char winner;
    char currentMarker;
    

private:

};

#endif /* TICTACTOE_H */

