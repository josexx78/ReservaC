#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	int dato;
	struct nodo*sgt;
}nodo;

typedef struct queue{
	struct nodo*head;
	struct nodo*tail;
}queue;


queue*enqueue(queue*a,int n)
{
	nodo*b=(nodo*) malloc(sizeof(nodo));
	b->dato=n;
	if(!a)
	{
		a=(queue*) malloc(sizeof(queue));
		a->head=b;
		
	}
	else if(!a->tail)
	{
		a->head->sgt=b;
		a->tail=b;
	}
	else
	{
		a->tail->sgt=b;
		a->tail=a->tail->sgt;
	}
	return a;
}
queue*dequeue(queue*a)
{
	nodo*b=a->head;
	a->head=a->head->sgt;
	free(b);
	return a;
}
void mostrar(nodo*a)
{
	nodo*b;
	b=a;
	while(b)
	{
		printf("Dato: %d \n",b->dato);
		b=b->sgt;
	}
	free(b);
}
int main(void)
{
	queue*cola=NULL;
	int op;//Opción del menu
	int n;//numero de datos
	int x;//Dato
	do{
		printf("1° Ingrese cierto numero de dato a la cola:\n");
		printf("2° Eliminar la cabeza:\n");
		printf("3° Mostrar los datos de la cola:\n");
		printf("0° Terminar:\n\n");
		printf("Ingrese la opción:\n");
		scanf("%d",&op);
		switch(op){
		case 0:
			break;
		case 1:
			printf("Ingrese el numero de datos a ingresar:\n");
			scanf("%d",&n);
			do{
				printf("Ingrese el dato entero:\n");
				scanf("%d",&x);
				cola=enqueue(cola,x);
				n--;
			}while(n);
			break;
		case 2:
			printf("Se elimina el dato en la cabeza:\n");
			cola=dequeue(cola);
			break;
		case 3:
			printf("Los elementos en la cola son:\n");
			mostrar(cola->head);
			break;
		default:
			printf("Error opción no valida");
			break;
		}
	}while(op);
	while(cola->head)
	{
		cola=dequeue(cola);
	}
	free(cola);
	return 0;
}
