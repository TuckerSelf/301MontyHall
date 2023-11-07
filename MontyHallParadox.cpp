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

void monty_hall();

void simulate(int num_iterations);

int main() {
  
  
  return 0;
}

void monty_hall(){
  int playerChoice;
  char doors[3] = {'G', 'G', 'G'};
  char closedDoors[3] = {'D', 'D', 'D'};

  int carDoor = rand()%3;

  doors[carDoor] = 'C';

  for(int i = 0; i<3; i++)
    cout << closedDoors[i] << " ";
  cout << endl;
  cout << "Choose a door (1 - 3): ";
  cin >> playerChoice;
  
  int removeDoor = 0;
  while(removeDoor == (playerChoice-1) || removeDoor == carDoor){
    removeDoor++;
  }
  doors[removeDoor] = 'X';
  closedDoors[removeDoor] = 'X';

  for(int i = 0; i<3; i++)
    cout << closedDoors[i] << " ";
  cout << endl;
  
  char decision;
  cout << "Change doors or stay? (c or s): ";
  cin >> decision;
  if(decision == 'c'){
    playerChoice++;
    if((playerChoice-1) == removeDoor){
      playerChoice++;
    }
    if(playerChoice > 3){
      playerChoice = 1;
    }
  }
  for(int i = 0; i<3; i++)
    cout << doors[i] << " ";
  cout << endl;
  if((playerChoice-1) == carDoor)
    cout << "You Win!" << endl;
  else
    cout << "You Lose :(" << endl;
}
