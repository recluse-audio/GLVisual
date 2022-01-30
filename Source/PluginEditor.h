/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscilloscope2D.h"
#include "Spectrum.h"

//==============================================================================
/**
*/
class GLVisualAudioProcessorEditor  : public juce::AudioProcessorEditor, 
    private OpenGLRenderer
{
public:
    GLVisualAudioProcessorEditor (GLVisualAudioProcessor&);
    ~GLVisualAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    /* Renderer pure virtual functions*/
    void newOpenGLContextCreated() override;
    void openGLContextClosing() override;
    void renderOpenGL() override;

    Matrix3D<float> getProjectionMatrix() const;
    Matrix3D<float> getViewMatrix() const;
    


private:
    GLVisualAudioProcessor& audioProcessor;

    std::unique_ptr<Oscilloscope2D> scope2D;
    std::unique_ptr<Spectrum> spectrum;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GLVisualAudioProcessorEditor)
};
