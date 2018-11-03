/*
  ==============================================================================

    SynthVoice.h
    Created: 21 Oct 2018 4:26:55pm
    Author:  Sidner

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Maximilian.h"
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
		env1.trigger = 1;

		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		Logger::outputDebugString(std::to_string(midiNoteNumber));
	}

	void stopNote(float velocity, bool allowTailOff)
	{
		env1.trigger = 0;
		allowTailOff = true;

		if (velocity = 0)
		{
			clearCurrentNote();
		}
	}

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		// set adsr for voice
		env1.setAttack(10);
		env1.setDecay(500);
		env1.setSustain(0.8);
		env1.setRelease(200);

		for (int sample = 0; sample < numSamples; ++sample)
		{
			// create sound wave to output
			float wave = osc1.saw(frequency);
			float sound = env1.adsr(wave, env1.trigger) * level;
			float filteredSound = filter1.lores(sound, 3000, 0.5);

			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{
				outputBuffer.addSample(channel, startSample, filteredSound);
			}
			++startSample;
		}
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

	maxiOsc osc1;
	maxiEnv env1;
	maxiFilter filter1;
};