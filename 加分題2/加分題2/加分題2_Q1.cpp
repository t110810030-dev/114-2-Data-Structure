#include <vector>
using namespace std;
class Solution{
public:
    bool isValidSudoku(vector<vector<char>>&board){
        //檢查列
        for(int i=0;i<9;i++){
            bool seen[10]={false};
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){//只檢查數字
                    int num=board[i][j]-'0';
                    if(seen[num])return false;//有重複出現
                    seen[num]=true;//沒有重複出現
                }
            }
        }
        //檢查行
        for(int j=0;j<9;j++){
            bool seen[10]={false};
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    if(seen[num])return false;
                    seen[num]=true;
                }
            }
        }
        //檢查9宮格
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                bool seen[10]={false};
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j]!='.'){
                            int num=board[i][j]-'0';
                            if(seen[num])return false;
                            seen[num]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
