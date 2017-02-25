//
//  BoardRow.cpp
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
#include "BoardRow.h"


namespace cs31
{
	/*************************************************************************
	* Default Constructor
	*------------------------------------------------------------------------
	* Purpose = This method will initialize the members of boardRow. 
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    BoardRow::BoardRow() : mHumanWinner( false ),
                           mComputerWinner( false ),
                           mRound( 0 ),
                           mCurrentRound( false )
    {
		//empty
    }

	/*************************************************************************
	* setHumanAsWinner method
	*------------------------------------------------------------------------
	* Purpose = This method will set the human as the winner for the round.
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void BoardRow::setHumanAsWinner()
    {
        mHumanWinner = true;
    }
    
	/*************************************************************************
	* setComputerAsWinner method
	*------------------------------------------------------------------------
	* Purpose = This method will set the computer as the winner for the round.
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void BoardRow::setComputerAsWinner()
    {
        mComputerWinner = true;
    }
    
	/*************************************************************************
	* setRound method
	*------------------------------------------------------------------------
	* Purpose = This method will set the round of the game.
	* Parameters = round - the round the game is currently on.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void BoardRow::setRound( int round )
    {
        mRound = round;
    }
    
	/*************************************************************************
	* setCurrentRound method
	*------------------------------------------------------------------------
	* Purpose = This method will set the current round of the game.
	* Parameters = b - the current round being played.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void BoardRow::setCurrentRound( bool b )
    {
        mCurrentRound = b;
    }
    
	/*************************************************************************
	* didComputerWin method
	*------------------------------------------------------------------------
	* Purpose = This method will return if the computer won or not.
	* Parameters = No parameters.
	* Return Values = It returns the boolean value equals true if computer won,
	*				  else it returns false.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    bool BoardRow::didComputerWin( ) const
    {
        return( mComputerWinner );
    }
    
	/*************************************************************************
	* didHumanWin method
	*------------------------------------------------------------------------
	* Purpose = This method will return if the human won or not.
	* Parameters = No parameters.
	* Return Values = It returns the boolean value equals true if human won,
	*				  else it returns false.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    bool BoardRow::didHumanWin( ) const
    {
        return( mHumanWinner );
    }

	/*************************************************************************
	* display method
	*------------------------------------------------------------------------
	* Purpose = This method will display the arrow pointing the current round
	*			being played and will also display an 'X' value in case the 
	*			human or computer won the round.
	* Parameters = No parameters.
	* Return Values = It returns the string with corresponding data.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    std::string BoardRow::display() const
    {
        std::string s = "";
        if (mCurrentRound)
        {
            s = s + "--->";
        }
        s = s + "\t";
        if (mHumanWinner)
        {
            s = s + "X\t";
        }
        else
        {
            s = s + "\t";
        }
        s = s + "\t";
        char c = mRound + '0';
        s = s + c + "\t";
        if (mComputerWinner)
        {
            s = s + "X\t";
        }
        else
        {
            s = s + "\t";
        }
        return( s );
    }
    
}