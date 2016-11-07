// Native implementation without sparse matrix

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class DlxMatrix
{
	vector<vector<int> > _origMatrix;
	vector<vector<int> > _solnMatrix;
	size_t _noRows;
	size_t _noCols;
	public:
	DlxMatrix(const set<set<int> >& iInputSet, size_t iMaxValue)
	{
		_noRows = iInputSet.size();
		_noCols = iMaxValue;
		for(const auto& aRow: iInputSet)
		{
			vector<int> aVecRow;
			aVecRow.reserve(iMaxValue);
			for(int i = 1; i <= iMaxValue; ++i)
			{
				if(std::find(aRow.begin(), aRow.end(), i) != aRow.end())
				{
					aVecRow.push_back(1);
				}
				else
				{
					aVecRow.push_back(0);
				}
			}
			_origMatrix.push_back(aVecRow);
		}
		_solnMatrix = _origMatrix;
	}

	void displayMatrix()
	{
		for(const auto& iRow : _origMatrix)
		{
			for(auto iCol : iRow)
			{
				cout << iCol << "\t";
			}
			cout << endl;
		}
	}

	const vector<vector<int>> & getMatrix()
	{
		return _solnMatrix; 
	}

	vector<vector<int>>& accessMatrix()
	{
		return _solnMatrix;
	}


};

void displayMatrix(const vector<vector<int>>& iMatrix)
{
	for(const auto& iRow : iMatrix)
	{
		for(auto iCol : iRow)
		{
			cout << iCol << "\t";
		}
		cout << endl;
	}
}


int find_column_with_min_1s(const vector<vector<int>>& iSolnMatrix)
{
	int aMin = 100;
	int aColNo = 0;
	for(size_t i = 0; i < iSolnMatrix.begin()->size(); ++i)
	{
		int aCount = 0;
		for(size_t j = 0; j < iSolnMatrix.size(); ++j)
		{
			if(iSolnMatrix[j][i] == 1)
			{
				aCount++;
			}
		}
		if(aCount < aMin)
		{
			aMin = aCount;
			aColNo = i;
		}
	}
	return aColNo;
}

set<int> find_1s_in_row(const vector<vector<int>>& iMatrix, int iRowNo)
{
	set<int> aSol;
	int i = 0;
	for(const auto aCol : iMatrix[iRowNo])
	{
		if ( aCol == 1 )
		{
			aSol.insert(i);
		}
		i++;
	}
	return aSol;
}

set<int> find_rows_with_1s_at_col(const vector<vector<int>>& iMatrix, int iColNo)
{
	set<int> aSol;
	for(int i = 0; i < iMatrix.size(); ++i)
	{
		if(iMatrix.at(i).at(iColNo) == 1)
		{
			aSol.insert(i);
		}
	}
	return aSol;
}

void displaySet(const set<int>& iSet)
{
	for(const auto i: iSet)
	{
		cout << i << "\t"; 
	}
	cout << endl;
}

void update_soln_matrix(vector<vector<int>>& ioSolnMatrix, int iRowNumber)
{
	const set<int>& aCols = find_1s_in_row(ioSolnMatrix, iRowNumber);
	set<int> aRowsToBeDeleted;
	for(const auto i : aCols)
	{
		const set<int>& aRows = find_rows_with_1s_at_col(ioSolnMatrix, i);
		aRowsToBeDeleted.insert(aRows.begin(), aRows.end());
	}
	for(int i = ioSolnMatrix.size()-1; i >= 0; --i)
	{
		if(std::find(aRowsToBeDeleted.begin(), aRowsToBeDeleted.end(), i) != aRowsToBeDeleted.end())
		{
			ioSolnMatrix.erase(ioSolnMatrix.begin()+i);
		}
	}

	for(auto & aRow: ioSolnMatrix)
	{
		for(int i = aRow.size()-1; i >= 0 ; --i)
		{
			if(std::find(aCols.begin(), aCols.end(),i) != aCols.end())
			{
				aRow.erase(aRow.begin()+i);
			}
		}
	}
	cout << "Updated Matrix " << endl;
	displayMatrix(ioSolnMatrix);
}

set<set<int>> get_all_solutions(vector<vector<int>>& iInput)
{
	
}

int main()
{
	set<set<int> > aInputSet = {{1, 4, 7},{1, 4},{4, 5, 7},{3, 5, 6},{2, 3, 6, 7},{2, 7}};
	DlxMatrix aMatrix(aInputSet,7);
	aMatrix.displayMatrix();
	cout << endl << "Column with minimum 1s is : " << find_column_with_min_1s(aMatrix.getMatrix()) << endl;
	update_soln_matrix(aMatrix.accessMatrix(),0);
}

