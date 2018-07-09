#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> set(n);
    vector<int> country_astronaut(n);
    fill(country_astronaut.begin(), country_astronaut.end(), 1);
    for(int i=0; i<n; i++) set[i] = i;
    for(int i=0; i<astronaut.size(); i++){
        int a1 = astronaut[i][0];
        int a2 = astronaut[i][1];
        int root1 = a1;
        int root2 = a2;
        while(set[root1] != root1) root1 = set[root1];
        while(set[root2] != root2) root2 = set[root2];
        if (root1 != root2){
            set[root1] = root2;
            country_astronaut[root2] += country_astronaut[root1];
            country_astronaut[root1] = 0;
        } else {
            continue;
        }
    }
    long long sum = 0;
    for(int i=0; i<country_astronaut.size(); i++){
        if(country_astronaut[i] != 0)
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
