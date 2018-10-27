/*
  ==============================================================================

    SynthVoice.h
    Created: 21 Oct 2018 4:26:55pm
    Author:  Sidner

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include <iostream>
#include <string>

class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound * sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound * sound, int currentPitchWheelPosition)
	{
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		Logger::outputDebugString(std::to_string(midiNoteNumber));
	}

	void stopNote(float velocity, bool allowTailOff)
	{
		clearCurrentNote();
	}

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{

	}

	void pitchWheelMoved(int newPitchWheelValue)
	{

	}

	void controllerMoved(int controllerNumber, int newControllerValue)
	{

	}

private:
	double level;
	double frequency;
};