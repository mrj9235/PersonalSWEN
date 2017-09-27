#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "health.h"

/*
* health_util.c - Helper functions for the Health Monitoring System
*
* Add any optional helper function declarations here, define
* the functions after the required functions below.
*
* static void myOptionalFunc();   // EXAMPLE
*
*/

/*
* addPatient: check-in a new patient
*   (1) allocate a new Chart for the patient
*   (2) initialize the chart with the passed patientID
*   (3) new patients are inserted at the start of the patient list
*
* (note that the variable patientList is globally accessible)
*/
void addPatient( int patientID ){
	Chartptr patientChart = getChart(patientID);
	if(patientChart == NULL){
		Chartptr newPatient = malloc(sizeof(Chart));
		newPatient->id = patientID;
		newPatient->buffer = NULL;
		newPatient->next = patientList;
		patientList = newPatient;
	}
  }

/*
* addHealthType: add a new health type buffer for a given patient
*	(1) allocate a new CircularBuffer
*	(2) initialize the buffer
* 	(3) link it to the existing patient's Chart
*/
void addHealthType( int patientID, int newType ){
	CBuffptr healthType = getHealthType(patientID, newType);
	Chartptr patient = getChart(patientID);
	if(healthType == NULL && patient != NULL){
		CBuffptr newHealthType = malloc(sizeof(CircularBuffer));
		newHealthType->type = newType;
		newHealthType->start = 0;
		newHealthType->end = 0;
		newHealthType->next = patient->buffer;
		patient->buffer = newHealthType;
	}
 }

/*
*  getChart: given a patientID, return a pointer to their Chart
*/
Chartptr getChart( int patientID ){
	Chartptr foundChart = NULL;
	Chartptr iterator = patientList;
	while(iterator != NULL){
		if(iterator->id == patientID){
			foundChart = iterator;
			return foundChart;
		}
		else{
			iterator = iterator->next;
		}
	}
	return foundChart;
}

/*
*  getHealthType: given a patientID & healthType, return a pointe
r
*  to the CircularBuffer for that type. If the health type does NOT exist
*  for that patient, return NULL
*/
CBuffptr getHealthType( int patientID, int healthType ){
	CBuffptr foundType = NULL;
	Chartptr patientChart = getChart(patientID);
	CBuffptr buff = patientChart -> buffer;
	while( buff != NULL){
		if( buff->type == healthType){
			foundType = buff;
			return foundType;
		}
		else{
			buff = buff->next;
		}
	}
  return foundType;
  }

/*
*  addHealthReading: given a pointer to CircularBuffer, add the passed
*  timestamp and health data type reading to the buffer
*/
void addHealthReading( CBuffptr buffer, char* timestamp, int reading ){ 
		buffer->reading[(buffer->end)%10].value = reading;
		strcpy(buffer->reading[(buffer->end)%10].timestamp, timestamp);
		buffer->end += 1;
}

/*
*  removePatient: check-out an existing patient
*	  (1) delete the patient's Chart & accompanying
*         health data readings.
*     (2) update the list of current patients
*/
void removePatient( int patientID ){
	Chartptr patient = getChart(patientID);
	Chartptr update = patientList;
	CBuffptr curr = patient->buffer;
	Chartptr test;
	CBuffptr currNext;
	while(curr != NULL){
		currNext = curr->next;
		free(curr);
		curr = currNext;
	}
	patient->buffer = NULL;
	if(update->id == patientID){
		patientList = patientList->next;
		update->next =  NULL;
	        patient->next = NULL;
        	free(patient);
	}
	else{
		while(update->next->id != patientID){
                update = update->next;
	        }
        	update->next = update->next->next;
	        patient->next = NULL;
        	free(patient);
	}
	test = patientList;
	while(test != NULL){
		printf("UPDATED LIST: %i", test->id);
		test = test->next;
	}
}

/*
* Optional helper functions defined starting here:
*
* static void myOptionalFunc(){ }  // EXAMPLE
*
*/


/*
*this method will go through the health buffers and free up all of their memory 
*but keep the patients chart intact
*/
void removeHealth( int patientID ){
	Chartptr patient = getChart( patientID );
	CBuffptr curr = patient->buffer;
	CBuffptr currNext;
	while( curr != NULL){
		currNext = curr->next;
		free(curr);
		curr = currNext;
	}
	patient->buffer = NULL;
}
