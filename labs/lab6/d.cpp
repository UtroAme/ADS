#include <iostream>
#include <string>
using namespace std;

struct date{
    int day, month,year;
};

bool isless(date a, date b){
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

void quickSort(date dates[], int left, int right){
    if(left >= right) return;

    date pivot = dates[(left+right)/2];
    int i = left, j = right;

    while (i <= j){
        while (isless(dates[i], pivot)) i++;
        while (isless(pivot, dates[j])) j--;

        if(i <= j){
            swap(dates[i], dates[j]);
            i++;
            j--;
        }
    }
    quickSort(dates,left,j);
    quickSort(dates,i,right);
}

int main(){
    int n;
    cin >> n;

    date* dates = new date[n];

    for(int i = 0; i<n; i++){
        string dateStr;
        cin >> dateStr;

        dates[i].day = stoi(dateStr.substr(0,2));
        dates[i].month = stoi(dateStr.substr(3,2));
        dates[i].year = stoi(dateStr.substr(6,4));
    }

    quickSort(dates,0,n-1);

    for (int i = 0; i < n; i++) {
        if (dates[i].day < 10) cout << "0";
        cout << dates[i].day << "-";
        if (dates[i].month < 10) cout << "0";
        cout << dates[i].month << "-" << dates[i].year << endl;
    }
    
    delete[] dates;
    return 0;
}