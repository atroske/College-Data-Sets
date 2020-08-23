/*
 */

# ifndef LIST_H
# define LIST_H

typedef struct list LIST;

extern LIST *createList();

extern void destroyList(LIST *lp);

extern void addStudent(LIST *lp, int age, int id);

extern void removeStudent(LIST *lp, int id);

extern void searchID(LIST *lp, int id);

extern void searchAge(LIST *lp, int age);

extern int maxAgeGap(LIST *lp);

# endif /* LIST_H */
