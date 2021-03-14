// Демина Виктория Алексеевна  М80-206Б-19
#include "mlisp.h"

extern double dd;
extern double mm;
extern double yyyy;

double day__of__week();
double zeller(int d, int m, int y, int c);
double neg__to__pos(int d);
double birthday(int dw);


double day__of__week() {
	return zeller(dd,
		mm > 3. ? mm + 10. : mm - 2.,
		remainder(mm < 3. ? yyyy - 1. : yyyy, 100.),
		quotient(mm < 3. ? yyyy - 1. : yyyy, 100.)
	);

}

double zeller(int d, int m, int y, int c) {
	return neg__to__pos(remainder(d + y + quotient(26 * m - 2, 10) + quotient(y, 4) + quotient(c, 4), 7));
}

double neg__to__pos(int d) {
	return (d < 0. ? d + 7.
		: true ? d
		: _infinity
		);
}

double birthday(int dw) {
	display("Your were born on ");
	display(dw == 1. ? "Monday "
		: dw == 2. ? "Tuesday "
		: dw == 3. ? "Wednesday "
		: dw == 4. ? "Thursday "
		: dw == 5. ? "Friday "
		: dw == 6. ? "Saturday "
		: "Sunday ");
	display(dd); display(".");
	display(mm); display(".");

	return  yyyy;
}


double dd = 31;
double mm = 7;
double yyyy = 2001;


int main() {
	display(birthday(day__of__week()));
	newline();
	std::cin.get();
	return 0;
}
