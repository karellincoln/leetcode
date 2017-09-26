/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();

        int res = 0;

        for (int i = 0; i < points.size() - 1; ++i) {
            unordered_map<double, int> num;
            int vertical = 1, duplicate = 0;
            int local = 1;
            for (int j  = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y)
                        ++duplicate;
                    else
                        ++vertical;
                }
                else {
                    double slope =  1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                    num[slope] = (num[slope] == 0) ? 2 : num[slope] + 1;
                    local = max(local, num[slope]);
                }
            }
            local = max(local, vertical) + duplicate;
            res = max(res, local);
        }

        return res;
    }
};

// 解决方案。
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();

        int res = 0;

        for (int i = 0; i < points.size() - 1; ++i) {
            map<pair<int, int>, int> num;
            int vertical = 0, duplicate = 0;
            int local = 0;
            for (int j  = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y)
                        ++duplicate;
                    else
                        ++vertical;
                }
                else {
                    int a = (points[i].y - points[j].y);
                    int b = (points[i].x - points[j].x);
                    int g = GCD(a, b);
                    a /= g;
                    b /= g;
                    ++num[make_pair(a,b)];
                    local = max(local, num[make_pair(a,b)]);
                }
            }
            local = max(local, vertical) + duplicate + 1;
            res = max(res, local);
        }

        return res;
    }

    int GCD(int a, int b) {
        if (b == 0) return a;
        else return GCD(b, a%b);
    }
};