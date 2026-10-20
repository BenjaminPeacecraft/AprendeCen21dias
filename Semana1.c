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
        printf("\n\tEnter Birthday: ");
        
        do
        {
            printf("\n\tMonth (0 - 12): ");
            scanf("%d", &month[ctr]);
        }while (month[ctr] < 0 || month[ctr] > 12);

        do
        {
            printf("\n\tDay (0 - 31): ");
            scanf("%d", &day[ctr]);
        }while (day[ctr] < 0 || day[ctr] > 31);

        do
        {
            printf("\n\tYear (0 - 1994): ");
            scanf("%d", &year[ctr]);
        }while ( year[ctr] < 0 || year[ctr] > 1994);

        printf("\nEnter Yearly Income (whole dollars): ");
        scanf("%ld", &income[ctr]);

        cont = continue_function();
    }

    /* ctr es igual a la cantidad de gente que se ha tecleado.*/
}

/*Funcion display_report. Esta funcion despliega un reporte en la pantalla. Regresa: Nada. 
Nota: Aun se puede imprimir mas informacion */

void display_report()
{
    grand_total = 0;
    printf("\n\n\n");
    printf("\n      SALARY SUMMARY");
    printf("\n      ==============");

    for( x = 0; x <= 12; x++)   /*Para cada mes. Incluyendo 0*/
    {
        month_total = 0;
        for ( y = 0; y < ctr; y++)
        {
            if (month[y] == x)
                month_total += income[y];
        }
        printf("\nTotal for mont %d is %ld", x, month_total);
        grand_total += month_total;
    }
    printf("\n\nReport totals: ");
    printf("\nTotal Income is %ld", grand_total);
    printf("\nAverage Income is %ld", grand_total/ctr);

    printf("\n\n* * * End of Report * * * ");
}

/*Funcion: continue_function()
Objetivo: Preguntar al usuario si quiere continuar
Regresa: YES - si el usuario desea continuar
        NO - si el usuario desea terminar*/

int continue_function(void)
{
    printf("\n\nDo you wish to continue? (0 = NO / 1 = YES): ");
    scanf("%d", &x);

    while ( x < 0 || x > 1)
    {
        printf("\n%d is invalid!", x);
        printf("\nPlease enter 0 to Quit or 1 to continue: ");
        scanf("%d", &x);
    }
    if(x == 0)
        return(NO);
    else
        return(YES);
}
