//
//  Board.cpp
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
#include "Board.h"


namespace cs31
{
	/*************************************************************************
	* Default Constructor
	*------------------------------------------------------------------------
	* Purpose = This method will initialize the board and set the round for the
	*		     board row
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Board::Board() : mRound( 0 )
    {
        // initialize each BoardRow
        for (int i = 1; i <= 6; i++)
        {
            mBoardRow[ i ].setRound( i );
        }
    }
    
	/*************************************************************************
	* setCurrentRound method
	*------------------------------------------------------------------------
	* Purpose = This method will set the current round being played
	* Parameters = round - the current round in play
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Board::setCurrentRound( int round )
    {
        // unset the current board row
		if (mRound >= 0 && mRound <= 6)
		{
			mBoardRow[mRound].setCurrentRound(false);
		}

			mRound = round; //--> assigns new round

        // set the current board row
		if (mRound >= 0 && mRound <= 6)
		{
			mBoardRow[mRound].setCurrentRound(true);
		}
    }
    
    // TODO: set the human player to have won this current BoardRow
	/*************************************************************************
	* markHumanAsWinner method
	*------------------------------------------------------------------------
	* Purpose = This method will set the human player as the winner for the round
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Board::markHumanAsWinner()
    {
		mBoardRow[mRound].setHumanAsWinner();
    }
    
    // TODO: set the computer player to have won this current BoardRow
	/*************************************************************************
	* markComputerAsWinner method
	*------------------------------------------------------------------------
	* Purpose = This method will set the computer player as the winner for 
	*			the round
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Board::markComputerAsWinner()
    {
		mBoardRow[mRound].setComputerAsWinner();
    }
    
	/*************************************************************************
	* display method
	*------------------------------------------------------------------------
	* Purpose = This method will output the board itself, and display if there
	*			 was a winner on the round or not decided yet.
	* Parameters = No parameters.
	* Return Values = It returns a string with all desired data.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    std::string Board::display( ) const
    {
        std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
        
        for( int i = 1; i <= 6; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
    // TODO: how many rounds has the human player won?
	/*************************************************************************
	* countUpHumanRoundWins method
	*------------------------------------------------------------------------
	* Purpose = This method will count the number of won rounds by the human 
	*			player and then return it.
	* Parameters = No parameters.
	* Return Values = It returns nthe number of rounds won.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int Board::countUpHumanRoundWins( ) const
    {
		int numOfWins = 0;  //variable to hold number of wins

		//for-loop - This will loop through each board row checking for the 
		//			  round winner and update the number of wins.
		for (int i = 0; i <= 6; i++)
		{
			if (mBoardRow[ i ].didHumanWin())
			{
				numOfWins += 1;
			}
		}
        return(numOfWins);
    }
    
    // TODO: how many rounds has the computer player won?
	/*************************************************************************
	* countUpComputerRoundWins method
	*------------------------------------------------------------------------
	* Purpose = This method will count the number of won rounds by the computer
	*			player and then return it.
	* Parameters = No parameters.
	* Return Values = It returns nthe number of rounds won.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int Board::countUpComputerRoundWins( ) const
    {
		int numOfWins = 0;  //variable to hold number of wins

		//for-loop - This will loop through each board row checking for the 
		//			  round winner and update the number of wins.
		for (int i = 0; i <= 6; i++)
		{
			if (mBoardRow[i].didComputerWin())
			{
				numOfWins += 1;
			}
		}
        return(numOfWins);
    }

    
}