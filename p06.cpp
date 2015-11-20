// Copyright 2015 Joshua Rodriguez
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Convert the class into a number
int count(string word) {
    if (word == "upper") {
        return 1;
    } else if (word == "middle") {
        return 0;
    } else if (word == "lower") {
        return -1;
    } else {
        return -0xFFFFFFFF;
    }
}

struct Class {
    string name;
    int score = 0;
    // Create the class only construct valid classes
    inline Class(string _name, string ranks) {
        if (_name.size() > 30) throw "Name to long";
        name = _name;
        string rank = "";
        int found = 0;
        for (int i = 0 ; i <= ranks.size() ; i++) {
            if (ranks[i] == '-' || ranks[i] == '\0') {
                if (++found == 10) throw "To many classes";
                score += count(rank);
                rank = "";
            } else {
                rank += ranks[i];
            }
        }
        cerr << name << ' ' << score << endl;
    };
    // Sort the classes first by rank then by name
    inline friend bool operator<(Class a, Class b) {
        if (a.score == b.score) { 
            return a.name < b.name;
        }
        return a.score > b.score; 
    };
};

int main() {
    string line;
    vector<Class> classes;
    int found = 0;
    while (getline(cin, line)) {
        if (line.size() == 0 || found++ == 100) break;
        string name = line.substr(0, line.find(":"));
        string ranks = line.substr(line.find(":") + 2);
        ranks = ranks.substr(0, ranks.rfind(" "));
        try {
            classes.push_back(Class(name, ranks));
        } catch (string error) {
            cerr << error << endl;
        }
    }
    sort(classes.begin(), classes.end());
    for (Class rank : classes) {
        cout << rank.name << endl;
    }
    return 0;
}
