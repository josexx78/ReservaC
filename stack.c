#include<stdlib.h>
#include<stdio.h>
typedef struct stack{
	int num;
	struct stack*sig;
}stack;
stack*push(stack*a,int x)
{
	stack*b;
	b=(stack*) malloc(sizeof(stack));
	b->num=x;
	b->sig=a;
	return b;
}
stack*pop(stack*a)
{	
	stack*b;
	b=a->sig;
	free(a);
	return b;
}
void mostrar(stack*a)
{
	stack*b;
	b=a;
	printf("Los elementos de la ṕila son:\n");
	while(b)
	{
		printf("Dato : %d\n",b->num);
		b=b->sig;
	}
	free(b);
}
int main(void)
{
	stack*a=NULL;
	int x,n;
	printf("Ingrese la cantidad de numeros de la pila:\n");
	scanf("%d",&n);
	do{
		printf("Ingrese un numero entero:\n");
		scanf("%d",&x);
		a=push(a,x);
		n--;
	}while(n);
	mostrar(a);
	printf("Aplicar pop:\n");
	a=pop(a);
	mostrar(a);
	return 0;
}
