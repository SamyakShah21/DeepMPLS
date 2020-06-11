#include "coordinate.h"
#include <cmath>

namespace aalwines {

    //Using the 'Coordinate' class from "coordinate.h"	
    Coordinate::Coordinate(double latitude, double longitude) : _latitude(latitude), _longitude(longitude),
        _rad_lat(M_PI / 180 * latitude), _rad_long(M_PI / 180 * longitude) {}

    //adding to the distance_to function defined in the Coordinate class in "coordinate.h"	
    double Coordinate::distance_to(const Coordinate& other) const {
        // Using the Haversine's distance formula.
        return 2* _R_km  * std::asin(std::sqrt(std::pow((_rad_lat - other._rad_lat)/2, 2) +
        std::cos(_rad_lat) * std::cos(other._rad_lat) * std::pow(std::sin((_rad_long - other._rad_long) / 2), 2)));
    }

    void Coordinate::write_xml_attributes(std::ostream& s) const {
        s << " latitude=\"" << _latitude << "\" longitude=\"" << _longitude << "\" ";
    }
}
