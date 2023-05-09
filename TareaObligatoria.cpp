#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dim 50
void Opcion1(int cod,float monto,int ddp,int *p_cod,float *p_monto, int *p_ddp){
	int i = 0;
	while(*(p_cod+i)!=0 && i<dim){
		i++;
	}

	*(p_cod+i) = cod;
	*(p_monto+i) = monto;
	*(p_ddp+i) = ddp;

}
void Opcion3(int *p_cod,float *p_monto, int *p_ddp, float *p_cpresu){
	int i = 0; int cod; int cont10=0; float montotal;
	printf("\t\t******************************************\n");
	printf("\t\t********EVALUACION DE COBRADORES**********\n");
	printf("\t\t******************************************\n");
	printf("\n\t\tCobrador [1]\n\t\tCobrador [2]\n\t\tCobrador [3]\n\t\tCobrador [4]\n\t\tCobrador [5]");
	printf("\n\t\tDigite el codigo del cobrador a evaluar : ");
	fflush(stdin);
	scanf("%i",&cod);
	for(i = 0; i < dim ; i++){
		if(cod == *(p_cod+i)){
			montotal += *(p_monto+i);
		}
		if(*(p_ddp+i) > 10){
			cont10++;
		}
	}
	system("cls");
	printf("\n\n-Cantidad de cobranzas que superaron los 10 dias de plazo del cobrador [%i]:%i\n\n", cod , cont10 );
	printf("\n\n-Monto total de todas las cobranzas del cobrador [%i]:%.2f\n\n", cod , montotal );
	if(montotal >= *(p_cpresu+cod)){
		printf("\n\n\t\t\t===================\n\t\t\t=BUENA PERFORMANCE=\n\t\t\t===================\n\n");
		if(montotal == *(p_cpresu+cod)){
			system("color B0");
			system("color F0");
			system("color C0");
			system("color E0");
			system("color D0");
			system("color F0");
			system("color B0");
			system("color F0");
			system("color C0");
			system("color E0");
			system("color D0");
			system("color F0");
			printf("\t===============================================================\n");
			printf("\t=====================RECIBE PREMIO DE $10.000==================\n");
			printf("\t===============================================================\n");
		}else{}
		if(montotal > *(p_cpresu+cod)){
			system("color B0");
			system("color F0");
			system("color C0");
			system("color E0");
			system("color D0");
			system("color F0");
			system("color B0");
			system("color F0");
			system("color C0");
			system("color E0");
			system("color D0");
			system("color F0");
			printf("\t================================================================\n");
		    printf("\t====================RECIBE PREMIO DE $20.000====================\n");	
		    printf("\t================================================================\n");
		}
	}else{
		system("color C7");
		printf("\n\n=====================\n===BAJA PERFOMANCE===\n=====================\n\n");
		printf("\n\nFALTO $%.2f PARA CUMPLIR CON EL PRESUPUESTO DADO POR LA EMPRESA\n\n",*(p_cpresu+cod)-montotal);
	}
	system("pause");
	
	
	

}







int main(){
	int op;
	int codcob;
	char tdc;
	float monto;
	int dplazo = 0;
	int i = 0;
	int carga=0;
	int v_codcob[dim]={0}; int *p_cod;
	int v_ddp[dim]={0}; int *p_ddp;
	float v_monto[dim]={0}; float *p_monto;
	float v_cpresu[dim]={0}; float *p_cpresu;
	
	do{
		system("color F4");
		printf("\t\t=========================================================================\n");	
	    printf("\t\t===========================SECTOR DE FINANZAS============================\n");
	    printf("\t\t=========================================================================\n");
		printf("\t\t==== 1. Ingreso de datos de cobranzas a clientes                     ====\n");
		printf("\t\t====                                                                 ====\n");
		printf("\t\t==== 2. Carga de cobranzas presupuestadas por cobrador en finanzas   ====\n");
		printf("\t\t====                                                                 ====\n");
		printf("\t\t==== 3. Evaluacion de cobranzas en Recursos Humanos                  ====\n");
		printf("\t\t====                                                                 ====\n");
		printf("\t\t==== 4. Salir                                                        ====\n");
		printf("\t\t=========================================================================\n");
		printf("\t\t=========================================================================\n");
		printf("\t\t=========================================================================\n\n\n");
		printf("\t\t-Ingrese el numero donde desea ingresar: ");
		fflush(stdin);
		scanf("%i", &op);
		p_cod = &v_codcob[0];
		p_monto = &v_monto[0];
		p_ddp = &v_ddp[0];
		p_cpresu = &v_cpresu[0];
		
		
		switch(op){
			
			case 1 : //INGRESO DE OPERACIONES REALIZADAS POR LOS COBRADORES
				system("cls");
				printf("\n-Ingrese codigo del cobrador: ");
				fflush(stdin);
				scanf("%i",&codcob);
				printf("\n-Ingrese tipo de cobranza('e'= Efectivo - 't'= Tarjeta - 'c'= Cheque): ");
				fflush(stdin);
				scanf("%c",&tdc);
				switch(tdc){
					case'e':
						printf("\n-Ingrese monto a cobrar: ");
						fflush(stdin);
						scanf("%f",&monto);
					    dplazo = 0;
					    Opcion1(codcob,monto,dplazo,p_cod,p_monto,p_ddp);
					break;
					
					case't':
						printf("\n-Ingrese monto a cobrar: ");
						fflush(stdin);
						scanf("%f",&monto);
					    dplazo = 15;
					    Opcion1(codcob,monto,dplazo,p_cod,p_monto,p_ddp);
					break;
					
					case'c':
						printf("\n-Ingrese monto a cobrar: ");
						fflush(stdin);
						scanf("%f",&monto);
					    printf("\n-Ingrese dias de plazo: ");
					    fflush(stdin);
					    scanf("%i",&dplazo); 
					    Opcion1(codcob,monto,dplazo,p_cod,p_monto,p_ddp);
					default : break;
				}
			break;
				
				
			case 2 : //CARGA DE PRESUPUESTOS ESPERADOS DE PARTE DE LA EMPRESA SOBRE LOS COBRADORES
			    system("cls");
			    carga = 1;
			    for(i = 0 ; i < 5 ; i++){
			    	printf("\n-Ingrese cobranza presupuestada para el cobrador numero #%i:", i+1);
			    	fflush(stdin);
			    	scanf("%f", &v_cpresu[i]);
				}; 
			break;
				
				
			case 3 :        //EVALUACION DE LOS COBRADORES Y PREMIOS
			    system("cls");
			    if(carga == 1){
			    	Opcion3(p_cod,p_monto,p_ddp,p_cpresu);
		    	}else{
					printf("\n\n\n\t\t***ANTES DEBE INGRESAR LAS COBRAZANSAS PRESUPUESTADAS***\n\n\n\n");
					system("pause");
				}
			break;
			    
			       
			case 4 : default : system("cls");break;
		}
		
	    system("cls");
	}while(op != 4 );

	
	system("pause");
	return 0;
}
