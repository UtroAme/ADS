#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& row, int x, bool decreasing){
    int low = 0, hight = row.size()-1;
    while(low <= hight){
        int mid = low + (hight - low)/2;

        if(row[mid]==x) return mid;
        if(decreasing){ //если убывеат 
            if(row[mid]>x) low = mid +1;
            else hight = mid -1;
        } else { //если возрастает 
            if(row[mid]<x) low = mid +1;
            else hight = mid -1;
        }
    }
    return -1;

}

int main(){
    int n, x, a, b;
    cin >> n;
    vector<int> vc;

    for(int i = 0; i < n; i++){
        cin >> x;
        vc.push_back(x);
    }
    cin >> a >> b;
    vector<vector<int>> snake(a, vector<int>(b));

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> snake[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        int target = vc[k];
        bool found = false;

        for(int i = 0; i < a; i++){
            int mx,mn;
            if(i%2 == 0){
                mx = snake[i][0];
                mn = snake[i][b-1];
            } else {
                mx = snake[i][b-1];
                mn = snake[i][0];
            }

            if(target >= mn && target <= mx){ // провека если входит в диапозон
                int pos = binarySearch(snake[i], target, i%2==0);
                if(pos != -1){
                    cout << i << " " << pos << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << -1 << "\n";
    }
}