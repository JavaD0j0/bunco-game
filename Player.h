//
//  Player.h
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
#ifndef Player_h
#define Player_h
#include "Die.h"
#include <cassert>

namespace cs31
{
    
    // CS 31 students have been provided this class to represent
    // one of the Bunco Players.  Each Player has its own Die, knows
    // which round is currently being played and knows how to scores
    // it rolled value for the current round.
    // CS 31 students need to complete the TODO portions of this class
    class Player
    {
    public:
		//Constructor
        Player();

		//Mutators
        int roll( int amount = 0 );  // toss the Die, unless provided a forced amount value
        void setRound( int round );  // set current round, resetting the Player's score
		void setScore();             // set score for winner player

		//Accessors
		int  getScore( ) const;      // how many times has Player tossed the current round value?

	private:
        Die mDie;    // the Player's Die
        int mScore;  // the Player's score for this round
        int mRound;  // the current round value, a number between 1 and 6
    };
    
}

#endif /* Player_h */
