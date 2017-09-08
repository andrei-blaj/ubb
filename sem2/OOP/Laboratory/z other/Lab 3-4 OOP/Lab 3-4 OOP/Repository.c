#include "Repository.h"

EstateRepository * create_allocate_repository()
{
    EstateRepository* repo = (EstateRepository*)malloc(sizeof(EstateRepository));
    repo->estates = allocate_array(20);
    return repo;
}

int add_repository(EstateRepository* repo, TElement t)
{
    if (search_by_address(repo->estates, t) == -1)
        //repo->estates->elems[length] = t;
    {
        add_to_array(repo->estates, t);
        return 1; //succes
    }
    
    else
        return 0; //era deja gasit
}

int get_repo_length(EstateRepository * repo)
{
    return get_length(repo->estates);
    
}

Estate* delete_repository(EstateRepository * repo, char * address)
{
    int pos = search_by_address(repo->estates, address);
    if (pos == -1)
        return NULL;
    Estate* new_estate = copy_estate(repo->estates->elems[pos]);
    delete_from_array(repo->estates, pos);
    return new_estate;
}

Estate* update_repository(EstateRepository * repo, TElement t)
{
    int pos = search_by_address(repo->estates, t->address);
    if (pos < 0 || pos >= repo->estates->length)
        return NULL;
    Estate* new_estate = copy_estate(repo->estates->elems[pos]);
    update_array(repo->estates, pos, t);
    return new_estate;
}

void destroy_repository(EstateRepository* repo)
{
    deallocate_array(repo->estates); 
    free(repo);
}

