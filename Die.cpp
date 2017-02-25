//
//  Die.cpp
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
#include "Die.h"
#include <random>

namespace cs31
{
	/*************************************************************************
	* Default Constructor
	*------------------------------------------------------------------------
	* Purpose = This method will initialize a die object with the number of
	*			sides and value from toss.
	* Parameters = sides - the number of sides of the die.
	* Return Values = It returns nothing;
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    Die::Die( int sides ) : mSides( sides ), mValue( 1 )
    {
		//empty
    }

	/*************************************************************************
	* Roll method
	*------------------------------------------------------------------------
	* Purpose = This method will generate a random distribution of values
	*			 between 1 and mSides, storing the random value in the member
	*			 variable mValue for later use.
	* Parameters = No parameters
	* Return Values = It returns nothing;
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    void Die::roll()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_int_distribution<> dist(1, mSides);
        mValue = dist(e2);
    }
    
    // returns the most recent tossed value
	/*************************************************************************
	* getValue method
	*------------------------------------------------------------------------
	* Purpose = This method will return the value obtained from the roll method.
	* Parameters = No parameters.
	* Return Values = It returns the mValue.
	* Input = No input from user.
	* Output = No output.
	************************************************************************/
    int  Die::getValue( ) const
    {
        return( mValue );
    }

}