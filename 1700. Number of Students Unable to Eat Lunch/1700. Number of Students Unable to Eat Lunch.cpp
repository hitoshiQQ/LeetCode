class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        // Init a count array to store the number of students preferring each type of sandwich
        int count[2] = { 0 };

        // Count the number of students preferring each type of sandwich (zero or one)
        for (int student : students) {
            count[student]++;
        }

        // Iterate through the sandwiches queue
        for (int sandwich : sandwiches) {

            // If no students prefer the current type of sandwich
            if (count[sandwich] == 0) {
                // use 1 - sandwich to get the opposite type
                return count[1 - sandwich];
            }

            // Otherwise, decrement the count of students who prefe the current type of sandwich
            count[sandwich]--;
        }
        return 0;
    }
};