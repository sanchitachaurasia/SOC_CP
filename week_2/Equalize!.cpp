#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
    long long a, b, c, d;
    cin>>a>>b>>c>>d;

    if(a*d < b*c){
        long long movie_w = a;
        long long movie_h = d*a;
        long long screen_w = a;
        long long screen_h = b*c;

        long long movie_area = movie_w*movie_h;
        long long screen_area = screen_w*screen_h;

        long long empty_area = screen_area-movie_area;
        long long g = gcd(empty_area,screen_area);
        cout<<(empty_area/g)<<"/"<<(screen_area/g)<<endl;
    }
    else{
        long long movie_h = b;
        long long movie_w =c*b;
        long long screen_w =a*d;
        long long screen_h = b;

        long long movie_area = movie_w*movie_h;
        long long screen_area = screen_w*screen_h;

        long long empty_area = screen_area-movie_area;
        long long g = gcd(empty_area,screen_area);
        cout<<(empty_area/g)<<"/"<<(screen_area/g)<<endl;
    }

    return 0;
}
