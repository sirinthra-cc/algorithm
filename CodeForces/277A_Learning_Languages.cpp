#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;


void graph_count(int current_language, vector<set<int>> &graph, 
                vector<bool> &checked_languages, vector<bool> &valid_languages){
    checked_languages[current_language] = true;
    for(auto language: graph[current_language]){
        if(!checked_languages[language]){
            graph_count(language, graph, checked_languages, valid_languages);
        }
    }
}

int main(){
    int n_employees, n_languages;
    cin >> n_employees >> n_languages;
    vector<vector<int>> employee_languages(n_employees);
    vector<set<int>> graph(n_languages+1);
    int zero_count = 0;
    vector<bool> valid_languages(n_languages+1);
    for(int i=0; i<n_employees; i++){
        int n_languages_of_employee;
        cin >> n_languages_of_employee;
        if(n_languages_of_employee == 0) {
            zero_count++;
        } else {
            vector<int> languages_of_employee(n_languages_of_employee);
            for(int j=0; j<n_languages_of_employee; j++){
                cin >> languages_of_employee[j];
                valid_languages[languages_of_employee[j]] = true;
            }
            for(int a=0; a<n_languages_of_employee-1; a++){
                for(int b=a+1; b<n_languages_of_employee; b++){
                    graph[languages_of_employee[a]].insert(languages_of_employee[b]);
                    graph[languages_of_employee[b]].insert(languages_of_employee[a]);
                }
            }
        }
    }
    int count = 0;
    // get the number of graph
    vector<bool> checked_languages(n_languages+1);
    for(int i=1; i<=n_languages; i++){
        if(valid_languages[i] && !checked_languages[i]){
            count++;
            graph_count(i, graph, checked_languages, valid_languages);
        }
    }
    if(count!=0)
        cout << count + zero_count - 1 << endl;
    else
        cout << zero_count << endl;
    return 0;
} 