#pragma once

#include <iostream>

namespace ColorLib 
{

	void clear() {
		system("cls");
		system("color 0F");
	}

	void DisplayColor(bool result) {
 
		if (result) {
			system("color 2F");
		}
		else {
			system("color 4F");
		}
	}

}