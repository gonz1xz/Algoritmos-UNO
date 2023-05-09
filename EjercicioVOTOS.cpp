#include <stdio.h>
#include <stdlib.h>
int main(){
    int select;
	do{
		printf("\n\t\t===========================\n");
		printf("\n\t\t======Elecciones 2020======\n");
		printf("\n\t\t===========================\n");
		printf("\n\t[1] Votar\n");
		printf("\n\t[2] Ver resultados\n");
		printf("\n\t[3] Salir\n");
		printf("\n\n\tDigite la opcion donde desea ingresar :");
		fflush(stdin);
		scanf("%i", &select);
    }while(select!=3);






system("pause");
return 0;
}
