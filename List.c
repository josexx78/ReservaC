#include<stdio.h>
#include<stdlib.h>

typedef struct lista{//TDA lista
    int num;//Dato del TDA
    struct lista*sig;//Puntero que conencta los nodos
}lista;//Nombre de referencia

lista*ingresoinicio(int n,lista*p) //Función de ingreso inicio
{
    if(!p)
    {
	   p=(lista*) malloc(sizeof(lista));
	   p->num=n;
	   return p;
    }
    lista*q;
    q=(lista*)malloc(sizeof(lista));		
    if(!q)
    {
        puts("No hay memoria suficiente");
        return p;
    }
    q->num=n;
    q->sig=p;
    return q;
}

lista*ingresofinal(int n,lista*p) //Funcion de ingreso final
{
    if(!p)
    {
        p=(lista*) malloc(sizeof(lista));
        p->num=n;
        return p;
    }
    else
    {
        lista*q=p;
        while(q->sig)
        {
            q=q->sig;
        }
        q->sig=(lista*) malloc(sizeof(lista));
        q->sig->num=n;
        q=NULL;
        free(q);
        return p;

    }
}
lista*ingresoPos(lista*p,int pos,int n)//Funcion:Ingresa un dato en la posicion tanto
{   lista*r,*z;
    lista*q=p;
    r=NULL;    
    int i=0;
    while(q)
    {   
        if(i==pos)
        {
            if(r)
            {
                z=(lista*) malloc(sizeof(lista));
                z->num=n;
                r->sig=z;
                z->sig=q;
                q=NULL;r=NULL;
                free(q);free(r);
                return p;
            }
            else
            {
                z=(lista*) malloc(sizeof(lista));
                z->sig=q;
                q=NULL;r=NULL;
                free(q);free(r);
                return z;
            }
        }
        r=q;
        q=q->sig;
        i++;
    }
    if(pos==i)
    {
        z=(lista*) malloc(sizeof(lista));
        z->num=n;
        z->sig=NULL;
        r->sig=z;
        r=NULL;
        free(q);free(r);
        return p;
    }
    else
    {
        r->sig;
        free(q);free(r);free(z);
        printf("Error posicion invalida:\n");
        return p;
    }
}

lista*eliminadato(int n,lista*p)//Funcion:Elimina un dato de la lista si se encuentra
{
    lista*r,*q;
    if(p==NULL)
    {
        puts("Lista vacia");
    }
    else
    {
        q=p;
        if(p->num==n)
        {
            p=p->sig;
            free(q);
        }
        else
        {
            do{
                r=q;
                q=q->sig;

            }while(q&&(q->num!=n));
            if(q)
            {
                r->sig=q->sig;
                free(q);
            }
            else
            {
                printf("%s \t %d %s","El numero ",n," no esta en la lista");
            }
        }
    }
    return p;
}

lista*eliminaPos(lista*p,int pos)//Funcion:Elimina una posicion de la lista(nodo)
{
    lista*q,*r;
    q=p;
    int i=0;
    while(q)
    {
        if(i==pos)
        {
            if(r)
            {
                if(q->sig)
                {
                    r->sig=q->sig;
                    free(q);
                    r=NULL;
                    free(r);
                }
                else//Fin de lista
                {
                    r->sig=NULL;
                    free(q);
                    r=NULL;
                    free(r);
                }
                return p;
            }
            else //Cabeza de lista
            {
                p=p->sig;
                q=NULL;
                free(q);free(r);
                return p;
            }
        }
        r=q;
        i++;
        q=q->sig;
    }
    r=NULL;
    free(q); free(r);
    printf("Posicion no valida:\n");
    return p;
}

lista*vaciar(lista*p)//Funcion:Vacia la lista y retorna null
{
    while(p)
    {
        p=eliminadato(p->num,p);
    }
    return NULL;
}

int linealSearch(lista*p,int x)//Funcion:Busca un dato y devuelve su posicion
{
    lista*q=p;
    int i=0;
    while(q)
    {
        if(q->num==x)
        {
            return i;
        }
        i++;
        q=q->sig;
    }
    free(q);
    return -1;
}

int devuelveDato(lista*p,int pos)//Funcion:Devuelve el elementos de la posicion
{
    lista*q=p;
    int i=0;
    while(q)
    {
        if(i==pos)
        {
            return q->num;
        }
        i++;
        q=q->sig;
    }
    free(q);
    return -1;
}

int apariciones(lista*p,int n)//Funcion:Cuenta el numero de aparicion de un elemento en la lista
{
    lista*q;
    q=p;
    int i=0;
    while(q)
    {
        if(q->num==n)
        {
            i++;
        }
        q=q->sig;
    }
    free(q);
    return i;
}

lista*eliminaRepetidos(lista*p)//Funcion:Elimina elementos repetidos
{
    lista*q,*r;
    q=p;
    int j;
    while(q)
    {
        j=apariciones(q,q->num);
        if(j>1)
        {
            while(j>1 && p)
            {
                q->sig=eliminadato(q->num,q->sig);
                j--;
            }
        }
        q=q->sig;
    }
    free(q);
    return p;
}

lista*concatenar(lista*p,lista*q)//Funcion:Concatena dos listas
{
    lista*r=p;
    while(r->sig)
    {
        r=r->sig;    
    }
    r->sig=q;
    r=NULL;
    free(r);
    return p;
}

lista*invertir(lista*p)//Funcion:Invierte la lista
{
    lista*q=NULL;
    while(p)
    {
        q=ingresoinicio(p->num,q);
        p=p->sig;
    }
    free(p);
    return q;
}

int largo(lista*p)//Funcion:Muestra el largo de una lista
{
    lista*q=p;
    int i=0;
    while(q)
    {
        i++;
        q=q->sig;
    }
    free(q);
    return i;
}
void intercambiarPos(lista*p,int n,int m)//Funcion:Intercambiar dos posiciones
{
        int aux=largo(p);
        if(n<=aux && m<=aux && n!=m && n>=1 && m>=1)
        {
                lista*q,*r;
                q=p;
                int i=0;
                int aux1,aux2;
                if(n<=m)
                {
                    aux1=n;
                    aux2=m;
                }
                else
                {
                    aux1=m;
                    aux2=n;
                }
                while(q)
                {
                    i++;
                    if(i==aux1)
                    {
                        r=q;
                    }
                    if(i==aux2)
                    {
                        aux=r->num;
                        r->num=q->num;
                        q->num=aux;
                    }
                    q=q->sig;
                }
                q=NULL;r=NULL;
                free(q); free(r);
        }
        else
        {
            printf("Posicion invalidas\n");
        }
}

void mostrar(lista*p)//Funcion:Muestra los elementos de una lista
{
    lista*q;
    q=p;
    printf("Los numeros de la lista son:\n");
    while(q)
    {
        printf("%s %d \n","Numero: ",q->num);
        q=q->sig;
    }
    free(q);
}

int main()
{
    	lista*p=NULL;//Creacion de un nodo nulo de lista
    	int n;//Numero de datos a ingresar
        int x;//Dato a ingresar
        int op;//Opcion del menu
        int pos;//Posicion de la lista
	do{
 	printf("Lista enlazada simple:\n\t");
	printf("0: Para terminar\n\t");
	printf("1: Ingresar cierto numero de datos(ingreso al inicio):\n\t");
	printf("2: Eliminar un dato especifico\n\t");
	printf("3: Mostrar\n\t");
    printf("4: Ingresar un dato en la cierta posicion (lista no vacia):\n\t");
    printf("5: Vaciar la lista:\n\t");
    printf("6: Eliminar la posicion de la lista (lista no vacia):\n\t");
    printf("7: Busqueda lineal:\n\t");
    printf("8: Devuelve dato en posicion:\n\t");
    printf("9: Numero de apariciones de un dato:\n\t");
    printf("10: Eliminar elementos repetidos:\n\t");
    printf("11: Invierte la lista dada:\n\t");
    printf("12: Intercambia dos posiciones de la listas(o datos):\n");
 	printf("Ingrese un numero\n");
	scanf("%d",&op);
	switch(op){
        case 0:
                printf("Fin del programa:\n");
                break;
		case 1:	   
		    	printf("%s \t","Ingrese un la cantidad de elementos a ingresar: ");
		        scanf("%d",&n);
	    		do{  
				    printf("Ingrese un numero a la lista:\n");
				    scanf("%d",&x);  
		    		p=ingresoinicio(x,p);
				    n--;
	    		}while(n);
			break;
		case 2:
			    printf("\n %s","Ingrese un numero a eliminar:");
    		    scanf("%d",&n);
    			p=eliminadato(n,p);
			    break;
		case 3:
    			mostrar(p);
			break;
    		default:
			printf("Opcion no valida\n");
			break;
        case 4:
                printf("Ingrese un numero a la lista:\n");
                scanf("%d",&x);
                printf("Ingrese la pos:\n");
                scanf("%d",&pos);
                p=ingresoPos(p,pos,x);
                mostrar(p);
                break;
        case 5:
                p=vaciar(p);
                break;
        case 6:
                printf("Ingrese la posicion a eliminar:\n");
                scanf("%d",&pos);
                p=eliminaPos(p,pos);
                break;
        case 7:
                printf("Ingrese el dato:\n");
                scanf("%d",&x);
                if (linealSearch(p,x)==-1)
                {
                    printf("El dato no se encuentra en la lista\n");
                }
                else
                {
                    printf("El dato se encuentra en la posicion:%d\n",linealSearch(p,x));
                }
                break;
        case 8:
                printf("Ingrese la posicion:\n");
                scanf("%d",&x);
                if(devuelveDato(p,x)==-1)
                {
                    printf("Posicion invalida\n");
                } 
                else
                {
                    printf("El dato en la posicion %d es:%d\n",x,devuelveDato(p,x));
                }
                break;       
        case 9:
                printf("Ingrese el dato:\n");
                scanf("%d",&x);
                printf("El numero aparece en la lista:%d veces\n",apariciones(p,x));
                break;
        case 10:
                p=eliminaRepetidos(p);
                mostrar(p);
                break;
        case 11:
                p=invertir(p);
                mostrar(p);
                break;
        case 12:
                printf("Ingrese la posicion 1:\n");
                scanf("%d",&x);
                printf("Ingrese la posicion 2:\n");
                scanf("%d",&pos);
                intercambiarPos(p,x,pos);
                mostrar(p);
        }
	}while(op);
    p=vaciar(p);
    free(p);
    return 0;
}
