class Solution {
public:
    /*

This topic is very similar to the topic of the largest number of conferences and belongs to a Fellow Up.
 * In order to complete the most courses, the greedy strategy is as follows:
 * 1. The courses with the earliest course ending time are processed first, so we need to sort the courses according to the
  deadline.
 * 2. When the time to complete the course> the deadline of the current course, we should remove the course that takes the
  longest time from the selected course.
 * So we need to use a maxHeap to help us maintain this information.
 * The number of courses (duration) in the final queue shows how many courses we can complete at most.
 *
 * Time complexity: O(nlogn)
 *
 * Maximum number of meetings:
for question  scroll down

*/
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
       int i,j,k,l,n=courses.size();
        int t=0;
        priority_queue<int> pq;
        sort(courses.begin(),courses.end(),comp);
        for(i=0;i<courses.size();i++){
            t+=courses[i][0];
            pq.push(courses[i][0]);
            if(t>courses[i][1]){
                t-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

/*
There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:

Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

*/
