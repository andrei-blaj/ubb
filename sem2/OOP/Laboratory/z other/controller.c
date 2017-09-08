#include "controller.h"
#include <string.h>
Controller createController(EstateRepo* r)
{
    Controller c;
    c.repo = r;
    
    return c;
}

int addEstate(Controller* c, char type[], char address[], double surface, double price)
{
    Estate x = createEstate(type, address, surface, price);
    
    int res = add(c->repo, x);
    return res;
}

int deleteEstate(Controller* c, char address[30+1])
{
    int res = delete(c->repo, address);
    return res;
}
int updateEstate(Controller* c, char type[], char address[], double surface, double price)
{
    Estate x = createEstate(type, address, surface, price);
    int res = update(c->repo, x);
    return res;
}

EstateRepo* getRepo(Controller* c)
{
    return c->repo;
}
void swap(Estate *a, Estate *b)
{
    Estate aux=*a;
    *a=*b;
    *b=aux;
}
EstateRepo filterByAddressCombination(Controller* c, char address[],int CMD)
{
    EstateRepo res = createRepo();
    if (strcmp(address, "null") == 0)
    {
        if (CMD == 1)
        {
            //sorted ascending by price !
            int ok =0;
            // Estate aux = createEstate("", "", 0, 0);;
            char str[200+1];
            
            while(ok!=1)
            {
                ok=1;
                for (int i = 0 ; i < getLength(c->repo) - 1; i++)
                {
                    // Estate x=getEstateOnPos(c->repo, i);
                    //Estate y=getEstateOnPos(c->repo, i+1);
                    // toString(x, str);
                    // printf("%s\n", str);
                    //toString(y, str);
                    //printf("%s\n", str);
                    if(c->repo->estate[i].price >c->repo->estate[i+1].price)
                    {
                        double aux;
                        char aux2[20+1];
                        //type swap
                        strcpy(aux2,c->repo->estate[i].type);
                        strcpy(c->repo->estate[i].type,c->repo->estate[i+1].type);
                        strcpy(c->repo->estate[i+1].type,aux2);
                        
                        //address swap
                        strcpy(aux2,c->repo->estate[i].address);
                        strcpy(c->repo->estate[i].address,c->repo->estate[i+1].address);
                        strcpy(c->repo->estate[i+1].address,aux2);
                        
                        //surface swap
                        aux=c->repo->estate[i].surface;
                        c->repo->estate[i].surface=c->repo->estate[i+1].surface;
                        c->repo->estate[i+1].surface=aux;
                        
                        //price swap
                        aux=c->repo->estate[i].price;
                        c->repo->estate[i].price=c->repo->estate[i+1].price;
                        c->repo->estate[i+1].price=aux;
                        
                        ok=0;
                    }
                }
            }
            return *(c->repo);
        }
        else if (CMD == 2)
        {
            //sorted descending by price !
            for (int i = 0 ; i < getLength(c->repo) - 1; i++)
            {
                Estate x = getEstateOnPos(c->repo, i);
                for (int j = i; j < getLength(c->repo); j++)
                {
                    Estate y = getEstateOnPos(c->repo, j);
                    Estate aux = y;
                    if (x.price < y.price)
                    {
                        y = x;
                        x = aux;
                    }
                }
            }
            return *(c->repo);
        }
    }
    
    for (int i = 0; i < getLength(c->repo); i++)
    {
        Estate x = getEstateOnPos(c->repo, i);
        if (strstr(getAddress(&x), address) != NULL)
            add(&res, x);
    }
    
    return res;
}

EstateRepo filterByTypeSurface(Controller* c, char type[12+1], double surface)
{
    EstateRepo res = createRepo();
    for (int i = 0; i < getLength(c->repo); i++)
    {
        Estate x = getEstateOnPos(c->repo, i);
        if (strcmp(getType(&x), type) == 0 && x.surface >= surface)
        {
            add(&res, x);
        }
    }
    
    return res;
}
EstateRepo filterByPrice(Controller* c, double price, int CMD)
{
    EstateRepo res = createRepo();
    if (CMD == 1)
    {
        for (int i = 0; i < getLength(c->repo); i++)
        {
            Estate x = getEstateOnPos(c->repo, i);
            if (x.price >= price)
            {
                add(&res, x);
            }
        }
        return res;
    }
    else if (CMD == 2)
    {
        for (int i = 0; i < getLength(c->repo); i++)
        {
            Estate x = getEstateOnPos(c->repo, i);
            if (x.price <= price)
            {
                add(&res, x);
            }
        }
        return res;
    }
    return res;
}
