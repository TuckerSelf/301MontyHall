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

using namespace std;

bool monty_hall();

void simulate(int num_iterations);

int main() {
  
  
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

  double stayPercentage = (stay/gamesPlayed)*10.00;
  double changePercentage = (change/gamesPlayed)*10.00;
  
  cout << "Wins by Staying: " << stay << endl << "Wins by Switching: " << change << endl
       << "Times Played: " << gamesPlayed << endl;
  cout << "Win Percentage when Staying: " << stayPercentage << "%" << endl;
  cout << "Win Percentage when Switching: " << changePercentage << "%" << endl;
}
