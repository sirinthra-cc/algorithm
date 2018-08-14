bool compareLen(const string &a, const string &b){
    return a.size() <= b.size(); 
}

bool dfs(string current_word, unordered_map<string, bool> &visited, unordered_map<string, bool> &dict, int &min_len){
    bool found = false;
    if(current_word.size() == 0 || dict.find(current_word) != dict.end()) return true;
    for(int i=min_len; i<current_word.size(); i++){
        string prefix = current_word.substr(0, i);
        if(dict.find(prefix) != dict.end()){
            string suffix = current_word.substr(i, current_word.size()-i);
            if(visited.find(suffix) == visited.end()){
                found = dfs(suffix, visited, dict, min_len);
                visited[suffix] = found;
                if(found) return found;
            } else if (visited[suffix] == true){
                return true;
            }
        }
    }
    return found;
}

string get_longest_word(vector<string> words){
    unordered_map<string, bool> dict;
    for(auto word: words){
        dict[word] = true;
    }
    sort(words.begin(), words.end(), compareLen);  // sort by length assendingly
    int min_len = words[0];
    unordered_map<string, bool> visited;
    bool fond = false;
    for(int i=words.size()-1; i>=0; i--){
        found = dfs(words[i], visited, dict, min_len);
        if(found){
            return words[i];
        }
    }
    return "No longest word";
}