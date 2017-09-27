/*
* Health Monitoring System
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXPATIENTS 5
#define MAXREADINGS 10
#define MAXTYPES 5
#define MAXTIME 8

/* One health type reading: timestamp + actual value */
typedef struct{
	char timestamp[MAXTIME+1];
	int value;
}Element;

/* Circular buffer of health type readings */
typedef struct{
	int start;	/* index of oldest reading */
	int end;	/* index of most current reading */
	Element reading[MAXREADINGS + 1];
}CircularBuffer;

/* Patient's health chart: ID + multiple health type readings */
typedef struct{
	int id;
	CircularBuffer buffer[MAXTYPES];
}Chart;


/*
* Health records for all patients defined here.
* The variable record is visible to all functions
* in this file, i.e. it is global.
*/
Chart record[MAXPATIENTS];

void main(){
int i, j;

/* initialize health data records for each patient */

for( i=0; i < MAXPATIENTS; i++ ){
    record[i].id = i + 1;
    for( j=0; j < MAXTYPES; j++ ){
        record[i].buffer[j].start = 0;
	record[i].buffer[j].end = 0;
        }
    }
printf("Welcome to the Health Monitoring System\n\n");

/*
*  YOUR CODE GOES HERE:
*  (1) Read a csv line of health data from stdin
*  (2) Parse csv line into appropriate fields
*  (3) Store health data in patient record or print if requested
*  (4) Continue (1)-(3) until EOF
*/

	int id; //variable to keep the id
	char time[MAXTIME + 1]; //variable to keep the time
	int type; // variable to keep the type
	int value; //variable to keep the value
	float valueF; //To keep track of the float used for temperature
	int idx = 0; // index used to get rid of extra comma
	int idxT = 9;//index used to copy over the array
	int idxP = 1;//index used for printing

	// this while loop keeps repeating all of the actions until no more input it added
	//scanf reads in the data which is always in the same format, automatically assigns it to their respectful variables
	while(scanf("%i, %s %i, %i" , &id, &time[MAXTIME + 1], &type, &value) != EOF){
		if(type != 6){//if the type isn't the print command
			// while loop to remove the extra comma on the end of the time array
			while( time[idx] != ','){
				time[idx] = time[idx];
				idx ++;
			}
			time[idx] = '\0'; //terminates the time array
			record[id].id = id; //sets the records id equal to the id
			if(record[id].buffer[type].end < MAXREADINGS){
				record[id].buffer[type].reading[record[id].buffer[type].end].value = value; //sets the records, type value, equal to the value from scanf
				record[id].buffer[type].end++;
			}
			else{
				if(record[id].buffer[type].start < MAXREADINGS){
					record[id].buffer[type].reading[record[id].buffer[type].start].value = value;
					record[id].buffer[type].start++;
				}
				else{
					record[id].buffer[type].start = 0;
					record[id].buffer[type].reading[record[id].buffer[type].start].value = value;
                                        record[id].buffer[type].start++;
				}
			}
			idx = 0; //resets this index to zero
			idxT = 9; //resets this index to 9
			/*
			* For this while loop, in stage 1 I realized that in time from scanf, the actual time indexes don't start until the time[9].
			* I have no idea why this happens since I set the length to MAXTIME + 1, however, this is how the code works
			* In this loop, it goes until time[idxT] equals '\0', if it doesnt, then it will set the records timestamp index equal to the higher index of time[]
			* It then increases both variables and after the loop ends, null terminates the time.
			*/
			if(record[id].buffer[type].end < MAXREADINGS){
				while(time[idxT]){
					record[id].buffer[type].reading[record[id].buffer[type].end].timestamp[idx] = time[idxT];
					idx++;
					idxT++;
				}
				record[id].buffer[type].reading[0].timestamp[idx] = '\0';
			}
			else{
				while(time[idxT]){
                                	record[id].buffer[type].reading[record[id].buffer[type].start].timestamp[idx] = time[idxT];
	                                idx++;
        	                        idxT++;
                	        }
                        	record[id].buffer[type].reading[0].timestamp[idx] = '\0';
			}
		}
		else if(type == 6){//goes into this series of print statements if a print command is entered
			idx = 1; //starts the index at one
			printf("--------------------------------------------------\n");
			printf("Readings for Patient ID = %i are:\n", id);
			while(idx <= MAXTYPES){//goes through each of the types in the buffer array
				switch(idx){//has a specific print statement for each type that could be entered
					case 1:
						//prints out for temperature
						printf("Temperature:\n");
						idxP = 1;//resets the idxP to 1
						if(record[id].buffer[idx].end == 0){//checks to see if there was anything added into the readings
							printf("<none>\n");//since there wasn't anything it prints out none
						}
						else{//will go into a while loop that will print out each timestamp and value for each reading
							//checks to see if the end is less than nine
							if(record[id].buffer[idx].end < 9){
								//if it is it will go until that last number
								while(idxP <= record[id].buffer[idx].end){
									valueF  = record[id].buffer[idx].reading[idxP-1].value  / 10.0;
									printf("%s: %.1f\n", record[id].buffer[idx].reading[idxP].timestamp, valueF);
									idxP++;
								}
							}
							else{
								//if it is greater than 9, then it will print until right before the 9th value
								while(idxP < record[id].buffer[idx].end){
                                                                	valueF  = record[id].buffer[idx].reading[idxP-1].value  / 10.0;
                                                                        printf("%s: %.1f\n", record[id].buffer[idx].reading[idxP].timestamp, valueF);
                                                                        idxP++;
                                                                }
								//it will then print out the last value which is in the 0th index
								if(idxP >= 9){
									valueF = record[id].buffer[idx].reading[idxP-1].value / 10.0;
									printf("%s: %.1f\n", record[id].buffer[idx].reading[0].timestamp, valueF);
								}
							}
						}
						break;
					case 2:
						//prints out for Heart Rate
						idxP = 1;
						printf("Heart Rate:\n");
						if(record[id].buffer[idx].end == 0){
							printf("<none>\n");
                                                }
						else{
							if(record[id].buffer[idx].end < 9){
            	   						while(idxP <= record[id].buffer[idx].end){
									//The two indexes are different for some reason which is why the value has an index of idxP-1
									printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
									idxP++;
								}
							}
							else{
								while(idxP < record[id].buffer[idx].end){
                                                                        printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                                                        idxP++;
                                                                }
								if(idxP >= 9){
										printf("%s: %i\n", record[id].buffer[idx].reading[0].timestamp, record[id].buffer[idx].reading[idxP-1].value);
								}
							}
						}
						break;
					case 3:
						//prints out for Systolic Pressure
						printf("Systolic Pressure:\n");
						idxP = 1;
						if(record[id].buffer[idx].end == 0){
                                                        printf("<none>\n");
                                                }
                                                else{
							if(record[id].buffer[idx].end < 9){
								while(idxP <= record[id].buffer[idx].end){
                        	                        	       	printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                	                        	idxP++;
								}
							}
							else{
								while(idxP < record[id].buffer[idx].end){
                                                                        printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                                                        idxP++;
                                                                }
								if(idxP >= 9){
									printf("%s: %i\n", record[id].buffer[idx].reading[0].timestamp, record[id].buffer[idx].reading[idxP-1].value);
								}
							}
                                                }
						break;
					case 4:
						//Prints out for Diastolic Pressure
						printf("Diastolic Pressure:\n");
						idxP = 1;
						if(record[id].buffer[idx].end == 0){
                                                        printf("<none>\n");
                                                }
                                                else{
							if(record[id].buffer[idx].end < 9){
                	                                	while(idxP <= record[id].buffer[idx].end){
                        	                                	printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                	                       		idxP++;
								}
							}
							else{
								while(idxP < record[id].buffer[idx].end){
                                                                        printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                                                        idxP++;
								}
								if(idxP >= 9){
									printf("%s: %i\n", record[id].buffer[idx].reading[0].timestamp, record[id].buffer[idx].reading[idxP-1].value);
								}
							}
                                                }

						break;
					case 5:
						//Prints out information for Respiration Rate
						printf("Respiration Rate:\n");
						idxP = 1;
						if(record[id].buffer[idx].end == 0){
                                                        printf("<none>\n");
                                                }
                                                else{
							if(record[id].buffer[idx].end < 9){
                                  	        	      	while(idxP <= record[id].buffer[idx].end){
                                        	                	printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP - 1].value);
                                                       			idxP++;
								}
							}
							else{
								while(idxP < record[id].buffer[idx].end){
                                                                        printf("%s: %i\n", record[id].buffer[idx].reading[idxP].timestamp, record[id].buffer[idx].reading[idxP-1].value);
                                                                        idxP++;
                                                                }
								if(idxP >= 9){
									printf("%s: %i\n", record[id].buffer[idx].reading[0].timestamp, record[id].buffer[idx].reading[idxP - 1].value);
								}
							}
                                                }

						break;
					default:
						printf("invalid index");
						break;
				}
				idx++;//increases the index by one
			}
			printf("--------------------------------------------------\n");
		}
	}


printf("\nEnd of Input\n");

}
