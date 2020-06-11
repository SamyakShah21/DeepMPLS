//Could have used #ifdef too since AALWINES_COORDINATE_H is defined using #define, wouldn't cause change in functionality.

#ifndef AALWINES_COORDINATE_H
#define AALWINES_COORDINATE_H

#include <ostream>
using namespace std;

//defining a new namespace

namespace aalwines {

    class Coordinate {
    public:
	// used explicit to disallow the consturctor with single arguement to become conversion constructor
        explicit Coordinate(pair<double, double> pair) : Coordinate(pair.first, pair.second) {};
        Coordinate(double latitude, double longitude);
	
	//[[nodiscard]] is used to issue a warning in case the return object of a function is ignored.
        [[nodiscard]] double distance_to(const Coordinate& other) const;
        [[nodiscard]] double latitude() const { return _latitude; }
        [[nodiscard]] double longitude() const { return _longitude; }
        void write_xml_attributes(ostream& s) const;

	// overloading == operator and != operator
        bool operator==(const Coordinate& other) const {
            return _latitude == other._latitude && _longitude == other._longitude;
        }
        bool operator!=(const Coordinate& other) const {
            return !(*this == other);
        }

    private:
        static constexpr double _R_km = 6372.8;
        const double _latitude;
        const double _longitude;
        const double _rad_lat;
        const double _rad_long;
    };
}

#endif //AALWINES_COORDINATE_H
