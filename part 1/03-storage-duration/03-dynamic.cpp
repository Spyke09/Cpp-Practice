#include <iostream>
#include <vector>

int main() {
    int *data = new int; // Dynamic starage duration
                         // "На куче (heap)"
    int *data = new int;    // непроинициализирован 
    int *data = new int();  // проинизиализирован
    delete data;

}