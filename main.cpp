//
//  main.cpp
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
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Bunco.h"

//PrintHeader - This function will display the programmers info
std::string PrintHeader(std::string programmer, std::string asNameF, char asTypeF,
	               int asNumF);

//clearScreen - This function will clear the screen
void clearScreen( );

int main()
{
    using namespace cs31;
    using namespace std;

	//clearScreen - this clears the screen
    clearScreen();

	//PrintHeader - This function will display the programmers info
	cout << PrintHeader("Mario Rodriguez", "Bunco Game", 'P', 1);
    
    Bunco game;          //This is a varialbe of the Bunco Game 
    int human, computer; //Variables to hold the number tossed for each play 
   
	int round = 1;       //Variable holding the current round number
    
	//setRound - This will update the round accross all the classes
	game.setRound( round ); 
    
	std::string action;  //Variable to hold input by user
	std::string message = "(r)oll (q)uit: "; //Message to user

	//display - This will display the bunco game
    cout << game.display( message ) << endl;

    //do-while - this will loop thru while the game is not over
    do
    {
        getline( cin, action ); // user inputs decision to roll dice or quit playing
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }

		//switch - This will execute the corresponding action input by user
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
				//humanPlay - This will roll the dice for the human
                human = game.humanPlay();
				assert(human >= 1 && human <= 6);

				//humanPlay - This will roll the dice for the computer
                computer = game.computerPlay();
				assert(computer >= 1 && computer <= 6);

                cout << "human rolled:" << human;
                cout << "\tcomputer rolled:" << computer << endl;

				//if-statement - This will check for the round winner and if it
				//				 is decided then it will update the round and display
				//				 the winner, else do nothing
                if (game.determineRoundOutcome() != Bunco::NOTDECIDED)
                {
					assert(game.determineRoundOutcome() != Bunco::NOTDECIDED);

                    round = round + 1;
					assert(round >= 1 && round <=7);

					//setRound - This will update the round accross all the classes
                    game.setRound(round);
					cout << endl;

					//display - This will display the bunco game
                    cout << game.display( message ) << endl;
                }
	 
	 //DO NOT REALLY NEED THIS		
     //           if (game.gameIsOver())
     //           {
					////display - This will display the bunco game
     //               cout << game.display( ) << endl;
     //           }
                break;
        }
        
    } while( !game.gameIsOver() );
    
    return( 0 );
}

/*************************************************************************
 * PrintHeader
 *------------------------------------------------------------------------
 * Purpose = This function will display the header for the project with 
 *	         information regarding the author.
 * Parameters = programmer - string variable for author name
 *				asNameF    - the name of the project
 *			    asTypeF    - the type of work (Assignment or Project)
 *				asNumF	   - the number of the project or assignment
 * Return Values = It returns an string with corresponding values
 * Input = It gets 4 inputs from the user, which are the name of author,
 *		   the name of project, type of project, and number.
 * Output = A string variable with corresponding message.
 ************************************************************************/
std::string PrintHeader(std::string programmer, std::string asNameF, char asTypeF,
	int asNumF)
{
	std::ostringstream header;

	header << std::left;
	header << "***********************************************************";
	header << "\n* PROGRAMMED BY : " << programmer;
	header << "\n* " << std::setw(14) << "STUDENT ID" << ": 1596508";
	header << "\n* " << std::setw(14) << "CLASS" << ": CS20A -> T - 6:45pm";
	header << "\n* ";

	// IF STATEMENT - The user will be able to choose if its a Lab or
	//				  assignment and output the proper output.
	if (toupper(asTypeF) == 'A')
	{
		header << "ASSIGNMENT #" << std::setw(2);
	}
	else
	{
		header << "PROJECT #" << std::setw(5);
	}

	header << asNumF << ": " << asNameF << std::endl;
	header << "***********************************************************";
	header << std::endl << std::endl;
	header << std::right;

	return header.str();
}

void clearScreen();

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

