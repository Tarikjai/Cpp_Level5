#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

 


int main() {
    srand(time(nullptr));   // initialise la graine une seule fois

    int nombre = rand() % 10 + 1;   // nombre entre 1 et 10

    cout << "Nombre aleatoire : " << nombre << endl;

}