#include <iostream>
#include <vector>
#include <random>
#include "Particle.h"
#include "MaterialSurface.h"

using namespace std;

int main() {
    vector<Particle> particles; // Creating a particle vector
    MaterialSurface floor; // Creating a material surface object
    floor.enterSurface();

    for (int i = 0; i < 100; ++i)
    {
        // Generation of random coordinates and velocities for a particle
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;
        double z = static_cast<double>(rand()) / RAND_MAX;
        double vx = static_cast<double>(rand()) / RAND_MAX;
        double vy = static_cast<double>(rand()) / RAND_MAX;
        double vz = static_cast<double>(rand()) / RAND_MAX;

        // Creating particles and adding them to a vector
        Particle particle(x, y, z, vx, vy, vz);
        particles.push_back(particle);
    }

    // Simulation of particle motion
    double dt = 0.01; // Time step
    int sum = 0;
    int numOfParticle = 0;
    for (Particle& particle : particles)
    {
        int steps = 0;
        // Motion of a particle before collision with a material surface
        do
        {
            particle.move(dt);
            steps += 1;
        } while (!floor.checkCollision(particle));
        particles.pop_back();
        sum += steps;
        numOfParticle += 1;
    }
    // Application of the Monte Carlo method to determine the average number of steps
    // that 100 particles with random coordinates and velocities will need 
    // to reach a given material surface
    double Sum = sum;
    cout << "Monte Carlo method: " << Sum / 100 << endl;
    return 0;
}