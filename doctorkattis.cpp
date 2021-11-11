#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int counter = 0;
struct node{
    int infectionLevel; //Infection level
    string catName; //Cat names
    int entrance;//When the cat entered

    bool operator< (const node& oneCat) const { //logical operator for moving the cats up the set
        if (infectionLevel != oneCat.infectionLevel){
            return infectionLevel > oneCat.infectionLevel;
        }
        return entrance < oneCat.entrance;
    }
};

set<node> cats;
node oneCat;
map<string, pair<int, int>> catInfo;

void ArriveAtClinic(string name, int level){ //inserts cat into set
    oneCat.infectionLevel = level;
    oneCat.catName = name;
    oneCat.entrance = counter;
    cats.insert(oneCat);
    catInfo[name] = {level, counter};
    counter++;
    return;
}

void UpdateInfectionLevel(string name, int level){ //removes old cat, inserts new cat with new level
    oneCat.catName = name;
    oneCat.infectionLevel = catInfo[name].first;
    int newLevel = oneCat.infectionLevel + level;
    oneCat.entrance = catInfo[name].second;
    int entranceLevel = oneCat.entrance;
    cats.erase(oneCat);
    catInfo.erase(name);
    oneCat.infectionLevel = newLevel;
    oneCat.entrance = entranceLevel;
    oneCat.catName = name;
    cats.insert(oneCat);
    catInfo[name] = {newLevel, entranceLevel};
    return;
}

void Treated(string name){ //removes cat from set
    oneCat.catName = name;
    oneCat.infectionLevel = catInfo[name].first;
    oneCat.entrance = catInfo[name].second;
    cats.erase(oneCat);
    catInfo.erase(name);
    return;
}

void Query(){ //prints name of cat with highest infection level
    if(cats.empty()){
        cout << "The clinic is empty\n";
    } else {
        cout << (*cats.begin()).catName << "\n";
    }
    return;
}

int main(){
    int n,caseN,level;
    string name;
    cin >> n; //number of lines needed to complete

    for(int i = 0; i < n; i++){
        cin >> caseN;
        if(caseN == 3){
            Query(); //print the cats name with the highest infection level
        }
        else if(caseN == 2){
            cin >> name;
            Treated(name); //remove the cat from the list
        }
        else if(caseN == 1){
            cin >> name >> level;
            UpdateInfectionLevel(name, level); //updates the value for the cats name
        }
        else if(caseN == 0){
            cin >> name >> level;
            ArriveAtClinic(name, level); //adds the cat to the MaxHeap object
        }
    }
    return 0;
}
