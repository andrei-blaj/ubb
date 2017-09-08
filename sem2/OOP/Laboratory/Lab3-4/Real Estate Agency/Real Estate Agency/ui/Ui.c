//
//  Ui.c
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Ui.h"

UI * create_allocate_UI(EstateController* ctrl)
{
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->ctrl=ctrl;
    return ui;
}

void destroy(UI * ui)
{
    destroy_controller(ui -> ctrl);
    free(ui);
}

int get_integer(const char* msg)
{
    int nr = 0;
    char s[10];
    int ok = 0;
    int check = 0;
    while (ok == 0) {
        printf("%s", msg);
        scanf("%s", s);
        check = sscanf(s, "%d", &nr);
        if (check == 1)
            ok = 1;
        else
            printf("> Please give an integer!\n");
    }
    return nr;
}

void first_estates(UI* ui)
{
    add_controller(ui->ctrl, "Penthouse", "Intre Lacuri", 300, 80000);
    add_controller(ui->ctrl, "House", "Zorilor", 247, 120000);
    add_controller(ui->ctrl, "Apartment", "Manastur", 43, 780000);
    add_controller(ui->ctrl, "House", "Gheorgheni", 400, 70000000);
    add_controller(ui->ctrl, "Penthouse", "Marasti", 800, 100000000);
    
    ui->ctrl->undo_stack->length = 0;
}

void print_estates(UI* ui)
{
    EstateRepository* repo = get_repo(ui->ctrl);
    int length = get_repo_length(repo);
    if (length == 0)
    {
        printf("> NO ESTATES\n");
        
    }
    else
    {
        char str[900];
        for (int i = 0; i < length; i++)
        {
            toString(repo->estates->elems[i], str);
            printf("%s\n", str);
        }
    }
}


int valid_command(int cmd)
{
    if (cmd >= 0 && cmd <= 10)
        return 1;
    return 0;
}



void add_ui(UI* ui)
{
    char type[20], address[100];
    double price, surface;
    printf("> give type: ");
    scanf("%s", type);
    printf("> give address: ");
    scanf("%s", address);
    surface = get_integer("> give surface: ");
    price = get_integer("> give price: ");
    int result = add_controller(ui->ctrl, type, address, surface, price);
    if (result == 0)
        printf("> ADD FAILED\n");
    
}

void delete_ui(UI* ui)
{
    char address[100];
    printf("> Give address: ");
    scanf("%s", address);
    int result = delete_controller(ui->ctrl, address);
    if (result == 0)
        printf("> DELETE FAILED\n");
}

void filter_by_address(UI* ui)
{
    char str[30], s[170];
    printf("> Search for: ");
    scanf("%s", str);
    if (strcmp(str, "null") == 0)
        print_estates(ui);
    else
    {
        int i;
        EstateRepository* repo = filter_by_keyword(ui->ctrl, str);
        if (get_repo_length(repo) == 0)
            printf("> Sorry! No items matching te requested keyword.\n");
        else
        {
            repo = sort_repository(ui->ctrl, repo);
            for (i = 0; i < repo->estates->length; i++)
            {
                toString(repo->estates->elems[i], s);
                printf("%s\n", s);
            }
        }
    }
}

void update_ui(UI* ui)
{
    char address[100], new_type[20];
    double new_price, new_surface;
    printf("> Please insert an address in order to update the estate: ");
    scanf("%s", address);
    printf("> NEW TYPE: ");
    scanf("%s", new_type);
    new_surface = get_integer("> NEW SURFACE: ");
    new_price = get_integer("> NEW PRICE:");
    int result = update_controller(ui->ctrl, address, new_type, new_surface, new_price);
    if (result == 0)
    {
        printf("> The address is invalid or it does not exist. Please try again. UPDATE FAILED!\n");
        
    }
    
}


void filter_l(UI* ui)
{
    char type[40], s[100];
    double sr;
    sr = get_integer("> SURFACE: ");
    EstateRepository* new_repo=filter_by_surface_l(ui->ctrl, sr, ui->ctrl->repo);
    new_repo = filter_by_surface_l(ui->ctrl, sr, new_repo); //ctrl new function silter_by_surface_l
    if (get_repo_length(new_repo) == 0)
        printf("> NO ITEMS MATCHING\n");
    else
    {
        new_repo = sort_repository_l(ui->ctrl, new_repo);
        for (int i = 0; i < new_repo->estates->length; i++)
        {
            toString(new_repo->estates->elems[i], s);
            printf("%s\n", s);
        }
    }
    
    
}

void filter_c(UI* ui)
{
    char type[40], s[100];
    printf("> TYPE: ");
    scanf("%s", type);
    int min_sf = get_integer("> Give min_surface: ");
    EstateRepository* repo = filter_by_type(ui->ctrl, type);
    repo = filter_by_surface(ui->ctrl, min_sf, repo);
    if (get_repo_length(repo) == 0)
        printf("> NO ITEMS MATCHING\n");
    else {
        for (int i = 0; i < repo->estates->length; i++) {
            toString(repo->estates->elems[i], s);
            printf("%s\n", s);
        }
    }
}

void print_menu()
{
    printf("> 1.ADD ESTATE\n> 2.PRINT ALL ESTATES\n> 3.DELETE ESTATE\n> 4.UPDATE ESTATE\n> 5.FILTER BY KEYWORD ADDRESS ASCENDING BY PRICE\n> 6.SEE THE ESTATES OF A GIVEN TYPE HAVING A MINUMUM GIVEN SURFACE\n> 7.LAB ACTIVITY\n> 8.UNDO\n> 9.REDO\n> 0.EXIT\n");
}

void run(UI* ui)
{
    first_estates(ui);
    print_menu();
    while (1)
    {
        int cmd = get_integer("> Please give a command: ");
        if (valid_command(cmd) == 0)
        {
            printf("> Invalid command! Try again using a given integer\n");
            continue;
        }
        if (cmd == 0)
        {
            break;
        }
        switch (cmd)
        {
            case 1: {
                add_ui(ui);
                break;
            }
            case 2:
            {
                print_estates(ui); 
                break;
            }
            case 3:
            {
                delete_ui(ui);
                break;
            }
            case 4:
            {
                update_ui(ui);
                break;
            }
            case 5:
            {
                filter_by_address(ui);
                break;
            }
            case 6:
            {
                filter_c(ui);
                break;
            }
            case 7:
            {
                filter_l(ui);
                break;
            }
            case 8:
            {
                int res = undo(ui->ctrl);
                if (res == 0)
                    printf("> Cannot undo more!\n");
                break;
            }
            case 9:
            {
                int res = redo(ui->ctrl);
                if (res == 0)
                    printf("> Cannot redo more!\n");
                break;
            }
        }
        
        
    }
    
}
