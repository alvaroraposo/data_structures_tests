
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {

    // sort the vector according to the end points
    std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
        return a.end < b.end;
    });

    std::cout << "RESULT\n";
    for(int i = 0; i < segments.size(); i++) {
      std::cout << segments[i].start << " " << segments[i].end << "\n";
    }

    vector<int> points; // create a vector to store the common points in the segments
    int point = segments[0].end; // set the point to the first end point i-e shortest end point
    points.push_back(point);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (point < segments[i].start || point > segments[i].end) { // if the point is not in the segment
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
        }
    }

    return points;
}

int main() {
    unsigned int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}

// #include <algorithm>
// #include <iostream>
// #include <climits>
// #include <vector>

// using std::vector;

// struct Segment {
//   int start, end;
// };

// struct Overlap {
//   int qtd, number;
//   vector<int> segments;
// };

// vector<int> optimal_points(vector<Segment> &segments) {
//   vector<int> points;
//   int min = -1;
//   int max = -1;
//   //write your code here
//   for (size_t i = 0; i < segments.size(); ++i) {
//     if(min == -1 || segments[i].start < min)
//       min = segments[i].start;
    
//     if(max == -1 || segments[i].end > max)
//       max = segments[i].end;    
//   }

//   vector<Overlap> overlaps;
//   int count = min;
//   while(count <= max) {
//     int overlap = 0;
//     Overlap o = Overlap();
//     for (size_t i = 0; i < segments.size(); ++i) {        
//         if(count >= segments[i].start && count <= segments[i].end)
//         {          
//           o.segments.push_back(i);
//           overlap++;
//         }
//     }
    
//     o.qtd = overlap;
//     o.number = count;
//     overlaps.push_back(o);
//     count++;
//   }


//   int max_segments = segments.size();
//   vector<int> s;
//   while(max_segments > 0) {
//     int number = 0;

//     for(int i = 0; i < overlaps.size(); i++) {
//       if(overlaps[i].qtd == max_segments) {
//         number = overlaps[i].number;
//         int countNumber = 0;

//         for(int j = 0; j < overlaps[i].segments.size(); j++) {
//           std::vector<int>::iterator it = std::find(s.begin(), s.end(), overlaps[i].segments[j]);
//           if (it == s.end()) {
//             countNumber++;
//             s.push_back(overlaps[i].segments[j]);
//           }            
//         }
        
//         if(countNumber > 0)
//           points.push_back(number);
        
//         if(s.size() == segments.size()){          
//           return points;
//         }
//       }
//     }

//     max_segments--;
//   }  
//   return points;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<Segment> segments(n);
//   for (size_t i = 0; i < segments.size(); ++i) {
//     std::cin >> segments[i].start >> segments[i].end;
//   }
  
//   vector<int> points = optimal_points(segments);
// //  sort(points.begin(), points.end());

//   std::cout << points.size() << "\n";
//   for (size_t i = 0; i < points.size(); ++i) {
//     std::cout << points[i] << " ";
//   }
// }
