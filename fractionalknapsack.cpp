#include <iostream>//Fractional Kanapsack 
#include <vector>
#include <algorithm>
using namespace std;
struct iteam
{
    int weight;
    int value;
};
bool compare(iteam a, iteam b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractinalkapsack(int capacity , vector<iteam>& items){
    sort(items.begin(),items.end() ,compare);
    double totalvalue = 0.0;
    for (int i =0 ; i<items.size();i++){
        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            totalvalue += items[i].value;
        }
        else{
            totalvalue += items[i].value *((double)capacity / items[i].weight);
            break;
        }

    }
    return totalvalue;
}
int main()
{
    int capacity = 50;
    vector<iteam> items = {{60, 10}, {100, 20}, {120, 30}};

    double maxValue = fractinalkapsack(capacity, items);
    cout << "Maximum value in knapsack =" << maxValue << endl;
    return 0;
}