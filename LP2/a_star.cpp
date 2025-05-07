#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    string state;
    int g, h;
    string path;

    Node(string state, int g, int h, string path){
        this->state = state;
        this->path = path;
        this->g = g;
        this->h = h;
    }

    int f() const {
        return g + h;
    }

    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

vector<pair<int,char>> get_moves(int zeroIndex){
    vector<pair<int,char>> valid_moves;
    int x = zeroIndex / 3, y = zeroIndex % 3;
    if(x > 0) valid_moves.push_back({zeroIndex - 3, 'U'});
    if(x < 2) valid_moves.push_back({zeroIndex + 3, 'D'});
    if(y > 0) valid_moves.push_back({zeroIndex - 1, 'L'});
    if(y < 2) valid_moves.push_back({zeroIndex + 1, 'R'});
    return valid_moves;
}

vector<pair<int,int>> getGoalPos(string& goal){
    vector<pair<int,int>> pos(9);
    for(int i=0;i<9;i++){
        int val = goal[i] - '0';
        pos[val] = {i/3, i%3};
    }
    return pos;
}

string swaped(string& s, int i, int j){
    string res = s;
    swap(res[i], res[j]);
    return res;
}

int heuristic(string& state, vector<pair<int,int>>& pos){
    int dist = 0;
    for(int i=0;i<9;i++){
        if(state[i] == '0') continue;
        int val = state[i] - '0';
        int currRow = i / 3, currCol = i % 3;
        dist += abs(currRow - pos[val].first) + abs(currCol - pos[val].second);
    }

    return dist;
}

void astar(string& start, string& goal){
    vector<pair<int,int>> goalPos = getGoalPos(goal);
    priority_queue<Node, vector<Node>, greater<Node>> openList;
    unordered_set<string> visited;

    openList.emplace(start, 0, heuristic(start, goalPos), "");

    while(!openList.empty()){
        Node curr = openList.top();
        openList.pop();

        if (visited.count(curr.state)) continue;
        visited.insert(curr.state);

        if(curr.state == goal){
            cout<<"Solved in "<<curr.g<<"moves"<<endl;
            cout<<"Path: "<<curr.path<<endl;
            return;
        }

        int zero = curr.state.find('0');
        for(auto it : get_moves(zero)){
            string newState = swaped(curr.state, zero, it.first);
            if(!visited.count(newState)){
                int h = heuristic(newState, goalPos);
                openList.emplace(newState, curr.g + 1, h, curr.path + it.second);
            }
        }
    }

    cout<<"No solution Found"<<endl;
}

int main(){

    string start;
    getline(cin, start);
    string goal;
    getline(cin, goal);
    astar(start, goal);
    
    return 0;
}