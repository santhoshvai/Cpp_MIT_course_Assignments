

int factorial (int n) {
	int i = 1;
	while (n > 1) {
		i = i * n;
		n = n - 1; // remove the int ... it becomes a local scope if int n is there
	}
	return i;
}
