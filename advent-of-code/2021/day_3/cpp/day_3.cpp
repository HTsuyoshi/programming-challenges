#include<iostream>
#include<fstream>
#include<stdint.h>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

int task_1(int bit_qnt, fstream &input)
{
    int values[bit_qnt] = { 0 },
        tot = 0;

    int32_t gamma = 0,
            epsilon = 0;

    string tmp;


    while (input >> tmp)
    {
        for (int i=0; i<bit_qnt; i++) {
            if (tmp[i] == '1')
                values[i] += 1;
        }
        tot++;
    }

    for (int i=0; i<bit_qnt; i++) {
        if (values[i] > tot/2)
            gamma ^= (1 << (bit_qnt - 1 - i));
        else
            epsilon ^= (1 << (bit_qnt - 1 -i));
    }

    return gamma * epsilon;
}

int task_2(int bit_qnt, fstream &input)
{
   int bits_on = 0;

    string list_bit_oxygen = "",
           list_bit_co2    = "";

    int32_t o2  = 0,
            co2 = 0;

    string tmp;

    list<string> oxygen_list;

    while (input >> tmp)
    {
        oxygen_list.push_back(tmp);
    }

    list<string> co2_list(oxygen_list);

    for (int i=0; i<bit_qnt; i++)
    {
        if (oxygen_list.size() == 1)
        {
            list_bit_oxygen = oxygen_list.front();
            break;
        }

        for (auto const& value : oxygen_list)
            if (value[i] == '1') bits_on++;

        if (bits_on >= ((float)oxygen_list.size())/2) list_bit_oxygen += '1';
        else list_bit_oxygen += '0';

        oxygen_list.remove_if([i, &list_bit_oxygen] (string value){
            return (value[i] != list_bit_oxygen[i]);
        });

        bits_on = 0;
    }

    for (int i=0; i<bit_qnt; i++)
    {
        if (co2_list.size() == 1)
        {
            list_bit_co2 = co2_list.front();
            break;
        }
        for (auto const& value : co2_list) {
            if (value[i] == '1') bits_on++;
        }

        if (bits_on < ((float)co2_list.size())/2) list_bit_co2 += '1';
        else list_bit_co2 += '0';

        co2_list.remove_if([i, &list_bit_co2] (string value) {
            return (value[i] != list_bit_co2[i]);
        });

        bits_on = 0;
    }

    for (int i=0; i<bit_qnt; i++) {

        if (list_bit_oxygen[i] == '1')
            o2 += (1 << (bit_qnt - 1 - i));

        if (list_bit_co2[i] == '1')
            co2 += (1 << (bit_qnt - 1 - i));
    }

    return o2 * co2;
}

int main()
{
    fstream input("./input1_test.txt", ios::in);
    int output = task_1(5,input);
    cout << "example 1: " << output << "." << endl;
    input.close();

    input.open("./input1.txt", ios::in);
    output = task_1(12, input);
    cout << "task 1: " << output << "." << endl;
    input.close();

    input.open("./input1_test.txt", ios::in);
    output = task_2(5, input);
    cout << "example 2: " << output << "." << endl;
    input.close();

    input.open("./input2.txt", ios::in);
    output = task_2(12, input);
    cout << "task 2: " << output << "." << endl;
    input.close();

    return 0;
}
