#ifndef DECLARATIONS_H
#define DECLARATIONS_H

struct Stablo;
typedef struct Stablo* Position;
typedef struct Stablo{
    int num;
    Position left;
    Position right;
}cvor;

struct Queue;
typedef struct Queue* positionQ;
typedef struct Queue{
    Position leaf;
    positionQ next;
}queue;

int Push(positionQ head, Position current);
int Pop(positionQ head);

Position insert(Position current, Position newEl);
Position createElem();

Position deleteCvor(Position root, int selected);
Position FindMin(Position current);

int InOrderPrint(Position root);
int PreOrderPrint(Position root);
int PostOrderPrint(Position root);
int LevelOrderPrint(Position root);
Position freeTree(Position root);

#endif
