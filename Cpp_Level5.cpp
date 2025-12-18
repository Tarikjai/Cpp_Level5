#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

void  printTitle() {
	cout << "\t\t\tMultiplication Table From 1 to 10 \n";
	cout <<" \n";
	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i ;
	}
	cout << " \n";
	cout << "----------------------------------------------------------------------------------\n";
	
}

void printTable() {

	

		

			for (int i = 1; i <= 10; i++) {
				if (i < 10) {
					cout << 1 * i << "   | ";
				}
				else {
					cout << 1 * i << "  | ";
				}
					
				for (int j = 1; j <= 10; j++) {
					cout << "\t" << j * i ;
				}
				cout << endl;
			}
	
		   




	


}


int main() {
	
	
	printTitle();
	printTable();
}
 