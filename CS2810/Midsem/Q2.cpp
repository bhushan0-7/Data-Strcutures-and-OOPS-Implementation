#include <iostream>
#include <vector>
using namespace std;
template <typename T> 
std::vector<T> filterGreater(const std::vector<T>& data, T threshold){
    vector <T> res;
for(int i=0;i<data.size();i++) {
    if(v[i] > threshold) res.push_back(v[i]);
}
return res;
}
class Service{
public:
    virtual double calculateCost() const = 0;
};
// Derived Classes:
// • Create HourlyService. Its constructor takes two doubles: rate and hours. Its cost is
// rate * hours.
// • Create ProjectService. Its constructor takes two doubles: fee and materials. Its cost
// is fee + materials.
class HourlyService: public Service {
    public:
    double rate,hours;
    double calculateCost(){
        return rate*hours;
    }

};
class ProjectService: public Service {
    public:
    double fee,materials;
    double calculateCost(){
        return fee+materials;
    }
};
int main(){

    return 0;
}
