#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include"LibreriasTFI.h"


void RegistrarVet(FILE *Vet);
int UsuarioRepetido(char NomU[10],FILE *&Vet);
void ComprobarUsuario(char NomU[10],int &b,FILE *&Vet);
void ComprobarContra(char ConU[32],int &b);
void RegistrarUs(FILE *Vet);
void Atenciones(int mes);// Listar Atenciones por Veterinarios

main()
{
	int menu=0;
	setlocale(LC_ALL,"spanish");
	FILE *Vet;
	int smes;
	system("COLOR 3F");
	
	printf ("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
	printf("\n\n\n\n");
	printf (" \t       . . . BIENVENIDO A NUESTRA BASE DE DATOS ...");
	printf("\n\n\n\n");
	printf ("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
	printf("\n\n\n\n");
	system ("pause");
	system ("cls");

	
	while(menu!=5)
	{
		printf("\n\n");
	printf("                      .- Modulo Administracion -.");
	printf("\n =================================================================");
		printf("\n\n         1.- Registrar un nuevo veterinario");
		printf("\n         2.- Registrar un nuevo asistente");
		printf("\n         3.- Atenciones por Veterinarios");
		printf("\n         5.- Cerrar Menú");
		printf("\n");
		printf("\n  --------------------------------------------------------------");
		printf("\n\n- Ingrese una opcion: ");
		scanf("%d",&menu);
		system("CLS");
		
		switch(menu)
		{
			case 1: RegistrarVet(Vet);
			break;
			case 2: RegistrarUs(Vet);
			break;
			case 3:
				printf("Ingrese el mes que desea buscar:");
				scanf("%d",&smes);
				
				Atenciones(smes);
				system("PAUSE");
				break;
				break;
				
			case 5: 
			break;
			default: printf("ERROR.. opcion invalida");
		}
		if(menu!=5)
		{
			printf("\n\n\n");
			system("pause");
		}
		system("CLS");
	}
	
	
	
}

void RegistrarVet(FILE *Vet)
{
	DatosVet DatV;
	Usuario DatU;
	int b;
	
	Vet = fopen("Veterinario.dat","ab");
	
	if(Vet == NULL)
	{
		printf("Error al abrir el archivo\n");
	}
	else
	{
		printf("Ingrese los siguientes datos del veterinario: \n");
		
		printf("\t- Apellido y Nombre: ");
		_flushall();
		gets(DatV.ApeyNom);
		printf("\t- Matricula: ");
		scanf("%d",&DatV.Mat);
		printf("\t- DNI: ");
		scanf("%d",&DatV.DNI);
		printf("\t- Telefono: ");
		_flushall();
		gets(DatV.Tel);
		fwrite(&DatV,sizeof(DatosVet),1,Vet);
		fclose(Vet);
		
	    //Registro de usuario  del veterinario.
	    system("CLS");
	    Vet = fopen("Usuario.dat","a+b");
	    if(Vet==NULL)
	    {
	    	printf("Error al abrir el archivo\n");
	    }
	    else
	    {
	    	strcpy(DatU.Nombre,DatV.ApeyNom);
		
		    printf("Registrar nombre de usuario\n");
		    printf("1.-Debe ser unico.\n2.-Debe comenzar con una letra minuscula.\n3.-Debe tener como minimo dos letras mayusculas.\n");
		    printf("4.-Debe tener como maximo 3 digitos.\n5.-Debe tener entre 6-10 caracteres.\n");
		    b=0;
		    while(b==0)
		    {
		        printf("\n- Ingrese el nombre de usuario: ");
		        _flushall();
	    	    gets(DatU.Usuar);
			    ComprobarUsuario(DatU.Usuar,b,Vet);
		    }
		  
	       //registro de contraseñia del veterinario
	  
	  	    printf("\nRegistrar contraseña:\n");
		    printf("1.- Debe contener como minimo una letra mayuscula, una minuscula y un numero.\n");
		    printf("2.- Solo puede contener caracteres alfanumericos.\n");
		    printf("3.- Debe tener entre 6-32 caracteres.\n");
		    printf("4.- No debe tener mas de 3 caracteres numericos consecutivos.\n");
		    printf("5.- No debe tener 2 letras consecutivas ascendentes.\n");
		    b=0;
	  	    while(b==0)
	  	    {
	  		    printf("\n- Ingrese la contraseña: ");
			    _flushall();
			    gets(DatU.Contra);
			    ComprobarContra(DatU.Contra,b);
	  	    }
	  	    
	  	    fwrite(&DatU,sizeof(Usuario),1,Vet);
	  	    fclose(Vet);
		
	    }

	}
}



int UsuarioRepetido(char NomU[10],FILE *&Vet)
{
	Usuario Us;
	int b=1;

    rewind(Vet);
	fread(&Us,sizeof(Usuario),1,Vet);
	while(!feof(Vet))
	{
    	if(strcmp(Us.Usuar,NomU)==0)
    	{
    		return b=0;
    	}
    	
    	fread(&Us,sizeof(Usuario),1,Vet);
    	
    }
    return b;
    fclose(Vet);
}

void ComprobarUsuario(char NomU[10], int &b,FILE *&Vet)
{
	    
	    int Long,r,cm=0;
	    
		Long = strlen(NomU);
		r = UsuarioRepetido(NomU,Vet);
		if(r==1)
		{
		    if(Long>=6 && Long<=10)
	        {
		        if(islower(NomU[0]) != 0)
		        {
		        	for(int i=0;i<Long;i++)
		        	{
		        		if(isupper(NomU[i]) != 0)
		        		{
		        			cm++;
		        		}
		        	}
		        	if(cm>=2)
		        	{
		        		cm=0;
		        		for(int i=0;i<Long;i++)
		        		{
		        			if(isdigit(NomU[i])!=0)
		        			{
		        				cm++;
		        			}
		        		}
		        		if(cm<=3)
		       			{
		       				b=1;
		       			}
		       			else
		       			{
		       				printf("\n ERROR.. No puede contener mas de 3 digitos.\n");
		       			}
		       		}
	        		else
	        		{
						 printf("\nERROR.. Debe tener como minimo 2 letras mayusculas.\n");
		        	}
		        		
		        }
		       	else
		        {
		        	printf("\nERROR.. La primera letra debe ser minuscula.\n");
		        }
	        }
	        else
	        {
		       	printf("\nERROR.. Debe ingresar un usuario de 6-10 caracteres.\n");
	        }
		}
		else
		{
		    printf("\nERROR.. El usuario ya existe.\n");
		}
}
	        
	
void ComprobarContra(char ConU[32],int &b)
{	
        char aux,aux1;
        int Long,May=0,Min=0,Num=0;
			
		Long = strlen(ConU);
		if(Long >= 6 && Long <= 32)
		{
			for(int i=0;i<Long;i++)
			{		
				if(isalnum(ConU[i])==0)
				{
					Num=1;
				}
			}
			if(Num==0)	
			{
				for(int i=0;i<Long;i++)
				{
					if(isupper(ConU[i])!=0)
					{
						May=1;
					}
					else if(islower(ConU[i])!=0)
					{
						Min=1;
					}
					else if(isdigit(ConU[i])!=0)
					{
						Num=1;
					}
				}
				if(Num==1 && May==1 && Min==1)
				{
					Num=0;
					May=0;
					for(int i=0;i<Long;i++)
					{
						if(isdigit(ConU[i])!=0)
						{
							Num++;
							if(Num==4)
							{
								May=1;
								i=Long;
							}
						}
						else if(isalpha(ConU[i])!=0)
						{
							Num=0;
						}
					}
					if(May==0)
					{
						Num=0;
						for(int i=0;i<Long;i++)
						{
							if(isalpha(ConU[i])!=0)
							{
								Num++;
								if(Num==2)
								{
									
									aux = toupper(ConU[i]);
									aux1 = toupper(ConU[i-1]);
									
									if(aux1 == aux-1)
									{
									   May=1;
									   i=Long;	
									}
									
								}
							}
							else
						    {
						    	Num=0;
						    }
					    }
					    if(May==0)
					    {
					    	b=1;
					    }
					    else
					    {
					    	printf("\nERROR.. No debe ingresar dos letras consecutivas y ascendentes.\n");
					    }
					}	
					else
					{
						printf("\nERROR.. No debe ingresar mas de 3 digitos seguidos.\n");
					}
				}
				else
				{
					printf("\nERROR.. Debe ingresar al menos una mayúscula, una minúscula y un número.\n");
				}
				
			}
			else
			{
				printf("\nERROR.. Debe ingresar caractéres alfanumericos.\n");
			}
		}
		else
		{
			printf("\nERROR.. Debe ingresar una contrasenia de 6-32 caractéres.\n");
		}
					
}


void RegistrarUs(FILE *Vet)
{
        Usuario DatU;
        int b=0;
	
	    printf("Ingrese apellido y nombre de asistente: ");
	    _flushall();
    	gets(DatU.Nombre);
	
	    //Registro de usuario  del asistente.
	    system("CLS");
	    Vet = fopen("Usuario.dat","a+b");
	    if(Vet==NULL)
	    {
	    	printf("Error al abrir el archivo\n");
	    }
	    else
	    {
		    printf("Registrar nombre de usuario:\n");
		    printf("1.- Debe ser unico.\n2.- Debe comenzar con una letra minuscula.\n3.- Debe tener como minimo dos letras mayusculas.\n");
		    printf("4.- Tener como maximo 3 digitos.\n5.- Debe tener entre 6-10 caracteres\n");
		    b=0;
		    while(b==0)
		    {
		        printf("\n- Ingrese el nombre de usuario: ");
		        _flushall();
	    	    gets(DatU.Usuar);
			    ComprobarUsuario(DatU.Usuar,b,Vet);
		    }
		  
	       //registro de contraseñia del asistente.
	  
	  	    printf("\nRegistrar contraseña:\n");
		    printf("1.- Debe contener como minimo: una letra mayuscula,una minuscula y un numero.\n");
		    printf("2.- Solo puede contener caracteres alfanumericos.\n");
		    printf("3.- Debe tener entre 6-32 caracteres.\n");
		    printf("4.- No debe tener mas de 3 caracteres numericos consecutivos.\n");
		    printf("5.- No debe tener 2 letras consecutivas ascendentes.\n");
		    b=0;
	  	    while(b==0)
	  	    {
	  		    printf("\n- Ingrese la contraseña: ");
			    _flushall();
			    gets(DatU.Contra);
			    ComprobarContra(DatU.Contra,b);
	  	    }
	  	    
	  	    fwrite(&DatU,sizeof(Usuario),1,Vet);
	  	    fclose(Vet);
		
	    }
}
void Atenciones(int mes)// Listar Atenciones por Veterinarios
{
    FILE *arch_turno;
//	printf("Ejecuto pa.");
	FILE *arch_admin;
	arch_admin=fopen("Usuarios.dat","rb");
	if(arch_admin==NULL)
	{
		printf("No hay usuarios registrados");
		exit(1);
	}
	else
	{
		arch_turno=fopen("Usuarios.dat","rb");
		if(arch_turno==NULL)
		{
			printf("No hay turnos registrados");
			exit(1);
		}
	}

	Turnos regtur;
	Usuario  regus;
	int c=0,c2=0;
	system("CLS");
	printf("LISTADO DE ATENCION DEL MES %d",mes);
	printf("\n===============================");

	rewind(arch_admin);
	rewind(arch_turno);
	fread(&regtur, sizeof(Turnos), 1,arch_turno);
	fread(&regus,sizeof(Usuario),1,arch_admin);

	while(!feof(arch_admin))
	{
		c=0;
		rewind(arch_turno);
		fread(&regus,sizeof(Turnos), 1,arch_turno);	
		while(!feof(arch_turno) && regtur.borrado==false)
        {
        	if(regtur.FecT.mes==mes && regtur.borrado!=0)
			{
			 	c++;
			}
			fread(&regus ,sizeof(Turnos), 1,arch_turno);
		}
		printf("%s: %d\n",regus.Nombre,c);
		fread(&regtur,sizeof(Usuario) , 1,arch_admin);
    } 
    fclose(arch_turno);
    fclose(arch_admin);
    printf("\n");
    system("PAUSE");

}
	
