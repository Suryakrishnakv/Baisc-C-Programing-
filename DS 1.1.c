#include <stdio.h> 
extern int global_var; 
void demoAuto()  
{ 
    auto int auto_var = 5;  
    printf("Auto variable: %d\n", auto_var); 
} 
void demoRegister()  
{ 
    register int reg_var = 10; 
    printf("Register variable: %d\n", reg_var); 
} 
void demoStatic()  
{ 
    static int static_var = 0; 
    static_var++; 
    printf("Static variable: %d\n", static_var); 
} 
void demoExtern()  
{ 
    printf("Extern variable: %d\n", global_var); 
} 
int global_var = 100;  
int main()  
{ 
    printf("Storage Classes in C\n"); 
    demoAuto();    
    demoRegister();  
    demoStatic();  
    demoExtern();  
    return 0; 
} 

