

void squareByVal(int num) {
	num = num * num;
}

void squareByRef(int* num) {
	(*num) = (*num) * (*num);
}
