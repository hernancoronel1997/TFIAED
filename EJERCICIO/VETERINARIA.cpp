#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha
{
	int dd;
	int mm;
	int aa;
};

struct FechadeNacimiento
{
	int dd;
	int mm;
	int aa;
};
struct Usuarios{
	char usuario;
	char contrasenea;
	char ApellidoyNombre[60];
};

struct Veterinario
{
	char ApellidoyNombre[60];
	int Matricula;
	int Dni;
	char Telefono[25];
};

struct Mascota{
	char ApellidoyNombre[60];
	char Domiciolio[60];
	int DNIdueneo;
	char Localidad[60];
	FechadeNacimiento Fecha;
	float Peso;
	char Telefono[25];
};



struct Trunos{
	int MatriculadeVeterinario;
	Fecha fecha;
	int DNIdueneo;
	char DetalledeAtencion[380];
};
main()
{
		int opcion;
	//float
	
	do
	{
		system("cls"); //CLS significa clear screan(limpiar pantalla)
		printf("\n\tMENU");
		printf("\n\n1-Modulo Consultorio Veterinario");//\t es una tabulacion
		printf("\n\n2-Modulo del Asistente");
		printf("\n\n3- Módulo Administración");
		printf("\n\n0-Salir");
		
		printf("\n\nIngrese la Opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion)
		{
		
		case 1:
				int opcion1;

			do
			{
				system("cls"); //CLS significa clear screan(limpiar pantalla)
				printf("\n\tMENU");
				printf("\n\n1-Iniciar Sesión");
				printf("\n\n2-Visualizar Lista de Espera de Turnos (informe)");
				printf("\n\n3- Registrar Evolución de la Mascota");
				printf("\n\n4-Cerrar la aplicación");
				
				printf("\n\nIngrese la Opcion: ");
				scanf("%d",&opcion1);
				
				switch(opcion1)
				{
				
				case 1:
				
				
				break;
				
				case 2:
				
				
					break;
					
				case 3:
					
					
				case 4:
					printf("\n Ud Salio del sistema...");
					break;
				default:
				
					printf("\nSE EQUIVOCO DE OPCION DEL MENU!!!");	
				
				
			
				}
				printf("\n\n");
				system("pause");
			}while(opcion1!=4);
				

		break;
		
		case 2:	
				int opcion2;

	
			do
			{
				system("cls"); //CLS significa clear screan(limpiar pantalla)
				printf("\n\tMENU");
				printf("\n\n1-Iniciar Sesión");//\t es una tabulacion
				printf("\n\n2-Registrar Mascota");
				printf("\n\n3- Registrar Turno");
				printf("\n\n4- Listado de Atenciones por Veterinario y Fecha");
				printf("\n\n5-Cerrar la aplicación.");
				
				printf("\n\nIngrese la Opcion: ");
				scanf("%d",&opcion2);
				
				switch(opcion2)
				{
				
				case 1:
				
			
				break;
				
				case 2:
				
				
					break;
					
				case 3:
					
					break;
					
				case 4:
					
					break;
					
				case 5:
					printf("\n Ud Salio del sistema...");
					break;
				default:
				
					printf("\nSE EQUIVOCO DE OPCION DEL MENU!!!");	
				
				
			
				}
				printf("\n\n");
				system("pause");
			}while(opcion2!=5);
					
					
		break;
		case 3:
				int opcion3;
	
			do
			{
				system("cls"); //CLS significa clear screan(limpiar pantalla)
				printf("\n\tMENU");
				printf("\n\n1-- Registrar Veterinario");//\t es una tabulacion
				printf("\n\n2-Registrar Usuario Asistente");
				printf("\n\n3- Atenciones por Veterinarios");
				printf("\n\n4- Ranking de Veterinarios por Atenciones");
				printf("\n\n5-Cerrar la aplicación");
			
				printf("\n\nIngrese la Opcion: ");
				scanf("%d",&opcion3);
				
				switch(opcion3)
				{
				
				case 1:
			
				break;
				
				case 2:
				
				break;
				case 3:
				
				break;
				
				case 4:
				
				break;
				
					
				case 5:
					printf("\n Ud Salio del sistema...");
					break;
				default:
				
					printf("\nSE EQUIVOCO DE OPCION DEL MENU!!!");	
				
				
			
				}
				printf("\n\n");
				system("pause");
			}while(opcion!=5);
					
		break;
		case 0:
			printf("\n Ud Salio del sistema...");
			break;
		default:
		
			printf("\nSE EQUIVOCO DE OPCION DEL MENU!!!");	
		
		
	
		}
		printf("\n\n");
		system("pause");
	}while(opcion!=0);	
}
