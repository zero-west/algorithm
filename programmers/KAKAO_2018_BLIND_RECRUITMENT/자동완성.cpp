#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> words) {
	int answer = 0;

	map<string, vector<int>> mapping;

	auto it = mapping.begin();
	for (auto i = 0; i < words.size(); i++) {
		it = mapping.find(words[i].substr(0, 1));

		if (it != mapping.end())
			(*it).second.emplace_back(i);
		else
			mapping.insert(make_pair(words[i].substr(0, 1), vector<int>(1, i)));
	}

	for (auto it2 = mapping.begin(); it2 != mapping.end(); it2++) {
		auto len = (*it2).first.length();
		if ((*it2).second.size() == 1) answer += len;
		else {
			for (auto i = 0; i < (*it2).second.size(); i++) {
				if ((*it2).first == words[(*it2).second[i]]) {
					answer += len;
				}
				else {
					it = mapping.find(words[(*it2).second[i]].substr(0, len + 1));

					if (it != mapping.end()) {
						(*it).second.emplace_back((*it2).second[i]);
					}
					else {
						mapping.insert(make_pair(words[(*it2).second[i]].substr(0, len + 1), vector<int>(1, (*it2).second[i])));
					}
				}
			}
		}
	}

	return answer;
}
