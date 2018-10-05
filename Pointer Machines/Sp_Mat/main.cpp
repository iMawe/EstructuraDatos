int main()
{
	sparse_matrix<int> S(10,10);

	S(2, 8) = 2;
	S(3, 2) = 3;
	S(5, 7) = 1;
	S(3, 2) = 4;
	S.print(1);

	
	return 0;
}