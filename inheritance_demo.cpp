#include<iostream>
#include<string>
using namespace std;

class Animal {
private:
    string name;

public:
    // CONSTRUCTOR
    Animal(string n) : name(n) {} 

    // Getter
    string getName() const {
        return name;
    }

    // Virtual allows overriding in derived classes
    virtual void speak() const {
        cout << "Some generic animal sound" << endl;
    }
}; // <-- Added closing semicolon for Animal

// Dog is now OUTSIDE of Animal
class Dog : public Animal { 
public:
    Dog(string n) : Animal(n) {}

    // Overrode the speak method inside the Dog class
    void speak() const override {
        cout << "Scooby my name is " << getName() << endl;
    }

    void bark() const {
        cout << "le minions" << endl;
    }
}; // <-- Added missing semicolon for Dog

int main() {
    // Testing the BASE class
    Animal a("Generic");
    a.speak();

    // Testing the DERIVED class (Dog)
    Dog d("Rex");
    d.speak();  
    d.bark();   

    // PROOF that the getter works:
    cout << "Dog's name from getter: " << d.getName() << endl;

    return 0;
} // <-- Added missing closing brace for main

