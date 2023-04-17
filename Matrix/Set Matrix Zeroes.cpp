// Brute Force
class Solution {
public:
    void markRow(int row,int n,vector<vector<int>>& matrix){
        for(int i=0;i<n;i++){
            if(matrix[row][i]!=0) matrix[row][i]=-4;
        }
    }
    void markCol(int col,int m,vector<vector<int>>& matrix){
        for(int i=0;i<m;i++){
            if(matrix[i][col]!=0) matrix[i][col]=-4;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    markRow(i,n,matrix);
                    markCol(j,m,matrix);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-4){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// Better
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1) matrix[i][j]=0;
                if(col[j]==1) matrix[i][j]=0;
            }
        }
    }
};