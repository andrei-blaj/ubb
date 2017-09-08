#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

/* tipul pentru nodul lista */

typedef struct elem

{
    
    float info;
    int pozitie;
    
//    int data;
//    int varsta;
    
    struct elem *urm;
    
} nod;



/* cauta in lista indicata de p nodul cu campul info = inf si
 
 returneaza pointerul catre acel nod, daca nodul cautat nu exista returneaza NULL  */

nod *caut(nod *p, float inf)

{
    
    for ( ; p!=NULL && p->info<inf; p=p->urm);
    
    /* cautam doar pana la primul element mai mare decat inf (daca el nu exista),
     
     deoarece lista e ordonata, deci nu mai are sens sa parcurgem mai departe*/
    
    if (p!=NULL && inf==p->info)
        
        return p; /* daca info a fost gasit in lista */
    
    return NULL;  /* daca nu a fost gasita */
    
}



/*   Functia listez parcurge lista si pentru fiecare nod
 
 afiseaza informatia memorata.       */

void listez(nod *p)

{
    
    printf("Un nod ocupa %d octeti, pointerul catre nod ocupa %d octeti\n",
           
           sizeof(*p), sizeof(p));
    
    for ( ; p!=NULL; p=p->urm)
        
        printf("(adr=%p) |%6g| %p | \n",p,p->info, p->urm);
    
}



/* Functia sterg elimina din lista (indicata de pointerul
 
 p) nodul ce are campul info egal cu argumentul inf     */

nod *sterg(nod *radacina, float inf)

{
    
    nod *aux, *p;
    
    if (radacina==NULL){  // lista vida
        
        printf("Eroare: lista e vida\n");
        
        return NULL;
        
    }
    
    else
        
        if (radacina->info==inf){   // sterg primul element
            
            aux=radacina;
            
            radacina=radacina->urm;
            
            free(aux);
            
            return radacina;
            
        }
    
        else{
            
            // parcurgem lista pana gasim nodul cu info=infonou sau pana la sfarsit
            
            for(p=radacina; p->urm!=NULL && p->urm->info<inf; p=p->urm);
            
            
            
            if (p->urm != NULL  && p->urm->info==inf) // nodul cautat exista
                
            {
                
                aux=p->urm;
                
                p->urm=aux->urm;  // adica p->urm=p->urm->urm;
                
                free(aux);
                
            }
            
            else     // nodul cautat nu exista
                
                printf("Eroare: identificatorul %f nu apare in lista\n", inf);
            
            return radacina;
            
        }
    
}



/*Functia introduc insereaza un nod  in lista ordonata,
 
 Functia returneaza pointerul catre inceputul listei modificate  */

nod * introduc(nod *radacina, float infonou)

{
    
    nod  *nou, *p;
    
    if ((nou=(nod *)malloc(sizeof(nod)))==NULL)
        
    {
        
        /* daca nu e memorie suficienta pentru a crea un nod nou,se da un mesaj
         
         de eroare dupa care se termina functia sise returneaza NULL */
        
        printf("Eroare: memorie insuficienta\n");
        
        return NULL;
        
    }
    
    nou->info=infonou;    /* se salveaza infonou in nodul nou */
    
    nou->urm=NULL;
    
    /* nodul nou este inserat in lista ordonata astfel incat ea ramane ordonata
     
     si dupa inserare. Lista este parcursa cautandu-se primul nod avand
     
     campul info mai mare sau egal cu info */
    
    if (radacina==NULL)   // lista vida
        
        radacina=nou;
    
    else {
        
        for(p = radacina; p->urm != NULL; p = p->urm);
            
        //nou->urm = NULL;
            
        p->urm = nou;
    
    }
    
    return radacina;
    
}



/* Functia main afiseaza meniul programului,citeste comanda */

/* si apeleaza functia corespunzatoare                     */

int main(void)

{
    
    char o;
    
    float val;
    
    nod *radacina=NULL, *p;     /* pastreaza inceputul listei */
    
    puts("");
    
    while(1)
        
    {
        
        puts("");
        
        /* se afiseaza meniul programului */
        
        puts("a : adauga un nod");
        
        puts("c : cauta si tipareste un nod");
        
        puts("s : sterge un nod");
        
        puts("l : listeaza tot");
        
        puts("t : termina programul");
        
        printf("\nOptiunea: ");
        
        while(isspace(o=getchar()) );
        
        puts("");
        
        switch (tolower(o))
        
        {
                
            case 'a': {  printf("adauga  nr=");
                
                scanf("%f", &val);
                
                radacina=introduc(radacina, val);
                
                break;}
                
            case 'c': {  puts("cauta si tipareste un nod");
                
                printf("nr=");
                
                scanf("%f", &val);
                
                if ((p=caut(radacina, val))!=NULL) /* cauta nodul in lista */
                    
                    printf(" Valoare:%f\n", p->info);
                
                else
                    
                    printf("Eroare: Identificator nedefinit\n");
                
                break;
                
            }
                
            case 's':{   printf("stergere  nr=");
                
                scanf("%f", &val);
                
                radacina=sterg(radacina, val); /* sterge nodul din lista */
                
                break;}
                
            case 'l':{  puts("listare");
                
                listez(radacina);
                
                break;}
                
            case 't':
                
                return 0;
                
            default:
                
                printf("Eroare : Comanda inexistenta\n");
                
        }
        
    }
    
    return 0;
    
}


////
////  main.c
////  Lista Simplu Inlantuita
////
////  Created by Andrei-Sorin Blaj on 11/05/2017.
////  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Element {
//
//    int valoare;
//    
//    struct Element *urmator;
//
//} nod;
//
//// Afisarea tuturor valorilor din linsta simplu inlantuita
//void afisare(nod* radacina) {
//    
//    // cat timp mai avem elemente in lista
//    while (radacina != NULL) {
//        
//        printf("%d ", radacina -> valoare);
//        
//        radacina = radacina -> urmator;
//        
//    }
//    
//}
//
//nod* adaugare(nod* radacina, int valoare_noua) {
//    
//    nod* nod_nou;
//    
//    nod_nou = (nod *) malloc(sizeof(nod));
//    
//    nod_nou -> valoare = valoare_noua;
//    nod_nou -> urmator = NULL;
//    
//    while (radacina != NULL) {
//        
//        radacina = radacina -> urmator;
//        
//    }
//    
//    radacina -> urmator = nod_nou;
//    
//    return radacina;
//}
//
//
//int main(){
//    
//    nod *radacina = NULL;
//    
//    radacina = adaugare(radacina, 10);
//    radacina = adaugare(radacina, 11);
//    radacina = adaugare(radacina, 12);
//    radacina = adaugare(radacina, 13);
//    radacina = adaugare(radacina, 14);
//    
//    afisare(radacina);
//    
//    return 0;
//    
//}
