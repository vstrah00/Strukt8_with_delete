#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "declarations.h"

Position insert(Position current, Position newEl){
    if(current==NULL){
        current = newEl;
    }
    else if(current->num < newEl->num){
        current->right=insert(current->right, newEl);
    }
    else if(current->num > newEl->num){
        current->left=insert(current->left, newEl);
    }
    else{
        printf("New element is a duplicate!");
        free(newEl);
    }
    return current;
}


Position createElem(){
    Position newEl=NULL;
    int numb=0;

    printf("Input new element number:\t");
    scanf(" %d", &numb);

    newEl=(Position)malloc(sizeof(cvor));
    if(newEl==NULL){
        printf("Cannot allocate memory!");
        return NULL;
    }

    newEl->num=numb;
    newEl->left=NULL;
    newEl->right=NULL;

    return newEl;
}

Position deleteCvor(Position root, int selected){
    Position temp=NULL;

    if(root==NULL){
        printf("This number was not stored\n");
    }
    else if(root->num > selected){
        root->left=deleteCvor(root->left, selected);
    }
    else if(root->num < selected){
        root->right=deleteCvor(root->right, selected);
    }
    else if(root->left!=NULL && root->right!=NULL){
        temp=FindMin(root->right);
        root->num=temp->num;
        root->right=deleteCvor(root->right, root->num);
    }
    else{
        temp=root;
        if(root->left==NULL){
            root=root->right;
        }
        else
            root=root->left;

        free(temp);
    }
    return root;
}

Position FindMin(Position current){
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}


int InOrderPrint(Position root){
    if(root!=NULL){
        if(root->left!=NULL){
            InOrderPrint(root->left);
        }

        printf(" %d", root->num);

        if(root->right!=NULL){
            InOrderPrint(root->right);
        }
    }
    else{
        printf("The tree is empty!");
    }
    return 0;
}

int PreOrderPrint(Position root){
    if(root!=NULL){
        printf(" %d", root->num);
        if(root->left!=NULL){
            PreOrderPrint(root->left);
        }
        if(root->right!=NULL){
            PreOrderPrint(root->right);
        }
    }
    else{
        printf("The tree is empty!");
    }
    return 0;
}

int PostOrderPrint(Position root){
    if(root!=NULL){
        if(root->left!=NULL){
            PostOrderPrint(root->left);
        }
        if(root->right!=NULL){
            PostOrderPrint(root->right);
        }
        printf(" %d", root->num);
    }
    else{
        printf("The tree is empty!");
    }
    return 0;
}

int LevelOrderPrint(Position root){
    queue headOfQueue={.leaf=NULL, .next=NULL};
    positionQ head=&headOfQueue;
    Position current=NULL;
    int check=0;

    if(root==NULL){
        printf("The tree is empty\n\n");
        return 0;
    }
    check=Push(head, root);
    if(check<0)
        return -1;

    while(head->next){
        current=head->next->leaf;
        printf("%d ", current->num);
        Pop(head);
        if(current->left){
            check=Push(head, current->left);
            if(check<0)
                return -1;
        }
        if(current->right){
            check=Push(head, current->right);
            if(check<0)
                return -1;
        }

    }

    return 0;
}

int Push(positionQ head, Position current){
    positionQ temp=head;
    positionQ newEl=NULL;

    newEl=(positionQ)malloc(sizeof(queue));
    if(newEl==NULL){
        return -1;
    }
    while(temp->next){
        temp=temp->next;
    }

    newEl->next=temp->next;
    temp->next=newEl;

    newEl->leaf=current;

    return 0;
}

int Pop(positionQ head){
    positionQ temp=NULL;
    if(head->next!=NULL){
        temp=head->next;
        head->next=temp->next;
        free(temp);
    }
    return 0;
}

int freeTree(Position root){
    if(root!=NULL){
        if(root->left!=NULL){
            freeTree(root->left);
        }
        if(root->right!=NULL){
            freeTree(root->right);
        }
        free(root);
    }

    return 0;
}
