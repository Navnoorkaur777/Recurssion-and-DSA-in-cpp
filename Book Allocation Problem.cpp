//You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
//
//Input Format
//First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.
//
//Constraints
//1 < t < 50
//1< n < 100
//1< m <= 50
//1 <= Ai <= 1000
//
//Output Format
//Print the maximum number of pages that can be assigned to students.
//
//Sample Input
//1
//4 2
//12 34 67 90
//Sample Output
//113 
//Explanation
//1st students : 12 , 34, 67 (total = 113)
//2nd students : 90 (total = 90)
//Print max(113, 90)
#include <bits/stdc++.h>//n=books m=students
using namespace std;
bool isPossible(int pages[], int n, int m, int min) {
    int studentsReq = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > min) {
            return false;
        }
        if (sum + pages[i] > min) {
        
            studentsReq += 1;
            
            sum = pages[i];
            
            if (studentsReq > m) {
                return false;
            }
        } 
		else {
            
            sum += pages[i];
        }
    }
    return true;
}
int allocateMinimum(int pages[], int n, int m) {
    
    if (n < m) {
        return -1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    
    int start = 0, end = sum;
    int ans = INT_MAX;
    while (start <= end) {
        
        int mid =  ( start+end) / 2;
        if (isPossible(pages, n, m, mid)) {
            ans = min(ans, mid); 
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	
    int n,m;
    cin>>n>>m;
    
    int pages[n];
    for(int i=0;i<n;i++){
    	cin>>pages[i];
	}
    cout <<allocateMinimum(pages, n, m) << endl;
}
}
