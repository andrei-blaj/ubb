//
//  OperationStack.c
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "OperationStack.h"

Operation * create_operation(Estate* estate, char * type)
{
    Operation* op = (Operation*)malloc(sizeof(Operation));
    op->estate = copy_estate(estate);
    op->type = (char*)malloc(sizeof(char)*strlen(type) + 1);
    strcpy(op->type, type);
    
    return op;
}

void destroy_operation(Operation * op)
{
    destroy_estate(op->estate);
    
    free(op);
}

Operation * operation_copy(Operation * op)
{
    Operation* new_op = create_operation(get_operation_estate(op), get_operation_type(op));
    return new_op;
}

char * get_operation_type(Operation * op)
{
    return op->type;
}

Estate * get_operation_estate(Operation * op)
{
    return op->estate;
}

// -----------------------------------------------------

OperationStack* create_operation_stack()
{
    OperationStack* stack = (OperationStack*)malloc(sizeof(OperationStack));
    stack->length = 0;
    
    return stack;
}

void destroy_operation_stack(OperationStack* stack)
{
    for (int i = 0; i < stack->length; i++) {
        destroy_operation(stack->operations[i]);
    }
    
    free(stack);
}

void push(OperationStack* stack, Operation* op)
{
    if (stack->length == 100)
        return;
    stack->operations[stack->length] = operation_copy(op);
    stack->length++;
}

Operation* pop(OperationStack* stack)
{
    if (stack->length == 0)
        return NULL;
    Operation* op = stack->operations[stack->length - 1];
    stack->length--;
    
    return op;
}

