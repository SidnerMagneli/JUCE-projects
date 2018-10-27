/*
  ==============================================================================

    SynthSound.h
    Created: 21 Oct 2018 4:26:41pm
    Author:  Sidner

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
	bool appliesToNote(int midiNoteNumber) 
	{
		return true;
	}

	bool appliesToChannel(int midiChannel)
	{
		return true;
	}
};
