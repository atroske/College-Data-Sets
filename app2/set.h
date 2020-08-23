/*
 * File:        set.h
 *
 * Copyright:	2017, Darren C. Atkinson
 *
 * Description: This file contains the public function and type
 *              declarations for a set abstract data type for strings.  A
 *              set is an unordered collection of distinct elements.
 */

# ifndef SET_H
# define SET_H

typedef struct set SET;

SET *createSet(int maxElts);

void destroySet(SET *sp);

void addStudent(SET *sp, int age,int id);

void removeStudent(SET *sp, int id);

int searchID(SET *sp, int id);


# endif /* SET_H */
