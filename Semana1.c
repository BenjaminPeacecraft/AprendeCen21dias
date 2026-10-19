/* week1.c*/
/*Programa pra teclear las edades e ingresos de hasta 100 personas. 
El programa imp´rime un repoirte basado en las cantidades tecleadas*/
#include <stdio.h>

#define MAX 100
#define YES 1
#define NO 0

long income [MAX];
int month [MAX], day[MAX], year[MAX]; /*Para guradar fechas de nacimiento*/
int x, y, ctr; /*Para contadores*/
int cont; /*Para control de programa*/
long month_total, grand_total; /*Para totales*/

/*Prototipos de funcion*/

void main(void);
int display_instructions(void);
void get_data(void);
void display_report();
int continue_function(void);

/*Inicio del programa*/

void main()
{
    cont = display_instructions();

    if (cont == YES)
    {
        get_data();
        display_report();
    }
    else
        printf("\n Program Aborted by USer!\n\n"); 
}

/*Funcion display instructions. Esta funcion despliega informacion sobre la manera de usar este programa y pide al usuario 
teclear 0 para terminar o 1 para continuar */

int display_instructions(void)
{
    printf("\n\n");
    printf("\nThis program enables you to enter up to 99 people    s");
    printf("\nincomes and birthdays. It then prints the incomes by");
    printf("\nmonth along with the overall income and overall average.");
    printf("\n");

    cont = continue_function();

    return(cont);
}
/*Funcion get_data. Obtiene datos del usuario, continua pidiendo datos hasta que se hayan tecleado 100 personas
o hasta que el usuario teclee 0 en el mes. Permite teclear 0/0/0 si no se sabe la fecha de nacimiento y tambien toma
todos los meses de 31 dias*/

void get_data(void)
{
    for(cont = YES, ctr = 0; ctr < MAX && cont == YES; ctr++)
    {
        printf("\n Enter information for Person %d.", ctr + 1);
        
    }
}
