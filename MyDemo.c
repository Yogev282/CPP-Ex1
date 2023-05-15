#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>


int main() {
    // Create books and an adaptive array for books
    pbook b1 = creat_book("The Lord of the Rings", 11111);
    pbook b2 = creat_book("To Kill a Mockingbird", 22222);
    pbook b3 = creat_book("1984", 33333);
    pbook b4 = creat_book("Pride and Prejudice", 44444);

    PAdptArray mybooks = CreateAdptArray(copy_book, delete_book, print_book);
    SetAdptArrayAt(mybooks, 0, b1);
    SetAdptArrayAt(mybooks, 2, b2);
    SetAdptArrayAt(mybooks, 4, b3);
    SetAdptArrayAt(mybooks, 99999999, b4); // very big index

    printf("The size is %d\n", GetAdptArraySize(mybooks));  // should print 100000000

    pbook b = GetAdptArrayAt(mybooks, 3); // should return null
    assert(b == NULL); // doesn't fail
    pbook bb = GetAdptArrayAt(mybooks, 99999999); // should return null
    assert(bb == NULL); // doesn't fail


    b = GetAdptArrayAt(mybooks, 0);
    printf("The book is %s\n", b->name); // should print "The Lord of the Rings"

    PrintDB(mybooks);

    // Create persons and an adaptive array for persons
    pperson p1 = creat_person("John", "Doe", 123);
    pperson p2 = creat_person("Jane", "Smith", 456);
    pperson p3 = creat_person("Alice", "Johnson", 789);
    pperson p4 = creat_person("Bob", "Williams", 321);

    PAdptArray people = CreateAdptArray(copy_person, delete_person, print_person);
    SetAdptArrayAt(people, 1, p1);
    SetAdptArrayAt(people, 3, p2);
    SetAdptArrayAt(people, 5, p3);
    SetAdptArrayAt(people, 7, p4);

    printf("The size is %d\n", GetAdptArraySize(people)); // prints 8
    PrintDB(people); // prints:
    // first name: John last name: Doe id: 123
    // first name: Jane last name: Smith id: 456
    // first name: Alice last name: Johnson id: 789
    // first name: Bob last name: Williams id: 321

    // Delete the arrays and free memory
    DeleteAdptArray(mybooks);
    DeleteAdptArray(people);
    delete_book(b1);
    delete_book(b2);
    delete_book(b3);
    delete_book(b4);
    delete_book(b);
    delete_person(p1);
    delete_person(p2);
    delete_person(p3);
    delete_person(p4);

    return 0;
}
