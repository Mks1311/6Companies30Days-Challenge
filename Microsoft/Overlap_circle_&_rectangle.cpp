#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int x, int y, int x1, int y1, int x2, int y2) {
        int closestX=max(x1,min(x2,x));
        int closestY=max(y1,min(y2,y));
        int dist=(closestX-x)*(closestX-x)+(closestY-y)*(closestY-y);
        return dist<=(radius*radius);
    }
};