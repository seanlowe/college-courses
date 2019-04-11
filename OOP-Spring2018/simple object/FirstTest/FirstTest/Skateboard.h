#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include "pch.h"

class AssertionError {
public: std::string message;
public: AssertionError(const std::string &_message) : message(_message) {}
};

// -- actual class stuff

class Skateboard {
public: Skateboard();

public: bool isMoving();
public: bool isGreased();
public: void grease();
public: void clean();
public: void kickOff();
public: void tailGrind();

protected: bool moving;
protected: bool greased;
};

class PoweredSkateboard : public Skateboard {
public: PoweredSkateboard();

public: bool isCharged();
public: void charge();
public: void ActivateBoost();

protected: bool charged;
};