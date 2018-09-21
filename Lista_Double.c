#include<stdio.h>
#include<stdlib.h>
//Lista doblemente enlazada 
typedef struct list_double{
	int dato;
	struct list_double*sig;
	struct list_double*ant;
}list_double;

list_double*search(list_double*a,int n)//Busca un valor y retorna el puntero con la dirección del nodo
{
	list_double*b=a;
	while(b!=NULL && b->dato!=n)
	{
		b=b->sig;
	}
	return b;
}

list_double*insertarCab(list_double*a,int x)//Inserta un valor al inicio de la lista como nueva cabeza
{	
	if(a==NULL)
	{
		a=(list_double*) malloc(sizeof(list_double));
		a->dato=x;
		return a;
	}
	else
	{
		list_double*b=(list_double*) malloc(sizeof(list_double));
		b->dato=x;
		b->sig=a;
		a->ant=b;
		b->ant=NULL;
		return b;
	}
}

list_double*InsertarEnd(list_double*a,int x)
{
	if(a==NULL)
	{
		a=(list_double*) malloc(sizeof(list_double));
		a->dato=x;
		return a;
	}
	else
	{
		list_double*b=a;
		while(b->sig)
		{
			b=b->sig;
		}
		b->sig=(list_double*) malloc(sizeof(list_double));
		b->sig->dato=x;
		b->sig->ant=b;
		b=NULL;
		free(b);
		return a;
	}
}
list_double*delete(list_double*a,list_double*b)//Elimina un nodo de la lista
{
	if(a==b)
	{
		if(a->sig==NULL)
		{		
			free(a);
			return NULL;
		}
		else
		{
			b=a->sig;
			free(a);
			b->ant=NULL;
			return b;
		}	
	}
	else
	{	
		if(b->sig==NULL)
		{
			b=b->ant;			
			free(b->sig);
			b->sig=NULL;			
			return a;
		}
		else
		{
			b->ant->sig=b->sig;
			b->sig->ant=b->ant;
			free(b);
			return a;
		}
	}
}

list_double*vaciar(list_double*a)
{
	while(a)
	{
		a=delete(a,a);
	}
	return a;
}
void mostrar(list_double*a)//Muestro los datos de la lista
{
	list_double*b;
	b=a;
	printf("Los datos dentro de la lista son:\n");
	while(b)
	{	
		printf("Dato: %d\n",b->dato);
		printf("Direccion del nodo anterior: %p\n",b->ant);
		printf("Direccion del nodo siguiente: %p\n",b->sig);
		b=b->sig;
	}
}

int main(void)
{
	list_double*a=NULL;//Cabeza de list_double;
	int n,x,op;//n=numero de elementos y x = elemento
	do{
		printf("Lista doblemente enlazada:\n\t");
		printf("0: Para terminar\n\t");
		printf("1: Ingresar como cabeza \n\t");
		printf("2: Ingresar al final \n\t");
		printf("3: Eliminar \n\t");
		printf("4: Mostrar \n\t");
		printf("5: Vaciar \n");
		printf("Ingrese una opcion\n");
		scanf("%d",&op);
		switch(op){
			case 0:
					printf("Fin del programa:\n");
					break;
			case 1:
				printf("Ingrese el numero de elementos a ingresar en la lista\n");
				scanf("%d",&n);
				do{
					printf("Ingrese un numero entero\n");
					scanf("%d",&x);
					a=insertarCab(a,x);
					n--;
				}while(n);
				break;
			case 2:
				printf("Ingrese el numero de elementos a ingresar en la lista\n");
				scanf("%d",&n);
				do{
					printf("Ingrese un numero entero\n");
					scanf("%d",&x);
					a=InsertarEnd(a,x);
					n--;
				}while(n);
				break;
			case 3:
				printf("Ingrese un numero a eliminar\n");
				scanf("%d",&x);
				a=delete(a,search(a,x));
				break;
			case 4:
				mostrar(a);
				break;
			case 5:
					a=vaciar(a);
					break;
			default:
				printf("Opcion no validad\n");
				break;
		}
	}while(op);
	a=vaciar(a);
	free(a);
	return 0;
}
