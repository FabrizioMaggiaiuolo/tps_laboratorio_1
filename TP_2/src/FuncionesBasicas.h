#ifndef FUNCIONESBASICAS_H_
#define FUNCIONESBASICAS_H_

/*
struct
{
	int id;
	char nombre[32];

}typedef structura;
*/

int GetInt(char mensaje[]);
float GetFloat(char mensaje[]);
char GetChar(char mensaje[]);

int ValidarDistinto0(float);
int ValidarEntreRangos(float,float,float);
int ValidarAfueraRangos(float,float,float);

int CalcularSignoNumero(float);
int CalcularParidadNumero(int);

void ImprimirVectorInt(int[],int);
void OrdenarVectorMenorAMayor(int[],int);

#endif /* FUNCIONESBASICAS_H_ */
