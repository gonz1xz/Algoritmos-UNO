#include <stdio.h>
#include <stdlib.h>
#define tam 50

int menu(){
	int op;
	printf("\t\t==================\n");
	printf("\t\t===SUPERMERCADO===\n");
	printf("\t\t==================\n");
	printf("\t\n1.Ingresar datos de venta");
	printf("\t\n2.Generar informe del dia");
	printf("\t\n3.Salir\n");
	printf("\t\nDigite opcion:");
	fflush(stdin);
	scanf("%i", &op);
	return op;
}

void carga(int num, char tip, float imp,int *p_num,char *p_tip, float *p_imp){
	int i = 0;
	while(*p_num != 0 && i < tam){
		i++;
	}
	
	*(p_num+i) = num;
	*(p_tip+i) = tip;
	*(p_imp+i) = imp;
}

void informe(int *p_n, char *p_t,float *p_i){
	int cm5 = 0;
	float acum = 0;
	float acumefe = 0;
	int i;
	for(i = 0; i < tam ; i++){
		if( *(p_t+i) == 't' && *(p_i+i) >= 5000){
			cm5++;
		}
		if(*(p_t+i)== 'e'){
			acumefe += (*p_i+i);
	    }
	acum += (*p_i+i);
	}
	printf("\nCantidad de clientes con compras mayor a $5000 y pagaron con tarjeta:%i" , cm5);
	printf("\nTotal facturado en el dia:%f", acum);
	printf("\nTotal facturado en efectivo:%f", acumefe);
}

int main(){
	int vmenu; int load=0;
	int numc;
	char tipop;
	float importe;
	vmenu=menu();
	int compras=0;
	
	int v_numc[tam]; int *p_numc;
	char v_tipop[tam]; char *p_tipop;
	float v_importe[tam]; float *p_importe;
	
	while(vmenu !=3 && compras < tam){
		switch(vmenu){
			case 1:
				load=1;
				system("cls");
				printf("\nOpcion 1: Ingreso de datos de cliente\n\n");
				printf("\nIngrese numero de cliente:");
				fflush(stdin);
				scanf("%i", &numc);
				printf("\nIngrese tipo de pago:");
				fflush(stdin);
				scanf("%c", &tipop);
				printf("\nIngrese importe de la compra:");
				fflush(stdin);
				scanf("%f", &importe);
				p_numc = &v_numc[0];
				p_tipop= &v_tipop[0];
				p_importe = &v_importe[0];
				
				carga(numc, tipop, importe, p_numc, p_tipop, p_importe);
			break;
			case 2:
				if( load == 1){
					informe(p_numc,p_tipop,p_importe);
					system("pause");
					
				}else{
					system("cls");
					printf("\n***Aun no se registraron ventas***\n");
					system("pause");
				}
			break;
			default: break;
		}
		system("cls");
		vmenu=menu();
		compras++;
	}
	
	
	system("pause");
	return 0;
}
