#pragma once

#include <exception>
#include <string>

class RecordingException : public std::exception {

private:
	std::string message;

public:
	RecordingException(const std::string& message) : message(message) {}

	virtual const char* what() const noexcept override {
		return message.c_str();
	}

	~RecordingException() {}
};