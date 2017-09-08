#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// 2. Sa se creeze o structura de studenti
//typedef struct {
//    char* nume;
//    char* prenume;
//    int varsta;
//    int lab1, lab2, lab3;
//} Student;
//
//typedef Student* TElement;
//
//typedef struct {
//    
//    int length;
//    int capacity;
//    TElement* elems;
//
//} DynamicArray;
//
///////////////////////////////////////////////////////////////////////////////////
//
//typedef DynamicArray* list;
//
//typedef struct {
//    
//    int length;
//    int capacity;
//    list* elems;
//    
//} DynamicMatrix;
//
//
//DynamicMatrix* allocate_matrix(int capacity)
//{
//    DynamicMatrix* dMatrix = (DynamicMatrix*) malloc(sizeof(DynamicMatrix));
//    
//    dMatrix->elems = (list*) malloc(sizeof(list)*capacity);
//    dMatrix->length = 0;
//    dMatrix->capacity = capacity;
//    
//    return dMatrix;
//}
//
///////////////////////////////////////////////////////////////////////////////////
//
//
//DynamicArray* allocate_array(int capacity)
//{
//    DynamicArray* darray = (DynamicArray*) malloc(sizeof(DynamicArray));
//    
//    darray->elems = (TElement*) malloc(sizeof(TElement)*capacity);
//    darray->length = 0;
//    darray->capacity = capacity;
//    
//    return darray;
//}
//
//void add_to_array(DynamicArray* darray, Student* t)
//{
//    darray->elems[darray->length] = t;
//    darray->length++;
//}
//
//int main() {
//    
//    int n, i;
//    char nume[20], prenume[20];
//    int varsta, lab1, lab2, lab3;
//    
//    FILE *f;
//    f = fopen("stud.txt", "r");
//    
//    fscanf(f, "%i", &n);
//    
//    // 3. Sa se aloce dinamic sirul de studenti
//    DynamicArray* dArray = allocate_array(n);
//    
////    Student list[10];
////    for (i = 1; i <= n; i++)
////        fscanf(f, "%s %s %i %i %i %i", list[i].nume, list[i].prenume, &list[i].varsta, &list[i].lab1, &list[i].lab2, &list[i].lab3);
////    
////    for (i = 1; i <= n; i++)
////        printf("%s %s %i %i %i %i\n", list[i].nume, list[i].prenume, list[i].varsta, list[i].lab1, list[i].lab2, list[i].lab3);
//    
//    for (i = 1; i <= n; i++) {
//        // 1. Sa se citeasca din fisier studentii
//        fscanf(f, "%s %s %i %i %i %i", nume, prenume, &varsta, &lab1, &lab2, &lab3);
//        
//        Student* student = (Student*) malloc(sizeof(Student));
//        
//        student -> nume = (char *) malloc(sizeof(char) * strlen(nume) + 1);
//        student -> prenume = (char *) malloc(sizeof(char) * strlen(prenume) + 1);
//        
//        strcpy(student -> nume, nume);
//        strcpy(student -> prenume, prenume);
//        
//        student -> varsta = varsta;
//        student -> lab1 = lab1;
//        student -> lab2 = lab2;
//        student -> lab3 = lab3;
//        
//        add_to_array(dArray, student);
//        
//    }
//    
//    // 4. Sa se afiseze sirul de studenti
//    for (i = 0; i < n; i++) {
//        Student* student = dArray->elems[i];
//        printf("%s %s | %i | %i, %i, %i\n", student->nume, student->prenume, student->varsta, student->lab1, student->lab2, student->lab3);
//    }
//    
//    // 5. Sa se parcurga sirul de studenti, sa se calculeze media celor 3 note pentru fiecare student. Sa se afiseze apoi fiecare student urmat de medie
//    //   (Sa se adauge un camp "medie" in structura Student.
//    
//    // 6. Pentru fiecare student sa se incrementeze toate notele cu 1. Sa se afiseze studentii si notele lor modificate.
//    
//    return 0;
//}
int n;
int minim = 28;
char v[100];

void distanta_minima(int n) {
    
    if (n == 0)
        return;
    
    distanta_minima(n-1);
    
    int distanta = v[n-2] - v[n-1];
    
    if (distanta < minim && distanta >= 0)
        minim = distanta;
    
}

int main() {
    
    v[0] = 'a';
    v[1] = 'b';
    v[2] = 'c';
    v[3] = 'a';
    v[4] = 'd';
    v[5] = 'a';
    
    n = (int) strlen(v);
    
    distanta_minima(n);
    
    printf("%i\n", minim);
    
}

