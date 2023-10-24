
class Particle {
public:
    // Constructor for creating a new particle
    Particle(double x, double y, double z, double vx, double vy, double vz)
        : x_(x), y_(y), z_(z), vx_(vx), vy_(vy), vz_(vz) {}

    // Getters for obtaining coordinates and particle velocities
    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }
    double getVx() const { return vx_; }
    double getVy() const { return vy_; }
    double getVz() const { return vz_; }

    // A method for updating the position of a particle according to the velocity
    void move(double dt) {
        x_ += vx_ * dt;
        y_ += vy_ * dt;
        z_ += vz_ * dt;
    }

private:
    // Coordinates and velocities of the particle
    double x_;
    double y_;
    double z_;
    double vx_;
    double vy_;
    double vz_;
};

