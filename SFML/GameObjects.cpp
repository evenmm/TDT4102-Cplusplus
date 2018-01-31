#include "GameObjects.h"
#include "cannonball.h"
#include <cmath>

// implement all (member) functions in this file
Target::Target(double size, double position) {
	this->size = size;
	this->position = position;
	shape = sf::RectangleShape(sf::Vector2f((float)size, (float)size));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition((float)position, (float)0);
}

void Target::update() {}

void Target::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}
/////////////////////////////CANNON/////////////////////////////////////////

Cannon::Cannon() {
	shape = sf::RectangleShape(sf::Vector2f((float)length, (float)width));
	shape.setFillColor(sf::Color::White);
	shape.setOrigin((float)(width / 2), (float)0);
	shape.setPosition((float)0, (float)0);
}

void Cannon::update() {
	shape.setRotation((float)(theta));
}
void Cannon::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
void Cannon::incrementAngle(double dtheta) {
	theta += dtheta;
}
void Cannon::decrementAngle(double dtheta) {
	theta -= dtheta;
}
void Cannon::incrementVelocity(double dvel) {
	velocity += dvel;
}
void Cannon::decrementVelocity(double dvel) {
	velocity -= dvel;
}

Cannonball Cannon::shoot() {
	return Cannonball(theta, velocity, getTipX(), getTipY());
}

double Cannon::getTipX() const {
	return length*cos(degToRad(theta));
}
double Cannon::getTipY() const {
	return length*sin(degToRad(theta));
}

/////////////////////////////CANNONBALL/////////////////////////////////////////
Cannonball::Cannonball(double angle, double initial_velocity, 
	double startPosX, double startPosY) {
	this->startPosX = startPosX;
	this->startPosY = startPosY;
	getVelocityVector(angle, initial_velocity,
		&startVelX, &startVelY);
	shape = sf::CircleShape(size);
	shape.setOrigin(size, size);
	shape.setFillColor(sf::Color::Yellow);
}

double Cannonball::getPosX() const {
    return posX(startPosX, startVelX, getAirTime());
}

double Cannonball::getPosY() const {
    return posY(startPosY, startVelY, getAirTime());
}

void Cannonball::update() {
	shape.setPosition((float)getPosX(), (float)getPosY());
}

void Cannonball::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

bool operator==(const Cannonball &c1, const Cannonball &c2) {	return c1.clock.getElapsedTime() == c2.clock.getElapsedTime();}
