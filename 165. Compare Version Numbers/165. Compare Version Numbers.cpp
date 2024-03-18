class Solution {
public:
    int compareVersion(string version1, string version2) {

        istringstream iss1(version1);
        istringstream iss2(version2);

        int v1, v2;
        char dot_char;

        while (bool(iss1 >> v1) + bool(iss2 >> v2)) {

            if (v1 < v2) {
                return -1;
            }
            if (v1 > v2) {
                return 1;
            }

            iss1 >> dot_char;
            iss2 >> dot_char;
            v1 = 0;
            v2 = 0;
        }
        return 0;
    }
};