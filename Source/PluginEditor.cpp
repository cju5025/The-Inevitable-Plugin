/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Delay03AudioProcessorEditor::Delay03AudioProcessorEditor (Delay03AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    setSize (250, 250);
    
    auto& params = processor.getParameters();
    
    //drywet slider
    AudioParameterFloat* dryWetParameter = (AudioParameterFloat*)params.getUnchecked(0);
    
    mDryWetSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mDryWetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 15);
    mDryWetSlider.setRange(dryWetParameter->range.start, dryWetParameter->range.end);
    mDryWetSlider.setValue(*dryWetParameter);
    addAndMakeVisible(mDryWetSlider);
    
    mDryWetSlider.onValueChange = [this, dryWetParameter] { *dryWetParameter = mDryWetSlider.getValue(); };
    
    mDryWetSlider.onDragStart = [dryWetParameter] { dryWetParameter->beginChangeGesture(); };
    
    mDryWetSlider.onDragEnd = [dryWetParameter] { dryWetParameter->endChangeGesture(); };
    
    //depth slider
    AudioParameterFloat* depthParameter = (AudioParameterFloat*)params.getUnchecked(1);
    
    mDepthSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mDepthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 15);
    mDepthSlider.setRange(depthParameter->range.start, depthParameter->range.end);
    mDepthSlider.setValue(*depthParameter);
    addAndMakeVisible(mDepthSlider);
    
    mDepthSlider.onValueChange = [this, depthParameter] { *depthParameter = mDryWetSlider.getValue(); };
    
    mDepthSlider.onDragStart = [depthParameter] { depthParameter->beginChangeGesture(); };
    
    mDepthSlider.onDragEnd = [depthParameter] { depthParameter->endChangeGesture(); };
    
    //rate slider
    AudioParameterFloat* rateParameter = (AudioParameterFloat*)params.getUnchecked(2);
    
    mRateSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mRateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 15);
    mRateSlider.setRange(rateParameter->range.start, rateParameter->range.end);
    mRateSlider.setValue(*rateParameter);
    addAndMakeVisible(mRateSlider);
    
    mRateSlider.onValueChange = [this, rateParameter] { *rateParameter = mDryWetSlider.getValue(); };
    
    mRateSlider.onDragStart = [rateParameter] { rateParameter->beginChangeGesture(); };
    
    mRateSlider.onDragEnd = [rateParameter] { rateParameter->endChangeGesture(); };
    
    
    //feedback slider
    AudioParameterFloat* feedbackParameter = (AudioParameterFloat*)params.getUnchecked(3);
    
    mFeedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 15);
    mFeedbackSlider.setRange(feedbackParameter->range.start, feedbackParameter->range.end);
    mFeedbackSlider.setValue(*feedbackParameter);
    addAndMakeVisible(mFeedbackSlider);
    
    mFeedbackSlider.onValueChange = [this, feedbackParameter] { *feedbackParameter = mFeedbackSlider.getValue(); };
    
    mFeedbackSlider.onDragStart = [feedbackParameter] { feedbackParameter->beginChangeGesture(); };
    
    mFeedbackSlider.onDragEnd = [feedbackParameter] { feedbackParameter->endChangeGesture(); };
    
}

Delay03AudioProcessorEditor::~Delay03AudioProcessorEditor()
{
}

//==============================================================================
void Delay03AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
    g.drawText("Mix", 1, 18, 100, 100, Justification::centred, false);

}

void Delay03AudioProcessorEditor::resized()
{
    mDryWetSlider.setBounds(0, 25, 100, 100);
    mFeedbackSlider.setBounds(100, 25, 100, 100);
    mDepthSlider.setBounds(0, 150, 100, 100);
    mRateSlider.setBounds(100, 150, 100, 100);
}

