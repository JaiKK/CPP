#include<iostream>
#include<memory>

class Rectangle{
    int lenght;
    int breadth;

    public:
        Rectangle(int l, int b){
            lenght = l;
            breadth = b;
        }

        int area(){
            return lenght * breadth;
        }

};

int main(){
    
    // Safer way to create unique pointer is to use make_unique function for exception handling;
    std::unique_ptr<Rectangle> SaferP1 = std::make_unique<Rectangle>(10,50);
    std::cout << SaferP1->area() << std::endl;
 
 
    std::unique_ptr<Rectangle> P1( new Rectangle(10,5) );

    // Below line will not work as unique pointer cannot be copied
    // std::unique_ptr<Rectangle> P2( P1 );
    
    // P1 pointer can access instance
    std::cout << "area from P1 :" << P1->area() << std::endl;

    // transfer control to P2
    std::unique_ptr<Rectangle> P2 = std::move(P1);
    
    // P2 pointer can access instance
    std::cout << "area from P2 :" << P2->area() << std::endl;
    
    // P1 pointer cannot access instance as it alreacy transfer the control
    std::cout << "area from P1 :" << P1->area() << std::endl;

    return 0;
}