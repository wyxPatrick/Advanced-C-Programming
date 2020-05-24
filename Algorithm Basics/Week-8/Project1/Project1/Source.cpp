#include <iostream>
#include <bitset>
#include <memory.h>
using namespace std;

int Puzzle[6][6] = { 0 }, FlipBlack[6][6] = { 0 }, FlipWhite[6][6] = { 0 };
int MinStep = 10000;

bool AllBlack(int row) {
	for (int i = row; i < 5; i++) 
		for (int j = 1; j < 5; j++)
			if ((Puzzle[i][j] + FlipWhite[i][j] + FlipWhite[i][j - 1] + FlipWhite[i][j + 1] + FlipWhite[i - 1][j]) % 2 == 0)
				return false;
	return true;
}

bool AllWhite(int row) {
	for (int i = row; i < 5; i++)
		for (int j = 1; j < 5; j++)
			if ((Puzzle[i][j] + FlipBlack[i][j] + FlipBlack[i][j - 1] + FlipBlack[i][j + 1] + FlipBlack[i - 1][j]) % 2 == 1)
				return false;
	return true;
}

void fun(int StepForBlk, int StepForWt) {
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 5; j++) {
			FlipBlack[i + 1][j] = (Puzzle[i][j] + FlipBlack[i][j] + FlipBlack[i][j - 1] + FlipBlack[i][j + 1] + FlipBlack[i - 1][j]) % 2;
			if (FlipBlack[i + 1][j] == 1) StepForBlk++;
			FlipWhite[i + 1][j] = (Puzzle[i][j] + FlipWhite[i][j] + FlipWhite[i][j - 1] + FlipWhite[i][j + 1] + FlipWhite[i - 1][j] + 1) % 2;
			if (FlipWhite[i + 1][j] == 1) StepForWt++;
		}
	if (AllBlack(4))
		if (StepForWt < MinStep)
			MinStep = StepForWt;
	if (AllWhite(4))
		if (StepForBlk < MinStep)
			MinStep = StepForBlk;
}

int main() {
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'b') Puzzle[i][j] = 1;
		}
	if (AllBlack(1) || AllWhite(1)) cout << "0" << endl;
	else {
		for (int i = 0; i < 16; i++) {
			bitset<4>firstRow(i);
			for (int j = 1; j < 5; j++) {
				FlipBlack[1][j] = firstRow[j - 1];
				FlipWhite[1][j] = firstRow[j - 1];
			}
			int Count = firstRow.count();
			fun(Count, Count);
			memset(FlipBlack, 0, sizeof(FlipBlack));
			memset(FlipWhite, 0, sizeof(FlipWhite));
		}
		if (MinStep == 10000) cout << "Impossible" << endl;
		else cout << MinStep << endl;
	}
	return 0;
}