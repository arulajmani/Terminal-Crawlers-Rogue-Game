bool checkedGrid[numRows][numCols] = {{ false }};

// static chamberNum parameter


void Floor::makeChamber() {
	vector<pair<int, int>> v;
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			v.clear();
			if(theBoard[i][j] == '.' && checkedGrid[i][j] == false) {
				shared_ptr<Chamber> newChamber = new Chamber(chamberNum, v);
				recursiveChamber(i, j, newChamber);
				chamberVec.emplace_back(newChamber);
				++chamberNum;
				checkedGrid[i][j] = true;
			}
			checkedGrid[i][j] = true;
		}
	}
}


void Floor::recursiveChamber(int xcoord, int ycoord, shared_ptr<Chamber> newChamber) {

	if(xcoord < 0 || ycoord < 0 || xcoord >= numRows || ycoord >= numCols) {return;}

	checkedGrid[xcoord][ycoord] = true;
	pair<int, int> validChamCoords {xcoord, ycoord};
	if(theBoard[xcoord][ycoord] == '.') {
		newChamber.chamberCoords.emplace_back(validChamCoords);
	}
	if(theBoard[xcoord + 1][ycoord] == '.' && checkedGrid[xcoord + 1][ycoord] ==  false) {
		recursiveChamber(xcoord + 1, ycoord, newChamber);
	}
	if(theBoard[xcoord - 1][ycoord] == '.' && checkedGrid[xcoord - 1][ycoord] == false) {
		recursiveChamber(xcoord - 1, ycoord, newChamber);
	}
	if(theBoard[xcoord][ycoord + 1] == '.' && checkedGrid[xcoord][ycoord + 1] == false) {
		recursiveChamber(xcoord, ycoord + 1, newChamber);
	}
	if(theBoard[xcoord][ycoord - 1] == '.' && checkedGrid[xcoord][ycoord - 1] == false) {
		recursiveChamber(xcoord, ycoord - 1, newChamber)
	}

}