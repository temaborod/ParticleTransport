
using namespace std;
class MaterialSurface {
public:
    // Axis and coordinate of the plane
    int axis_ = 0;
    double coor_ = 0;
    // Constructor for creating a bounding plane
    MaterialSurface() {}

    // Function for user selection of material surface
    void enterSurface() {
        cout << "Enter a material surface coordinate:\n1. X\n2. Y\n3. Z\n::::";
        cin >> axis_;
        switch (axis_)
        {
        case 1:
            cout << "Enter a coordinate of surface on X:\n::::";
            cin >> coor_;
            break;
        case 2:
            cout << "Enter a coordinate of surface on Y:\n::::";
            cin >> coor_;
            break;
        case 3:
            cout << "Enter a coordinate of surface on Z:\n::::";
            cin >> coor_;
            break;
        }
    }

    // A method for checking collisions with a given bounding plane
    bool checkCollision(const Particle& particle) {
        switch (axis_)
        {
        case 1:
            // Check whether the particle is located before or after the plane
            if (particle.getX() >= coor_) {
                // The collision has occurred, the particle is above the plane
                return true;
            }
            break;
        case 2:
            if (particle.getY() >= coor_) {
                return true;
            }

            break;
        case 3:
            if (particle.getZ() >= coor_) {
                return true;
            }

            break;
        }
        return false;
    }

};
