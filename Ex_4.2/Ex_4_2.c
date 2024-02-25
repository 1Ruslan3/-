#include<stdio.h>
#include<stdlib.h>

typedef int tvalue;

typedef struct bl_item {
    tvalue value;
    struct bl_item* next;
    struct bl_item* previous;
} bl_item;


typedef struct bl {
    bl_item* head;
    bl_item* tail;
} bl;


bl* create()
{
    bl* tmp = (bl*)malloc(sizeof(bl));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void delete(bl **list)
{
    bl_item* tmp = (*list)->head;
    bl_item* next = NULL;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
 }


void pushBack(bl* list, tvalue value)
{
    bl_item* tmp = (bl_item*)malloc(sizeof(bl_item));
    if (tmp == NULL)
    {
        return;
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->previous = list->tail;

    if (list->tail)
    {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL)
    {
        list->head = tmp;
    }

}

int pred(tvalue const* value)
{
    if ((*value) % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

tvalue foo(tvalue const* accumulator, tvalue const* next_value_from_list)
{
    tvalue tmp;
    tmp = (*accumulator) + (*next_value_from_list);
    return tmp;

}

int aggregate_by(bl const* from, int (*predicate)(tvalue const* value), tvalue accumulator_initial_value, tvalue
(*fold)(tvalue const* accumulator, tvalue const* next_value_from_list), tvalue* result)
{
    if (from == NULL)
    {
        return 1;
    };

    if (predicate == NULL)
    {
        return 2;
    };

    if (fold == NULL)
    {
        return 3;
    };

    if (result == NULL)
    {
        return 4;
    }

    bl_item* current_item = (bl_item*)malloc(sizeof(bl_item));
    if (current_item == NULL)
    {
        return 5;
    };

    current_item = from->tail;
    while (current_item != NULL)
    {
        if (predicate(&current_item->value) != 0)
        {
            //continue;
        accumulator_initial_value = fold
        (
            &accumulator_initial_value,
            &current_item->value
        );
        }
        current_item = current_item->previous;
    }

    *result = accumulator_initial_value;

    return 0;
}

int main()
{
	
    bl* start = create();
    if (start == NULL)
    {
        return 1;
    }
    tvalue result = 0;
   
    pushBack(start, 1);
    pushBack(start, 2);
    pushBack(start, 3);
    pushBack(start, 4);
    pushBack(start, 5);
    pushBack(start, 6);

    int x = aggregate_by(start, pred, 0, foo, &result);

    printf("%d\n", x);
    printf("%d", result);

    delete(&start);

    return 0;
}