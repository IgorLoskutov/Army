#include "State.hpp"
#include <iostream>

State::State(std::string& nature,std::string& status, std::string& role) :	nature(new std::string(nature)), status(new std::string(status)), role(new std::string(role)) {}
State::State() {
	this->nature = new std::string("undefined");
	this->status = new std::string("undefined");
	this->role = new std::string("undefined");
}

State::~State(){
	delete(this->nature);
	delete(this->status);
	delete(this->role);
}

const std::string& State::getNature() const {
	return *this->nature;
}

const std::string& State::getStatus() const {
	return *this->status;
}

const std::string& State::getRole() const {
	return *this->role;
}



std::ostream& operator<<(std::ostream& out, State& state) {
	out << "\n|nature: " << state.getNature();
	out << "|status: " << state.getStatus();
	out << "|role: " << state.getRole();

	return out;
}