bool isSafe(int row,int col,vector<vector<int>>& board,int val){
    int n=board.size();
    for(int i=0;i<n;i++){
        if(board[row][i]==val){
            return false;
        }
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    int n=board[0].size();
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(board[row][col]==0)
            {
                for(int val=1;val<10;val++)
                {
                    if(isSafe(row,col, board, val))
                    {
                        board[row][col]=val;
                        bool PossibleSolution=solve(board);
                        if(PossibleSolution)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
