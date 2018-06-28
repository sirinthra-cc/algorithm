#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int check(set<int> &to_check, unordered_map<int, bool> &checked_astronaut, 
          vector<set<int>> &astronaut_graph){
    int count = 1;
    if(to_check.size() == 0) return count;
    for(auto a: to_check){
        if(checked_astronaut.find(a) == checked_astronaut.end()){
            //cout << a << endl;
            checked_astronaut[a] = true;
            count += check(astronaut_graph[a], checked_astronaut, astronaut_graph);
        }       
    }
    return count;
}
// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    unordered_map<int, bool> checked_astronaut;
    vector<set<int>> astronaut_graph(n);
    for(int i=0; i<astronaut.size(); i++){
        int a1 = astronaut[i][0];
        int a2 = astronaut[i][1];
        astronaut_graph[a1].insert(a2);
        astronaut_graph[a2].insert(a1);
    }
    // Find astronaut who came from the same country as astronaut i
    vector<int> country_astronaut;
    for(int a=0; a<astronaut_graph.size(); a++){
        if(checked_astronaut.find(a) == checked_astronaut.end()){
            checked_astronaut[a] = true;
            int count = check(astronaut_graph[a], checked_astronaut, astronaut_graph);
            if(count!=-1) country_astronaut.push_back(count);
        }        
    }
    
    long long sum = 0;
    for(int i=0; i<country_astronaut.size(); i++){
        sum += (long long)country_astronaut[i];
    }
    long long result = 0;
    for(int i=0; i<country_astronaut.size()-1; i++){
        sum -= (long long)country_astronaut[i];
        result += (long long)country_astronaut[i]*sum;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
