#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int percorrido = 0;
    int paradas = 0;
    
    if(percorrido + tank >= dist)
        return 0;    
    
    if(stops.size() <= 0)
        return -1;

    while(percorrido < dist){
        int currentStop = -1;
        for(int i = 0; i < stops.size(); i++){
            if(percorrido < stops[i] && (percorrido + tank >= stops[i])) {                
                currentStop = stops[i];
            }
            else if(percorrido + tank >= dist) {
                currentStop = dist;
                paradas--;
                break;
            }
        }

        if(currentStop > 0) {
            percorrido = currentStop;
            paradas++;
        }
        else {
            paradas = -1;
            break;
        }
        
    }
    // write your code here
    return paradas;
}


int main() {
    int d = 0; // distancia total
    cin >> d;
    int m = 0; // maximo com tanque cheio
    cin >> m;
    int n = 0; // numero de paradas 
    cin >> n;

    vector<int> stops(n); // vetor com as distancias de cada parada
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
