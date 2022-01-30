/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "RingBuffer.h"

//==============================================================================
/**
    GOAL:  Offer openGL capabilities in a VST3 / AU

        1.) Load shaders
            a.) Parse correctly (version, text format, file location)
            b.) Close context and reload with new shader
            c.) Application Command Manager for selections

        2.) Handle Matrices of variable type/size (vectors included)
            a.) Varied fill options e.g. GL_DRAW_TRIANGLES / GL_DRAW_POINTS 
            b.) Transform in real time
            c.) Draw with solid colors

        3.) Load Shapes
            a.) Basic Mesh with assignable vertex positions
            b.) load from .obj / .svg
            c.) Draw primitives

        4.) Load Textures
            a.) handle all photo types, especially jpeg / png
            b.) handle all video types, especially .mov / .mp4
            c.) Texture map options
*/
class GLVisualAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    GLVisualAudioProcessor();
    ~GLVisualAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    RingBuffer<float>* getRingBuffer();
private:
    
    RingBuffer<float>* ringBuffer;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GLVisualAudioProcessor)
};
