#include<stdio.h>
#include<stdlib.h>
//Lista circular doblemente enlazada 
typedef struct list_circle_double{
	int dato;
	struct list_circle_double*sig;
	struct list_circle_double*ant;
}list_circle_double;

list_circle_double*search(list_circle_double*a,int n)//Busca un valor y retorna el puntero con la dirección del nodo
{
	list_circle_double*b=a;
	while(b!=NULL && b->dato!=n)
	{
		b=b->sig;
	}
	return b;
}
list_circle_double*insert(list_circle_double*a,int x)//Inserta un valor al inicio de la lista
{	
	if(a==NULL)
	{
		a=(list_circle_double*) malloc(sizeof(list_circle_double));
		a->dato=x;
		return a;
	}
	else
	{
		if(a->sig==NULL)
		{
			list_circle_double*b=(list_circle_double*) malloc(sizeof(list_circle_double));
			b->dato=x;
			b->sig=a;
			b->ant=a;
			a->sig=b;
			a->ant=b;
			return b;
		}
		else
		{
			list_circle_double*b=(list_circle_double*) malloc(sizeof(list_circle_double));
			b->dato=x;
			a->ant->sig=b;
			b->ant=a->ant;
			b->sig=a;
			a->ant=b;
			return b;
		}
	}
}
list_circle_double*delete(list_circle_double*a,list_circle_double*b)//Elimina un nodo de la lista
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
			a->ant->sig=b;
			b->ant=a->ant;
			free(a);
			return b;
		}	
	}
	else
	{	
		if(b==a->ant)
		{
			a->ant=b->ant;
			b->ant->sig=a;	
			free(b);			
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
void mostrar(list_circle_double*a)//Muestro los datos de la lista
{
	list_circle_double*b;
	list_circle_double*head=a;
	b=a;
	printf("Los datos dentro de la lista son:\n");
	while(b->sig!=head)
	{	
		printf("Dato: %d\n",b->dato);
		printf("Direccion del nodo anterior: %p\n",b->ant);
		printf("Direccion del nodo siguiente: %p\n",b->sig);
		b=b->sig;
	}
	printf("Dato: %d\n",b->dato);
	printf("Direccion del nodo anterior: %p\n",b->ant);
	printf("Direccion del nodo siguiente: %p\n",b->sig);
}
int main(void)
{
	list_circle_double*a=NULL;//Cabeza de list_double;
	int n,x;//n=numero de elementos y x = elemento
	printf("Ingrese el numero de elementos a ingresar en la lista\n");
	scanf("%d",&n);
	do{
		printf("Ingrese un numero entero\n");
		scanf("%d",&x);
		a=insert(a,x);
		n=n-1;
	}while(n!=0);
	mostrar(a);
	printf("Ingrese un numero a eliminar\n");
	scanf("%d",&x);
	a=delete(a,search(a,x));
	mostrar(a);
	return 0;
}
