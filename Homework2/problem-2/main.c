#include "part-a-problem-1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argC, char** argV){



	if(argC < 2){
		fprintf(stderr, "USAGE: %s <specify sorting filter(last or height)>\n", argV[0]);
		exit(1);
	}

	int amtOfPeople = 4;
	PartA* weThePeople = (PartA*)malloc(sizeof(PartA)*amtOfPeople);
	getPeople(amtOfPeople, weThePeople);

	if(!strcmp(argV[1], "last")){
		qsort(weThePeople, amtOfPeople, sizeof(PartA), comparePeopleNames);
		printPeople(amtOfPeople, weThePeople);
	}
	else if(!strcmp(argV[1], "height")){
		qsort(weThePeople, amtOfPeople, sizeof(PartA), comparePeopleHeight);
		printPeople(amtOfPeople, weThePeople);
	} else{
		printf("Please select a proper filter for sorting, either use last or height.\n");
	}

	//strcpy(weThePeople[0].firstName, argV[1]);
	//strcpy(weThePeople[0].lastName, argV[2]);
	//int personHeight = atoi(argV[3]);


	//printf("%s %s %d\n", weThePeople[0].firstName, weThePeople[0].lastName, personHeight);

	free(weThePeople);

	return 0;
}
