#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float IngresoFloat(char[]);

int ImprimirMenu(float,float,float);
int CalcularCostos(float,float,float,float[]);
void InfomarResultados(float[],int,float,float,float);

float PrecioTarjetaDebito(float,float);
float PrecioTarjetaCredito(float,float);
float PrecioBitcoin(float,float);
float PrecioUnitario(float,float);
float DiferenciaDePrecio(float,float);

#endif /* FUNCIONES_H_ */
