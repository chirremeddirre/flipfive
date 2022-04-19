#include <iostream>
#include <queue>
#include <cmath>
#include <vector>


int get_board_hash(){
  // Board -> Binary -> Tenary
  int sum = 0;
  for (int i = 0; i < 3; i++){
    std::string row;
    std::cin >> row;
    for (int j = 0; j < 3; j++){
      if (row[j] == '.') sum += std::pow(2,3*i+j);
    }
  }
  return sum;
}


int flip_all(std::queue<std::pair<int,int>> &q, int target, std::vector<int> &visited, std::vector<int> &moves){
  std::pair<int,int> curr = q.front();
  int next;
  int depth = curr.second + 1;
  for(int move: moves){
    next = curr.first ^ move;
    if (next == target) return depth;
    if(!visited[next]){
      q.push(std::make_pair(next, depth));
      visited[next]++;
    }
  }
  return 0;
}

int solve(std::queue<std::pair<int,int>> &q, int target){
  int res = 0;
  std::vector<int> moves = {416,464,200,308,186,89,38,23,11};
  std::vector<int> visited(512,0);
  while(!res){
    res = flip_all(q, target, visited, moves);
    q.pop();
  }
  return res;

}


int main(){
  int N;
  std::cin >> N;
  for (int i = 0; i < N; i++){
    int target_hash = get_board_hash();
    if (target_hash == 511){
      std::cout << 0 << std::endl;
      continue;
    }
    std::queue<std::pair<int,int>> q; // BFS
    q.push(std::make_pair(511,0));
    int res = solve (q, target_hash);
    std::cout << res << std::endl;
  }

}
