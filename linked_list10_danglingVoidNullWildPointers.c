#include <stdio.h>
#include <stdlib.h>

//A pointer can be a dangling pointer in 3 ways:
//1. after freeing the memory
//2. function call
//3. pointer used out of its scope

/*
int main()
{   //allocate the memory
    int* ptr= (int*)malloc(sizeof(int));
    //dangling pointer
    free(ptr);
    //not more a dangling pointer
    ptr=NULL;
    printf ("%d", ptr);
    return 0;
}
*/

//2. function call
/*
int *fun(){
    //non static variable will have local scope only and will be called on a local stack only
    int x= 7;
    
    return &x;
}

int main(){
    //will not have the pointer to the variable x because the x is deleted from the stack when the fun() is returned
    int* p= fun();
    fflush(stdin);
    printf("%d", *p);
    return 0;
}
*/

/*
int *fun(){
    // static variable will have global scope now and will be called on a global stack
    static int x= 8;
    
    return &x;
}

int main(){
    //will have the pointer to the variable x because the x is still present in the global stack
    int* p= fun();
    fflush(stdin);
    printf("%d", *p);
    return 0;
}
*/

//3.pointer used out of its scope
void main()
{
   int *ptr;
   {
       int ch;
       ptr = &ch;
   }    
   // Here ptr is dangling pointer
}

//Void Pointer
#include<stdlib.h>
  
int main()
{
    int x = 4;
    float y = 5.5;
      
    //A void pointer
    void *ptr;
    ptr = &x;
  
    // (int*)ptr - does type casting of void 
    // *((int*)ptr) dereferences the typecasted 
    // void pointer variable.
    printf("Integer variable is = %d", *( (int*) ptr) );
  
    // void pointer is now float
    ptr = &y; 
    printf("\nFloat variable is= %f", *( (float*) ptr) );
  
    return 0;
}

//NULL pointer
#include <stdio.h>
int main()
{
	// Null Pointer
	int *ptr = NULL;
	
	printf("The value of ptr is %p", ptr);
	return 0;
}

//wild pointer
int main()
{
	int *p; /* wild pointer */

	int x = 10;

	// p is not a wild pointer now
	p = &x;

	return 0;
}
