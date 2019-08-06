#include<iostream>
#include <map>
#include<string>

using namespace std;

class CStudent {

public:
	struct CInfo {
		int id;
		string name;
	};
	int score;
	CInfo info;
};

typedef multimap<int, CStudent::CInfo> MAP_STD;//缺省，使用less<int>，即学生成绩升序排列
int main() {
	MAP_STD mp;
	CStudent st;
	string cmd;
	while (cin >> cmd) {
		if (cmd == "Add") {
			cin >> st.info.id >> st.info.name >> st.score;
			mp.insert(MAP_STD::value_type(st.score, st.info));
		}
		else if (cmd == "Query") {
			int score;
			cin >> score;
			MAP_STD::iterator p = mp.lower_bound(score);
			if (p != mp.begin()) {
				p--;
				score = p->first;
				MAP_STD::iterator maxp = p;
				int maxID = p->second.id;
				for (; p != mp.begin() && p->first == score; p--) {
					if (p->second.id > maxID) {
						maxID = p->second.id;
						maxp = p;
					}
				}
				if(p->first == score){
					if (p->second.id > maxID) {
						maxID = p->second.id;
						maxp = p;
					}
				}
				cout << maxp->second.id <<" "
					<<maxp->second.name << " "
					<< maxp->first << endl;
			}
			else
				cout << "Nobody" << endl;
		}
	}
	return 0;

 }//test for change
