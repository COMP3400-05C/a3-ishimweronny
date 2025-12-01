#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 * Returns the last node (tail) of the linked list. 
 * If the list is empty, returns NULL.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if(head==NULL) {
        return NULL;

    }
    while (head->next !=NULL){

    }
        head=head->next;
    
    return head;
}



/**
 * TODO: Describe what the function does
 * Counts and returns the number of nodes in the linked list.
 */
int ll_size(struct ll_node *head) {
     int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
  
}

/**
 * TODO: Describe what the function does
 * Finds and returns the first node containing the given value.
 * if the value is not found, returns NULL.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
     while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
   
}

/**
 * TODO: Describe what the function does
 * Converts the linked list to a dynamically allocated int array.
 * Returns a pointer to the array, or NULL if the list is empty.
 */
int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0) {
        return NULL;
    }

    int *arr = malloc(sizeof(int) * size);
    int i = 0;

    while (head != NULL) {
        arr[i++] = head->data;
        head = head->next;
    }

    return arr;
   
}

/**
 * TODO: Describe what the function does
 * Creates a new linked list node with the given data.
 * Returns the newly created node.
 */
struct ll_node *ll_create(int data) {
     struct ll_node *node = malloc(sizeof(struct ll_node));
    if (!node) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
   
}

/**
 * TODO: Describe what the function does
 *  Frees all nodes in the linked list from memory.
 */
void ll_destroy(struct ll_node *head) {
     while (head != NULL) {
        struct ll_node *next = head->next;
        free(head);
        head = next;
    }
    
}
/**
 * TODO: Describe what the function does
 * Appends a new node with the given data to the end of the list.
 */
void ll_append(struct ll_node *head, int data) {

    struct ll_node *tail = ll_tail(head);
    struct ll_node *newnode = ll_create(data);

    if (tail != NULL) {
        tail->next = newnode;
    }


 
}

/**
 * TODO: Describe what the function does
 * Creates a linked list from an array of integers.
 * Returns the head of the linked list.
 * If the array is empty, returns NULL.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (len == 0) return NULL;

    struct ll_node *head = ll_create(data[0]);
    struct ll_node *curr = head;

    for (int i = 1; i < len; i++) {
        curr->next = ll_create(data[i]);
        curr = curr->next;
    }

    return head;

}

/**
 * TODO: Describe what the function does
 * Removes the first node with the given value from the list.
 * Returns the (possibly new) head of the list.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {

      if (head == NULL) return NULL;

    // If removing the head
    if (head->data == value) {
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }

    struct ll_node *prev = head;
    struct ll_node *curr = head->next;

    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head; // Value not found
}

