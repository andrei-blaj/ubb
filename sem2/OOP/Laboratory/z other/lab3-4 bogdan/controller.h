#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"

typedef struct controller_s{
    repository *repo;
}controller;

void free_memory(controller *cont)//frees memory
{
    free_repo(cont->repo);
    free(cont->repo);
}

void controller_load_data(controller *cont)//load data into controller cont
{
    cont->repo=load_data();
}

void controller_save_data(controller cont)//save the data from controller cont in the file
{
    save_data(cont.repo);
}

int isContinentValid(char *s)//returns 0 if the given string is a valid continent
{
    const char ss[4][10]={ "Europe", "Asia", "America", "Africa" };
    for(int i=0;i<4;i++)
        if(strcmp(s,ss[i])==0)
            return 0;
    return 1;
}

int populationCompare(country x, country y)
{
    return x.population > y.population;
}

int nameCompare(country x, country y)
{
    return strcmp(x.name, y.name)>0;
}

char *search1(controller cont, char *continent)
{
    sort(cont.repo, nameCompare);
    char *out=(char*)malloc(1000*sizeof(char));
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(strcmp(get(cont.repo,i).continent,continent)==0)
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}

char *search2(controller cont, char *continent, int val)//returns all the countries from a given continent whose population is larger than val
{
    sort(cont.repo,populationCompare);
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(get(cont.repo,i).population>val && (strcmp(get(cont.repo,i).continent,continent)==0 || strlen(continent)==0))
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}



char *continentSearch(controller cont, char *continent)//returns all the countries from a given continent whose population is larger than val
{
    sort(cont.repo,nameCompare);
    if(strlen(continent)==0)
    {
        return to_string(cont.repo);
    }
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(strcmp(get(cont.repo,i).continent,continent)==0)
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}

char *substringSearch(controller cont, char *s)//returns all countries whose name contain a given string
{
    if(strlen(s)==0)
        return to_string(cont.repo);
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    for(int i=0;i<size(cont.repo);i++)
        if(strstr(get(cont.repo,i).name,s)!=NULL)
        {
            country x=get(cont.repo,i);
            strcat(out, x.name);
            strcat(out," ");
            strcat(out, x.continent);
            strcat(out," ");
            char aux[20];
            sprintf(aux,"%ld\n",x.population);
            strcat(out,aux);
        }
    return out;
}

int Update(controller cont, char *name, int val)//updates the population of a given country
{
    int pos=find_by_name(cont.repo,name);
    if(pos==-1)
        return 1;
    update(cont.repo,pos,val);
    save_data(cont.repo);
    return 0;
}

int Migration(controller cont, char *name1, char *name2, int val)//updates the population of 2 given countries
{
    int pos1=find_by_name(cont.repo,name1),pos2=find_by_name(cont.repo,name2);
    if(pos1==-1 || pos2==-1)
        return 1;
    update(cont.repo,pos1,-val);
    update(cont.repo,pos2,val);
    save_data(cont.repo);
    return 0;
}

int Add(controller cont, char *name, char *continent, long population)//adds a country
{
    if(find(cont.repo,name,continent,population)!=-1 || isContinentValid(continent)==1)
        return 1;
    add(cont.repo,name,continent,population);
    return 0;
}

char *Show_all(controller cont)//returns all countries
{
    return to_string(cont.repo);
}

int Del(controller cont, char *name)//erases a country
{
    int pos=find_by_name(cont.repo,name);
    if(pos==-1)
        return 1;
    del(cont.repo,pos);
    return 0;
}

#endif
