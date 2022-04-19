/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:04:09 by ctardy            #+#    #+#             */
/*   Updated: 2022/04/19 15:05:52 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct mlist {
    char *fullname;
    struct mlist *next;
} mlist_t;
 
void removeNodes(mlist_t *first) {
    mlist_t *curptr;
     
    while(first) {
        curptr=first;
        first=first->next;
        free(curptr->fullname);
        free(curptr);
    }
}
 
void displayNodes(mlist_t *first) {
    while(first) {
        printf("%s\n",first->fullname);
        first=first->next;
    }
}
 
// Create a new node
mlist_t *newNode(char *fullname) {
    mlist_t *new;
     
    new=malloc(sizeof(*new));
    if(new) {
        memset(new,0,sizeof(*new));
        new->fullname=malloc(strlen(fullname)+1);
        if(!new->fullname) {
            free(new);
            return(NULL);
        }
        strcpy(new->fullname,fullname);
    }
    return(new);
}
 
// Insert fullname at end of list
mlist_t *insertNode(mlist_t **first,mlist_t **last,char *fullname) {
    mlist_t *new;
     
    new=newNode(fullname);
    if(new) {
        if(*first==NULL) *first=new;
        else (*last)->next=new;
        *last=new;
    }
    return(new);
}
 
// Calling
int main(void) {
    mlist_t *firstnode,*lastnode;
     
    firstnode=NULL;
    lastnode=NULL;
     
    for(....) {
        ....        // Do some job to obtain a string (called fullname, let's say)
        if(!insertNode(&firstnode,&lastnode,fullname))
            // treat error on insert
        ....
    }
    displayNodes(firstnode);
    removeNodes(firstnode);
     
    return(0);
}