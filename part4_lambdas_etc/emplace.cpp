#include <utility>
#include <string>
#include <set>

using namespace std;

int main()
{

  set<pair<int, string>> s;

  s.insert(make_pair(1, "HI"));

  s.emplace(4, "HI");

  
}
  
