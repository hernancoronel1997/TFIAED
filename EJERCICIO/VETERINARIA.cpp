#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void crearUsuario();
void loginUsuario();
void menuPrinciapl();
void registrarveterinario();

typedef char cadena[50];

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
struct Usuarios
{
	cadena usuario,contrasenea;
	char ApellidoyNombre[60];
};

struct Veterinario
{
	char ApellidoyNombre[60];
	int Matricula;
	int Dni;
	int Telefono;
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
//	system("color 48");
	int n;
	while(true)
	{
		system("cls");
		
        printf("\n\n\n\n\n\n\n\t\t\t\t1-registrarse.\n\t\t\t\t2-login.\n\t\t\t\t3-salir.\n\t\t\t\tElija una opcion: ");
        scanf("%d",&n);
        _flushall();
        
        switch(n)
        {
            case 1: 
			crearUsuario();
                break;
            case 2: 
			loginUsuario();
                break;
            case 3: 
			exit(1);
                break;
            default: printf("\nLa Opcion Ingresada no es correcta.\n\n");
			 _flushall();
			  system("pause");
                break;
        }
	}
}

void crearUsuario()
{
	FILE *arch;
	Usuarios nuevo;
	Usuarios nuevoArch;
	cadena contra;
	int cantmayusculas, cantminusculas, cantdigitos,comprobante, longitud=0;
	arch = fopen("Usuarios.dat","a+b");
	
	regreso:
	
	while(true)
	{
		cantmayusculas=0;
		cantminusculas=0;
		cantdigitos=0;
		comprobante=0;
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\tIngrese un Nombre de usuario que cumpla las siguientes pautas:\n\n");
        printf("\t\t\t\t*Comenzar con minuscula.\n\t\t\t\t*Tener al menos 2 letras mayusculas.\n\t\t\t\t*Tener Como Maximo 3 Digitos. \n\n\n\t\t\t\t*El usuario debe tener entre 6 y 10 caracteres\n\n");
        printf("\t\t\t\tUsuario: ");
        _flushall();
        gets(nuevo.usuario);
        
        longitud = strlen(nuevo.usuario);
        
        if(longitud<6 && longitud>10)
        {
            comprobante--;
        }
        
        if(nuevo.usuario[0]>='a' && nuevo.usuario[0]<='z')
        {
            comprobante++;
        }
        
        for(int i=1;i<longitud;i++)
        {
           
            if(nuevo.usuario[i]>='A' && nuevo.usuario[i]<='Z')
            {
                cantmayusculas++;
            }

            
            if(nuevo.usuario[i]>='0' && nuevo.usuario[i]<='9')
            {
                cantdigitos++;
            }
            
            if(nuevo.usuario[i]=='+' || nuevo.usuario[i]=='-' || nuevo.usuario[i]=='!' || nuevo.usuario[i]=='¡' || nuevo.usuario[i]=='*' || nuevo.usuario[i]=='?' || nuevo.usuario[i]=='¿' || nuevo.usuario[i]=='/')
            {
            	cantdigitos++;
            }
            
        }
        
        if(cantmayusculas>=2 && cantdigitos<=3)
        {
            comprobante++;
        }
        
        rewind(arch);
        fread(&nuevoArch,sizeof(Usuarios),1,arch);
        
        while(!feof(arch))
        {

            if(strcmp(nuevoArch.usuario,nuevo.usuario)==0)
            {
               printf("\t\t\t\tEL usuario ya existe, ingrese otro.\n\t\t\t\t");
               system("pause");

               goto regreso;
            }

            fread(&nuevoArch,sizeof(Usuarios),1,arch);
        
        }
        
        if(comprobante==2)
        {
            break;
        }
        else printf("\t\t\t\tSu usuario no cumple con alguna de las condiciones, intentelo nuevamente\n\n");

        system("pause");
        
	}
	regresopass:
	while(true)
    {

        cantmayusculas=0;
        cantminusculas=0;
        cantdigitos=0;
        comprobante=0;

        system("cls");
        printf("\n\n\n\n\n\n\n\tIngrese una Contrase%ca que cumpla las siguientes pautas:\n\n",164);
        printf("\t*Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n");
        printf("\t*No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n");
        printf("\t*Debera tener entre 6 y 32 caracteres\n");
        printf("\t*No debe tener mas de 3 caracteres numericos consecutivos.\n");
        printf("\t*No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente).\n\n");
        printf("\tContrase%ca: ",164);
        gets(nuevo.contrasenea);

        longitud = strlen(nuevo.contrasenea);

        for(int i=0;i<longitud;i++)
        {
            if(nuevo.contrasenea[i]>=65 && nuevo.contrasenea[i]<=90 || nuevo.contrasenea[i]>=97 && nuevo.contrasenea[i]<=122 || nuevo.contrasenea[i]>=48 && nuevo.contrasenea[i]<=57)
            {

                if(nuevo.contrasenea[i]>=65 && nuevo.contrasenea[i]<=90)
                {
                    cantmayusculas++;

                     if(nuevo.contrasenea[i]==nuevo.contrasenea[i+1]-1)
                    {
                        printf("\n\n\n\n\n\n\n\t\t\t\tla contraseña no cumple con las pautas, vuelva a intentarlo\n\n");
                        system("pause");
                        goto regresopass;
                    }


                }
                else if(nuevo.contrasenea[i]>=97 && nuevo.contrasenea[i]<=122)
                {
                    cantminusculas++;

                    if(nuevo.contrasenea[i]==nuevo.contrasenea[i+1]-1)
                    {
                        printf("\n\n\n\n\n\n\n\t\t\t\tla contraseña no cumple con las pautas, vuelva a intentarlo\n\n");
                        system("pause");
                        goto regresopass;
                    }
                }
                else
                {
                    cantdigitos++;


                    if(nuevo.contrasenea[i]==nuevo.contrasenea[i+1]-1 && nuevo.contrasenea[i+1]== nuevo.contrasenea[i+2]-1)
                    {
                        printf("\n\n\n\n\n\n\n\t\t\t\tla contraseña no cumple con las pautas, vuelva a intentarlo\n\n");
                        system("pause");
                        goto regresopass;
                    }
                }
            }
            else
            {
                printf("\n\n\n\n\n\n\n\t\t\t\tLa contraseña ingresada es incorrecta, ingresela nuevamente \n\n");
                system("pause");

                goto regresopass;
            }


        }

        if(cantmayusculas>=1 && cantminusculas>=1 && cantdigitos>=1)
        {
            comprobante++;
        }

        if(longitud>=6 && longitud<=32)
        {
            comprobante++;
        }

        regresopass2:
        if(comprobante==2)
        {
            printf("\n\tIngrese Nuevamente la contrase%ca: ");
            gets(contra);

            if(strcmp(contra,nuevo.contrasenea)!=0)
            {
                printf("\tLas Contraseñas no coincide, vuelva a intentarlo.\n\n");

                goto regresopass2;
            }

            else
            {
                printf("\n\tLa contrase%ca se ingreso correctamente\n\n\t",164);
                system("pause");
                break;
            }
        }

    }

    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\tEl usuario se registro exitosamente!!!\n\n\t");
    fwrite(&nuevo,sizeof(Usuarios),1,arch);
    fclose(arch);
    system("pause");
}

void loginUsuario()
{
	FILE *puntero;
    Usuarios nuevo;
	Usuarios nuevoArch;
    int intento,bandera=2;
    puntero = fopen("Usuarios.dat","r+b");
    if(puntero==NULL)
    {
        printf("\n\t\t\t\tAUN NO SE REGISTRARON USUARIOS\n\n\t\t\t\t");
        system("pause");
        system("cls");
        return;
    }
    
    regresarusuario:
    while(true)
    {
        intento=0;
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\tIngrese su usuario: ");
        gets(nuevo.usuario);

        rewind(puntero);

        fread(&nuevoArch,sizeof(Usuarios),1,puntero);

        while(!feof(puntero))

        {
            if(strcmp(nuevo.usuario,nuevoArch.usuario)==0)
            {
                printf("\t\t\t\tUsuario ingresado correctamente.\n\n\t\t\t\t");
                system("pause");
                bandera=1;
                break;
            }
            else
            {
                bandera=0;
            }
            fread(&nuevoArch,sizeof(Usuarios),1,puntero);

        }
        if(bandera==0)
        {
            printf("\t\t\t\tEl Usuario Ingresado no existe, intentelo nuevamente.\n\n\t\t\t\t");
            system("pause");
            goto regresarusuario;
        }
        if(bandera==2)
        {
            printf("\t\t\t\tNo existe ningun usuario registrado\n\n\t\t\t\t");
            system("pause");
            break;
        }


        regresarpass:
        system("cls");

        printf("\n\n\n\t\t\t\tTiene %i intentos\n\n",3-intento);
        intento++;

        if(intento > 3)
        {
            printf("\t\t\t\tSe le acabaron los intentos.\n\n\t\t\t\t");
            system("pause");
            exit(1);
        }

        printf("\t\t\t\tIngrese la contrase%ca: ",164);
        gets(nuevo.contrasenea);


        if(strcmp(nuevo.contrasenea,nuevoArch.contrasenea)==0)
        {
            printf("\t\t\t\tContrase%ca Correcta.\n\n\t\t\t\t",164);
            system("pause");
            menuPrinciapl();
            //AQUI IRIA EL MENU PARA LOS MODULOS
            fseek(puntero, (-1)*sizeof(Usuarios),SEEK_CUR);
		    fwrite(&nuevoArch,sizeof(Usuarios),1,puntero);
		    
		    system("pause");
            break;
        }
        else
        {
            printf("\t\t\t\tLa contrase%ca ingresada no es correcta. Intente nuevamente\n\n\t\t\t\t",164);
            system("pause");

            goto regresarpass;
        }


    }
}

void menuPrinciapl()
{
	int opcion;

	
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
					system("cls"); //CLS significa clear screan(limpiar pantalla)
					registrarveterinario();
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
				
			}while(opcion3!=5);
					
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
	} while (vet.Matricula <= 0 && vet.Matricula >= 999999);

	do
	{
		printf("DNI: ");
		scanf("%08d", &vet.Dni);
	} while (vet.Dni <= 10000000 && vet.Dni >= 99999999);

	_flushall();

		printf("Télefono: ");
		scanf("%10d", &vet.Telefono);
	
	_flushall();
//	fwrite()
	//fprintf(fp, "%s;%06d;%08d;%s;\n",vet.ApellidoyNombre,vet.Matricula,vet.Dni,vet.Telefono);
	//printf("\nCREACION DE USUARIO PARA EL VETERINARIO");
	
	//stdcpy(vet.ApellidoyNombre,
	//crearUsuario()
	
	fclose(fp);
	//system("CLS");
}
