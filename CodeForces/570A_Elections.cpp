#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n_candidate, n_city;
    cin >> n_candidate >> n_city;
    vector<int> number_of_city_won(n_candidate);
    fill(number_of_city_won.begin(), number_of_city_won.end(), 0);
    int country_won_candidate = 101;
    int country_max_score = 0;
    for(int i=0; i<n_city; i++){
        int won_candidate = 0;
        int max_score = 0;
        for(int j=0; j<n_candidate; j++){
            int score;
            cin >> score;
            if(score > max_score) {
                max_score = score;
                won_candidate = j;
            }
        }
        number_of_city_won[won_candidate]++;
        if(number_of_city_won[won_candidate] > country_max_score || 
            (number_of_city_won[won_candidate] == country_max_score && won_candidate < country_won_candidate)) {
            country_max_score = number_of_city_won[won_candidate];
            country_won_candidate = won_candidate;
        }
    }
    cout << country_won_candidate + 1 << endl;
    return 0;
}