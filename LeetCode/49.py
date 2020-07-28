from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        s_dict = {}

        for cur_str in strs:
            s_str = ''.join(sorted(list(cur_str)))

            if s_str in s_dict:
                s_dict[s_str].append(cur_str)
            else:
                s_dict[s_str] = [cur_str]

        result = [[] for _ in range(len(s_dict))]
        for idx, k in enumerate(s_dict):
            for v in s_dict[k]:
                result[idx].append(v)
        return result
