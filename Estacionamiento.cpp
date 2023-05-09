#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define tam 50
int menu(void){
	int op;
	printf("\t\t\t\t|||||||||||||||||||||||||||||||||||||\n");
	printf("\t\t\t\t|||||||||||ESTACIONAMIENTO|||||||||||\n");
	printf("\t\t\t\t|||||||||||||||||||||||||||||||||||||\n");
	printf("\t\t\t\t|||||||||||EL CRIS REEEEEY|||||||||||\n");
	printf("\t\t\t\t|||||||||||||||||||||||||||||||||||||\n\n\n");
	printf("\t\t\t\tSELECCION DE OPCIONES:\n\n");
	printf("\t\t\t\t1. Salida de auto y costo del estacionamiento\n");
	printf("\t\t\t\t2. Generar resumen del dia\n");
	printf("\t\t\t\t3. Salir");
	printf("\n\n\n\t\t\t\tDigite una opcion:");
	fflush(stdin);
	scanf("%i",&op);

return op;
}



void Opcion1(char tipo,float pago, char *ptipo, float *ppago ){
	int i = 0;
	while(*(ppago+i)!=0 && i<tam){
		i++;
	}

	*(ptipo+i) = tipo;
	*(ppago+i) = pago;
       
    
	
}


void Opcion2(char *ptipo, float *ppago){
	
}

int main(){
	int op = 0; int i;
	float horas;
	char patente[10];
	char tipo;
	float pago;
	float v_pago[tam]; float *p_pago;
	char v_tipo[tam]; char *p_tipo;
	int carga;
	
	
	for(i = 0;i < tam;i++){
		v_pago[i] = 0;
		v_tipo[i] = 0;
	}
	p_pago = &v_pago[0];
	p_tipo = &v_tipo[0];
	
	
	do{
		op = menu();
		system("cls");
		switch(op){
			case 1:
				printf("\t\t\n-Ingresar patente del vehiculo:");
				fflush(stdin);
				gets(patente);
				printf("\t\t\n-Ingresar tipo de vehiculo:");
				fflush(stdin);
				scanf("%c",&tipo);
				printf("\t\t\n-Tiempo de permanencia dentro del estacionamiento(HORAS):");
				fflush(stdin);
				scanf("%f",&horas);
				switch(tipo){
					case 'a': pago = horas * 100;break;
					case 'm': pago = horas * 50;break;
					case 'c': pago = horas * 200;break;
					default:break;
			    }
			    printf("\t\t\n|EL PAGO A COBRAR ES $%.2f|\n\n\n",pago);
			    Opcion1(tipo,pago,p_tipo,p_pago);
			    carga = 1;
				system("pause");
				system("cls");	
			    break;
			    
			case 2:
				if(carga==1){
					Opcion2(p_tipo,p_pago);
					
					
					
				}else{
					printf("|NO HAS REGISTRADO SALIDAS DE AUTOS EN EL ESTACIONAMIENTO|\n\n");
					system("pause");
					system("cls");
				}
			    break;    
		}
		
	}while(op != 3);
	
	
	
	system("pause");
	return 0;
}
