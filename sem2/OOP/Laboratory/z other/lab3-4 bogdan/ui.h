#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "controller.h"

typedef struct ui_s{
    controller cont;
}ui;

void stack_realloc(ui *stack, int *nr, int *sz)
{
    if(*nr+1 >= *sz)
    {
        *sz=2*(*sz)+1;
        stack=(ui*)realloc(stack,sizeof(ui)*(*sz));
        for(int i=*nr+1;i<*sz;i++)
            stack[i].cont.repo=NULL;
    }
}

void run_app(ui App)
{
    controller_load_data(&App.cont);
    ui *undo_stack=(ui*)malloc(sizeof(ui)*3);
    for(int i=0;i<3;i++)
        undo_stack[i].cont.repo=NULL;
    int nr=0,stack_size=3,m=0;
    while(1)
    {
        printf("\nEnter 0 to exit.\nEnter 1 to add a country.\nEnter 2 to see all countries.\nEnter 3 to delete a country.\nEnter 4 to update the population of a country.\nEnter 5 to add a migration.\nEnter 6 to see all countries whose name contain a given substring.\nEnter 7 to see all countries from a given continent.\nEnter 8 to see all countries from a given continent with population greater than a given number.\nEnter 9 to undo.\nEnter 10 to redo.\nYour command:");
        int cmd=0;
        scanf("%d",&cmd);
        if(cmd==0)
        {
            printf("\nGoodbye!\n");
            break;
        }
        if(cmd==1)
        {
            stack_realloc(undo_stack,&nr,&stack_size);
            controller_load_data(&undo_stack[nr].cont);
            nr++;
            m=nr;

            char name[MAXSIZE_COUNTRY_NAME],continent[MAXSIZE_CONTINENT_NAME];
            int population;
            printf("Country name:");

            getchar();
            fgets(name,sizeof(name),stdin);
            name[ strlen(name)-1 ]='\0';

            printf("Continent:");
            scanf("%s",continent);
            printf("Population:");
            scanf("%d",&population);
            int ok=Add(App.cont,name,continent,population);
            if(ok==0)
            {
                printf("\nDone!\n");
            }
            else{
                printf("\nAlready added or invalid input data!\n");
                nr--;
                m--;

            }
            continue;
        }
        if(cmd==2)
        {
            char *s=Show_all(App.cont);
            printf("\n%s\n",s);
            free(s);
            continue;
        }
        if(cmd==3)
        {
            stack_realloc(undo_stack,&nr,&stack_size);
            controller_load_data(&undo_stack[nr].cont);
            nr++;
            m=nr;

            char name[MAXSIZE_COUNTRY_NAME];
            printf("Country name:");

            getchar();
            fgets(name,sizeof(name),stdin);
            name[ strlen(name)-1 ]='\0';

            int ok=Del(App.cont,name);
            if(ok==1)
            {
                printf("\nThere's no country with name %s\n",name);
		nr--;
                m--;
            }
            else{
                printf("\nDone!\n");
            }
            continue;
        }
        if(cmd==4)
        {
            stack_realloc(undo_stack,&nr,&stack_size);
            controller_load_data(&undo_stack[nr].cont);
            nr++;
            m=nr;

            printf("Country name:");
            char name[MAXSIZE_COUNTRY_NAME];

            getchar();
            fgets(name,sizeof(name),stdin);
            name[ strlen(name)-1 ]='\0';

            printf("Insert the amount by which the population has changed:");
            int val;
            scanf("%d",&val);
            int ok=Update(App.cont,name,val);
            if(ok==1)
            {
                printf("\nThere's no country with name %s\n",name);
		nr--;
                m--;
            }
            else{
                printf("\nDone!\n");
            }
            continue;
        }
        if(cmd==5)
        {
            stack_realloc(undo_stack,&nr,&stack_size);
            controller_load_data(&undo_stack[nr].cont);
            nr++;
            m=nr;

            char name1[MAXSIZE_COUNTRY_NAME],name2[MAXSIZE_COUNTRY_NAME];
            printf("Country 1:");

            getchar();
            fgets(name1,sizeof(name1),stdin);
            name1[ strlen(name1)-1 ]='\0';

            printf("Country 2:");

            //getchar();
            fgets(name2,sizeof(name2),stdin);
            name2[ strlen(name2)-1 ]='\0';

            printf("The amount of people who migrates:");
            int val;
            scanf("%d",&val);
            int ok=Migration(App.cont,name1,name2,val);
            if(ok==1)
            {
                printf("\nError\n");
                nr--;
                m=nr;
            }
            else{
                printf("\nDone!\n");
            }
            continue;
        }
        if(cmd==6)
        {
            char *res,s[MAXSIZE_COUNTRY_NAME];
            printf("Substring:");
            getchar();
            fgets(s,sizeof(s),stdin);
            s[ strlen(s)-1 ]='\0';
            res=substringSearch(App.cont,s);
            printf("\n%s\n",res);
            free(res);
            continue;
        }
        if(cmd==7)
        {
            char *res,s[MAXSIZE_CONTINENT_NAME];
            printf("Continent:");
            getchar();
            fgets(s,sizeof(s),stdin);
            s[ strlen(s)-1 ]='\0';
            res=continentSearch(App.cont,s);
            printf("\n%s\n",res);
            free(res);
            continue;
        }
        if(cmd==8)
        {
            char *res,s[MAXSIZE_CONTINENT_NAME];
            printf("Continent:");
            getchar();
            fgets(s,sizeof(s),stdin);
            s[ strlen(s)-1 ]='\0';
            int val;
            printf("Minimum population:");
            scanf("%d",&val);
            res=search2(App.cont,s,val);
            printf("\n%s\n",res);
            free(res);
            continue;
        }
        if(cmd==9)
        {       
            if(m==nr)
            {
                stack_realloc(undo_stack,&m,&stack_size);
                controller_load_data(&undo_stack[m].cont);
                m++;
            }
            if(nr<=0)
            {
                printf("\nCan't undo anymore!\n");
                m=nr;
                continue;
            }
            controller_save_data(undo_stack[nr-1].cont);
            free_memory(&App.cont);
            controller_load_data(&App.cont);

            nr--;
            printf("\nDone!\n");
            controller_save_data(App.cont);
            continue;
        }
        if(cmd==10)
        {
            if(nr+1>=m)
            {
                printf("\nCan't redo anymore!\n");
                continue;
            }

            controller_save_data(undo_stack[nr+1].cont);
            free_memory(&App.cont);
            controller_load_data(&App.cont);

            nr++;
            printf("\nDone!\n");
            controller_save_data(App.cont);
            continue;
        }
        printf("\nInvalid command!\n");
    }
    for(int i=0;i<stack_size;i++)
    if(undo_stack[i].cont.repo!=NULL)
    {
        free_memory(&undo_stack[i].cont);
        undo_stack[i].cont.repo=NULL;
    }
    free(undo_stack);
    if(App.cont.repo!=NULL)
        free_memory(&App.cont);
}

#endif
