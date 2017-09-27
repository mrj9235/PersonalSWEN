#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* Main function for the Health Monitoring System. Primarily responsible for
* processing input of csv lines and printing as required. Data structures are
* maintained using the helper functions in health_util.c
*
*/

Chartptr patientList = NULL;    /* Define global variable patientList (declared in health.h) */
								/* patientList is globaaly accessible in health_util.c    */

void main(){

printf("Welcome to the Health Monitoring System\n\n");

/*
*  YOUR CODE GOES HERE:
*  (1) Read an input csv line from stdin
*  (2) Parse csv line into appropriate fields
*  (3) Take action based on input type:
*  		 - Check-in or check-out a patient with a given ID
*        - Add a new health data type for a given patient
*        - Store health data in patient record or print if requested
*  (4) Continue (1)-(3) until EOF
*/

	int id; //variable to keep track of scanf's id imput
	char time[MAXTIME + 1]; //variable to keep track of scanf's time input
	int type; //variable to keep track of the type
	int value; // variable to keep track of the value
	int buffIndex; //variable for print statement to keep track of number of buffers
	int readIndex;//variable for print case to keep track of the readings in the buffer
	CBuffptr patientHealth; //a buffer pointer to get the health records to add in a new health reading
	//a character array to keep track of all of the types of readings
	char* types[] = {"Temperature:", "Heart Rate:", "Systolic Pressure:", "Diastolic Pressure:", "Respiration Rate"};
	Chartptr checking;//Pointer to make sure that the chart of the patient doesn't equal NULL
	CBuffptr patientPrint; //A bufferpointer used during the print case

	//A while loop that will keep scanning until the input is "End of File"
	while(scanf("%i, %8[^,], %i, %i", &id, &time[MAXTIME + 1], &type, &value)!= EOF){
		//goes to the case based on what the type is 
		switch(type){
			//type to reset the patient values
			case 0:
				printf("--------------------------------------------------\n");
				printf("%s: Patient ID = %i reset data\n", &time[MAXTIME + 1], id);
				printf("--------------------------------------------------\n");
				//calls a function that just removes the health values but keeps the chart intact
				removeHealth(id);
				break;
			//Because of the waterfall effect, I decided to avoid redundancy and set all the cases and allow them to drop into the next case until case 5, where the actions will actually happen
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				checking = getChart(id);
				//Checks to see if the chart is NULL
				if(checking == NULL){
					break;
				}
				//if it isn't it will get the health type buffer
				patientHealth = getHealthType(id, type);
				//if it isn't NULL then it will add the health reading
				if(patientHealth != NULL){
					addHealthReading(patientHealth, &time[MAXTIME + 1], value);
				}
				break;
			case 6:
				//checks to see if the chart is NULL
				checking = getChart(id);
				if(checking == NULL){
					break;
				}
				//if it isn't it will go through each data type in the types array and print out each of their readings
				buffIndex = 0;
				printf("--------------------------------------------------\n");
				printf("Readings for Patient ID = %i are:\n", id);
				for(buffIndex; buffIndex < 5; buffIndex++){
					printf("%s\n", types[buffIndex]);
					patientPrint = getHealthType(id, buffIndex+1);
					if(patientPrint == NULL){
						printf("<none>\n");
					}
					else{
						readIndex = 0;
						if(patientPrint->end < MAXREADINGS){
							for(readIndex; readIndex < patientPrint->end; readIndex++){
								if(buffIndex == 0){
									printf("%s: %.1f\n", patientPrint->reading[readIndex].timestamp, patientPrint->reading[readIndex].value / 10.0);
								}
								else{
									printf("%s: %i\n", patientPrint->reading[readIndex].timestamp, patientPrint->reading[readIndex].value);
								}
							}
						}
						else{
							for(readIndex; readIndex < MAXREADINGS; readIndex++){
                                                                if(buffIndex == 0){
                                                                        printf("%s: %.1f\n", patientPrint->reading[readIndex].timestamp, patientPrint->reading[readIndex].value / 10.0);
                                                                }
                                                                else{
                                                                        printf("%s: %i\n", patientPrint->reading[readIndex].timestamp, patientPrint->reading[readIndex].value);
                                                                }
                                                        }
						}
					}
				}
				printf("--------------------------------------------------\n");
				break;
			case 7:
				//Checks in a patient by calling a helper function
				printf("--------------------------------------------------\n");
				addPatient(id);
				printf("%s: PatientID = %i checking in\n", &time[MAXTIME + 1], id);
				printf("--------------------------------------------------\n");
				break;
			case 8:
				//checks out a patient by calling the original removePatient method
				printf("--------------------------------------------------\n");
				printf("%s: Patient ID = %i  checking out\n", &time[MAXTIME + 1], id);
				printf("--------------------------------------------------\n");
				removePatient(id);
				break;
			case 9:
				//calls addHealthType to add another buffer to the patients health types
				addHealthType(id, value);
				break;
		}

	}

printf("\nEnd of Input\n");

}
