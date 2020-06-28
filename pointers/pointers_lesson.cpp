#include<iostream>

//This function will create a copy of variable
void byVal(int x){
    std::cout << "(byVal)value: " << x << std::endl;
    std::cout << "(byVal)address: " << &x << std::endl;
}

//This function will not create a copy of variable
void byRef(int &x){
    std::cout << "(byRef)value: " << x << std::endl;
    std::cout << "(byRef)value: " << *(int *)&x << std::endl; // you can think of type casting of pointers as well 
    std::cout << "(byRef)address: " << &x << std::endl;
}

//This function will not create a copy of variable
void byPtr(int *x){
    std::cout << "(byPtr)value: " << x << std::endl;
    std::cout << "(byPtr)address: " << &x << std::endl;
    std::cout << "(byPtr)value of: " << *x << std::endl;    
    std::cout << "(byPtr)address value: " << *&x << std::endl;
}

int retByVal(){
    int x = 5; //This will allocate stack memory
    std::cout << "(retByVal)value: " << x << std::endl;
    std::cout << "(retByVal)address: " << &x << std::endl;
    return *(int*)&x;
}


//This function will not create a copy of variable
int* retByRef(){

    int* x = new int;
    *x = 5;
    std::cout << "(retByRef)value: " << x << std::endl;
    std::cout << "(retByRef)address: " << &x << std::endl;
    std::cout << "(retByRef)value of: " << *x << std::endl;        
    return x;    
}

/*
//This function will not create a copy of variable
int& retByPtr(int *x){
    std::cout << "(byPtr)value: " << x << std::endl;
    std::cout << "(byPtr)address: " << &x << std::endl;
    std::cout << "(byPtr)value of: " << *x << std::endl;    
    std::cout << "(byPtr)address value: " << *&x << std::endl;
}
*/

int main(){

    int x = 2;
    std::cout << "value: " << x << std::endl;
    std::cout << "address: " << &x << std::endl;
    std::cout << "value of: " << *&x << std::endl;
    std::cout << "address of: " << &(*(&x)) << std::endl;

    byVal(x);
    byRef(x);
    // byPtr(x); // This will result in compile error as converting from int to int*
    byPtr(&x);

    int x1 = retByVal();
    std::cout << "value of retByVal(): " << x1 << std::endl;
    
    

    return 0;
}