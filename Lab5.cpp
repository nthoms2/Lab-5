/*
Nolan Thoms
C++ Fall Semester
Lab 5
Creating a number guessing game 
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*preconditions: There needs to be a value for numGuesses so the function can determine to output 
a win statment or a lose statement, there also needs to be a valid random number.*/

/*postconditions: Either a win statement or lose statement should be outputted and if it is the lose
statement it should output the random number.*/
void winOrLose(int numGuesses, int& randomNum_);

/*preconditions: The only precondition is that the function needs to be reached with zero errors.*/

/*postcoditions: The function replayQuestion should be called and this function value
should be set to either a true or false value based on the player input.*/
bool again();

/* preconditions: The only precondition is that this function is reached inside of the again function.
with out errors.*/

/*postconditions: When the function again is called this function outputs a statement aking player to
play again.*/
void replayQuestion();

/*preconditions: A value for numGuesses must be passed through it's counterpart as well as for the values
of gamesWon and gamesLost.*/

/*postconditions: The function should determine wheather the player won or lost and add value to
either gamesWon or gamesLost.*/
void winCounter(int& gamesWon_, int& gamesLost_, int& numGuesses_);

/*preconditions: Values for numGuesses and randomNum need to be passed through their counterparts for this
function to work. Also the conditions for the for loop must me valid.*/

/*postconditions: This function should allow a player to input their guess, check that input for errors,
determine if the guess was correct or incorrect, and rerun the loop untill its conditions are met.*/
void gameLoop(int& numGuesses_, int& randomNum_);

int main()
{
	// Variables needed in the main function are declared.//
	int gamesWon = 0;
	int gamesLost = 0;
	int numGuesses;
	bool playAgain = true;
	
	//This outputs a welcome statement and instructions at the begining of the program.
	cout << "welcome to the number guessing game, \nyou will have twenty attempts to guess a random number " << endl;
	
	// This do loop checks to see if the playAgain variable is true and will repeat the game
	// as long as the user wants to keep playing.
	do
	{
		// This generates the main random number that is used within the game and assigns it to an int.
		srand(unsigned int(time(NULL)));
		int randomNum = rand() % 101;

		//This calls the game loop function.
		gameLoop(numGuesses, randomNum);

		//This statement that ends loop if useer inputs invalid input.
		if(!cin)
		{
			break;
		}

		//This calls the winCounter function.
		 winCounter(gamesWon, gamesLost, numGuesses);

		 //This calls the WinOrLose function.
		 winOrLose(numGuesses, randomNum);

		 // This checks to see if the value of the again function is true or false then sets the variable
		 // playAgain accordingly.
		if(again())
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

		cout << "\n";
		// This checks to see if the value of PlayAgain is true or false, if true the loop is repeated
		// and if false the loop ends.
	} while (playAgain);
	
	//This is the final error chaeck and if there is an invalid input the programs returns error 1.
	if (!cin)
	{
		cout << " \n please do not enter characters or other invalid inputs, this program will now end";
		return 1;
	}
	
	//  If there are no errors the program ends and tells the player how many times they won and lost.
	else 
	{
		cout << "thanks for playing \n" << "you won: " << gamesWon << " times \n" << "you lost: " << gamesLost << " times";
	
	}

	// Program returns with 0 errors.
	return 0;
}

// This function looks to see if the player won and out puts a statement accordingly.
void winOrLose(int numGuesses, int& randomNum_)
{
	// Another random number is generated to determine which of the 10 different win or lose statements 
	// should be used.
	srand(unsigned int(time(NULL)));
	int randomNum2 = rand() % 10 + 1;
	
	// Gives the value of the random number to variables witch will be used in two different switch statments
	// depeding on if the player won or lost .
	int winStatement = randomNum2;
	int loseStatement = randomNum2;
	 
	// Checks to see if numguesses was set to the winning value.
	if (numGuesses == 103)
	{
		cout << "you win, \n";

		//This switch statement switches between the different win statements based on the random number.
		switch (winStatement)
		{
		case 1: cout << "now go drink milk straight from the carton champ";
			break;
		case 2: cout << "because you did not lose";
			break;
		case 3: cout << "congratulations ";
			break;
		case 4: cout << "the number you have guessed, that means you passed my test";
			break;
		case 5: cout << "that was a piece of cake";
			break;
		case 6: cout << "easy peasy lemon squeezy";
			break;
		case 7: cout << "you deserve a back sratch";
			break;
		case 8: cout << "winner winner chicken dinner";
			break;
		case 9: cout << "ladies and gentlemen we have a winner!!!";
			break;
		case 10: cout << "hooray!! you just saved the world from exploding";
			break;
		}
		cout << "\n \n";
	}

	// If the player does not win a losing statement is outputed.
	else 
	{
		// If the player loses they are told what the actual number is.
		cout << "you lose, the number is " << randomNum_ << "\n";

		// This switch statement switches between the different lose statments based on the random number.
		switch (loseStatement)
		{
		case 1: cout << "numbers are hard";
			break;
		case 2: cout << "my grandma could guess numbers better than you";
			break;
		case 3: cout << "since you failed to guess the number this device will now self destruct";
			break;
		case 4: cout << "ha ha you stinky";
			break;
		case 5: cout << "how does it feel to lose loser";
			break;
		case 6: cout << "better luck next time";
			break;
		case 7: cout << "on the bright side you didn't get trampled by an angry buffalo";
			break;
		case 8: cout << "you are now my slave, give me a foot massage";
			break;
		case 9: cout << "within the next hour a seagull will poo on you";
			break;
		case 10: cout << "you have small brain";
			break;
		}
		cout << "\n \n";
	}
}

// This is a bool funtion that returns either a true or false value.
bool again()
{
	// This declares the variable yes or no.
	int YoN = 0;

	// This tells the player to input either a 1 or 2.
	replayQuestion();
	cout << "press 1 for yes and 2 for no: ";
	cin >> YoN;

	// If 1 is inputed a true value is returned.
	// If 2 or anything else is inputted a false value is returned.
	switch (YoN)
	{

	case 1: return true;
		break;

	case 2: return false;
		break;

	default: cout << "I will take that as a no";
		return false;
		break;
	}

	cout << "\n";
}

// This is a void function that outputs a random playagain statement.
void replayQuestion()
{
	// This generates another random number.
	srand(unsigned int(time(NULL)));
	int randomNum3 = rand() % 10 + 1;

	// This declares an int which has a random value.
	int replayStatement = randomNum3;

	//This is a switch statment that outputs a random statement asking the player to play again based on the random 
	// number.
	switch (replayStatement)
	{
	case 1: cout << "would you like to play again? ";
		break;
	case 2: cout << "if you had a good time you should play again, ";
		break;
	case 3: cout << "yor intelligence has just increased, play again to get even smarter, ";
		break;
	case 4: cout << "if you do not play again you will be attacked by a pack of badgers, \n what will it be? ";
		break;
	case 5: cout << "if you win 5 more times I might give you a lollipop, will you play again? ";
		break;
	case 6: cout << "I bet you have nothing better to do, why don't you play again? ";
		break;
	case 7: cout << "play again or I will self destuct, ";
		break;
	case 8: cout << "smelling bees is fun, this game is also fun, play again? ";
		break; 
	case 9: cout << "this game is a game and games are played by people like you, \n will you play this game some more? ";
		break;
	case 10: cout << "knock knock, who is there? would, would who? would you like to play again? ";
		break;
	}
}

/* This void function stores values into the integers gamesWon and GamesLost based and two them
every time the player wins or loses a game, it also uses passby reference to communicate those values
between functions.
*/
void winCounter(int& gamesWon_, int& gamesLost_, int& numGuesses_)
{
	if (numGuesses_ == 103)
	{
		gamesWon_++;
	}
	else
	{
		gamesLost_++;
	}
}

// This void loop contains the main functions of the game such as figuring out if the guess
//is wrong or right.
void gameLoop(int& numGuesses_, int& randomNum_)
{
	//This interger is where the user input is stored.
	int guess;

	// This for loop allows the player to guess untill they win or reach 20 guesses.
	for (numGuesses_ = 1; numGuesses_ <= 20; numGuesses_++)
	{
		// This outputs instructions and allows player to input guess.
		cout << "you have " << (21 - numGuesses_) << " guesses remaining \n";
		cout << "please enter a value in betwen 0 and 100: ";
		cin >> guess;

		//This checks to make sure there is no invalid input.
		if (!cin)
		{
			break;
		}

		// If guess is out of range, this allows player to guess again.
		if ((guess < 0) || (guess > 100))
		{
			--numGuesses_;
			cout << "\n that number is out of the range please try again \n" << endl;
			continue;
		}

		// If player guesses correctly this loop is exited.
		if (guess == randomNum_)
		{
			cout << "\n your guess is correct \n" << endl;
			numGuesses_ = 102;
		}
		// If guess is wrong the loop is repeated and a the value of numGuesses increases.
		else
		{
			cout << "\n your guess is incorrect \n" << endl;
		}
	}
}