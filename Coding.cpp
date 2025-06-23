#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function To Calculate Longest Jump For Each Atlete
float calcLongestJump(float first, float second, float third);

// Function To Calculate Average Jump for Each Athlete
void calcAvgJump(float first, float second, float third, float &avgJump);

// Function To Calculate Points For Each Atlete
int calcPoints(float jump);

// Funtion To Display Club Winner
void winnerClub(string clubWinner, int points, float winnerSumJump, float winnerSumAvg);

// Function To Display Winner
void winner(string winner, float winnerJump, float winnerAvg);

int main()
{
	// Variables Declaration And Intialization
	int num, numAthlete, points, winClubPoint;
	float jump, avgJump, longestJump, winnerJump, winnerAvg, clubSumJump, clubSumAvg;
	string name, club, winnerName, winClubName;
	string clubName[4] = {"Red", "Yellow", "Blue", "Green"};
	string threeJumps[3] = {"first jump  : ", "second jump : ", "third jump  : "};
	char response;
	bool invalidClub, stop;
	
	// Set Fixed Two Decimal Points
	cout << fixed << setprecision(2);
	
	do {
		// Initialization
		int redPoints = 0, yellowPoints = 0, bluePoints = 0, greenPoints = 0,
			red = 0, yellow = 0, blue = 0, green = 0;
		float redSumJump = 0, yellowSumJump = 0, blueSumJump = 0, greenSumJump = 0,
			  redSumAvg = 0, yellowSumAvg = 0, blueSumAvg = 0, greenSumAvg = 0;
			  
		cout << "  ______________________________________________________" << endl;
		cout << " |                                                      |" << endl;
		cout << " | Welcome to the Chendering Long Jump Club Competition |" << endl;
		cout << " |______________________________________________________|" << endl << endl;
		
		// Input Number Of Athlete For Each Club
		cout << " Please enter the number of athletes participating for each club : ";
		cin >> num;
		
		// Calculate The Total Number Of Athletes
		numAthlete = num*4;
		
		// Arrays Declaration
		string athleteName[2][numAthlete], athleteInfo[4][num];
		float jumps[6][numAthlete];
		cout << endl;
		
		cin.ignore();
		for (int i = 0 ; i < numAthlete ; i++){
			// Input Athlete's Names
			cout << " Please enter your name : ";
			getline(cin,name);
			athleteName[0][i] = name;
			
			do {
				// Loop Initialization
				invalidClub = false;
				stop = false;
				
				// Input Athlete's Club
				cout << " Please enter your club's name (Red / Yellow / Blue / Green) (Enter 'Stop' to stop the program) : ";
				getline(cin,club);
				cout << endl;
				
				// Changes All The Letters In The Club's Name To Lowercase
				for (int j = 0 ; j < club.length() ; j++){
	                club[j] = tolower(club[j]);
				}
				
				// Display An Appropriate Message When The Club Reach The Maximum Quantity Of Athletes
				if (club == "red"){
				    if (red < num){
				        athleteInfo[0][red] = name;
				        athleteName[1][i] = "Red";
				        red++;
				    } else {
				        cout << " The Red Club is already full! Please join one of the other clubs." << endl;
				        invalidClub = true;
				    }
				} else if (club == "yellow"){
				    if (yellow < num){
				        athleteInfo[1][yellow] = name;
				        athleteName[1][i] = "Yellow";
				        yellow++;
				    } else {
				        cout << " The Yellow Club is already full! Please join one of the other clubs." << endl;
				        invalidClub = true;
				    }
				} else if (club == "blue"){
				    if (blue < num){
				        athleteInfo[2][blue] = name;
				        athleteName[1][i] = "Blue";
				        blue++;
				    } else {
				        cout << " The Blue Club is already full! Please join one of the other clubs." << endl;
				        invalidClub = true;
				    }
				} else if (club == "green"){
				    if (green < num){
				        athleteInfo[3][green] = name;
				        athleteName[1][i] = "Green";
				        green++;
				    } else {
				        cout << " The Green Club is already full! Please join one of the other clubs." << endl;
				        invalidClub = true;
				    }
				} else if (club == "stop"){
					//If The User Enters Stop, The Program Will Stop
					stop = true;
					break;
				} else {
				    cout << " You have entered an invalid club name!" << endl;
				    invalidClub = true;
				}
			} while (invalidClub == true);
			//To Break Out Of The Loop When The User Wants To Stop
			if (stop == true){
				break;
			}
		}
		
		//Only Runs When The User Doesn't Want To Stop
		if (stop == false){
			// Display Club And Names
			for (int i = 0 ; i < 4 ; i++){
				cout << " " << clubName[i] << " Club Athletes :" << endl;
				for (int j = 0 ; j < num ; j++){
					cout << "  " << j+1 << ". " << athleteInfo[i][j] << endl;
				}
				cout << endl;
			}
			
			cout << "\n Now begins the Long Jump Competition" << endl << endl;
			
			for (int x = 0 ; x < numAthlete ; x++){
				cout << " ------------------------------------" << endl << endl;
				cout << " " << athleteName[0][x] << "'s Jumps :" << endl << endl;
				
				// Input Athlete's Three Jump Distances
				for (int y = 0 ; y < 3 ; y++){
					cout << " Please enter " << athleteName[0][x]  << "'s " << threeJumps[y];
					cin >> jump;
					jumps[y][x] = jump;
				}
				cout << endl;
				
				// Call The Function To Determine The Longest Jump Distance
				longestJump = calcLongestJump(jumps[0][x], jumps[1][x], jumps[2][x]);
				
				// Call The Function To Determine Points Based On The Athlete's Longest Jump
				points = calcPoints(longestJump);
				
				// Call The Function To Calculate Average Jump Distance
				calcAvgJump(jumps[0][x], jumps[1][x], jumps[2][x], avgJump);
				
				// Display The Athlete's Longest And Average Jump Distance
				cout << " The Longest Jump Distance jumped by " << athleteName[0][x] << " is " << longestJump << " meters" << endl;
				cout << " " << athleteName[0][x] << "'s Average Jump Distance is " << avgJump << " meters" << endl << endl;
				
				jumps[3][x] = longestJump;
				jumps[4][x] = avgJump;
				jumps[5][x] = points;
				
				// Determines The Winner's Jump And Name
				if (longestJump == winnerJump){
					if (avgJump > winnerAvg){
						winnerJump = longestJump;
						winnerAvg = avgJump;
						winnerName = athleteName[0][x];
					}
				} else if (longestJump > winnerJump){
					winnerJump = longestJump;
					winnerAvg = avgJump;
					winnerName = athleteName[0][x];
				}
				
				// Determines Each Club's Points And Total Longest Jump
				if (athleteName[1][x] == "Red"){
					redPoints += points;
					redSumJump += longestJump;
					redSumAvg += avgJump;
				} else if (athleteName[1][x] == "Yellow"){
					yellowPoints += points;
					yellowSumJump += longestJump;
					yellowSumAvg += avgJump;
				} else if (athleteName[1][x] == "Blue"){
					bluePoints += points;
					blueSumJump += longestJump;
					blueSumAvg += avgJump;
				} else if (athleteName[1][x] == "Green"){
					greenPoints += points;
					greenSumJump += longestJump;
					greenSumAvg += avgJump;
				}
			}
			
			/*// Display Jump Distance (Only For Programmers To Ensure The Input Process Is Functioning)
			for (int i = 0 ; i < 6 ; i++){
				for (int j = 0 ; j < numAthlete ; j++){
					cout << jumps[i][j] << " | ";
				}
				cout << endl;
			}*/
			
			// Determines The Winner Club, Points And Total Longest Jump
			if ((redPoints > yellowPoints) && (redPoints > bluePoints) && (redPoints > greenPoints)){
				winClubName = "Red";
				winClubPoint = redPoints;
				clubSumJump = redSumJump;
				clubSumAvg = redSumAvg;
			} else if ((yellowPoints > redPoints) && (yellowPoints > bluePoints) && (yellowPoints > greenPoints)){
				winClubName = "Yellow";
				winClubPoint = yellowPoints;
				clubSumJump = yellowSumJump;
				clubSumAvg = yellowSumAvg;
			} else if ((bluePoints > redPoints) && (bluePoints > yellowPoints) && (bluePoints > greenPoints)){
				winClubName = "Blue";
				winClubPoint = bluePoints;
				clubSumJump = blueSumJump;
				clubSumAvg = blueSumAvg;
			} else if ((greenPoints > redPoints) && (greenPoints > yellowPoints) && (greenPoints > bluePoints)){
				winClubName = "Green";
				winClubPoint = greenPoints;
				clubSumJump = greenSumJump;
				clubSumAvg = greenSumAvg;
			} else {
				if ((redSumJump > yellowSumJump) && (redSumJump > blueSumJump) && (redSumJump > greenSumJump)){
					winClubName = "Red";
					winClubPoint = redPoints;
					clubSumJump = redSumJump;
					clubSumAvg = redSumAvg;
				} else if ((yellowSumJump > redSumJump) && (yellowSumJump > blueSumJump) && (yellowSumJump > greenSumJump)){
					winClubName = "Yellow";
					winClubPoint = yellowPoints;
					clubSumJump = yellowSumJump;
					clubSumAvg = yellowSumAvg;
				} else if ((blueSumJump > redSumJump) && (blueSumJump > yellowSumJump) && (blueSumJump > greenSumJump)){
					winClubName = "Blue";
					winClubPoint = bluePoints;
					clubSumJump = blueSumJump;
					clubSumAvg = blueSumAvg;
				} else if ((greenSumJump > redSumJump) && (greenSumJump > yellowSumJump) && (greenSumJump > blueSumJump)){
					winClubName = "Green";
					winClubPoint = greenPoints;
					clubSumJump = greenSumJump;
					clubSumAvg = greenSumAvg;
				} else {
					if ((redSumAvg > yellowSumAvg) && (redSumAvg > blueSumAvg) && (redSumAvg > greenSumAvg)){
						winClubName = "Red";
						winClubPoint = redPoints;
						clubSumJump = redSumJump;
						clubSumAvg = redSumAvg;
					} else if ((yellowSumAvg > redSumAvg) && (yellowSumAvg > blueSumAvg) && (yellowSumAvg > greenSumAvg)){
						winClubName = "Yellow";
						winClubPoint = yellowPoints;
						clubSumJump = yellowSumJump;
						clubSumAvg = yellowSumAvg;
					} else if ((blueSumAvg > redSumAvg) && (blueSumAvg > yellowSumAvg) && (blueSumAvg > greenSumAvg)){
						winClubName = "Blue";
						winClubPoint = bluePoints;
						clubSumJump = blueSumJump;
						clubSumAvg = blueSumAvg;
					} else if ((greenSumAvg > redSumAvg) && (greenSumAvg > yellowSumAvg) && (greenSumAvg > blueSumAvg)){
						winClubName = "Green";
						winClubPoint = greenPoints;
						clubSumJump = greenSumJump;
						clubSumAvg = greenSumAvg;
					}
				}
			}
			cout << " ====================================================================================================" << endl;
			cout << "                                              THE WINNER                                             " << endl;
			
			// Display The Club Winner
			winnerClub(winClubName, winClubPoint, clubSumJump, clubSumAvg);
			
			// Display The Individual Winner
			winner(winnerName, winnerJump, winnerAvg);
		}
		
		// Asking For Response From User (Sentinel Value)
		cout << "\n\n Do you want to repeat the entire process again? (Y/N) : ";
		cin >> response;
		cout << endl;
		
	} while (response == 'Y' || response == 'y');

	// Display Message Of Gratitude And Credits
	cout << " THANK YOU FOR USING OUR PROGRAM" << endl;
	cout << " Credits:" << endl;
	cout << " 1. Syazwan (Head Programmer)" << endl;
	cout << " 2. Syafiq  (Co-Head Programmer)" << endl;
	cout << " 3. Ammar   (Assistant Programmer)" << endl;
	cout << " 4. Wafiy   (Co-Assistant Programmer)" << endl;
	
	return 0;
}

float calcLongestJump(float first, float second, float third){
	// Declaration 
	float longestJump;
	
	// Determine The Longest Jump
	if (first >= second && first >= third){
		longestJump = first;
	} else if (second >= first && second >= third){
		longestJump = second;
	} else if (third >= first && third >= second){
		longestJump = third;
	}
	
	return longestJump;
}

void calcAvgJump(float first, float second, float third, float &avgJump){
	// Calculate The Average Jumps
	avgJump = (first + second + third) / 3;
	// Return The Average Jumps Through Passing-By-Reference
}

int calcPoints(float jump){
	// Declaration
	int point;
	
	// Determine The Points Based On The Longest Jump
	if (jump > 0 && jump < 3){
		point = 1;
	} else if (jump >= 3 && jump <= 4.5){
		point = 2;
	} else if (jump > 4.5 && jump <= 5.5){
		point = 3;
	} else if (jump > 5.5){
		point = 5;
	}
	
	return point;
}

void winnerClub(string clubWinner, int points, float winnerSumJump, float winnerSumAvg){
	// Display The Winner Club, Points And Total Longest Jump
	cout << "\n Congratulations! The Club Winner for this Long Jump Competition is\n Xx The " << clubWinner <<
	" Club xX\n with a Total Score of " << points << " points, a Total Longest Jump Distance of " << winnerSumJump <<
	" meters\n and a Total Average Jump Distance of " << winnerSumAvg << " meters." << endl;
}

void winner(string winner, float winnerJump, float winnerAvg){
	// Display Individual Winner's Name, Longest Jump And Average Jump
	cout << "\n And a Special Congratulations to the individual winner of this Long Jump Competition,\n Xx " << winner <<
	" xX\n with the Longest Jump Distance of " << winnerJump << " meters and an Average Jump Distance of " << winnerAvg << " meters." << endl;
}
