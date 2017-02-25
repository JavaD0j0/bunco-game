//
//  Player.cpp
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
#include "Player.h"

namespace cs31
{
	/*************************************************************************
	* Default Constructor
	*------------------------------------------------------------------------
	* Purpose = This constructor will initialize each player.
	* Parameters = mDie - Variable of class die with six sides
    *			   mScore - The score in the round
	*			   mRound - The round being played
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        //empty
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
	/*************************************************************************
	* Roll method
	*------------------------------------------------------------------------
	* Purpose = This method will execute a die roll and return it.
	* Parameters = amount - this variable is for debuggin purposes to pass a fix value
	* Return Values = It returns the value obtained from the die roll.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int Player::roll( int amount )
    {
		int number; //variable to hold number tossed

		mDie.roll(); //-->rolls the die 
		
		//This if statement is just to check if default amount of 0 is passed
		// then I want the die to generate a number, else if a number different
		//than 0 is passed, I am trying to cheat for error checking purposes.
		if (amount == 0)
		{
			number = mDie.getValue();//--> gets value from recent toss
			assert(number >= 1 && number <= 6);
		}
		else
		{
			number = amount;
		}
        return(number);
    }
    
    // TODO: set the current round and reset the player's score to 0
	/*************************************************************************
	* setRound method
	*------------------------------------------------------------------------
	* Purpose = This method will set the current around and clear the score
	* Parameters = round - The current round number
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Player::setRound( int round )
    {
		mRound = round;
		mScore = 0;
    }
    
    // TODO: return the score member variable
	/*************************************************************************
	* getScore method
	*------------------------------------------------------------------------
	* Purpose = This method will return the score of that player's round
	* Parameters = No parameters
	* Return Values = It returns the score of the player's round.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int  Player::getScore( ) const
    {
        return( mScore );
    }

	/*************************************************************************
	* setScore method
	*------------------------------------------------------------------------
	* Purpose = This method will update the score for the player's round
	* Parameters = No parameters
	* Return Values = It returns nothing;
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
	void Player::setScore()
	{
		mScore++;
	}
    
}