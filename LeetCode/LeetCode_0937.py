from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        num_logs = []
        ret_logs = []

        for log in logs:
            if log.split()[1].isdigit():
                num_logs.append(log)
            else:
                ret_logs.append(log)

        ret_logs.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        ret_logs += num_logs
        return ret_logs
