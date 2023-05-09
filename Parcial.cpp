#include <stdio.h>
#include <stdlib.h>
#define tam 50
void Opcion1(int calzado,char tipo,float importe,int *pcalzado,char *ptipo,float *pimporte){
	int i = 0;
	while(*(pcalzado+i) != 0 && i < 5){
		i++;
	}
	*(pcalzado+i) = calzado;
	*(ptipo+i)    = tipo;
	*(pimporte+i) = importe;
}
void Opcion2(int *pcalzado, char *ptipo, float *pimporte){
	int i = 0; int conts = 0; float acums = 0; float acumb = 0; int contb = 0;
	for(i = 0;i < 5 ; i++){
		if(*(ptipo+i) == 'b'){
			contb++;
			acumb += *(pimporte+i);
		}else if(*(ptipo+i) == 's'){
			conts++;
			acums += *(pimporte+i);
		}
	}
	system("cls");
	printf("\t\t*****************************\n");
	printf("\t\t*******RESUMEN DEL DIA*******\n");
	printf("\t\t*****************************\n");
	printf("\n-BOTAS VENDIDAS: %i",contb);
	printf("\n-FACTURADO POR VENTAS DE BOTAS: %.2f",acumb);
	printf("\n---------------------------------------\n");
	printf("\n-SANDALIAS VENDIDAS: %i",conts);
	printf("\n-FACTURADO POR VENTAS DE SANDALIAS: %.2f",acums);
	printf("\n---------------------------------------\n");
	printf("-TOTAL FACTURADO EN EL DIA: %.2f\n\n",acumb+acums);
	system("pause");	
}

int main(){	
	int op; int i = 0; int j = 0;
	int calzado;
	char tipo;
	float importe;
	int v_calzado[tam] = {0};   int *p_calzado;
	char v_tipo[tam];           char *p_tipo;
	float v_importe[tam] = {0}; float *p_importe;
	
    for(i = 0; i < tam ; i++){
		v_calzado[i] = 0;
		v_importe[i] = 0;
		v_tipo[i] = '\0';	
	}
	
  do{
  	 printf("\t\t\t\t ---------------------------------\n");
  	 printf("\t\t\t\t - ||||||||||||||||||||||||||||| -\n");
  	 printf("\t\t\t\t - ||||||||||ZAPATERIA|||||||||| -\n");
  	 printf("\t\t\t\t - |||||||||||CRiSREY||||||||||| -\n");
  	 printf("\t\t\t\t - ||||||||||||||||||||||||||||| -\n");
  	 printf("\t\t\t\t ---------------------------------\n\n\n");
  	 printf("\t\t\t\t 1.Ingresar datos de ventas\n");
  	 printf("\t\t\t\t 2.Generar informe de ventas del dia\n");
  	 printf("\t\t\t\t 3.Salir\n\n\n");
  	 printf("\t\t\t\tDigite una opcion:");
  	 fflush(stdin);
  	 scanf("%i",&op);
  	 p_calzado = &v_calzado[0];
  	 p_tipo    = &v_tipo[0]; 
  	 p_importe = &v_importe[0];
  	 switch(op){
  	 	 case 1:
			if(j == 0 || j  < 5){
				system("cls");
				printf("\n-Ingrese numero de calzado(0 = FINALIZAR):");
				fflush(stdin);
				scanf("%i",&calzado);
				if(calzado != 0){
					printf("\n-Ingrese tipo de calzado('b'= bota | 's'= sandalia):");
					fflush(stdin);
					scanf("%c", &tipo);
					printf("\n-Ingrese importe a cobrar:");
					fflush(stdin);
					scanf("%f", &importe);
					j++;
					Opcion1(calzado,tipo,importe,p_calzado,p_tipo,p_importe);
				}
			}else{
				system("cls");
				printf("\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
				printf("\t\t\t||| SE HA ALCAZADO EL LIMITE DE VENTAS POR DIAS |||\n");
				printf("\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
				system("pause");
			}	
			break;
  	 	 case 2:
  	 	 	if(j != 0){
				Opcion2(p_calzado,p_tipo,p_importe);
			}else{
			    system("cls");
			    printf("\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
			    printf("\t\t\t||| NO SE HAN REGISTRADO VENTAS PARA GENERAR EL INFORME |||\n");
			    printf("\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
			    system("pause");	
			}
			break;
  	 	 	
  	 	 case 3: ;default:break;
	    }
 
  	
  	system("cls");
    }while(op != 3);
 system("pause");
 return 0;
 }
