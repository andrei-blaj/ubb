#ifndef REPOSITORY_H
#define REPOSITORY_H


#include <stdlib.h>
#include <string.h>
#include "domain.h"

typedef struct repository_s{
    country *arr;
    int nr,total;
}repository;

void free_repo(repository *repo)//frees the memory
{
    free(repo->arr);
}

int size(repository *repo)//return the number of entities from a given repository
{
    return repo->nr;
}

void sort(repository *repo,int(*compare)(country, country))//sorts the repository
{
    for(int i=0;i < repo->nr;i++)
    for(int j=i+1;j < repo->nr;j++)
    if(compare(repo->arr[i],repo->arr[j]))
    {
        country x=repo->arr[i];
        repo->arr[i]=repo->arr[j];
        repo->arr[j]=x;
    }
}

country get(repository *repo,int index)//returns the country from a given index
{
    return repo->arr[index];
}

void save_data(repository *repo)//save the data from a given repository
{
    FILE *f=fopen(dataFILE,"w");
    fprintf(f,"%d\n",repo->nr);
    for(int i=0;i < repo->nr;i++)
    {
        fprintf(f,"%ld\n%s\n%s\n",repo->arr[i].population,repo->arr[i].name,repo->arr[i].continent);
    }
    fclose(f);
}

void repo_realloc(repository *repo)
{
    repo->total=repo->total*2+1;
    repo->arr=(country*)realloc(repo->arr,repo->total * sizeof(country));
}

void add(repository *repo, char *name, char *continent, long population)//adds a new element to repository
{
    if(repo->nr+1 >= repo->total)
        repo_realloc(repo);
    strcpy(repo->arr[ repo->nr ].name,name);
    strcpy(repo->arr[ repo->nr ].continent,continent);
    repo->arr[ repo->nr ].population=population;
    repo->nr++;
    save_data(repo);
}

void del(repository *repo, int pos)//erases the element found at position pos
{
    for(int i=pos;i< repo->nr-1;i++)
        repo->arr[i]=repo->arr[i+1];
    repo->nr--;
    save_data(repo);
}

int find_by_name(repository *repo, char *name)//returns an index if element with given name is found, -1 otherwise
{
    for(int i=0;i < repo->nr;i++)
        if(strcmp(name, repo->arr[i].name)==0)
            return i;
    return -1;
}

int find(repository *repo, char *name, char *continent, long population)//returns an index if element is found, -1 otherwise
{
    for(int i=0;i < repo->nr;i++)
        if(strcmp(name, repo->arr[i].name)==0 && strcmp(continent,repo->arr[i].continent)==0 && repo->arr[i].population==population)
            return i;
    return -1;
}


repository* load_data()//load data from file, returns a repository containing the data
{
    FILE *f=fopen(dataFILE,"r");
    repository *repo=(repository *)malloc(sizeof(repository));
    fscanf(f,"%d\n",&repo->nr);
    repo->arr=(country*)malloc(repo->nr*sizeof(country));
    repo->total=repo->nr;
    for(int i=0;i < repo->nr;i++)
    {
        long population;
        char name[MAXSIZE_COUNTRY_NAME],continent[MAXSIZE_CONTINENT_NAME];
        fscanf(f,"%ld",&population);

        getc(f);
        fgets(name,sizeof(name),f);
        name[ strlen(name)-1 ]='\0';

        fscanf(f,"%s",continent);

        repo->arr[i].population=population;
        strcpy(repo->arr[i].name,name);
        strcpy(repo->arr[i].continent,continent);
    }
    fclose(f);
    return repo;
}

void update(repository *repo, int pos, int val)//update the population of the country at index pos with value val
{
    repo->arr[pos].population+=val;
}

char *to_string(repository *repo)//returns a string with all the countries in the repository
{
    char *s=(char*)malloc(1000*sizeof(char));// TO BE MODIFIED
    strcpy(s,"");
    for(int i=0;i < repo->nr;i++)
    {
        strcat(s,repo->arr[i].name);
        strcat(s," ");
        strcat(s,repo->arr[i].continent);
        strcat(s," ");
        char aux[20];
        sprintf(aux,"%ld\n",repo->arr[i].population);
        strcat(s,aux);
    }
    if(repo->nr == 0)
    {
        strcpy(s,"The list is empty!\n");
    }
    return s;
}


#endif
