#ifndef INPUTS_H_
#define INPUTS_H_

/*
typedef struct
{
	int id;
	char nombre[32];

}structura;
*/

int input_GetInt(char mensaje[]);
float input_GetFloat(char mensaje[]);
char input_GetChar(char mensaje[]);
void input_GetString(char mensaje[],char* copiar);

void ImprimirVectorInt(int[],int);
void OrdenarVectorMenorAMayor(int[],int);

#endif /* INPUTS_H_ */
