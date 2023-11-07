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
  int playerChoice;
  char doors[3] = {'G', 'G', 'G'};

  int carDoor = rand()%3;

  doors[carDoor] = 'C';

  int playerChoice = 0;
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
