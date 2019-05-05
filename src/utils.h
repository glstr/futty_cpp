
#pragma once

// A macro to disallow the copy constructor and operator= functions
// This should be used in the priavte:declarations for a class
#define    DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);                \
    TypeName& operator=(const TypeName&)

typedef int(*add_func)(int, int);
int t_add(int a, int b);
void t_add_more();



