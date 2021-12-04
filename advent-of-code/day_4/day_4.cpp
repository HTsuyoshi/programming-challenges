#include<iostream>
#include<fstream>
#include<algorithm>
#include<unordered_map>
#include<tuple>
#include<stdlib.h>
#include<vector>
#include<sstream>

using namespace std;

struct verify_table
{
    int column[5] = { 0 };
    int line[5]   = { 0 };
};

class bingo_table
{
    public:

        //  (val),   (ver, hor)
        unordered_map<int, pair<int,int>>* unmarked_table;
        verify_table* occuped;
        int last_number;
        int won;

        void start(fstream &input);
        int insert(int mark);
        int do_the_win_stuff();

    private:

        int win();

        void fill_table(fstream &input);

        void init_occupied();
        void insert_occupied(pair<int, int>);
};
void bingo_table::start(fstream &input)
{
    won = 0;
    this->init_occupied();
    this->fill_table(input);
}

void bingo_table::init_occupied()
{
    this->occuped = (verify_table*) calloc(1, sizeof(verify_table));
}

void bingo_table::insert_occupied(pair<int,int> axis)
{
    occuped->line[axis.first]++;
    occuped->column[axis.second]++;
}

void bingo_table::fill_table(fstream &input)
{
    this->unmarked_table = new unordered_map<int, pair<int,int>>;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            int tmp;
            input >> tmp;
            this->unmarked_table->insert({tmp, make_pair(j, i)});
            //cout << tmp << ": ";
            //cout << unmarked_table->at(tmp).second << ",";
            //cout << unmarked_table->at(tmp).first << " ";
       }
       //cout << endl;
    }
}

int bingo_table::insert(int mark) {

    this->last_number = mark;
    if (unmarked_table->find(mark) != NULL)
    {
        pair<int, int> item_axis = unmarked_table->at(mark);
        this->insert_occupied(item_axis);
        this->unmarked_table->erase(mark);
    }
    return win();
}

int bingo_table::win() {
    for (int i=0; i<5; i++) {
        if (occuped->column[i] == 5
            || occuped->line[i] == 5) {
            this->won = 1;
            return 1;
        }
    }
    return 0;
}

int bingo_table::do_the_win_stuff()
{
    int sum = 0;
    for (auto& it : *this->unmarked_table) {
        sum += it.first;
    }
    return sum * last_number;

}

int task_1(int tables, fstream &input)
{
    // Get results
    string line;
    string number;
    getline(input, line);

    stringstream ss(line);
    vector<int> result;
    while (getline(ss, number, ',')) {
        result.emplace_back(stoi(number));
    }

    bingo_table *bingos = (bingo_table*) calloc (tables, sizeof(bingo_table));

    for (int i=0; i<tables; i++) {
        bingos[i].start(input);
    }

    for (int mark : result) {
        for (int i=0; i<tables; i++) {
            if (bingos[i].insert(mark)) {
                cout << "Table " << i << " have winned" << endl;
                return bingos[i].do_the_win_stuff();
           }
        }
    }

    return -1;
}

int task_2(int tables, fstream &input)
{
    // Get results
    string line;
    string number;
    getline(input, line);

    stringstream ss(line);
    vector<int> result;
    while (getline(ss, number, ',')) {
        result.emplace_back(stoi(number));
    }

    bingo_table *bingos = (bingo_table*) calloc (tables, sizeof(bingo_table));

    for (int i=0; i<tables; i++) {
        bingos[i].start(input);
    }

    int won_counter = 0;
    for (int mark : result) {
        for (int i=0; i<tables; i++) {
            if (bingos[i].won) continue;
            if (bingos[i].insert(mark)) {
                won_counter++;
                if (won_counter == tables) {
                    cout << "Table " << i << " have winned" << endl;
                    return bingos[i].do_the_win_stuff();
                }
           }
        }
    }

    return -1;
}

int main()
{
    fstream input("./input1_test.txt", ios::in);
    int output = task_1(3, input);
    cout << "example 1: " << output << "." << endl;
    input.close();

    input.open("./input1.txt", ios::in);
    output = task_1(100, input);
    cout << "task 1: " << output << "." << endl;
    input.close();

    input.open("./input1_test.txt", ios::in);
    output = task_2(3, input);
    cout << "example 2: " << output << "." << endl;
    input.close();

    input.open("./input2.txt", ios::in);
    output = task_2(100, input);
    cout << "task 2: " << output << "." << endl;
    input.close();

    return 0;
}
