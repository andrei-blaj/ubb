#ifndef TEST_H
#define TEST_H


#include "ui.h"
#include <assert.h>

void testAdd(controller cont)
{
    assert(Add(cont,"abc","abc",10)==1);
    int sz=size(cont.repo);
    assert(Add(cont,"abcd","Europe",100)==0);
    //printf("%d %d\n",size(cont.repo),sz);
    assert(size(cont.repo)==sz+1);
}

void testDel(controller cont)
{
    assert(Del(cont,"abc")==1);
    assert(Del(cont,"abcd")==0);
}

void testUpdate(controller cont)
{
    assert(Update(cont,"abc",10)==1);
}

void testsubstring_search(controller cont)
{
    char *str=substringSearch(cont,"abc");
    //printf("%s\n",str);
    assert(strcmp(str,"abcd Europe 100\n")==0);
    char *str2=substringSearch(cont,"zxy");
    printf("%s\n",str2);
    assert(strcmp(str2,"")==0);
    free(str);
}

void testShow_all(controller cont)
{
    assert(strcmp(Show_all(cont),"abcd Europe 100\n"));
}

void run_tests(controller cont)
{
    controller_load_data(&cont);
    testAdd(cont);
    testsubstring_search(cont);
    testDel(cont);
    testUpdate(cont);
}

#endif
