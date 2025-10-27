/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "include/exercise2.h"

node* isort(node* list) {

    node * head = list;
    node * curr_node = head;
    node * prior_node;
    node * temp;

    while (curr_node->next != NULL){ // kører så længe der findes en næste node
        
        if (curr_node->next->data < curr_node->data){ // hvis den næste node har en værdi mindre end den node vi kigger på
            temp = curr_node->next; // gem noden
            curr_node->next = curr_node->next->next; // gør klar til næste runde


            // vi sætter nu noden ind
            if (temp->data <= head->data){  // hvis noden er mindre end første node
                temp->next = head;
                head = temp;
            }

            else{ // hvis den ikke er mindre end første skal vi finde hvor i listen den skal ligge

                curr_node = head->next;
                prior_node = head;

                while(curr_node->next != NULL){

                    if (temp->data < curr_node->data){
                        prior_node->next = temp;
                        temp->next = curr_node;
                        break;
                    }

                    prior_node = curr_node;
                    curr_node = curr_node->next;
                }

                if (curr_node->next == NULL){ // hvis noden der skal indsættes er den anden største i listen
                    prior_node->next = temp;
                    temp->next = curr_node;
                }
            }
        }
        else{
            curr_node = curr_node->next;
        }
    }
    return head; // Placeholder implementation
}


/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
