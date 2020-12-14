#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LibreriasTFI.h"
#include <locale.h>


void listaEspera(FILE *Us);
void evolucionMascota(FILE *Us);

main()
{
	setlocale(LC_ALL,"spanish");
	FILE *Us;
	int menu=0, Is;
	int b=1;
	
	system("COLOR 3F");
	
	printf ("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
	printf("\n\n\n\n");
	printf (" \t       . . . BIENVENIDO A NUESTRA BASE DE DATOS ...");
	printf("\n\n\n\n");
	printf ("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
	printf("\n\n\n\n");
	system ("pause");
	system ("cls");
	
	while(menu!=4)
	{
		printf("\n\n");
	printf("                      .- Modulo Veterinarios -.");
	printf("\n =================================================================");
		printf("\n\n1.-Iniciar sesión");
		printf("\n2.-Visualizar lista de espera de turnos.");
		printf("\n3.-Registrar evolucion de mascota.");
		printf("\n4.-Cerrar Menú");
		printf("\n  ------------------------------------------------------------");
		printf("\n\n- Ingrese una opcion: ");
		scanf("%d",&menu);
		system("CLS");
		
		switch(menu)
		{
			case 1: Is = IniciarSesion(Us,b);
			        if(Is == 1)
			        {
			            printf("\n.. Sesión iniciada ..\n");
			        }
			break;
			 case 2:
			        if(Is == 1)
			        {
			            listaEspera(Us);
			        }
			        else
			        {
			        	printf("ERROR.. Debe iniciar sesión\n");
					}
			break;
			case 3: 
					if(Is == 1)
					{
						evolucionMascota(Us);
					}
					else
					{
						printf("ERROR.. Debe iniciar sesión\n");
					}
			break;
			
			
			
			
			       
		}
		if(menu!=4)
		{
			printf("\n\n\n");
			system("pause");
		}
		
		system("CLS");
	}
	
}

void listaEspera(FILE *Us)
{
	Fecha fecAux;
	int band=1;  //bandera
	Turnos turnAux;	
	DatosVet matriAux;	
	int matri;
	Mascotas mascAux;	
	FILE *aux;
			
	while(band==1)
	{
		printf("Ingrese la fecha de hoy. Ej(DD/MM/AAAA): ");
		scanf("%d/%d/%d",&fecAux.dia,&fecAux.mes,&fecAux.anio);
		
		if(fecAux.dia > 0 && fecAux.dia < 32)
		{
			if(fecAux.mes > 0 && fecAux.mes < 13)
			{
				if(fecAux.anio > 2019 && fecAux.anio < 2300)
				{
					Us = fopen("Turnos.dat","rb");
					if(Us == NULL)
					{
						printf("\nNo se han encontrado turnos.\n");
					}
					else
					{
						fread(&turnAux,sizeof(Turnos),1,Us);
						while(!feof(Us))
						{
							if(fecAux.dia == turnAux.FecT.dia && fecAux.mes == turnAux.FecT.mes && fecAux.anio == turnAux.FecT.anio && turnAux.borrado==false)
							{
								printf("Ingrese la matricula: ");
								scanf("%d",&matri);
						
					
								aux=fopen("Veterinario.dat","rb");
								if(aux==NULL)
								{
									printf("Error: No se pudo abrir el archivo.\n");
								}
								else
								{
									fread(&matriAux,sizeof(DatosVet),1,aux);
									while(!feof(aux))
									{
										if(matriAux.Mat == matri)
										{
											band=0;
											fseek(aux,0,2);
											fseek(Us,0,2);
										}
										fread(&matriAux,sizeof(DatosVet),1,aux);
									}
									if(band==1)
									{
										printf("Error: Matricula incorrecta.\n");
									}
								}
							}
							fread(&turnAux,sizeof(Turnos),1,Us);
						}
						if(band==1)
						{
							printf("No hay turnos disponibles hoy.\n");
						}
						fclose(Us);	
					}
				}
				else
				{
					printf("Error: Año de turno erróneo.\n");
				}
			}
			else
			{
				printf("Error: Mes de turno erróneo.\n");
			}
		}
		else
		{
			printf("Error: Dia de turno erróneo.\n");
		}
		if(band==1)
		{
			printf("1-Volver a ingresar una fecha, 2-Volver al menu.\n");
			scanf("%d",&band);
		}
	}
	
	
	if(band==0)
	{
		Us = fopen("Turnos.dat","rb");
		
		if(Us == NULL)
		{
			printf("Error: No se pudo leer el archivo.\n");
		}
		else
		{
			fread(&turnAux,sizeof(Turnos),1,Us);
			while(!feof(Us))
			{
				if(fecAux.dia == turnAux.FecT.dia && fecAux.mes == turnAux.FecT.mes && fecAux.anio == turnAux.FecT.anio)
				{
					if(matri == turnAux.MatV)
					{
						aux = fopen("Mascotas.dat","rb");
						if(aux==NULL)
						{
							printf("Error: No hay ninguna mascota registrada.\n");
						}
						else
						{
							fread(&mascAux,sizeof(Mascotas),1,aux);
							while(!feof(aux))
							{
								if(mascAux.DNID == turnAux.DNIT && turnAux.borrado == false)
								{
									printf("DATOS DEL TURNO:\n");
									printf("--------------------------------------------------\n");
									printf("Nombre de la mascota: ");
									puts(turnAux.NomMas);
									if((mascAux.fecNac.anio - fecAux.anio)>0)
									{
										printf("Edad: %d años\n",mascAux.fecNac.anio - fecAux.anio);
									}
									else if((mascAux.fecNac.mes - fecAux.mes) > 0)
									{
										printf("Edad: %d meses\n",mascAux.fecNac.mes - fecAux.mes);
									}
									else
									{
										printf("Edad: %d dias\n",mascAux.fecNac.dia - fecAux.dia);
									}									
									printf("Peso: %2.f\n",mascAux.Peso);
									printf("Localidad: %s\n",mascAux.Loc);
									printf("DNI del dueño: %d\n",mascAux.DNID);
									printf("\n\nEVOLUCION REGISTRADA DE LA MASCOTA:\n");
									puts(turnAux.evoMasc);
									printf("--------------------------------------------------\n");
								}
								else
								{
									
								}
								fread(&mascAux,sizeof(Mascotas),1,aux);
							}
						}
					}
				}
			    fread(&turnAux,sizeof(Turnos),1,Us);
			}
		    fclose(Us);
			
		}
	}
}

void evolucionMascota(FILE *Us)
{
	char auxNom[60];
	Mascotas auxM;
	FILE *aux;
	Turnos auxT;
	int band=0;
	
	Us = fopen("Mascotas.dat","rb");
	
	if(Us==NULL)
	{
		printf("ERROR.. No se ha registrado ninguna  mascota. (El archivo está vacío)\n");
	}
	else
	{
		printf("- Ingrese el nombre de la mascota a registrar: ");
		_flushall();
		gets(auxNom);
		strupr(auxNom);
		
		fread(&auxM,sizeof(Mascotas),1,Us);
		while(!feof(Us))
		{
			strupr(auxM.Nombre);
			if(strcmp(auxNom,auxM.Nombre)==0)
			{
				aux = fopen("Turnos.dat","r+b");
				if(aux==NULL)
				{
					printf("ERROR.. No hay turnos registrados.\n");
				}
				else
				{
					fread(&auxT,sizeof(Turnos),1,aux);
					while(!feof(aux))
					{
						if(auxM.DNID==auxT.DNIT)
						{
							printf("- Ingrese la evolucion de la mascota: \n");
							_flushall();
							gets(auxT.evoMasc);
							
							auxT.borrado=true;
							fseek(aux,-sizeof(Turnos),1);
							fwrite(&auxT,sizeof(Turnos),1,aux);
							fseek(aux,0,2);
							fseek(Us,0,2);
							
							printf(".. Evolucion registrada, paciente atendido.\n");
							band=2;
						}
						else
						{
							band=1;
						}
						
						fread(&auxT,sizeof(Turnos),1,aux);	
					}
					fclose(aux);
				}
				
			}
			fread(&auxM,sizeof(Mascotas),1,Us);
		}
		if(band==0)
		{
			printf("ERROR.. La mascota no se encuentra registrada.\n");
		}
		else if(band==1)
		{
			printf("ERROR.. No tiene un turno registrado, por favor, registrese.\n");
		}
		fclose(Us);
	}
	
	
}

