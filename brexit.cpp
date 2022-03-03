/* Author: Lucas Hartfiel @lhartfie
 * Due Date: December 13, 2021
 * Brexit Kattis Problem
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    bool exit;
    int initial;
    int remaining;
    vector<int> partners;
};

int main(){
    int c, p, x, l;
    queue<int> process;
    vector<node> countries;
    cin >> c >> p >> x >> l;

    if(x == l){
        cout << "leave" << "\n";
        return 0;
    }

    for(int i = 0; i < c+1; i++){
        node country;
        country.exit = false;
        country.initial = 0; // total number of connections to start
        country.remaining = 0; // number of connections at each current moment
        countries.push_back(country);
    }

    for(int j = 0; j < p; j++){
        int p1, p2;
        cin >> p1 >> p2;
        // Increases the number of connections by 1
        countries[p1].initial++;
        countries[p2].initial++;
        countries[p1].remaining++;
        countries[p2].remaining++;
        // Adds the two countries to each others neightbor vector
        countries[p1].partners.push_back(p2);
        countries[p2].partners.push_back(p1);
    }

    // Country l exits the Union
    countries[l].exit = true;
    // removes the edge beween l and its neighbors
    for(auto i : countries[l].partners){
        countries[i].remaining--;
        process.push(i);
    }

    while(process.size() > 0){
        int front = process.front();
        process.pop();
        if(countries[front].exit == true){
            continue;
        }
        // checks if the country at the top of the list should stay or leave (more than half of their initial parters are still in, they will stay)
        if(countries[front].remaining <= countries[front].initial/2){
            countries[front].exit = true;
            for(auto i : countries[front].partners){
                countries[i].remaining--;
                process.push(i);
            }
        }
    }
    // checks if country X is still in the Union or not after the whole process
    if(countries[x].exit == true){
        cout << "leave" << "\n";
    }
    else {
        cout << "stay" << "\n";
    }
}
