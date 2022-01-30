/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GLVisualAudioProcessorEditor::GLVisualAudioProcessorEditor (GLVisualAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    scope2D = std::make_unique<Oscilloscope2D>(audioProcessor.getRingBuffer());
    addAndMakeVisible(scope2D.get());
    scope2D->start();
    //spectrum = std::make_unique<Spectrum>(audioProcessor.getRingBuffer());
   // addAndMakeVisible(spectrum.get());

    setSize (400, 300);
}

GLVisualAudioProcessorEditor::~GLVisualAudioProcessorEditor()
{
    if (scope2D != nullptr)
    {
        scope2D->stop();
        removeChildComponent(scope2D.get());
        delete scope2D.get();
    }

    //if (spectrum != nullptr)
    //{
    //    spectrum->stop();
    //    removeChildComponent(spectrum.get());
    //    delete spectrum.get();
    //}

}

//==============================================================================
void GLVisualAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.setColour(Colours::black);
    g.fillAll();

}

void GLVisualAudioProcessorEditor::resized()
{
    scope2D->setBoundsRelative(0.05, 0.1, 0.9, 0.9);
}

void GLVisualAudioProcessorEditor::newOpenGLContextCreated()
{

}

void GLVisualAudioProcessorEditor::openGLContextClosing()
{
    //reset shaders and such
}

void GLVisualAudioProcessorEditor::renderOpenGL()
{



}


