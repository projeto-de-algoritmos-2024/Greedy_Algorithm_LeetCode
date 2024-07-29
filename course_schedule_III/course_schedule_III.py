import heapq
from typing import List

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        max_heap = []  
        courses.sort()  

        total_time = 0
        for duration, end_time in courses:
            heapq.heappush(max_heap, duration)  
            total_time += duration  

            if total_time > end_time:
                total_time += heapq.heappop(max_heap)

        return len(max_heap)
