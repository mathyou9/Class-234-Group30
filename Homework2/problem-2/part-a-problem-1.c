#include "part-a-problem-1.h"
#include "string.h"

void getPeople(int amtOfPeople, PartA* weThePeople){
  FILE* userInput = fopen("in.txt", "r");
  for(int i = 0; i < amtOfPeople; i++){
    fscanf(userInput, "%s %s %f\n", weThePeople[i].firstName, weThePeople[i].lastName, &weThePeople[i].height);
  }
}

void printPeople(int amtOfPeople, PartA* weThePeople){
  for(int i = 0; i < amtOfPeople; i++){
    printf("%s %s %.2f\n", weThePeople[i].firstName, weThePeople[i].lastName, weThePeople[i].height);
  }
}

int comparePeopleHeight(const void* p1, const void* p2){
  if( ((PartA*)p1)->height < ((PartA*)p2)->height) return -1;
  if( ((PartA*)p1)->height == ((PartA*)p2)->height) return 0;
  return 1;
}
int comparePeopleNames(const void* p1, const void* p2){
  if(strcmp(((PartA*)p1)->lastName, ((PartA*)p2)->lastName) < 0) return -1;
  if(strcmp(((PartA*)p1)->lastName, ((PartA*)p2)->lastName) == 0) return 0;
  return 1;

}
