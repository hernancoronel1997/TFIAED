#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LibreriasTFI.h"
#include <locale.h>

void RegistrarMas(FILE *Us);
void RegistarTur(FILE *Us);
void ListAt(FILE*Us);

main()
{
	setlocale(LC_ALL,"spanish");
	FILE *Us;
	int menu=0,b=0,Is,Vi=0;
	
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
	printf("                      .- Modulo Asistentes -.");
	printf("\n =================================================================");
		
		printf("\n\n1.- Iniciar sesión");
		printf("\n2.- Registrar mascota");
		printf("\n3.- Registrar turno");
		printf("\n4.- Listado de atenciones por veterinario y fecha");
		printf("\n5.- Cerrar Menú");
		printf("\n  ------------------------------------------------------------");
		printf("\n\n- Ingrese una opcion: ");
		scanf("%d",&menu);
		system("CLS");
		
		switch(menu)
		{
			case 1:  Is = IniciarSesion(Us,b);
			         if(Is == 1)
			         {
			            printf("\n ... Sesión iniciada ...\n");
			         }
			 break;
			
			 case 2:  if(Is==1)
			          {
			          	RegistrarMas(Us);
			          }
			          else
			          {
			          	printf("ERROR.. Debe iniciar sesión\n");
			          }
			 break;
			 		
			 case 3:  if(Is==1)
			          {
			          	RegistarTur(Us);
			          }
			          else
			          {
			          	printf("ERROR.. Debe iniciar sesión\n");
			          }    
		    break;
			case 4:  if(Is==1)
			         {
			         	ListAt(Us);
			         }
			         else
			         {
			         	printf("\nERROR.. Debe iniciar sesion\n");
			         }
			break;   
			        
		}
		if(menu!=5)
		{
			printf("\n\n\n");
			system("pause");
		}		
		system("CLS");
	}	
}



void RegistrarMas(FILE *Us)
{
	Mascotas DatM,Aux;
	int DNIRep,band=0;
	char NomRep[60];
	
	Us = fopen("Mascotas.dat","a+b");
	if(Us == NULL)
	{
		printf("ERROR.. No se pudo abrir archivo\n");
	}
	else
	{	
		printf("Ingrese los siguientes datos de la mascota:\n\n");
		
		printf("\n - Nombre y apellido de la mascota: ");
		_flushall();
		gets(NomRep);
		strupr(NomRep);
		
		printf("\n - DNI del dueño: ");
		scanf("%d",&DNIRep);
		
		rewind(Us);
		fread(&Aux,sizeof(Mascotas),1,Us);
		while(!feof(Us))
		{
			strupr(Aux.Nombre);
			
			if(Aux.DNID==DNIRep)
			{
			   	if(strcmp(Aux.Nombre,NomRep)==0)
			   	{
			   		printf("La mascota ya esta registrada.\n1.- Actualizar datos.\n2.- No Actualizar.\n\n- Ingrese una opcion: ");
			   		scanf("%d",&band);
			   		if(band==1)
			   		{
			   				printf("\n- Domicilio: ");
							_flushall();
							gets(DatM.Dom);
		
							printf("\n- Localidad: ");
							_flushall();
							gets(DatM.Loc);
			   			
			   				printf("\n- Peso de la mascota: ");
							scanf("%f",&DatM.Peso);
		
							printf("\n- Telefono: ");
							_flushall();
							gets(DatM.Tel);
							
							fseek(Us,-sizeof(Mascotas),1);
							fwrite(&DatM,sizeof(Mascotas),1,Us);
							
							printf("\n¡Datos actualizados con exito!\n");
							fseek(Us,0,2);
			   		}
			   		
			   	}
			   	
			}
			
		    fread(&Aux,sizeof(Mascotas),1,Us);	
		}
		
		if(band==0)
		{
			strcpy(DatM.Nombre,NomRep);
			DatM.DNID=DNIRep;
			
			printf("\n- Domicilio: ");
			_flushall();
			gets(DatM.Dom);
		
			printf("\n- Localidad: ");
			_flushall();
			gets(DatM.Loc);
			
			printf("\n- Fecha de nacimiento (DIA): ");
			scanf("%d",&DatM.fecNac.dia);
			printf("\n- Fecha de nacimiento (MES): ");
			scanf("%d",&DatM.fecNac.mes);
			printf("\n- Fecha de nacimiento (AÑO): ");
			scanf("%d",&DatM.fecNac.anio);
			
			printf("\n- Peso de la mascota: ");
			scanf("%f",&DatM.Peso);
		
			printf("\n- Telefono: ");
			_flushall();
			gets(DatM.Tel);
		
			fwrite(&DatM,sizeof(Mascotas),1,Us);
		}	
	}
	fclose(Us);
}



void RegistarTur(FILE *Us)
{
	Turnos DatP,AuxP;
	DatosVet Matri;
	Mascotas AuxM;
	FILE *Masc, *Tur;
	int band=0;
	
	printf("- Ingrese el numero de matricula de el veterinario: ");
	scanf("%d",&DatP.MatV);
	
	Us = fopen("Veterinario.dat","rb");
	if(Us==NULL)
	{
		printf("\nERROR.. No se registro ningun veterinario\n");
	}
	else
	{
       
		fread(&Matri,sizeof(DatosVet),1,Us);
		while(!feof(Us))
		{
			
			if(Matri.Mat == DatP.MatV)
			{
				printf("- Ingrese el DNI del dueño: ");
				scanf("%d",&DatP.DNIT);	
				
				Masc = fopen("Mascotas.dat","rb");
				if(Masc==NULL)
				{
					printf("\nERROR.. No se registro ninguna mascota\n");
				}
				else
				{
					    printf("- Ingrese el nombre de la mascota: ");
					    _flushall();
					    gets(DatP.NomMas);
					    strupr(DatP.NomMas);
					    
						fread(&AuxM,sizeof(Mascotas),1,Masc);
						while(!feof(Masc))
						{
							if(AuxM.DNID == DatP.DNIT && strcmp(AuxM.Nombre,DatP.NomMas)==0)
							{
								Tur = fopen("Turnos.dat","a+b");
								if(Tur==NULL)
								{
									band=1;
								}
								else
								{
									rewind(Tur);
									fread(&AuxP,sizeof(Turnos),1,Tur);
									while(!feof(Tur))
									{
										if(strcmp(AuxP.NomMas,DatP.NomMas)==0 && AuxP.DNIT == DatP.DNIT)
										{
											printf("\n- Ingrese la fecha de turno(DIA): ");
											scanf("%d",&DatP.FecT.dia);
											printf("\n- Ingrese la fecha de turno(MES): ");
											scanf("%d",&DatP.FecT.mes);
											printf("\n- Ingrese la fecha de turno(AÑO): ");
											scanf("%d",&DatP.FecT.anio);
											
											strcpy(DatP.evoMasc,AuxP.evoMasc);
											DatP.borrado=false;
											fseek(Tur,-sizeof(Turnos),1);
											fwrite(&DatP,sizeof(Turnos),1,Tur);
											
											printf(".. Turno registrado ..");
							                band=3;
											fseek(Tur,0,2);
											fseek(Masc,0,2);
											fseek(Us,0,2);
										}
										else
										{
											band=1;
										}
										
										fread(&AuxP,sizeof(Turnos),1,Tur);
									}
									fclose(Tur);
									if(band==0)
									{
										band=1;
									}
					
								}
								
							}
							else
							{
								band=2;
							}
							fread(&AuxM,sizeof(Mascotas),1,Masc);
						}
						fclose(Masc);
						
				}
                
			}
			
			fread(&Matri,sizeof(DatosVet),1,Us);
		}
		
		fclose(Us);
	}
	
	if(band==1)
	{
	    Tur = fopen("Turnos.dat","ab");
		//printf("Ingrese la fecha de turno(DD/MM/AAAA): ");
		//scanf("%d/%d/%d",&DatP.FecT.dia,&DatP.FecT.mes,&DatP.FecT.anio);
		printf("\n- Fecha de nacimiento (DIA): ");
		scanf("%d",&DatP.FecT.dia);
		printf("\n- Fecha de nacimiento (MES): ");
		scanf("%d",&DatP.FecT.mes);
		printf("\n- Fecha de nacimiento (AÑO): ");
		scanf("%d",&DatP.FecT.anio);
		
		fwrite(&DatP,sizeof(Turnos),1,Tur);
		printf("\n.. Turno registrado ..");
		fclose(Tur);
	}
	else if(band==2)
	{
		printf("\nERROR.. Mascota no registrada\n");
	}
	else if (band==0)
	{
		printf("\nERROR.. Matricula incorrecta\n");
	}
}


void ListAt(FILE*Us)
{
	FILE *Aux;
    Fecha fecAux;
    int matricula;
    DatosVet AuxV;
    Mascotas AuxM;
    int band=0;
    Turnos AuxT;
    
	printf("- Ingrese la matricula del veterinario: ");
	scanf("%d",&matricula);
	
	Us= fopen("Veterinario.dat","rb");
	if(Us==NULL)
	{
		printf("\nERROR.. No se registro ningun veterinario\n");
	} 
	else
	{
		fread(&AuxT,sizeof(Turnos),1,Us);
		//rewind(Us);
		while(!feof(Us))
		{
			if(matricula==AuxT.MatV)
			
			{
				printf("\n- Ingrese la fecha de turno(DIA): ");
				scanf("%d",&fecAux.dia);
				printf("\n- Ingrese la fecha de turno(MES): ");
				scanf("%d",&fecAux.mes);
				printf("\n- Ingrese la fecha de turno(AÑO): ");
				scanf("%d",&fecAux.anio);
				//printf("Ingrese la fecha a buscar(DD/MM/AAAA): ");
				//scanf("%d/%d/%d",&fecAux.dia,&fecAux.mes,&fecAux.anio);
	
				if(fecAux.dia > 0 && fecAux.dia < 32)
				{
					if(fecAux.mes > 0 && fecAux.mes < 13)
					{
						if(fecAux.anio > 2019 && fecAux.anio < 2300)
						{
							band==1;
						}
						else
						{
							printf("\nERROR.. Año incorrecto\n");
						}
        			}
        			else
        			{
        				printf("\nERROR.. Mes incorrecto\n");
        			}
				}
				else
				{
					printf("\nERROR.. Dia incorrecto\n");
				}
			}
			fread(&AuxT,sizeof(Turnos),1,Us);
		}
		fclose(Us);
	}
	
	if(band==1)
	{
		Us=fopen("Turnos.dat","rb");
		
		if(Us==NULL)
		{
			printf("\nERROR.. No se registraron turnos\n");
		}
		else
		{
			fread(&AuxV,sizeof(DatosVet),1,Us);
		
			while(!feof(Us))
			{
				if(AuxV.Mat == matricula)
				{
					if(fecAux.dia == AuxT.FecT.dia)
					{
						if(fecAux.mes == AuxT.FecT.mes)
						{
							if(fecAux.dia == AuxT.FecT.dia)
							{
								Aux = fopen("Mascotas.dat","rb");
								fread(&AuxM,sizeof(Mascotas),1,Aux);
								while(!feof(Aux))
								{
									
									printf("Datos de la mascota: \n");
									printf("-----------------------------------");
									printf("\n- Nombre: %d\n",AuxM.Nombre);
									printf("\n- Domicilio: %s\n",AuxM.Dom);
									printf("\n- Localidad: %s\n",AuxM.Loc);
									printf("\n- Telefono: %s\n",AuxM.Tel);
									printf("\n- DNI del dueño: %d\n",AuxM.DNID);
									printf("\n- Fecha de nacimiento: %d/%d/%d\n",AuxM.fecNac.dia,AuxM.fecNac.mes,AuxM.fecNac.anio);
									printf("\n- Peso: %d\n",AuxM.Peso);
									printf("-----------------------------------");
									fread(&AuxM,sizeof(Mascotas),1,Aux);
									
								}	
							}
						}
					}
				}
				fread(&AuxV,sizeof(DatosVet),1,Us);
			}
		}
	}
}

