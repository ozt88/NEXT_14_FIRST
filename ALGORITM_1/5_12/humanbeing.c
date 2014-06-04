#include<stdio.h>
#include <string.h> 
#include "human.h"


void humanInput(human* person)
{
	printf("Input name: ");
	scanf("%s", person->name);
	printf("Input age: ");
	scanf_s("%d", &(person->age));
	printf("Input salary: ");
	scanf_s("%d", &(person->salary));
}

int humansEqualValue(human person1, human person2)
{
	if (strcmp(person1.name, person2.name)) return FALSE;
	if (person1.age != person2.age) return FALSE;
	if (person1.salary != person2.salary) return FALSE;

	return TRUE;
}

int humansEqualReferance(human* person1, human* person2)
{
	if (strcmp(person1->name, person2->name)) return FALSE;
	if (person1->age != person2->age) return FALSE;
	if (person1->salary != person2->salary) return FALSE;

	return TRUE;
}

int main(void)
{
	human person1, person2;
	humanInput(&person1);
	humanInput(&person2);

	if (humansEqualValue(person1, person2)) printf("Two persons are equal by Value\n");
	if (humansEqualReferance(&person1, &person2))  printf("Two persons are equal by Referance\n");
	else printf("Twopersons are different\n");
	
	return 0;
}