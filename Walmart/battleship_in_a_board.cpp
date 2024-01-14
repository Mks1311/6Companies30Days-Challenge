class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        set<pair<int,int>>st;
        int cnt=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X' && st.find({i,j})==st.end()){
                    cnt++;
                    st.insert({i,j});
                    int row=i+1,col=j;
                    while(row<board.size()&&board[row][col]=='X'){
                        st.insert({row,col});
                        row++;
                    }
                    row=i,col=j+1;
                    while(col<board[0].size()&&board[row][col]=='X'){
                        st.insert({row,col});
                        col++;
                    }
                }
            }
        }
        return cnt;
    }
};