#pragma once

int main()
{
	int tree[ARRAY_LENGTH] = { 0 };			// array

	int input = 0;
	int i = 1;
	for (;i < ARRAY_LENGTH - 1;i++)
	{
		cin >> c;
		if (c == -1)
			break;
		tree[i] = c;
	}

	cout << isBST(tree);
	return 0;
}
