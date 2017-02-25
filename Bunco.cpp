//
//  Bunco.cpp
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
#include "Bunco.h"
#include <iostream>

namespace cs31
{
	/*************************************************************************
	* Default Constructor
	*------------------------------------------------------------------------
	* Purpose = This method will initialize the game with current round.
	* Parameters = No parameters.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Bunco::Bunco() : mRound( 0 )
    {
        //empty
    }
    
	/*************************************************************************
	* display method
	*------------------------------------------------------------------------
	* Purpose = This method will display the full game of bunco and at the 
	*		     6th round it will check if there is a winner or the game is tie.
	* Parameters = msg - The message to be display for user.
	* Return Values = It returns a string with corresponding data.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display(); //variable to hold the board data
        s = s + msg;
        
		//if-statement - This will check at the 6th round who the winner of the
		//				  game and add the winner to the string
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tYou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tYou lost Bunco!\n";
            }
        }
        return( s );
    }
    
	/*************************************************************************
	* setRound method
	*------------------------------------------------------------------------
	* Purpose = This method will set the current round of play, notifying the 
	*			board and each player of the current round.
	* Parameters = round - the current round of game.
	* Return Values = It returns nothing.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round ); //--> sets current round in board class
        mHuman.setRound(round);			 //--> sets current round in player class
        mComputer.setRound(round);	     //--> sets current round in player class
    }
    
    // TODO: let the human player play
	/*************************************************************************
	* humanPlay method
	*------------------------------------------------------------------------
	* Purpose = This method will let the human play and roll the die. 
	* Parameters = amount - if a non-zero is passed, it is for debugging purposes.
	* Return Values = It returns the number rolled.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int Bunco::humanPlay( int amount )
    {
		int amountrolled;   //the variable to hold the number rolled

		//if-statement - When the amount is zero, the Die should be rolled for
		//				 random play, but if it is not a zero, is for debugging
		//				 purposes
		if (amount == 0)
		{
			amountrolled = mHuman.roll(amount); //-->rolls the die
			assert(amountrolled >= 1 && amountrolled <= 6);

			//if the number tossed matches the round, update score
			if (amountrolled == mRound)
			{
				mHuman.setScore();
			}
		}
		else
		{
			amountrolled = amount;
		}
        
        return( amountrolled );
    }
    
    // TODO: let the computer player play
	/*************************************************************************
	* computerPlay method
	*------------------------------------------------------------------------
	* Purpose = This method will let the computer play and roll the die.
	* Parameters = amount - if a non-zero is passed, it is for debugging purposes.
	* Return Values = It returns the number rolled.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int Bunco::computerPlay( int amount )
    {
		int amountrolled;   //the variable to hold the number rolled

		//if-statement - When the amount is zero, the Die should be rolled for
		//				 random play, but if it is not a zero, is for debugging
		//				 purposes
		if (amount == 0)
		{
			amountrolled = mComputer.roll(amount); //-->rolls the die
			assert(amountrolled >= 1 && amountrolled <= 6);

			//if the number tossed matches the round, update score
			if (amountrolled == mRound)
			{
				mComputer.setScore();
			}
		}
		else
		{
			amountrolled = amount;
		}

		return(amountrolled);
    }
    
    // TODO: considering each player's score, determine the
    // winner of this round of play
	/*************************************************************************
	* determineRoundOutcome method
	*------------------------------------------------------------------------
	* Purpose = This method will determine the winner for each round, and mark 
	*			 either human or computer as winner.
	* Parameters = No parameters.
	* Return Values = It returns the winner of the round as an enum variable.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( ) 
    {
		ROUNDOUTCOME result;  //the winner of the round

		//if-statement - This checks if the human score is equals the computer
		//				  score then the round is still not decided, else if the
		//				  human score is greater than the computer score then the
		//				  human won the round, else the computer won the round
		if (mHuman.getScore() == mComputer.getScore())
		{
			result = ROUNDOUTCOME::NOTDECIDED;
		}
		else if (mHuman.getScore() > mComputer.getScore())
		{
			result = ROUNDOUTCOME::HUMANWON;
			mBoard.markHumanAsWinner(); //--> marks human as winner
		}
		else
		{
			result = ROUNDOUTCOME::COMPUTERWON;
			mBoard.markComputerAsWinner(); //--> marks computer as winner
		}
        return( result );
    }
    
    // TODO: count up the number of won rounds by each player to determine
    // the game's outcome
	/*************************************************************************
	* determineGameOutcome method
	*------------------------------------------------------------------------
	* Purpose = This method will count up the number of won rounds by each player
	*			 to determine the game's outcome.
	* Parameters = No parameters.
	* Return Values = It returns the winner of the game as an enum variable.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
		GAMEOUTCOME result;

		//if-statement - This checks only after the 6th round has being completed, to see
		//				  if the human has the same round wins as the computer, if so then
		//				  the game is tied up, else if the human round wins is greater than
		//				  the computer, if so the human won the game, else the computer won 
		//				  the game
		if (mRound > 6 && mBoard.countUpHumanRoundWins() == mBoard.countUpComputerRoundWins())
		{
			result = GAMEOUTCOME::TIEDGAME;
		}
		else if (mRound > 6 && mBoard.countUpHumanRoundWins() > mBoard.countUpComputerRoundWins())
		{
			result = GAMEOUTCOME::HUMANWONGAME;
		}
		else if (mRound > 6 && mBoard.countUpComputerRoundWins() > mBoard.countUpHumanRoundWins())
		{
			result = GAMEOUTCOME::COMPUTERWONGAME;
		}
		else
		{
			result = GAMEOUTCOME::GAMENOTOVER;
		}
		return( result );
    }
    
	/*************************************************************************
	* gameIsOver method
	*------------------------------------------------------------------------
	* Purpose = This method will check if the game is over yet or not.
	* Parameters = No parameters.
	* Return Values = It returns false while the game outcome is GAMENOTOVER,
	*				   otherwise it will return true and finish the game.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome(); //--> has anyone won the game?
        return( result != GAMENOTOVER );
    }

}