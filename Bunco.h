//
//  Bunco.h
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

/***********************************************************
* PROGRAMMED BY : Mario Rodriguez
* STUDENT ID    : 1596508
* CLASS         : CS20A->T - 6 : 45pm
* PROJECT #1    : Bunco Game
***********************************************************/
#ifndef Bunco_h
#define Bunco_h
#include <string>
#include "Player.h"
#include "Board.h"

namespace cs31
{
 
    // CS 31 students have been provided this class to represent
    // a Bunco Game.  Each Game is made up of a Board, two Players
    // and tracks the current round of play.
    // CS 31 students need to complete the TODO portions of this class
    class Bunco
    {
    public:
		//CONSTRUCTOR
        Bunco();
        
        // the possible results of a round:
        // - either a player won (human or computer) or
        // - the outcome has yet to be decided yet
        enum ROUNDOUTCOME { HUMANWON, COMPUTERWON, NOTDECIDED };
        
        // the possible results of a game:
        // - either a player won (human or computer) or
        // - the game wound up tied or
        // - the game is not yet over
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, TIEDGAME, GAMENOTOVER };
        
		//MUTATORS
		void setRound(int round);    	  // set the current round of play
		int humanPlay(int amount = 0); 	  // let the human player toss the die, returning the value rolled
		                                  // if a non-zero amount is passed, we are trying to cheat for
		                                  // testing purposes and force a particular rolled value
		int computerPlay(int amount = 0); // let the computer player toss the die, returning the value rolled
		                                  // if a non-zero amount is passed, we are trying to cheat for
		                                  // testing purposes and force a particular rolled value

		//ACCESSORS
        std::string display( std::string msg = "" ) const; //stringify this Game by 
		                                                   // stringifying the Game's Board
        ROUNDOUTCOME determineRoundOutcome( );             // what is the current round's result?
        GAMEOUTCOME  determineGameOutcome( ) const;        // what is the game's result?        
        bool gameIsOver() const;		                   // is the game over?
        
    private:
        Player mHuman;    // the human player
        Player mComputer; // the computer player
        int    mRound;    // the current round of play
        Board  mBoard;    // this game's board
    };
    
}

#endif /* Bunco_h */
