/*
 ============================================================================
 Name        : PRACTICO.c
 Author      : Kevin Worner
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
	int id;
	char marca[20];
	int tipo;
	float peso;

}typedef eVehiculo;
//.Dada la estructura eVehiculo crear una función constructora base y una parametrizada
//2. Dada la estructura del punto anterior declarar una variable con valores y guardarla en un archivo de texto.
eVehiculo* Vehiculo_new();
eVehiculo* newParametros(char* idStr,char* marcaStr,char* tipoStr,char* pesoStr);
int Vehiculo_setMarca(eVehiculo* this,char* marca);
int Vehiculo_setId(eVehiculo* this,int id);
int Vehiculo_setMarca(eVehiculo* this,char* marca);
int Vehiculo_setTipo(eVehiculo* this,int tipo);
int Vehiculo_setPeso(eVehiculo* this,float peso);


int main(void) {

	setbuf(stdout,NULL);
	eVehiculo vehiculo = {0, "Fiat", 2, 18000};
	FILE* pFile = fopen("ARCHIVO","w");

	fprintf(pFile,"%d,%s,%d,%f\n", vehiculo.id, vehiculo.marca, vehiculo.tipo,vehiculo.peso);

	fclose(pFile);
	return EXIT_SUCCESS;
}
eVehiculo* Vehiculo_new()
{
	eVehiculo* newVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));

	return newVehiculo;
}
eVehiculo* newParametros(char* idStr,char* marcaStr,char* tipoStr,char* pesoStr)
{
	eVehiculo* newVeh = Vehiculo_new();
	int auxId;
	float auxPeso;
	int auxTipo;
	if(newVeh != NULL)
	{
		auxId = atoi(idStr);
		auxTipo = atoi(tipoStr);
		auxPeso = atof(pesoStr);
		Vehiculo_setId(newVeh, auxId);
		Vehiculo_setMarca(newVeh, marcaStr);
		Vehiculo_setTipo(newVeh, auxTipo);
		Vehiculo_setPeso(newVeh, auxPeso);

	}
	return newVeh;
}
int Vehiculo_setId(eVehiculo* this,int id)
{
	int ret = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
/*------------------------------------------------------------------------------------------------*/
int Vehiculo_setMarca(eVehiculo* this,char* marca)
{
	int ret = -1;
	if(this != NULL && marca != NULL)
	{
		strcpy(this->marca, marca);
		ret = 0;
	}

	return ret;
}
/*-------------------------------------------------------------------------------------------------*/
int Vehiculo_setTipo(eVehiculo* this,int tipo)
{
	int ret = -1;
	if(this != NULL)
	{
		this->tipo = tipo;
		ret = 0;
	}
	return ret;
}
int Vehiculo_setPeso(eVehiculo* this,float peso)
{
	int ret = -1;
	if(this != NULL)
	{
		this->peso = peso;
		ret = 0;
	}
	return ret;
}
