#include<iostream>
#include<fstream>

using namespace std;

int task_1(fstream &input)
{
    string direction = "";

    int quantity = 0,
        depth = 0,
        horizontal = 0;

    while(input >> direction)
    {
        input >> quantity;
        if (direction[0] == 'f')
        {
            horizontal += quantity;
        }
        else if (direction[0] == 'd')
        {
            depth += quantity;
        }
        else
        {
            depth -= quantity;
        }

    }

    return (horizontal * depth);
}

int task_2(fstream &input)
{
    string direction = "";

    int quantity = 0,
        depth = 0,
        horizontal = 0,
        aim = 0;

    while(input >> direction)
    {
        input >> quantity;
        if (direction[0] == 'f')
        {
            horizontal += quantity;
            if (aim)
            {
                depth += quantity * aim;
            }
        }
        else if (direction[0] == 'd')
        {
            aim += quantity;
        }
        else
        {
            aim -= quantity;
        }

    }

    return (horizontal * depth);
}

int main()
{
    fstream input("./input1.txt", ios::in);
    int output = task_1(input);
    cout << "Task 1: If you multiply horizontal by depth will result " << output << "." << endl;
    input.close();

    input.open("./input2.txt", ios::in);
    output = task_2(input);
    cout << "Task 2: If you multiply horizontal by depth will result " << output << "." << endl;
    input.close();

    return 0;
}
