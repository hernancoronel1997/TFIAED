#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Fecha
{
	int dia;
	int mes;
	int anio;
};

struct FechadeNacimiento
{
	int dia;
	int mes;
	int anio;
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




void registrarveterinario()
{
	int b = 0;
	Veterinario vet;
	int i;
	FILE *fp;
	fp = fopen("Veterinarios.dat", "a+b");

	printf("Registro de Veterinario Nº%d", i+1);
	printf("\n------------------------------\n");

	_flushall();
	do
	{
		printf("Apellido y Nombre: ");
		gets(vet.ApellidoyNombre);
	} while (strlen(vet.ApellidoyNombre) == 0);
	_flushall();

	do
	{
		printf("Matricula: ");
		scanf("%06d", &vet.Matricula);
	} while (vet.Matricula >= 0 && vet.Matricula <= 999999);

	do
	{
		printf("DNI: ");
		scanf("%08d", &vet.Dni);
	} while (vet.Dni >= 10000000 && vet.Dni <= 99999999);

	_flushall();
	do
	{
		printf("Télefono: ");
		gets(vet.Telefono);
		i = 0;
		while (vet.Telefono[i] != '\0')
		{
			i++;
			if (isdigit(vet.Telefono[i]) || vet.Telefono[i] == '+')
				b = 1;
		}

	} while (strlen(vet.Telefono) == 0 || b == 1);
	_flushall();

	fprintf(fp, "%s;%06d;%08d;%s;\n",vet.ApellidoyNombre,vet.Matricula,vet.Dni,vet.Telefono);
	
	fclose(fp);
	system("CLS");
}

	/*char ApellidoyNombre[60];
	char Domiciolio[60];
	int DNIdueneo;
	char Localidad[60];
	FechadeNacimiento Fecha;
	float Peso;
	char Telefono[25];*/
void registrmascota()
{
	int b = 0;
	int i;
	Mascota masc;
	

	FILE *fm;
	fm= fopen("Mascota.dat", "a+b");

//	printf("Registro de Veterinario Nº%d", i+1);
	printf("\n------------------------------\n");

	_flushall();
	do
	{
		printf("Apellido y Nombre: ");
		gets(masc.ApellidoyNombre);
	} while (strlen(masc.ApellidoyNombre) == 0);
	_flushall();

	do
	{
		printf("Domicilio: ");
		gets(masc.Domiciolio);
	} while (strlen(masc.Domiciolio) == 0);

	do
	{
		printf("DNI: ");
		scanf("%08d", &masc.DNIdueneo);
	} while (masc.DNIdueneo >= 10000000 && masc.DNIdueneo<= 99999999);

	do
	{
		printf("Localidad: ");
		gets(masc.Localidad);
	} while (strlen(masc.Localidad) == 0);
	
		printf("\nFecha de Nacimiento de la Mascota: ");
		printf("\nDia: ");
		scanf("%d",&masc.Fecha.dia);
		printf("Mes: ");
		scanf("%d",&masc.Fecha.mes);
		printf("Año: ");
		scanf("%d",&masc.Fecha.anio);
		
			_flushall();
	do
	{
		printf("Télefono: ");
		gets(masc.Telefono);
		i = 0;
		while (masc.Telefono[i] != '\0')
		{
			i++;
			if (isdigit(masc.Telefono[i]) || masc.Telefono[i] == '+')
				b = 1;
		}

	} while (strlen(masc.Telefono) == 0 || b == 1);
	_flushall();

	fprintf(fm, "%s;%s;%08d;%s;%d,%d,%d;%s;\n",masc.ApellidoyNombre,masc.Domiciolio,masc.DNIdueneo,masc.Localidad,masc.Fecha.dia,masc.Fecha.mes,masc.Fecha.anio,masc.Telefono);
	
	
}
