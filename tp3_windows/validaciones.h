/*
 * validaciones.h
 *
 *  Created on: 23 May 2022
 *      Author: fa_mg
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validaciones_esNumerica(char*);

int validaciones_NumeroDistinto0(float);
int validaciones_NumeroEntreRangos(float,float,float);
int validaciones_NumeroAfueraRangos(float,float,float);

int validaciones_CalcularSignoNumero(float);
int validaciones_CalcularParidadNumero(int);

int validaciones_Anio(int anio, int anioMinimo, int anioMaximo);
int validaciones_Mes(int anio, int mes, int anioactual,int mesactual);
int validaciones_Dia(int anio, int mes,int dia,int anioactual,int mesactual,int diaActual);


#endif /* VALIDACIONES_H_ */
