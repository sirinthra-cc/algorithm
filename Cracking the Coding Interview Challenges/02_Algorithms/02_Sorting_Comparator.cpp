bool isLower(Player player1, Player player2){
    if (player1.score < player2.score) return true;
    else if (player1.score > player2.score) return false;
    else if ((player1.name).compare(player2.name) > 0) return true;
    return false;
}

void swap(vector<Player> &players, int i, int j){
    Player tmp = players[i];
    players[i] = players[j];
    players[j] = tmp;
}

vector<Player> comparator(vector<Player> players) {
    for(int i=0; i<players.size(); i++){
        for(int j=1; j<players.size()-i; j++){
            if(isLower(players[j-1], players[j])){
                swap(players, j-1, j);
            }
        }
    }
    return players;
}
