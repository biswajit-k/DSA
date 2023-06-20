
/*
    Keypoints:
    -> best_cell => -1 means no cells left

*/

class Sudoku {

    vector<unordered_set<int>> row, col, box;
    vector<vector<char>> board;
    vector<int> nums;

    void fill_container(vector<unordered_set<int>>& container) {
        container.resize(9);
        for(auto& st: container)
            st = unordered_set<int>(begin(nums), end(nums));
    }

    int get_box(int i, int j) {
        int r = i / 3, c =  j / 3;
        return 3 * r + c;
    }

    int get_cell(int i, int j) {
        return 9 * i + j;
    }


    void update_choices(int i, int j, char new_val, char prev_val) {

        if(new_val == prev_val)  return;

        // if prev. val is number => add it to sets: row, col, box
        if(prev_val != '.')
        {
            int prev_num = prev_val - '0';
            row[i].insert(prev_num);
            col[j].insert(prev_num);
            box[get_box(i, j)].insert(prev_num);
        }

        // if new val is number => remove it from sets: row, col, box
        if(new_val != '.')
        {
            int new_num = new_val - '0';
            row[i].erase(new_num);
            col[j].erase(new_num);
            box[get_box(i, j)].erase(new_num);
        }
    }

    int find_best_cell() {

        int best_cell = -1, least_choices = INT_MAX, curr_choices;

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    curr_choices = 0;
                    for(auto& x: row[i])
                        if(col[j].count(x) && box[get_box(i, j)].count(x))
                            curr_choices++;
                    
                    if(curr_choices < least_choices)
                        best_cell = get_cell(i, j), least_choices = curr_choices;
                }   
            }

        return best_cell;
    }

    unordered_set<int> get_choices(int i, int j) {
        unordered_set<int> choices;
        for(auto& x: row[i])
            if(col[j].count(x) && box[get_box(i, j)].count(x))
                choices.insert(x);
        
        return choices;
    }

public:
    Sudoku(vector<vector<char>>& board) {
        this -> board = board;
        nums.resize(9);
        iota(nums.begin(), nums.end(), 1);

        fill_container(row);
        fill_container(col);
        fill_container(box);

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                update_choices(i, j, board[i][j], '.');

    }

    bool solve() {

        int cell = find_best_cell();        // finds the empty cell with least no. of choices
        if(cell == -1)
            return true;

        int r = cell / 9, c = cell % 9;

        for(auto& choice: get_choices(r, c)) 
        {
            board[r][c] = choice + '0';
            update_choices(r, c, choice + '0', '.');
            if(solve())
                return true;
            board[r][c] = '.';
            update_choices(r, c, '.', choice + '0');
        }

        return false;
    }

    vector<vector<char>>& get_board() {
        return board;
    }

};

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        Sudoku my_sudoku(board);
        my_sudoku.solve();

        board = my_sudoku.get_board();   
    }
};