#ifndef PARTA_H
#define PARTA_H

#include <stdio.h>

typedef struct PartA{
	char firstName[20];
	char lastName[20];
	float height;
}PartA;

void getPeople(int amtOfPeople, PartA* weThePeople);
void printPeople(int amtOfPeople, PartA* weThePeople);
int comparePeopleHeight(const void* p1, const void* p2);
int comparePeopleNames(const void* p1, const void* p2);

#endif
