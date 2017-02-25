//
//  BoardRow.h
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
#ifndef BoardRow_h
#define BoardRow_h
#include <string>

namespace cs31
{
    
    // CS 31 Students have been provided this class which
    // is used to print one row in the Bunco board.  A row
    // tracks who won (the human player or the computer player)
    // with an X and uses an arrow (------>) to mark the
    // current round
    class BoardRow
    {
    public:
		//CONSTRUCTOR
        BoardRow();
        
		//MUTATORS
        void setHumanAsWinner();        // sets the human as winner
		void setComputerAsWinner();     // sets computer as winner
		void setRound(int round);       // what is the round of this row?
		void setCurrentRound(bool b);   // is this round the current round in play?

		//ACCESSORS
        bool didHumanWin( ) const;      // checks if human won the round
        bool didComputerWin( ) const;   // checks if computer won the round
        std::string display() const;    // stringify this row
        
    private:
        bool mHumanWinner;				// boolean to be set true when human wins
        bool mComputerWinner;			// boolean to be set true when computer wins
        int  mRound;					// the round 
        bool mCurrentRound;				// the current round being played
    };
    
}

#endif /* BoardRow_h */
