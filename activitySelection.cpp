#include <iostream>//Acitviy Selection 
#include <vector>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int finish;
};
bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}
void activitySelection(vector<Activity> &activities)
{
    int n = activities.size();
    sort(activities.begin(), activities.end(), compare);
    int i = 0;
    cout << "Selected activities are: " << endl;
    cout << "start:" << activities[i].start
         << ", finish:" << activities[i].finish << endl;

    for (int m = 1; m < n; m++)
    {
        if (activities[m].start >= activities[i].finish)
        {
            cout << "start:" << activities[m].start
                 << ", finish:" << activities[m].finish << endl;
            i = m;
        }
    }
}

int main()
{
    vector<Activity> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};
    activitySelection(activities);
    return 0;
}
