struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef sPassenger;

struct
{
	char flycode[10];
	int statusFlight;
}typedef sFlights;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


int initPassengers(sPassenger list[],int len);

int addPassengers(sPassenger list[],int len,int id,char name[],char lastName[],float price,int typePassenger,char flycode[]);

int findPassengerById(sPassenger list[],int len,int id);

int removePassenger(sPassenger list[],int len,int id);

void printPassengers(sPassenger list[],int len,sFlights listFlights[],int lenFlights);

int sortPassengers(sPassenger list[],int len,int order);

int sortPassengersByCode(sPassenger list[],int len,int order);

int sortPassengersByType(sPassenger list[],int len,int order);

#endif /* ARRAYPASSENGER_H_ */
