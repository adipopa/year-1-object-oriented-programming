#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingValidator.h"
#include "RecordingRepository.h"

class RecordingController {

private:
	RecordingValidator* recordingValidator;
	RecordingRepository* recordingRepository;
	std::string clearanceLevel;

public:
	RecordingController(RecordingValidator* recordingValidator, RecordingRepository* recordingRepository, const std::string clearanceLevel)
		: recordingValidator(recordingValidator), recordingRepository(recordingRepository), clearanceLevel(clearanceLevel) {};

	void setMode(const char mode);

	void addRecording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
		const int& timesAccessed, const std::string& footagePreview);

	void updateRecording(const std::string& title, const std::string& newLocation, const std::string& newTimeOfCreation,
		const int& newTimesAccessed, const std::string& newFootagePreview);

	void deleteRecording(const std::string& title);

	DynamicVector<Recording> getRecordings() const;

	Recording getNextRecording();

	void saveRecording(const std::string& title);

	DynamicVector<Recording> getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed);

	DynamicVector<Recording> getWatchlist();
};