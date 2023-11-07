/**
 * @file MontyHallParadox.cpp
 * @author Tucker Self
 * @date 2023-11-07
 * @brief The Monty Hall Paradox
 * 
 * a program that simulates the execution of Monty Hall over a large number of possible runs
 */
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool monty_hall();

void simulate(int num_iterations);

int main() {
  bool oneRun;
  int runAmount;
  char userChoice;
  cout << "Choose whether to simulate 1 instance or a number of instances (i or n): ";
  cin >> userChoice;
  if(userChoice == 'i'){
    oneRun = monty_hall();
    if(oneRun == true)
      cout << "Win on Stay." << endl;
    else
      cout << "Win on Switch." << endl;
  }
  else if(userChoice == 'n'){
    cout << "How many times will you run?: ";
    cin >> runAmount;
    simulate(runAmount);
  }
  else
    cout << "invalid" << endl;
  
  return 0;
}

bool monty_hall(){
  char doors[3] = {'G', 'G', 'G'};

  int carDoor = rand()%3;

  doors[carDoor] = 'C';

  int playerChoice = 1;
  int removeDoor = 0;
  while(removeDoor == (playerChoice-1) || removeDoor == carDoor){
    removeDoor++;
  }
  doors[removeDoor] = 'X';
  
  if((playerChoice-1) == carDoor)
    return true;
  else
    return false;
}

void simulate(int num_iterations){
  int gamesPlayed = 0;
  int stay = 0;
  int change = 0;
  bool carWin;
  for(int i=0; i<num_iterations; i++){
    carWin = monty_hall();
    gamesPlayed++;
    if(carWin == true)
      stay++;
    else
      change++;
  }

  double stayPercentage = stay*100.00/gamesPlayed;
  double changePercentage = change*100.00/gamesPlayed;
  
  cout << "Wins by Staying: " << stay << endl << "Wins by Switching: " << change << endl
       << "Times Played: " << gamesPlayed << endl;
  cout << "Win Percentage when Staying: " << stayPercentage << "%" << endl;
  cout << "Win Percentage when Switching: " << changePercentage << "%" << endl;
}
